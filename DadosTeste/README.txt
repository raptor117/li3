Estrutura dos ficheiros com dados para teste.


1. localidades.txt
Este ficheiro contém a informação das várias localidades existentes e das ligações directas a outras localidades.
O ficheiro tem linhas com o formato:
id_local:Nome:lista de ligacoes a partir de id_local (9 ligacoes)



Ex: 

2:Carnide do Meio:9743:16905:13305:12504:2633:4969:379:17776:14206

Legenda:
2 -> identificador de local
"Carnide do Meio" -> nome do local
9743:16905:13305:12504:2633:4969:379:17776:14206 -> identificadores dos locais a que está ligado



2. custosligacao.txt
Tem a informação dos quilómetros e do valores das portagens (e outras coisas) que constituem o custo fixo de ir de um local a outro.
O ficheiro tem a sintaxe
id_origem:id_destino:KM:custo




3. utilizadores.txt e utilizadores.csv

Contém em cada linha a informação de um utilizador. São fornecidos ficheiros em txt (separado por tab) e csv (separados por vírgula)
Ex: 
9000011000      Jon Yang        9000011000@foursquareUM.com     3761 N. 14th St

Legenda:
9000011000 -> NIF
"Jon Yang" -> nome
9000011000@foursquareUM.com -> email
"3761 N. 14th St" -> morada








