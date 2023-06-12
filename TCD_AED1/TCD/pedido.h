#ifndef PEDIDO_H
#define PEDIDO_H

#include "restaurante.h"

typedef struct pedido Pedido;

typedef struct endereco Endereco;

typedef struct filaPedidos FilaPedidos;

FilaPedidos *criarFilaDePedidos();
int fazerPedido(Restaurante *rest);
int prepararPedidos(FilaPedidos *f);
int verificaPendenciaPratos(ListaRestaurante *l, Restaurante r);
void limparFilaDePedidos(FilaPedidos *f);
int filaDePedidosVazia(FilaPedidos *f);
int adcionarPedidoNaFila(FilaPedidos *f, Pedido p);
int filaDePedidosCheia(FilaPedidos *f);
int removerPedido(FilaPedidos *f, Pedido *ret);
int entregarPedido(Pedido *p);
#endif