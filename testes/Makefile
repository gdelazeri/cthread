
CC=gcc
LIB_DIR=../lib

all: teste_basico banheiro

teste_basico: teste_basico.c $(LIB_DIR)/libcthread.a
	$(CC) -o teste_basico teste_basico.c -L$(LIB_DIR) -lcthread -Wall

banheiro: banheiro.c $(LIB_DIR)/libcthread.a
	$(CC) -o banheiro banheiro.c -L$(LIB_DIR) -lcthread -Wall

clean:
	rm -rf teste_basico banheiro *.o *~

