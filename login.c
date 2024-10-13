#include "bot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10                                 // matriz 10x10
const char *ARQUIVO_USUARIOS = "usuarios.txt"; // Nome do arquivo de usuários

// Estrutura para navios. Cada navio tem uma coordenada linha x coluna
typedef struct navio {
    int linha;
    int coluna;
} Navio;

// Definição das cores (Códigos ANSI)
const char *BRed = "\033[1;31m";   // Cor vermelha em negrito
const char *BGreen = "\033[1;32m"; // Cor verde em negrito
const char *reset = "\033[0m";     // Reset de cores (voltar ao padrão)

// Estrutura para armazenar informações do usuário
typedef struct {
    char nome[50];  // Tamanho fixo para o nome do usuário
    char senha[50]; // Tamanho fixo para a senha do usuário
} Usuario;

// Prototipação das funções
int login_usuario(); // Altere aqui para retornar int
void cadastrar_usuario();
int menu(); // Prototipação da função menu

// Função para cadastrar um novo usuário
void cadastrar_usuario() {
    Usuario novo_usuario;
    FILE *arquivo =
        fopen(ARQUIVO_USUARIOS, "a"); // Abre o arquivo para adicionar (append)

    printf("Digite seu nome: ");
    scanf("%s", novo_usuario.nome);
    printf("Digite sua senha: ");
    scanf("%s", novo_usuario.senha);

    // Salva o usuário no arquivo
    fprintf(arquivo, "%s %s\n", novo_usuario.nome, novo_usuario.senha);
    fclose(arquivo);

    printf("Usuário cadastrado com sucesso!\n");
}

// Função para fazer login
int login_usuario() {
    Usuario usuario;
    char nome[50], senha[50]; // Tamanhos fixos para nome e senha
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "r"); // Abre o arquivo para leitura

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    // Verifica se o usuário existe no arquivo
    while (fscanf(arquivo, "%s %s", usuario.nome, usuario.senha) != EOF) {
        if (strcmp(usuario.nome, nome) == 0 && strcmp(usuario.senha, senha) == 0) {
            fclose(arquivo);
            printf("Login bem-sucedido! Bem-vindo, %s!\n", usuario.nome);
            return 1; // Login bem-sucedido
        }
    }

    fclose(arquivo);
    printf("Nome ou senha inválidos!\n");
    return 0; // Login falhou
}

int menu() {
    int opcao;

    do {
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar Usuário\n");
        printf("2 - Fazer Login\n");
        printf("3 - Sair\n");
        printf("Digite a opção escolhida: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar_usuario();
        } else if (opcao == 2) {
            if (login_usuario()) { // Verifique se o login foi bem-sucedido
                return 1; // Retorna 1 para indicar login bem-sucedido
            }
        }
    } while (opcao != 3);

    printf("Saindo...\n");
    return 0; // Retorna 0 para indicar saída
}

// Função principal
int main() {
    int op = menu(); // Chama a função menu

    if (op == 1) { // 
        
    }

    return 0; // Retorna 0 para o fim do programa
}

// Menu pós-login
int menu_pos_login() {
  int opcao;

  do {
    printf("\nEscolha uma opção:\n");
    printf("1 - Jogar\n");
    printf("2 - Sair\n");
    printf("Digite a opção escolhida: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      return 1; // Jogar
    } else if (opcao == 2) {
      printf("Saindo do jogo...\n");
      return 0; // Sair
    }
  } while (opcao != 2);

  return 0; 
}
