#include "banco.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarSenha(char *senha){
    if(strlen(senha) < PASSWORD_LENGTH) return 0;
    int temLetra = 0, temNumero = 0;
    for(int i = 0; senha[i]; i++){
        if(isalpha(senha[i]))temLetra = 1;
	if(isdigit(senha[i]))temNumero = 1;
    }
    return temLetra && temNumero;
}

int gerarConta(char *conta){
    for(int i = 0; i < ACCOUNT_LENGTH; i++){
        conta[i] = '0' + (rand() % 10);
    
    }
    conta[ACCOUNT_LENGTH] = '\0';
    return validarConta(conta) ? 0 : gerarConta(conta);
}

int validarConta(char *conta){
    for(int i = 0; i < strlen(conta) - 1; i++){
        if(abs(conta[i] - conta[i + 1]) == 1)return 0;
    }
    return 1;
}
