#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "restaurante.h"
#include "funcoesAux.h"
#include "pedido.h"

typedef struct noPedido
{
    Pratos *valor;
} NoPedido;

typedef struct filaPedidos
{
    NoPedido *inicio;
    NoPedido *prox;
} FilaDePedidos;

// cria a lista de restaurantes
ListaRestaurante *criarListaRestaurantes()
{
    ListaRestaurante *l = (ListaRestaurante *)malloc(sizeof(ListaRestaurante));
    l->inicio = NULL;

    return l;
}

// verifica se a lista está vazia
int listaVaziaRestaurante(ListaRestaurante *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    return 1;
}

// Insere um restaurante a lista
int inserirRestaurante(ListaRestaurante *l, Restaurante item)
{
    if (l == NULL)
        return 1;
    NoRestaurante *no = (NoRestaurante *)malloc(sizeof(NoRestaurante));
    no->valor = item;
    no->prox = l->inicio;
    l->inicio = no;

    return 0;
}

// Cadastra um restaurante na listaRestaurantes
int cadastroRestaurantes(ListaRestaurante *l)
{
    char texto[150];
    if (listaVaziaRestaurante(l) != 1)
        return 2;
    Restaurante item; // item com o tipo restaurante para usar como variavel auxiliar para cadastro dos restaurantes
    int quant;        // quantidade de pratos que o usuario quer cadastrar

    // "formulário" para o usuário registrar o restaurante
    printf("Nome do restaurante: ");
    setbuf(stdin, NULL);
    gets(item.nome);
    printf("\nQual a categoria do seu restaurante:\n");
    printf("[1] Lanches\n[2] Pizza\n[3] Salgados\n[4] Self-Service\n[5] Sobremesas\n[6] Vegetariano\nR= ");
    scanf("%d", &item.categoria);
    printf("\nQuantos pratos voce deseja cadastrar?\nR= ");
    scanf("%d", &quant);
    item.qtdPratos = quant;
    
    // laço de repetição para cadastrar o numero de pratos que o usuario pediu
    for (int i = 0; i < quant; i++)
    {
        system("cls");
        // "formulário" para o usuário registrar os pratos do restaurante
        strcpy(texto, "CADASTRO DE PRATOS");
        printTitle(texto, strlen(texto));
        printf("\nPrato %d\n", i + 1);
        printf("Nome: ");
        setbuf(stdin, NULL);
        gets(item.pratos[i].nome);
        printf("Preco(R$): ");
        scanf("%f", &item.pratos[i].preco);
    }
    inserirRestaurante(l, item); // adiciona restaurante na lista
    return 0;
}

// buscar o restaurante pelo nome que o usuário digitou
int buscarRestauranteNome(ListaRestaurante *l, char *nome)
{
    if (listaVaziaRestaurante(l) != 1)
        return 2;

    char texto[50];
    int opt, i = 0;
    NoRestaurante *aux = l->inicio;

    strcpy(texto, "\nSua busca gerou os seguintes resultados: \n");
    printTimer(texto, strlen(texto));

    while (aux != NULL)
    {
        if (comparaStrings(nome, aux->valor.nome) == 0)
        {
            printf("[%d] %s\n", i, aux->valor.nome);
            i++;
        }
        aux = aux->prox;
    }
    if (i == 0)
    {
        printf("O restaurante %s nao foi encontrado.\n", nome);
        return -1;
    }
    else
        return 0;
}

// mostrar restaurantes procurados por TIPO
int buscarRestauranteTipo(ListaRestaurante *l, int tipoProcurado)
{
    if (listaVaziaRestaurante(l) != 1)
        return 2;

    int i = 0, opt;
    char texto[50];

    NoRestaurante *temp = l->inicio;
    NoRestaurante *aux = l->inicio;

    strcpy(texto, "\nSua busca gerou os seguintes resultados: \n");
    printTimer(texto, strlen(texto));

    while (temp != NULL)
    {
        if (tipoProcurado == temp->valor.categoria)
        {
            printf("[%d] %s\n", i, temp->valor.nome);
            i++;
        }
        temp = temp->prox;
    }
    return 0;
}

// Exibe menu do restaurante
int mostrarMenu(Restaurante *rest, ListaRestaurante *l)
{
    int i = 0, calc = 0, opt;
    printTitle(rest->nome, strlen(rest->nome));
    printf("Categoria: ");
    printCategoria(rest->categoria);
    printf("\n            Menu:            \n");
    printf("Prato                   Preco\n");
    while (i < rest->qtdPratos)
    {
        printf("[%d] %s", i, rest->pratos[i].nome);
        calc = 20 - strlen(rest->pratos[i].nome);
        for (int i = 0; i < calc; i++)
        {
            printf(" ");
        }
        printf("R$%.2f\n", rest->pratos[i].preco);
        i++;
    }
    printaLinha();
    if (l != NULL) // Se eu receber uma lista, é porque ainda não decidi fazer o pedido
    {
        do
        {
            printf("\nOPCOES:\n[1] Fazer Pedido\n[2] Voltar\nR= ");
            scanf("%d", &opt);

            switch (opt)
            {
            case 1:
                // Chamar função de fazer pedido
                fazerPedido(rest);
                break;
            case 2:
                buscarRestauranteTipo(l, rest->categoria);
                break;
            default:
                printf("Opcao invalida. Tente novamente!\n");
                break;
            }
        } while (opt != 1 && opt != 2);
    }
    return 0;
}

// Exibe o restaurante criado pelo usuário. Nesse caso, o restaurante será sempre o primeiro da lista
int mostrarMeuRestaurante(ListaRestaurante *l)
{
    if (listaVaziaRestaurante(l) != 1)
        return 2;

    int i = 0, calc = 0;
    NoRestaurante *rest = l->inicio;

    printTitle(rest->valor.nome, strlen(rest->valor.nome));
    printf("Categoria: ");
    printCategoria(rest->valor.categoria);
    printf("\n            Menu:            \n");
    printf("Prato                   Preco\n");
    while (i < rest->valor.qtdPratos)
    {
        printf("[%d] %s", i, rest->valor.pratos[i].nome);
        calc = 20 - strlen(rest->valor.pratos[i].nome);
        for (int i = 0; i < calc; i++)
        {
            printf(" ");
        }
        printf("R$%.2f\n", rest->valor.pratos[i].preco);
        i++;
    }
    printaLinha();
    return 0;
}
