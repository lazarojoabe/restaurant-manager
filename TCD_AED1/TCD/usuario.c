#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "funcoesAux.h"

// cria a lista de restaurantes
ListaUsuario *criarUsuario()
{
    ListaUsuario *l = (ListaUsuario *)malloc(sizeof(ListaUsuario));
    l->inicio = NULL;

    return l;
}

// verifica se a lista está vazia
int listaVaziaUsuario(ListaUsuario *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;

    return 1;
}

// adiciona um usuario a lista
int inserirUsuario(ListaUsuario *l, Usuario item)
{
    if(l == NULL)
        return 1;

    NoUser *no = (NoUser *)malloc(sizeof(NoUser));
    no->valor = item;
    no->prox = l->inicio;
    l->inicio = no;

    return 0;
}

// verifica se o usuario esta na lista
int buscaUsuario(ListaUsuario *l, char *nomeLogin, char *senhaLogin)
{
    if (listaVaziaUsuario(l) != 1)
        return 2;

    NoUser *noLista = l->inicio;
    while (noLista != NULL)
    {   
        // usuario  existe pq a senha e o nome de login estão registrados
        if (strcmp((noLista->valor).nome, nomeLogin) == 0 && strcmp((noLista->valor).senha, senhaLogin) == 0)
        {
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1; // retorna 1 se ele não achar na lista o usuario com nome e senha na lista
}

int cadastroUsuarios(ListaUsuario *l, Usuario *retorno)
{
    if (listaVaziaUsuario(l) != 1)
        return 2;
    Usuario item;            // item com o tipo usuario para usar como variavel auxiliar para cadastro dos usuarios
    char confirmarSenha[50]; // variavel auxilar para guardar oo valor da senha digitada novamente pelo usuario

    // "formulário" para o usuário registrar o cliente
    printf("Nome: ");
    setbuf(stdin, NULL);
    fgets(item.nome, 20, stdin);
    printf("Senha: ");
    setbuf(stdin, NULL);
    fgets(item.senha, 20, stdin);
    printf("Confirme a senha: ");
    setbuf(stdin, NULL);
    fgets(confirmarSenha, 20, stdin);
    *retorno = item;
    // se o usuario digitar senhas diferentes não é possível fazer o cadastro
    if (strcmp(item.senha, confirmarSenha) != 0)
    {
        return 1;
    }

    inserirUsuario(l, item); // adiciona o usuário na lista
    return 0;
}

// mostra os usuarios
void mostrarUsuarios(ListaUsuario *l)
{
    if (l != NULL)
    {
        NoUser *noLista = l->inicio;
        while (noLista != NULL)
        {
            puts(noLista->valor.nome);
            puts(noLista->valor.senha);
            noLista = noLista->prox;
        }
    }
}
