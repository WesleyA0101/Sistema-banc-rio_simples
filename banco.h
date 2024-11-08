#ifndef BANCO_H
#define BANCO_H

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define ACCOUNT_LENGTH 10
#define PASSWORD_LENGTH 8

typedef struct{
    char nome[100];
    char senha[100];
    char conta[ACCOUNT_LENGTH + 1];
    float saldo;
}Usuario;

//Função de cadastro e login
int criarConta(Usuario *usuarios, int *numUsuarios);
int realizarLogin(Usuario *usuarios, int numUsuarios);
void mostrarContas();
int realizarPix(Usuario *usuarios, int numUsuarios, int usuarioIndex);
int realizarTed(Usuario *usuarios, int numUsuarios, int usuarioIndex);
#endif
