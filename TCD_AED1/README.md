# Projeto do Aplicativo de Restaurante - AED1

<!--ts-->
   * [Sobre](#sobre)
   * [Datas](#datas)
   * [Entrega](#entrega)
   * [Funcionalidades](#funcionalidades)
   * [Como Rodar?](#rodar)
   * [Sobre os commits](#commits)
<!--te-->

<div id="sobre">
         
## 📚 - Sobre o projeto

O programa deve realizar o cadastrodo de restaurantes participantes, bem como dos pratos oferecidos por cada um deles. Cada restaurantepossui uma categoria, referente ao tipo de culinária que oferece. Os clientes tambémsão cadastro dos previamente, e podem acessar o programa (mediante usuário/senha) para fazer seus pedidos. Os usuários podem pesquisar por tipo de culinária, e o sistema mostra todos os restaurantes cadastrados como resultado. Ao selecionar um restaurante, o usuário seleciona o prato e a quantidade, e o sistema mostra o valor final para pagamento. O usuário deverá entrar no sistema e informar querecebeu o pedido, alterando o status do mesmo. É desejável que o grupo implemente outras funcionalidades no programa, além das citadas, de forma a simular mais fielmente um sistema comercial dessa natureza

</div>
         
<div id="datas">
               
## 🗓️ - Datas

- Entrega: 12/06/2023, ATÉ AS 12:00
- Apresentações: : 12/06/2023, 14/06/2023 e 19/06/2023
               
</div>

<div id="entrega">

## ⚠️ - Sobre a entrega

- A entrega dos trabalhos será feita via plataforma Microsoft Teams, na data especificadanaSeção 6;
- O professor não se responsabiliza por falhas na submissão, falhas no MICROSOFTTEAMS, eQUALQUER OUTRO PROBLEMA RELACIONADO. É de responsabilidade do alunonãodeixar
a entrega para última hora, e com isso se prevenir de tais problemas. Não serãoaceitas,posteriormente, nenhuma justificativa, e qualquer e-mail de tentativa de justificativaporparte dos alunos será descartado. c. O sistema pronto deverá ser transmitido em um arquivo compactado (.zip) contendoTRÊSPASTAS:
  - PASTA 01: códigos-fonte que compõem o software, e/ou estrutura completa geradapelaIDE utilizada;
  - PASTA 02: código-fonte compilado (arquivo .exe), de forma que seja possível executarosoftware sem necessidade de compilação. Este arquivo deve estar SEPARADOdapastacitada no item i;
  - PASTA 03: Documentação, contendo:
- Arquivo texto contendo os nomes dos integrantes do grupo;
- Qualquer biblioteca ou pacote utilizado (CASO SEJA UTILIZADO), comdocumentação de como instalá-la, configurá-la e utilizá-la. Alémdisso, aoutilizaruma biblioteca, o grupo deverá explicar quais elementos dela são utilizadosnosistema, e como são utilizados para o funcionamento do mesmo;

</div>   
      
<div id="funcionalidades">                 
                 
## 💻 - Funcionalidades Implementadas

- [X] Interface Básica
- [X] Cadastro de Restaurantes
- [X] Cadastro de Usuários
- [X] Tela de Login 
- [X] Fazer o sistema de pesquisar restaurantes

## 🛠️ - Funcionalidades a Serem Implementadas
- [ ] Tratamentos de erros
- [ ] Lógica para informar se o pedido foi entregue
- [ ] Otimizar o código

</div>                         
                         
<div id="rodar">
               
## 🚀 - Como rodar o código

Compilar o restaurante.c
```bash
gcc -c restaurante.c
```

Compilar o usuario.c
```bash
gcc -c usuario.c
```

Compilar a main.c
```bash
gcc restaurante.o usuario.o main.c -o main.exe
```
Executar o main
```bash
./main
```

</div>               

<div id="commits">

## 🖊️ - Padrão de Commits

Aqui tá uma sugestão de como escrever os commits do trablaho, pra não ficar tão bagunçado igual do truco kkkk

- [UPDATE] Breve descrição do commit (Para quando vc adiconar algo novo no código)
- [FIXING] Breve descrição do commit (Para arrumar algum bug no código)
- [DELETE] Breve descrição do commit (Para deletar alguma parte do código)
                  
</div>                

## 🤓 - Participantes
- Marcel Féo
- Lázaro Joabe
- Pedro Souza
- Fábio Signorini
