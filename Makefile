1:
	g++ server.cpp -lX11 -o server 
	g++ server2.cpp -lX11 -o server2
	g++ client.cpp -o client
dockerclient:
	docker build -t kurse .
	docker run --net=host -ti --rm kurse ./client