CC = gcc

SRC_DIR = src
SERVER_SRC_DIR = $(SRC_DIR)/server
CLIENT_SRC_DIR = $(SRC_DIR)/client

OBJ_DIR = bin
SERVER_OBJ_DIR = $(OBJ_DIR)/server
CLIENT_OBJ_DIR = $(OBJ_DIR)/client

CLIENT_OBJ = $(CLIENT_OBJ_DIR)/client.o
CLIENT_TARGET = $(CLIENT_OBJ_DIR)/client.bin



all:client server


client:$(CLIENT_TARGET)
	@echo "Compilation du client terminée"

$(CLIENT_TARGET):$(CLIENT_OBJ) $(CLIENT_SRC_DIR)/client.c $(CLIENT_SRC_DIR)/client.h
	$(CC) $(CLIENT_SRC_DIR)/main.c $(CLIENT_OBJ) -o $(CLIENT_TARGET)

$(CLIENT_OBJ):$(CLIENT_OBJ_DIR) $(CLIENT_SRC_DIR)/client.h $(CLIENT_SRC_DIR)/client.c
	$(CC) -c $(CLIENT_SRC_DIR)/client.c -o $(CLIENT_OBJ)

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)


server:
	@echo "Pas encore implémenté"


clean:
	rm -r bin/
