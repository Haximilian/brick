CC=g++
CFLAGS=-std=c++11 -g

all: flatbuffers server test_client

flatbuffers:
	./flatc --cpp transaction.fbs

server:
	$(CC) $(CFLAGS) -I ./include main.cpp -o server

test_client:
	$(MAKE) -C ./client

clean:
	rm ./transaction_generated.h ./server
	$(MAKE) clean -C ./client
