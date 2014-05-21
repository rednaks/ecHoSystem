CC = clang

SRC_DIR = src
SERVER_SRC_DIR = $(SRC_DIR)/server
CLIENT_SRC_DIR = $(SRC_DIR)/client

OBJ_DIR = bin
SERVER_OBJ_DIR = $(OBJ_DIR)/server
CLIENT_OBJ_DIR = $(OBJ_DIR)/client

CLIENT_OBJ = $(CLIENT_OBJ_DIR)/client.o
CLIENT_TARGET = $(CLIENT_OBJ_DIR)/client.bin

SERVER_OBJ = $(SERVER_OBJ_DIR)/server.o
SERVER_TARGET = $(SERVER_OBJ_DIR)/server.bin

COMMON_SRC_DIR = $(SRC_DIR)/common
COMMON_OBJ_DIR = $(OBJ_DIR)/common
MESSAGES_OBJ = $(COMMON_OBJ_DIR)/messages.o




all:client server


client:$(CLIENT_TARGET)
	@echo "Compilation du client terminée"

$(CLIENT_TARGET):$(MESSAGES_OBJ) $(CLIENT_OBJ) $(CLIENT_SRC_DIR)/main.c
	$(CC) $(CLIENT_SRC_DIR)/main.c $(MESSAGES_OBJ) $(CLIENT_OBJ) -o $(CLIENT_TARGET)

$(CLIENT_OBJ):$(CLIENT_OBJ_DIR) $(CLIENT_SRC_DIR)/client.h $(CLIENT_SRC_DIR)/client.c
	$(CC) -c $(CLIENT_SRC_DIR)/client.c -o $(CLIENT_OBJ)

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)


server:$(SERVER_TARGET)
	@echo "Compilation du serveur terminée"

$(SERVER_TARGET):$(MESSAGES_OBJ) $(SERVER_OBJ) $(SERVER_SRC_DIR)/main.c
	$(CC) $(SERVER_SRC_DIR)/main.c $(MESSAGES_OBJ) $(SERVER_OBJ) -o $(SERVER_TARGET)

$(SERVER_OBJ):$(SERVER_OBJ_DIR) $(SERVER_SRC_DIR)/server.c $(SERVER_SRC_DIR)/server.h $(SERVER_SRC_DIR)/clientInfo.h
	$(CC) -c $(SERVER_SRC_DIR)/server.c -o $(SERVER_OBJ)

$(SERVER_OBJ_DIR):
	mkdir -p $(SERVER_OBJ_DIR)


$(MESSAGES_OBJ):$(COMMON_OBJ_DIR) $(COMMON_SRC_DIR)/messages.h $(COMMON_SRC_DIR)/messages.c
	$(CC) -c $(COMMON_SRC_DIR)/messages.c -o $(MESSAGES_OBJ)

$(COMMON_OBJ_DIR):
	mkdir -p $(COMMON_OBJ_DIR)

clean:
	rm -r bin/
