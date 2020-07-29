CC=g++
CFLAGS=-std=c++11 -g

all: flatbuffers client server

flatbuffers:
	./flatc --cpp transaction.fbs

client:
	$(CC) $(CFLAGS) -I ./include client.cpp -o client

server:
	$(CC) $(CFLAGS) -I ./include main.cpp -o server

clean:
	rm ./transaction_generated.h ./client ./server