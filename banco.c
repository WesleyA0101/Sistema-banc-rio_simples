#include "banco.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int criarConta(Usuario *usuarios, int *numUsuarios){
    if(*numUsuarios >= MAX_USERS){
        printf("Número máximo de usuários atingidos.\n");
	return -1;
    }

    Usuario novoUsuario;
    printf("Digite o nome do usuario: ");
    scanf("%s", novoUsuario.nome);

    printf("Digite a senha (mínimo de %d caracteres): ", PASSWORD_LENGTH);
    scanf("%s", novoUsuario.senha);

    if(!validarSenha(novoUsuario.senha)){
        printf("Senha inválida!!\n");
	return -1;
    }

    gerarConta(novoUsuario.conta);
    novoUsuario.saldo = 0.0;

    FILE *file = fopen("contas.txt", "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo para salvar informações da conta.\n");
	return -1;
    }
    fprintf(file, "Nome: %s\nConta: %s\nSenha: %s\nSaldo: %.2f\n\n", novoUsuario.nome, novoUsuario.conta, novoUsuario.senha, novoUsuario.saldo);
    fclose(file);

    usuarios[*numUsuarios] = novoUsuario;
    (*numUsuarios)++;
    printf("Conta criada com sucesso""\n");
    printf("Número da conta: %s\n", novoUsuario.conta);
    return 0;
}


int realizarLogin(Usuario *usuarios, int numUsuarios){
    char conta[ACCOUNT_LENGTH + 1];
    char senha[PASSWORD_LENGTH + 1];

    printf("Digite o número da conta: ");
    scanf("%s", conta);

    printf("Digite a senha: ");
    scanf("%s", senha);

    for(int i = 0; i < numUsuarios; i++){
        if(strcmp(usuarios[i].conta, conta) == 0 && strcmp(usuarios[i].senha, senha) == 0){
	    printf("Login realizado!!\n");
	    

	    int opcaoTransacao;
	    while(1){
	        printf("\nMenu de transações: \n");
		printf("1. Realizar Pix\n");
		printf("2. Realizar TED\n");
		printf("3. Ver saldo\n");
		printf("4. Sair");
		printf("Escolha uma opção: ");
		scanf("%d", &opcaoTransacao);

		switch(opcaoTransacao){
		    case 1:
			realizarPix(usuarios, numUsuarios, i);
		        break;
		    case 2:
		        realizarTed(usuarios, numUsuarios, i);
		        break;
		    case 3:
		        printf("Saldo: %.2f\n", usuarios[i].saldo);
		        break;
		    case 4:
		        printf("Encerrando...\n");
		        break;
		    default:
		        printf("Opção inválida!!\n");	
		}
	    
	    }
	}
    
    }
    printf("Conta ou senha incorretas.\n");
    return -1;
}

void mostrarContas(){
    FILE *file = fopen("contas.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo de contas.\n");
	return;
    }

    char linha[256];
    while(fgets(linha, sizeof(linha), file)){
        printf("%s", linha);
    }
    fclose(file);

}

int realizarPix(Usuario *usuarios, int numUsuarios, int usuarioIndex){
    char contaDestino[ACCOUNT_LENGTH +1];
    float valor;
	
    printf("Digite o número da conta destino: ");
    scanf("%s", contaDestino);
    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);

    for(int i = 0; i < numUsuarios; i++){
	if(strcmp(usuarios[i].conta, contaDestino) == 0){
	    if(usuarios[usuarioIndex].saldo < valor){
	        printf("Saldo insuficiente.\n");
		return -1;
	    
	    }
	    usuarios[usuarioIndex].saldo -= valor;
	    usuarios[i].saldo += valor;
	    printf("Pix realizado com sucesso!! Saldo atual: %.2f\n", usuarios[usuarioIndex].saldo);
	    return 0;
	
	}
    }
    printf("Conta origem ou destino inválida.\n");
    return -1;
}

int realizarTed(Usuario *usuarios, int numUsuarios, int usuarioIndex){
    char contaDestino[ACCOUNT_LENGTH + 1];
    float valor;

    printf("Digite o número da conta destino: ");
    scanf("%s", contaDestino);
    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);

    for(int i = 0; i < numUsuarios; i++){
        if(strcmp(usuarios[i].conta, contaDestino) == 0){
	    if(usuarios[usuarioIndex].saldo < valor){
	        printf("Saldo insuficiente.\n");
		return -1;
	    }
	    usuarios[usuarioIndex].saldo -= valor;
	    usuarios[i].saldo += valor;
	    printf("TED realizado com sucesso! Saldo atual: %.2f\n", usuarios[usuarioIndex].saldo);
	    return 0;
	
	}
    }
    printf("Conta destino não encontrada.\n");
    return -1;

}




