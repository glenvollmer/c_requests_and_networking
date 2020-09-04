client.o:
	gcc -c src/client.c -o build/client.o

server.o:
	gcc -c src/server.c -o build/server.o

all: client.o server.o
	gcc build/client.o -o build/client
	gcc build/server.o -o build/server

run:
	# Run the server as a background process. Space after nohup is required.
	nohup ./build/server &

	# Run the client now that the server is up.
	./build/client

clean:
	# Gets rid of executables (without a file extension) using the find command
	# then specifically removes the object files.
	find ./build -type f -not -iname "*.*" -delete && rm -f build/*.o