// PARA RODAR -> CTRL SHIFT B
// PARA DEBUGAR -> F5

#include <stdio.h>

int menu() {
  int opcao;
  printf("\n 1. Cadastrar um novo cliente em uma posição específica. \n 2. "
         "Consultar um cliente pelo número da conta. \n3. Atualizar o saldo de "
         "um cliente. \n4. Encerra conta (remover cliente). \n5. Listar todos "
         "os clientes. \n6. Restaurar a leitura do arquivo do início com "
         "`rewind()` para repetir a listagem. \n7. Encerrar.\n");
  scanf("%d", &opcao);
  return opcao;
}

typedef struct Cliente {
  int id;
  char nome[155];
  int numeroConta;
  float saldo;
} cliente;

int main(void) {
  int escolha;
  FILE *listaClientes;
  listaClientes = fopen("clientes.dat", "ab+");

  if (listaClientes == NULL) {
    printf("Erro ao abrir o arquivo \n");
  } else {
    do {
      escolha = menu();

      switch (escolha) {
      case 1:
        printf("Vamos fazer o seu Cadastro, informe seu nome: \n");
        
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      default:
        printf("A opção digitada é inválida");
        break;
      }
    } while (escolha != 7);
  };
  fclose(listaClientes);
  return 0;
}
