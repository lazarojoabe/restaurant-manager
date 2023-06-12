#include "restaurante.h"
#include "pedido.h"
#include "funcoesAux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido
{
  int qnt,
      item[10],
      itemQnt[10],
      entregue[10]; // 0 se foi entregue, 1 se nao foi entregue
  float total;
  Pratos prato;
} Pedido;

typedef struct endereco
{
  char rua[30], bairro[30];
  int numero;
}Endereco;

typedef struct filaPedidos
{
  int qtd, inicio, fim;
  Pedido valores[100];
} FilaPedidos;

FilaPedidos *criarFilaDePedidos()
{
  FilaPedidos *f = (FilaPedidos *)malloc(sizeof(FilaPedidos));
  f->fim = 0;
  f->inicio = 0;
  f->qtd = 0;
  return f;
}
void limparFilaDePedidos(FilaPedidos *f)
{
  if (f != NULL && filaDePedidosVazia(f) != 0)
  {
    free(f);
    f = NULL;
  }
}
int filaDePedidosVazia(FilaPedidos *f)
{
  if (f == NULL)
    return -1;
  if (f->qtd == 0)
    return 0;
  else
    return 1;
}

int adcionarPedidoNaFila(FilaPedidos *f, Pedido p)
{
  if (f == NULL)
    return 1;
  if (filaDePedidosCheia(f) == 0)
    return 2;
  f->valores[f->fim] = p;
  f->fim = (f->fim + 1) % 100;
  f->qtd++;
  return 0;
}

int filaDePedidosCheia(FilaPedidos *f)
{
  if (f == NULL)
    return -1;
  if (f->qtd == 100)
    return 0;
  else
    return 1;
}
int fazerPedido(Restaurante *rest)
{
  int i = 0, optPedido = 0, optPagamento = 0, optEntrega;
  float troco;
  char x[50], texto[150]; // vai simular recebimento de informações do cartão
  FilaPedidos *f = criarFilaDePedidos();
  Pedido p;
  p.total = 0;
  Endereco ep;

  // Limpar tela
  while (i < 10 && optPedido != 2)
  {
    system("cls");
    mostrarMenu(rest, NULL);

    printf("Adicionar item no carrinho: \nR= ");
    scanf("%d", &p.item[i]);

    printf("Quantas unidades de %s?\nR= ", rest->pratos[p.item[i]].nome);
    scanf("%d", &p.itemQnt[i]);

    adcionarPedidoNaFila(f, p);

    p.total += (float)(rest->pratos[p.item[i]].preco) * (p.itemQnt[i]);
    
    p.entregue[i] = 1;
    printf("\nValor total do pedido: R$%.2f\n\n", p.total);
    p.qnt++;
    i++;
    
    printf("Deseja pedir outro item?\n[1] SIM\n[2] NAO\nR= ");
    scanf("%d", &optPedido);
  }
  
  prepararPedidos(f);
  
  printaLinha();
  strcpy(texto, "\nSeu pedido foi realizado com sucesso! Agora, vamos cadastrar o seu endereco.\n");
  printTimer(texto, strlen(texto));

  system("cls");
  strcpy(texto, "CADASTRO");
  printTitle(texto, strlen(texto));

  printf("Rua: ");
  setbuf(stdin, NULL);
  fgets(ep.rua, 30, stdin);
  setbuf(stdin, NULL);
  printf("Bairro: ");
  fgets(ep.bairro, 30, stdin);
  setbuf(stdin, NULL);
  printf("Numero: ");
  scanf("%d", &ep.numero);

  strcpy(texto, "\nUltima etapa!\nEscolha agora sua forma de pagamento:\n");
  printTimer(texto, strlen(texto));
  printf("[1] Dinheiro\n[2] Cartao\nR= ");
  scanf("%d", &optPagamento);
  switch (optPagamento)
  {
  case 1:
    do
    {
      printf("\nO troco sera para quanto?\nR= ");
      scanf("%f", &troco);
      if (troco < p.total)
        printf("Valor invalido! O valor nao pode ser menor que o Total do Pedido. Vamos tentar novamente.\n");
    } while (troco < p.total);
    break;
  case 2:
    printf("Forma de pagamento: \n[1] Credito\n[2] Debito\n[3] Pagar na entrega\nR= ");
    setbuf(stdin, NULL);
    scanf("%d", &optPagamento);
    if (optPagamento == 1 || optPagamento == 2)
    {
      setbuf(stdin, NULL);
      printf("Numero do cartao: ");
      gets(x);
      setbuf(stdin, NULL);
      printf("Validade: ");
      gets(x);
      setbuf(stdin, NULL);
      printf("CVV: ");
      gets(x);
      setbuf(stdin, NULL);
      printf("Nome do titular: ");
      gets(x);
    }
  default:
    break;
  }
  system("cls");
  printaLinha();
  printf("\nPEDIDO FINALIZADO!\n\nMuito obrigado por realizar o pedido conosco, a %s agradece!\n\nO seu pedido sera entregue dentro de 30 minutos.\n", rest->nome);
  printaLinha();
  
  printf("O seu pedido foi entregue?\n[1] Sim\n[2] Nao\nR= ");
  scanf("%d", &optEntrega);

  if (optEntrega == 1)
  {
    strcpy(texto, "\nAproveite a sua refeicao e volte sempre!\n");
    printTimer(texto, strlen(texto));
    return 0;
  }
  else if (optEntrega == 2)
  {
    printf("\nOcorreu um erro... De acordo com o nosso sistema, o seu pedido ja foi entregue.\nEm caso de duvidas, entre em contato com a nossa central: (34) 99999-9999\n");
  }
  printaLinha();

  return 0;
}

int prepararPedidos(FilaPedidos *f)
{
  if (filaDePedidosVazia(f) == 0)
    return 1;
  int i = 0;
  Pedido p;
  while(filaDePedidosVazia(f) != 0){
    removerPedido(f, &p);
    entregarPedido(&p);
  }
  return 0;
}
int entregarPedido(Pedido *p)
{
  int i = 0;
  while (i < 10)
  {
    p->entregue[i] = 0;
    i++;
    p->itemQnt[i] = 0;
  }
 
  return 0;
}
int removerPedido(FilaPedidos *f, Pedido *ret)
{
  if (f == NULL)
    return 1;
  if (filaDePedidosVazia(f) == 0) 
    return 2;
  *ret = f->valores[f->inicio];
  f->qtd--;
  f->inicio = (f->inicio + 1) % 50;
  return 0;
}

