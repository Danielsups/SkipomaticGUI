# SkipomaticGUI

Repositorio para versionamento de codigo em **C++** da interface visual do aplicativo **Skipo**, o mesmo trata-se de uma especie de *gamificação* da escolha de filmes para uma watch party.

## Regras Iniciais:

1.	*Deverá ser selecionada uma lista de Lettexboxd, para dar início aos trabalhos, a lista será escolhida de forma autocrática pelo administrador geral, que poderá decidir a melhor maneira a ser definida a lista do dia;*
2.	*Cada participante terá 3 skip’s, desde que esteja de acordo a assistir ao filme, independente do resultado final o agradar ou não;*
3.	*A cada rodada, será apresentado um filme, sorteado aleatoriamente pelo administrador geral. Todos os participantes, poderão aceitar ver o filme, ou gastar um dos seus skip’s para que um novo filme seja sorteado;*
4.	*Múltiplos membros poderão dividir a responsabilidade de skipar um filme, sendo descontado de cada um, 0,5 skips da Poll de cada um;*
5.	*Haverá também o movimento político, MSS (Movimento dos sem skip). Participarão do MSS todos aqueles que atingirem a quantidade de 0 skip’s;*
6.	*Os membros do MSS poderão expropriar um skip da pessoa com mais skip’s atualmente, e pular algum filme. Desde que, TODOS os membros MSS concordem;*
7.	*O presidente do MSS será o primeiro a se juntar ao movimento;*
8.	*Caso haja várias pessoas com o mesmo número de skip’s, o presidente do MSS deverá decidir quem será expropriado;*
9.	*O skip é inviolável, após um filme ser skipado, ele jamais deverá ser retomado naquela sessão, ainda que todos os membros sejam favoráveis a isso, ainda que ele retorne no sorteio, deverá ser desconsiderado automaticamente;*
10.	*O filme poderá ser pulado automaticamente caso algum dos participantes já tenha jurado ver o filme com algum terceiro que não esteja presente, ou caso tenha sido assistido recentemente por um ou mais participantes;*
11.	*Em caso de descumprimento do inciso II, ou seja, participar do processo democrático de escolha e fugir para Itália para não ver o filme, o infrator será submetido a uma punição;*
12.	*Independente da data de lançamento do filme, ele não será skipado automaticamente;*

## Paralelo regras funcionalidades

| Regras         | Funcionalidades                                                       |
| -------------- |:---------------------------------------------------------------------:|
| Inciso 1       | **"Seleção da Lista"**                                                |
| Inciso 2       | **"Configuração dos participantes e seus skips (padrão de 3)"**       |
| Inciso 3       | **"Sorteio do filme e opção de skip"**                                |
| Inciso 4       | **"Divisão de Skips"**                                                |
| Inciso 5       | **"Adição de membros do MSS"**                                        |
| Inciso 6       | **"Aproveitamento de skip sem uso pelo MSS"**                         |
| Inciso 7       | **"Configuração do presidente do MSS"**                               |
| Inciso 8       | **"Decisão do expropriado pelo presidente do MSS"**                   |
| Inciso 9       | **"Garantia de que um filme não sera sorteado mais de uma vez"**      |
| Inciso 10      | **"Skip automatico (Inciso 10)"**                                     |
| Inciso 11      | **"Punição por não ver o filme (Extrapola a ideia da ferramenta)"**   |
| Inciso 12      | **"O filme é valido independente de sua idade (Sem ação Necessaria)"**|

### Seleção da lista ❌

Atualmente o programa ainda não suporta o recebimento do link de uma lista, é usado o PythonScraper para extração de um txt contendo as informações necessarias da lista para então funcionamento do programa.

### Configuração dos participantes e seus skips (padrão de 3) ✔️

* É possivel configurar a quantidade de participantes e seus skips na tela inicial
* Existem validadores para garantir que o numero de skips e jogadores nunca seja 0
* O contador de skips é settado por padrão em 3

### Sorteio do filme e opção de skip ✔️

* Existe uma queue chamada listaFilmes que em cada um de seus elementos guarda todas as informações de um filme 
* A classe filmeInfos extrai as informações de cada elemento da listaFilmes e os mostra na telaSkip
* É dado ao usuario a opção de skipar o filme e selecionar o jogador que efetuou o skip

### Divisão de Skips ❌

Atualmente o programa ainda não oferece suporte para a atividade de divisão de skips.

### MSS ❌

##### Adição de membros do MSS

Atualmente o programa ainda não oferece suporte para a adição de membros ao MSS.

##### Aproveitamento de skip sem uso pelo MSS

Atualmente o programa ainda não oferece suporte automatico para o aproveitamento de skips de terceiros.

##### Configuração do presidente do MSS

Atualmente o programa ainda não oferece suporte para configuração dos membros do MSS.

##### Decisão do expropriado pelo presidente do MSS

Atualmente o programa ainda não oferece suporte automatico para escolha do membro a ter seu skip apropriado pelo presidente do MSS.

### Garantia de que um filme não sera sorteado mais de uma vez ✔️

* Após o skip de cada filme independente de sua razão o mesmo é retirado da lista
* Sendo retirado da lista, se torna impossivel seu retorno para a telaSkip

### Skip automatico (Inciso 10) ✔️

* Já existe uma opção de Inciso 10 dentre as escolhas na tela de skip
* Esta skipa o filme sem retirada de skips ou necessidade de justificativa
* A mesma deve ser utilizada para skip de filmes que já foram vistos, ou prometidos a vista com outro alguém
* Também sendo possivel o uso da opção para skip por motivos extraordinarios

## Adições a serem trabalhadas

- [X] Adição da duração do filme a tela de skip
- [ ] Analise para reorganização do codigo
- [ ] Retrabalho do design das telas
- [ ] Botão de retorno da tela jogadores para a tela inicial
- [ ] Botão de retorno da tela filme a ser assistido para a tela de skip
- [ ] Adição de vitrine que mostra quais seriam os proximos 4 filmes a aparecerem no skip
- [ ] Adição de hyperlink do filme ao clicar no poster dele na tela de skip, ou filme a ser assistido