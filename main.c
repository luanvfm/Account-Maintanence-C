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
  int id;          // 4 bytes
  char nome[155];  // 155 bytes
  int numeroConta; // 4 bytes
  float saldo;     // 4 bytes
} cliente;

int main(void) {
  int escolha;
  int contadorID = 0;
  FILE *listaClientes;
  listaClientes = fopen("clientes.dat", "rb+");

  if (listaClientes == NULL) {
    printf("Erro ao abrir o arquivo \n");
  } else {
    do {
      escolha = menu();

      switch (escolha) {
      case 1: {

        contadorID += 1;
        int posicao;
        cliente novoCliente;

        printf("Informe a posição que deseja cadastrar o Cliente: \n");
        scanf("%d", &posicao);

        fseek(listaClientes, sizeof(cliente) * posicao, SEEK_SET);
        int teste = fread(&novoCliente, sizeof(cliente), 1, listaClientes);
        if (teste != 0) {
          printf("A posição desejada já está preenchida em nossos cadastros.");
          break;
        } else {
          printf("Informe o nome do Cliente: \n");
          scanf("%154s", novoCliente.nome);

          novoCliente.id = contadorID;
          novoCliente.numeroConta = contadorID;
          novoCliente.saldo = 0;

          fseek(listaClientes, sizeof(cliente) * posicao, SEEK_SET);
          fwrite(&novoCliente, sizeof(cliente), 1, listaClientes);
        }
        break;
      };
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
