CC=g++
CFLAGS=-std=c++11 -g

client:
	$(CC) $(CFLAGS) client.cpp -o client

server:
	$(CC) $(CFLAGS) main.cpp -o server

clean:
	rm ./client ./server
