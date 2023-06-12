#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "restaurante.h"
#include "usuario.h"
#include "dataBase.h"
#include "funcoesAux.h"
#include "pedido.h"
#include "aplicativo.h"

int main()
{
    ListaUsuario *listaUsuario = criarUsuario();
    ListaRestaurante *listaRestaurante = criarListaRestaurantes();

    db(listaUsuario, listaRestaurante);

    Restaurante retorno; // variável para guardar o retorno da função buscarRestaurante
    char texto[150];     // variável usada para enviar texto para a função printaTimer();
    int optEnt;          // opcao para identificar se o usuário logou ou criou uma nova conta
    int op1;             // opcao do menu para o usuario escolher
    int cadastroRetorno; // retorna 0 para sucesso no cadastro e 1 para erro
    int entidadeLogada;  // Vai nos dizer se é um cliente ou empresa que está logado. O menu é diferente para cada um
    char senhaLogin[20], nomeLogin[20];
    Usuario user; // armazena os dados do usuario cadastrado

    // Boas vindas ao aplicativo
    strcpy(texto, "C FOOD");
    printTitle(texto, strlen(texto));

    strcpy(texto, "Bem vindo(a) ao C FOOD!\n\nEntre na sua conta ou cadastre-se\npara aproveitar as maravilhas \nculinarias do nosso aplicavo!\n");
    printTimer(texto, strlen(texto));

    // ETAPA 1: LOGIN OU CADASTRO NO APLICATIVO
    do
    {
        printf("\n[1] Entrar\n[2] Cadastrar\n[3] Sobre o aplicativo\nR= ");
        scanf("%d", &optEnt);

        system("cls");
        switch (optEnt)
        {
        case 1:
            strcpy(texto, "ENTRAR");
            printTitle(texto, strlen(texto));
            // "formulário" para o usuário tentar fazer o login
            printf("Nome: ");
            setbuf(stdin, NULL);
            gets(nomeLogin);
            printf("Senha: ");
            setbuf(stdin, NULL);
            gets(senhaLogin);

            // se o buscaUsuario retornar 1 é pq o usuário não existe
            if (buscaUsuario(listaUsuario, nomeLogin, senhaLogin) == 1)
            {
                strcpy(texto, "\n\nUsuario ou senha incorretos! Tente novamente.\n\n");
                printTimer(texto, strlen(texto));
            }
            else
            {
                strcpy(texto, "\n\nLogin efetuado com sucesso!\n\n");
                printTimer(texto, strlen(texto));
                entidadeLogada = 1;
                op1 = 1;
            }
            break;
        case 2:
            strcpy(texto, "CADASTRAR");
            printTitle(texto, strlen(texto));
            printf("Como voce deseja se cadastrar?\n\n[1] Cliente\n[2] Restaurante\nR= ");
            scanf("%d", &op1);

            system("cls");

            if (op1 == 1)
            {
                strcpy(texto, "CADASTRAR USUARIO:");
                printTitle(texto, strlen(texto));

                cadastroRetorno = cadastroUsuarios(listaUsuario, &user);
                if (cadastroRetorno == 1)
                    printf("\nAs senhas sao diferentes, nao foi possivel cadastrar o usuario!\n");
                if (cadastroRetorno == 0)
                    printf("\nUsuario cadastrado com sucesso!\n");
                entidadeLogada = 1; // Cliente logado
            }
            else if (op1 == 2)
            {
                strcpy(texto, "CADASTRAR RESTAURANTE:");
                printTitle(texto, strlen(texto));

                cadastroRestaurantes(listaRestaurante);
                entidadeLogada = 2; // Empresa logada
            }
            break;
        case 3:
            strcpy(texto, "SOBRE O APLICATIVO");
            printTitle(texto, strlen(texto));

            printf("Ola!\n\nO C FOOD e um aplicativo de restaurante, onde voce \npode pedir comidas que chegarao fresquinhas na sua casa!\n\n");
            printf("Trabalho de Conclusao de Disciplina - AED1\nProfessor: Jose Gustavo de Souza Paiva\n\nAlunos:\n   - Fabio Signorini de Freitas\n   - Lazaro Joabe Nunes Soares\n   - Marcel Fernando Lobo de Feo\n   - Pedro de Souza Ferreira\n\n");
            printf("@Copyright 2023 - Todos os direitos reservados aos integrantes.\n\n");
            printf("[1] Voltar\nR= ");
            scanf("%d", &op1);

            op1 = 3;

            system("cls");

            strcpy(texto, "C FOOD");
            printTitle(texto, strlen(texto));
            break;
        default:
            break;
        }
        if (optEnt < 1 || optEnt > 3)
        {
            printf("\nOpcao invalida! Vamos tentar novamente.\n");
        }
    } while (op1 != 1 && op1 != 2);

    system("cls");
    // ETAPA 2: APLICATIVO E SUAS FUNCIONALIDADES
    do
    {
        strcpy(texto, "C FOOD");
        printTitle(texto, strlen(texto));
        if (entidadeLogada == 1) // Se for um cliente logado
        {
            if (optEnt == 1) // Se o usuário já era cliente
            {
                strcpy(texto, "Seja bem vindo de volta, ");
                printTimer(texto, strlen(texto));
                printTimer(nomeLogin, strlen(nomeLogin));
                printf("!\n");
            }
            else if (optEnt == 2) // Se o usuário é um novo cliente
            {
                strcpy(texto, "Seja bem vindo ao C FOOD, ");
                printTimer(texto, strlen(texto));
                printTimer(user.nome, strlen(user.nome));
            }

            buscarRestauranteAplicativo(listaRestaurante);

            strcpy(texto, "C FOOD");
            printTitle(texto, strlen(texto));
            
            printf("\nSelecione a opcao: \n[1] Menu Principal\n[2] Sair\nR= ");
            scanf("%d", &op1);

            optEnt = 0; // Zerando a optEnt, que diz se o usuário é um novo cliente ou não, não será exibida a mensagem de boas vindas. Isso, pois como o usuário escolheu voltar ao menu principal, ela não faz sentido.
        }
        else if (entidadeLogada == 2) // Se é uma empresa logada
        {
            strcpy(texto, "Parabens! O seu cadastro foi finalizado com sucesso.\nAgora os clientes podem fazer pedidos para o seu restaurante!\n");
            printTimer(texto, strlen(texto));

            do
            {
                printf("\nSelecione a opcao: \n[1] Menu Principal\n[2] Sair\nR= ");
                scanf("%d", &op1);

                if (op1 == 1)
                {
                    do
                    {
                        system("cls");
                        strcpy(texto, "MENU PRINCIPAL");
                        printTitle(texto, strlen(texto));
                        printf("[1] Informacoes do meu restaurante\n[2] Buscar restaurantes\n[3] Sair\nR= ");
                        scanf("%d", &op1);
                        system("cls");
                        if (op1 == 1) // Exibir informações do restaurante do usuário
                        {
                            mostrarMeuRestaurante(listaRestaurante);
                            printf("\nSelecione a opcao: \n[1] Voltar\nR= ");
                            scanf("%d", &op1);
                        }
                        else if (op1 == 2) // Buscar restaurantes
                        {
                            buscarRestauranteAplicativo(listaRestaurante);
                        }
                    } while (op1 == 1);
                }
            } while (op1 == 1);
        }
    } while (op1 == 1);

    // Ao sair do programa, será exibida a seguinte mensagem.
    strcpy(texto, "Obrigado por escolher a C FOOD, ate breve!");
    printTimer(texto, strlen(texto));
    return 0;
}