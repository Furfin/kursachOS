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

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getValue() { //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

int getPValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
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
                std::string timeStr(timeString);
                char str[100];
                long double pval = ((long double)getPValue()/(long double)7917488);
                sprintf(str,"%Lf",pval);
                fullMsg = (string)timeString + " :: " + string(str);
            } else if (msgBuff[0]=='2') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);
                char str[100];
                long double val = ((long double)getValue()/(long double)1016736);
                sprintf(str,"%Lf",val);
                fullMsg = (string)timeString + " :: " + string(str);
            } else {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);
                char str[100];
                long double pval = ((long double)getPValue()/(long double)7917488);
                long double val = ((long double)getValue()/(long double)1016736);
                sprintf(str,"%Lf :: %Lf",val, pval);
                fullMsg = (string)timeString + " :: " + string(str);
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
                std::string timeStr(timeString);
                char str[100];
                long double pval = ((long double)getPValue()/(long double)7917488);
                sprintf(str,"%Lf",pval);
                fullMsg = (string)timeString + " :: " + string(str);
            } else if (msgBuff[0]=='2') {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);
                char str[100];
                long double val = ((long double)getValue()/(long double)1016736);
                sprintf(str,"%Lf",val);
                fullMsg = (string)timeString + " :: " + string(str);
            } else {
                string errmsg = std::to_string(errno);
                std::time_t currentTime = std::time(nullptr);
                std::tm* localTime = std::localtime(&currentTime);
                char timeString[100];
                std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
                std::string timeStr(timeString);
                char str[100];
                long double pval = ((long double)getPValue()/(long double)7917488);
                long double val = ((long double)getValue()/(long double)1016736);
                sprintf(str,"%Lf :: %Lf",val, pval);
                fullMsg = (string)timeString + " :: " + string(str);
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
    unsigned short int PORT = 8081;
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
