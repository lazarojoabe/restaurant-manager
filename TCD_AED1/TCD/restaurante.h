#ifndef CF9D2E52_512F_4A41_BB5E_50101AB6AEE8
#define CF9D2E52_512F_4A41_BB5E_50101AB6AEE8

// estrutura pratos dos restaurantes
typedef struct pratos
{
    char nome[50];
    float preco;
} Pratos;

// estrutura restaurante
typedef struct restaurante
{
    char nome[50];
    int categoria; 
    // Categorias de restaurantes: 
    //1 - Lanches
    //2 - Pizza
    //3 - Salgados
    //4 - Self-Service
    //5 - Sobremesas
    //6 - Vegetariano
    int qtdPratos;
    Pratos pratos[10];
} Restaurante;

// estrutura para o nó da lista encadeada
typedef struct noRestaurante
{
    Restaurante valor;
    struct noRestaurante *prox;
} NoRestaurante;

// estrutura da lista
typedef struct listaRestaurante
{
    NoRestaurante *inicio;
} ListaRestaurante;

typedef struct noPedido NoPedido;
// cria a lista de restaurantes
ListaRestaurante *criarListaRestaurantes();
// verifica se a lista está vazia
int listaVaziaRestaurante(ListaRestaurante *l);
// adiciona um restaurante a lista
int inserirRestaurante(ListaRestaurante *l, Restaurante item);
// cadastra os restaurantes
int cadastroRestaurantes(ListaRestaurante *l);
// buscar o restaurante que o usuário digitou
int buscarRestauranteNome(ListaRestaurante *l, char *nome);
// buscar restaurantes procurados por tipo
int buscarRestauranteTipo(ListaRestaurante *l, int tipoProcurado);
//exibe empresa do usuário
int mostrarMeuRestaurante(ListaRestaurante *l);
/*Mostra menu do restaurante. Tem duas opções:
    - mostrarMenu(restaurante, listaRestaurantes) : mostra as opções Fazer Pedido e Voltar
    - mostrarMenu(restaurante, NULL) : mostra apenas o menu, pois ele entende que se a listaRestaurantes não é necessária, é porque o pedido está sendo/foi feito.*/
int mostrarMenu(Restaurante *rest, ListaRestaurante *l);

#endif /* CF9D2E52_512F_4A41_BB5E_50101AB6AEE8 */
