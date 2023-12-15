#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <termios.h>
#include <X11/Xlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

int get_pos(int *y, int *x);

static int _XlibErrorHandler(Display *display, XErrorEvent *event) {
    fprintf(stderr, "An error occured detecting the mouse position\n");
    return True;
}

int get_pos(int* x, int* y) {
    int number_of_screens;
    int i;
    Bool result;
    Window *root_windows;
    Window window_returned;
    int root_x, root_y;
    int win_x, win_y;
    unsigned int mask_return;
    
    Display *display = XOpenDisplay(NULL);
    assert(display);
    XSetErrorHandler(_XlibErrorHandler);
    number_of_screens = XScreenCount(display);
    fprintf(stderr, "There are %d screens available in this X session\n", number_of_screens);
    root_windows = (Window*)malloc(sizeof(Window) * number_of_screens);
    for (i = 0; i < number_of_screens; i++) {
        root_windows[i] = XRootWindow(display, i);
    }
    for (i = 0; i < number_of_screens; i++) {
        result = XQueryPointer(display, root_windows[i], &window_returned,
                &window_returned, &root_x, &root_y, &win_x, &win_y,
                &mask_return);
        if (result == True) {
            break;
        }
    }
    if (result != True) {
        fprintf(stderr, "No mouse found.\n");
        return -1;
    }
    *x = root_x;
    *y = root_y;
    
    free(root_windows);
    XCloseDisplay(display);
    return 0;
}

std::string getEnvVar( std::string const & key ) {
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

void connection_handler(int socket) {
    char client_message[256];
    char msgBuff[256];
    memset(&msgBuff, 0, 256);
    size_t message_size = 0;
    struct termios oldattr, newattr;
    int dir;

    message_size = recv(socket, msgBuff, sizeof(msgBuff) - 1, 0);
    msgBuff[message_size] = '\0';
    cout << "[Server] Client message accepted" << endl;
    cout << "[Server] Client message: " << msgBuff[1] << endl;


    if (msgBuff[1] == '1') {
        while ((message_size = recv(socket, client_message, sizeof(client_message) - 1, 0)) > 0) {
            client_message[message_size] = '\0';
            cout << "[Server] Client message accepted" << endl;
            cout << "[Server] Client message: " << client_message << endl;

            //FILE* file = fopen("nonexistent_file.txt", "r");
            
            string fullMsg;
            if (msgBuff[0]=='3') {
                return;
            } else if (msgBuff[0]=='1') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);

                // Store the string in a std::string variable
                std::string timeStr(timeString);
                fullMsg = (string)timeString + " :: " + errmsg;
            } else if (msgBuff[0]=='2') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);

                int x = 0, y = 0;
                get_pos(&y, &x);
                char str[100];
                sprintf(str,"%d %d",x,y);
                fullMsg = (string)timeString + " :: " + string(str);
            } else {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);

                int x = 0, y = 0;
                get_pos(&y, &x);
                char str[100];
                sprintf(str,"%d %d",x,y);
                fullMsg = (string)timeString + " :: " + string(str) + " :: " +  std::to_string(errno);
            }
            
            if (write(socket, fullMsg.c_str(),fullMsg.size()) == -1) {
                cout << "[Client] Message sending failed" << endl;
                return;
            }
            cout << "[Server] Message sent to client" << endl << endl;
            cout << "============================" << endl << endl;
            cout.flush();

            memset(&client_message, 0, 256);
        }

    } else {
        while ((message_size = recv(socket, client_message, sizeof(client_message) - 1, 0)) > 0) {
            client_message[message_size] = '\0';
            cout << "[Server] Client message accepted" << endl;
            cout << "[Server] Client message: " << client_message << endl;

            

            string fullMsg;
            if (msgBuff[0]=='3') {
                return;
            } else if (msgBuff[0]=='1') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);

                // Store the string in a std::string variable
                std::string timeStr(timeString);
                fullMsg = (string)timeString + " :: " + errmsg;
            } else if (msgBuff[0]=='2') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);

                int x = 0, y = 0;
                get_pos(&y, &x);
                char str[100];
                sprintf(str,"%d %d",x,y);
                fullMsg = (string)timeString + " :: " + string(str);
            } else {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);

                int x = 0, y = 0;
                get_pos(&y, &x);
                char str[100];
                sprintf(str,"%d %d",x,y);
                fullMsg = (string)timeString + " :: " + string(str) + " :: " +  std::to_string(errno);
            }
            if (write(socket, fullMsg.c_str(),fullMsg.size()) == -1) {
                cout << "[Client] Message sending failed" << endl;
                return;
            }
            cout << "[Server] Message sent to client" << endl << endl;
            cout << "============================" << endl << endl;
            cout.flush();

            memset(&client_message, 0, 256);
        }

    }
    memset(&msgBuff, 0, 256);
}

int main() {
    unsigned short int PORT = 8080;
    int listener, client_socket;
    socklen_t client_len;

    struct sockaddr_in server_address{};

    memset(&server_address, 0, sizeof(server_address));

    listener = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_aton("127.0.0.1", &server_address.sin_addr) == 0) {
        cout << "[Server] Invalid IP address" << endl;
        return -1;
    }

    if (bind(listener, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        cout << "[Server] Binding failed" << endl;
        return -1;
    }
    cout << "[Server] All setting are done" << endl;
    cout << "[Server] Server enabled" << endl;

    if (listen(listener, 100) == -1) {
        cout << "[Server] Listening failed" << endl;
        return -1;
    }
    cout << "[Server] Waiting for connection..." << endl;

    for (; ;) {
        client_socket = accept(listener, (struct sockaddr*) &server_address, &client_len);
        cout << "[Server] Connection accepted" << endl << endl;
        cout << "----------------------------" << endl << endl;

        int* new_socket = new int;
        *new_socket = client_socket;

        thread handling_thread(connection_handler, *new_socket);
        handling_thread.detach();
    }
}
