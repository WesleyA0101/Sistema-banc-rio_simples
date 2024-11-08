<div align="center">
  <img src="https://media3.giphy.com/media/xTiTnqUxyWbsAXq7Ju/giphy.webp?cid=790b7611dk4bbh7h4vmweeke3yekjcpvul177x55axaa54x1&ep=v1_gifs_search&rid=giphy.webp&ct=g" width="300" height="300" alt="banco"/>
</div>


# Projeto Banco em C

Este é um projeto simples de um sistema bancário desenvolvido em C, onde o usuário pode criar uma conta, fazer login e realizar transações como transferências via Pix. O sistema inclui funcionalidades básicas de segurança, como validação de senhas e criação de contas, além de salvar informações em um arquivo de texto, simulando um sistema bancário.

## Atenção

Esse projeto recebera atualizações e novas funcionalidades, ele é apenas uma simples simulação de conta bancária, para reforçar os estudos e habilidades em programação e para estudar a arquitetura básica de um aplicativo de banco.

## Funcionalidades

- Criação de Conta: Permite ao usuário criar uma conta com um nome, senha (que deve conter pelo menos uma letra e um número) e um número de conta gerado automaticamente.
- Login: O usuário pode se autenticar utilizando o número da conta e a senha.
- Pix: O sistema permite realizar transferências de valores entre contas.
- Arquivo de Contas: As contas criadas são armazenadas em um arquivo contas.txt, que inclui nome, número da conta, senha e saldo.

## Tecnologias Utilizadas

<div align="center">
  <img src="https://icongr.am/devicon/c-original.svg?size=128&color=currentColor" alt="C Logo" width="60" height="60"/>
  <img src="https://icongr.am/devicon/vim-original.svg?size=128&color=currentColor" alt="Vim Logo" width="60" height="60"/>
</div>


### 1. Clonando o Repositório

Clone o repositório para o seu computador:

```bash
git clone https://github.com/SeuUsuario/projeto-banco.git
cd projeto-banco
```

## Compilação
```bash
gcc -o banco main.c banco.c utils.c -Wall
```

## Como Rodar o Projeto
```bash
./banco
```


