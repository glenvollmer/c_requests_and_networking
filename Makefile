# tool macros
CC := gcc
CCFLAGS := -O2
DBGFLAGS := #-g
CCOBJFLAGS := $(CCFLAGS) -c

# path macros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src

# default rule
default: makedir all

# non-phony targets
$(BIN_PATH)/client: $(OBJ_PATH)/client.o
	$(CC) $(CCFLAGS) $(DBGFLAGS) $(OBJ_PATH)/client.o -o $(BIN_PATH)/client

$(BIN_PATH)/server: $(OBJ_PATH)/server.o
	$(CC) $(CCFLAGS) $(DBGFLAGS) $(OBJ_PATH)/server.o -o $(BIN_PATH)/server

$(OBJ_PATH)/client.o: $(SRC_PATH)/client.c
	$(CC) $(CCOBJFLAGS) $(DBGFLAGS) $(SRC_PATH)/client.c -o $(OBJ_PATH)/client.o

$(OBJ_PATH)/server.o: $(SRC_PATH)/server.c
	$(CC) $(CCOBJFLAGS) $(DBGFLAGS) $(SRC_PATH)/server.c -o $(OBJ_PATH)/server.o

# phony rules
.PHONY: run
run:
	@# Run the server as a background process. Space after nohup is required.
	nohup ./bin/server &
	

	@# Run the client now that the server is up.
	./bin/client

.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: all
all: $(BIN_PATH)/client $(BIN_PATH)/server

.PHONY: clean
clean:
	@# "@" prevents this text from echoing to the terminal. We still need the hash so make knows this is a comment.
	@# Gets rid of executables (without a file extension) using the find command
	@# then specifically removes the object files.
	@# find ./bin -type f -not -iname "*.*" -delete && rm -f obj/*.o
	@rm -r bin obj