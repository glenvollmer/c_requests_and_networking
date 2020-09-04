all:
	gcc src/client.c -o build/client
	gcc src/server.c -o build/server

run:
	./build/client && ./build/server

clean:
	rm -f build/*