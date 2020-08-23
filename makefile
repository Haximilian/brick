CC=g++
CFLAGS=-std=c++11 -g

all: flatbuffers server client

flatbuffers:
	./flatc --cpp transaction.fbs

server:
	$(CC) $(CFLAGS) -I ./include main.cpp -o server

client:
	$(CC) $(CFLAGS) -I ./include client.cpp -o client

clean:
	rm ./transaction_generated.h ./server ./client
