FROM amytabb/docker_ubuntu16_essentials
COPY ./* /app
WORKDIR /app
RUN g++ -std=c++11 client.cpp -o client
