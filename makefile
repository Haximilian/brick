CC=g++
CFLAGS=-std=c++11 -g

all: flatbuffers client server test_client_read

flatbuffers:
	./flatc --cpp transaction.fbs

client:
	$(CC) $(CFLAGS) -I ./include client.cpp -o client

server:
	$(CC) $(CFLAGS) -I ./include main.cpp -o server

test_client_read:
	$(CC) $(CFLAGS) -I ./include test_client_read.cpp -o test_client_read

clean:
	rm ./transaction_generated.h ./client ./server
