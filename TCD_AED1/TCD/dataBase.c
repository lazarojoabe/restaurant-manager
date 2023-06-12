#include "dataBase.h"

int db(ListaUsuario *lu, ListaRestaurante *lr)
{
  Usuario f, l, m, p;
  ListaUsuario *lub;
  lub = criarUsuario();

  strcpy(f.nome, "Fabio");
  strcpy(f.senha, "12345");
  strcpy(l.nome, "Lazaro");
  strcpy(l.senha, "12345");
  strcpy(m.nome, "Marcel");
  strcpy(m.senha, "12345");
  strcpy(p.nome, "Pedro");
  strcpy(p.senha, "12345");

  inserirUsuario(lub, f);
  inserirUsuario(lub, l);
  inserirUsuario(lub, m);
  inserirUsuario(lub, p);

  Restaurante a, b, c, d, e, g, h;
  ListaRestaurante *lrb;
  lrb = criarListaRestaurantes();

  strcpy(a.nome, "McDonalds");
  a.categoria = 1;
  a.qtdPratos = 5;
  strcpy(a.pratos[0].nome, "Big Mac");
  a.pratos[0].preco = 15.99;
  strcpy(a.pratos[1].nome, "McChicken");
  a.pratos[1].preco = 13.99;
  strcpy(a.pratos[2].nome, "Big Tasty");
  a.pratos[2].preco = 39.99;
  strcpy(a.pratos[3].nome, "Melt Crispy");
  a.pratos[3].preco = 34.99;
  strcpy(a.pratos[4].nome, "McMelt");
  a.pratos[4].preco = 24.99;

  strcpy(b.nome, "Dominos Pizza");
  b.categoria = 2;
  b.qtdPratos = 5;
  strcpy(b.pratos[0].nome, "3 Queijos");
  b.pratos[0].preco = 69.99;
  strcpy(b.pratos[1].nome, "Calabresa");
  b.pratos[1].preco = 74.99;
  strcpy(b.pratos[2].nome, "Corn e Bacon");
  b.pratos[2].preco = 74.99;
  strcpy(b.pratos[3].nome, "Catuperony");
  b.pratos[3].preco = 85.99;
  strcpy(b.pratos[4].nome, "Portuguesa");
  b.pratos[4].preco = 87.99;

  strcpy(c.nome, "Casa Do Salgado");
  c.categoria = 3;
  c.qtdPratos = 5;
  strcpy(c.pratos[0].nome, "20 Unidades");
  c.pratos[0].preco = 25.99;
  strcpy(c.pratos[1].nome, "50 Unidades");
  c.pratos[1].preco = 42.99;
  strcpy(c.pratos[2].nome, "100 Unidades");
  c.pratos[2].preco = 79.99;
  strcpy(c.pratos[3].nome, "200 Unidades");
  c.pratos[3].preco = 149.99;
  strcpy(c.pratos[4].nome, "500 Unidades");
  c.pratos[4].preco = 299.99;

  strcpy(d.nome, "Prato Mineiro");
  d.categoria = 4;
  d.qtdPratos = 5;
  strcpy(d.pratos[0].nome, "Almondega 500g");
  d.pratos[0].preco = 24.99;
  strcpy(d.pratos[1].nome, "Bife de Vaca 500g");
  d.pratos[1].preco = 29.99;
  strcpy(d.pratos[2].nome, "File de Frango 500g");
  d.pratos[2].preco = 29.99;
  strcpy(d.pratos[3].nome, "Feijoada");
  d.pratos[3].preco = 29.99;
  strcpy(d.pratos[4].nome, "Carne de Porco 500g");
  d.pratos[4].preco = 29.99;

  strcpy(e.nome, "Johnny Joy");
  e.categoria = 5;
  e.qtdPratos = 5;
  strcpy(e.pratos[0].nome, "Brigadeiro");
  e.pratos[0].preco = 19.99;
  strcpy(e.pratos[1].nome, "Bis");
  e.pratos[1].preco = 19.99;
  strcpy(e.pratos[2].nome, "Ninho com Morango");
  e.pratos[2].preco = 19.99;
  strcpy(e.pratos[3].nome, "Cereja Amarena");
  e.pratos[3].preco = 19.99;
  strcpy(e.pratos[4].nome, "Cookies and Cream");
  e.pratos[4].preco = 19.99;

  strcpy(g.nome, "VeggieFood");
  g.categoria = 6;
  g.qtdPratos = 5;
  strcpy(g.pratos[0].nome, "Parmegiana Burguer");
  g.pratos[0].preco = 27.99;
  strcpy(g.pratos[1].nome, "Lentilha Burguer");
  g.pratos[1].preco = 35.99;
  strcpy(g.pratos[2].nome, "Cogula Burguer");
  g.pratos[2].preco = 37.99;
  strcpy(g.pratos[3].nome, "Soja Burguer");
  g.pratos[3].preco = 37.99;
  strcpy(g.pratos[4].nome, "Feijuca Burguer");
  g.pratos[4].preco = 39.99;
  
  strcpy(h.nome, "Vegetariano Comida");
  h.categoria = 6;
  h.qtdPratos = 5;
  strcpy(h.pratos[0].nome, "Parmegiana Burguer");
  h.pratos[0].preco = 27.99;
  strcpy(h.pratos[1].nome, "Lentilha Burguer");
  h.pratos[1].preco = 35.99;
  strcpy(h.pratos[2].nome, "Cogula Burguer");
  h.pratos[2].preco = 37.99;
  strcpy(h.pratos[3].nome, "Soja Burguer");
  h.pratos[3].preco = 37.99;
  strcpy(h.pratos[4].nome, "Feijuca Burguer");
  h.pratos[4].preco = 39.99;


  inserirRestaurante(lrb, a);
  inserirRestaurante(lrb, b);
  inserirRestaurante(lrb, c);
  inserirRestaurante(lrb, d);
  inserirRestaurante(lrb, e);
  inserirRestaurante(lrb, g);
  inserirRestaurante(lrb, h);

  *lr = *lrb;
  *lu = *lub;

  return 0;
}
