#ifndef F85D3FCC_5334_484C_A645_6EE1A8E61151
#define F85D3FCC_5334_484C_A645_6EE1A8E61151

// estrutura usuario
typedef struct usuario
{
    char nome[50];
    char senha[50];
} Usuario;

// estrutura para o nó da lista encadeada
typedef struct noUser
{
    Usuario valor;
    struct noUser *prox;
} NoUser;

typedef struct listaUsuario
{
    NoUser *inicio;
} ListaUsuario;

// cria a lista de usuarios
ListaUsuario *criarUsuario();
// verifica se a lista está vazia
int listaVaziaUser(ListaUsuario *l);
// adiciona um restaurante a lista
int inserirUsuario(ListaUsuario *l, Usuario item);
// verifica se o usuario esta na lista
int buscaUsuario(ListaUsuario *l, char *nomeLogin, char *senhaLogin);
// mostra a lista de usuarios
void mostrarUsuarios(ListaUsuario *l);
// cadastra os usuários
int cadastroUsuarios(ListaUsuario *l, Usuario *retorno);



#endif /* F85D3FCC_5334_484C_A645_6EE1A8E61151 */
