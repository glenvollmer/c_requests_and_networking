client.o:
	gcc -c src/client.c -o build/client.o

server.o:
	gcc -c src/server.c -o build/server.o

all: client.o server.o
	gcc build/client.o -o build/client
	gcc build/server.o -o build/server

run:
	# Needs work
	./build/client && ./build/server

clean:
	rm -f build/*