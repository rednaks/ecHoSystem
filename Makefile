CC = gcc

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



all:client server


client:$(CLIENT_TARGET)
	@echo "Compilation du client terminée"

$(CLIENT_TARGET):$(CLIENT_OBJ) $(CLIENT_SRC_DIR)/main.c
	$(CC) $(CLIENT_SRC_DIR)/main.c $(CLIENT_OBJ) -o $(CLIENT_TARGET)

$(CLIENT_OBJ):$(CLIENT_OBJ_DIR) $(CLIENT_SRC_DIR)/client.h $(CLIENT_SRC_DIR)/client.c
	$(CC) -c $(CLIENT_SRC_DIR)/client.c -o $(CLIENT_OBJ)

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)


server:$(SERVER_TARGET)
	@echo "Compilation du serveur terminée"

$(SERVER_TARGET):$(SERVER_OBJ) $(SERVER_SRC_DIR)/main.c
	$(CC) $(SERVER_SRC_DIR)/main.c $(SERVER_OBJ) -o $(SERVER_TARGET)

$(SERVER_OBJ):$(SERVER_OBJ_DIR) $(SERVER_SRC_DIR)/server.c $(SERVER_SRC_DIR)/server.h $(SERVER_SRC_DIR)/clientInfo.h
	$(CC) -c $(SERVER_SRC_DIR)/server.c -o $(SERVER_OBJ)

$(SERVER_OBJ_DIR):
	mkdir -p $(SERVER_OBJ_DIR)

clean:
	rm -r bin/
