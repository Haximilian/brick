CC=g++
CFLAGS=-std=c++11 -g

client:
	$(CC) $(CFLAGS) -I ./include client.cpp -o client

server:
	$(CC) $(CFLAGS) -I ./include main.cpp -o server

clean:
	rm ./client ./server
