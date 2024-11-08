#include "banco.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Usuario usuarios[MAX_USERS];
    int numUsuarios = 0;
    int opcao;

    while(1){    
        printf("\nMenu banco\n");
	printf("1. Criar conta\n");
	printf("2. Login\n");
	printf("3. Sair\n");
	printf("Escolha uma opção: ");
	scanf("%d", &opcao);

	switch(opcao){
	    case 1:
		criarConta(usuarios, &numUsuarios);
		break;
	    case 2: {
	        int usuarioIndex = realizarLogin(usuarios, numUsuarios);
		if(usuarioIndex >= 0){
		    printf("Acesso liberado para o menu de transações.\n");
		}
		break;
	    }	
	    case 3:
	        printf("Saindo...\n");
		return 0;
	    default:
	        printf("Opção inválida.\n");	
	
	}
    }
    return 0;



}
