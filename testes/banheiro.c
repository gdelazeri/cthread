/*	Este programa testa todas as primitivas da biblioteca cthread.h. 
	O programa faz uma analogia a situação em que 50 pessoas
	querem utilizar um banheiro público, tendo a possibilidade 
	de já ter alguém utilizando o banheiro (thread usando o recurso).
	As pessoas simulam as threads e o banheiro simula o semáforo.
	Quando alguém entra no banheiro, mais ninguém pode entrar.
*/


#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "../include/support.h"
#include "../include/cthread.h"

#define MAX_BANHEIRO 50
csem_t ban;

void* entrarNoBanheiro(void* arg)
{	
	int j;

	printf("Pessoa %d diz: \t'Quero entrar no banheiro. Sera que esta ocupado?'\n",(int)arg);
	cwait(&ban);
	printf("Pessoa %d diz: \t'Consegui entrar no banheiro!' \n",(int)arg);
	for (j=0;j<1000;j++);	//Tempo de usar o banheiro
	cyield();
	printf("Pessoa %d diz: \t'Pronto! Maos limpas, estou saindo do banheiro.' :) \n",(int)arg);
	csignal(&ban);

	return NULL;
}


int main(int argc, char *argv[]) {

	int	id[MAX_BANHEIRO];
	int i;
	char names[100];	

	printf("\nCASO DE TESTE DA BIBLIOTECA cthread\n\n");
	csem_init(&ban,1);

	for(i=1; i <= MAX_BANHEIRO; i++){
		id[i] = ccreate(entrarNoBanheiro, (void *)(i));
	}

	for(i=1; i <= MAX_BANHEIRO; i++){
		cjoin(id[i]);
	}

	printf("Todas as pessoas foram ao banheiro\n\n");
	printf("FIM DO CASO DE TESTE\n\n");
	cidentify(names, 100);
	printf("Nomes:\n %s", names);

	return 0;
}
