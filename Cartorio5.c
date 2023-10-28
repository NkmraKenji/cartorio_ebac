//tarefa_exerc�cio_modulo_4
#include <stdio.h> //inclui biblioteca stdio para uso da fun��o printf
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das vari�veis tipo string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //nessa fun��o, n�o se coloca o operador '&' porque o valor a ser lido � do tipo string
	
	strcpy(arquivo, cpf); //fun��o 'strcopy' serve para copiar strings em C. No caso, copia-se o conte�do da str 'cpf' para a str 'arquivo'
	
	FILE *file; //declara vari�vel "file" que � um ponteiro capaz de apontar para uma estrutura FILE. Esse tipo de declara��o � comum quando voc� trabalha com manipula��o de arquivos em C, permitindo que voc� crie vari�veis que podem ser usadas para representar e interagir com arquivos no seu programa.
	//o que se cria aqui � uma vari�vel chamada 'file' que vai ser usada para armazenar o endere�o de mem�ria de um arquivo durante as opera��es de entrada e sa�da
	//'FILE' � o tipo de dado que foi apontado pelo ponteiro '*' 
	
	file = fopen(arquivo, "w"); //fopen � um ponteiro para o arquivo aberto, armazenado na vari�vel 'file'. Abre-se um arquivo chamado 'arquivo' no mode de escrita 'w' e se n�o existir, o arquivo ser� criado
	fprintf(file, cpf); //o conte�do da vari�vel cpf � escrito no arquivo 'file'. fprintf � igual a printf, s� que ao inv�s da saida ser exibida na tela, a sa�da � direcionada no arquivo no formato especificado
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //reabre o 'arquivo', mas no modo anexar 'a', que adiciona mais dados ao final do arquivo criado
	fprintf(file, ", "); //',' � criado no final do 'file'
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	return 0;
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Tem acento na frase dentro dessa fun��o, ent�o tem que declarar o 'setlocale' de novo porque este estava em outra fun��o
	
	char cpf[40]; //cria-se novamente o arquivo 'cpf' porque dentro dessa fun��o 'consulta' n�o sabe-se ainda o 'cpf'
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //consultar o file em FILE
	file = fopen(cpf, "r"); //'r'de read, � o modo leitura para ler/consultar o arquivo 'cpf'
	
	if(file == NULL) //cria-se uma condicional em que retornar� uma resposta caso o valor digitado n�o tenha sido criado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //'while' � estrutura de loop. 'fgets' � uma fun��o para ler uma linha de texto de um arquivo
	//'fgets recebe tr�s argumentos: 'conteudo' � onde a linha de texto lida vai ser armazenada. '200' � o n�mero m�ximo de caracteres a serem lidos
	//'file' � o ponteiro para o arquivo do qual se deseja ler. '!= NULL' serve para verificar se a fun��o 'fgets' foi capaz de ler a linha do arquivo, se n�o, ele retorna resposta nula
	//em resumo: l� uma linha do arquivo apontado por 'file', armazena essa linha na vari�vel 'conteudo' e executa o bloco de c�digo associado enquanto houver mais linhas a serem lidas no arquivo.
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}		
	
	system("pause");
	
	return 0;
	
}	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) {
		printf("Usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
		
}

int main() { //In�cio da fun��o principal "main"
	int opcao = 0; //Declarando uma vari�vel inteira chamada "opcao" e inicizalizando-a com valor 0
	int laco = 1; //Declarando uma vari�vel inteira chamada "laco" e inicializando-a com valor 1
	char senhadigitada[10]="a";	
	int comparacao;
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de administrador! \n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

		for(laco=1; laco=1;)
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, sendo 'LC_ALL' uma constante que representa todas as categorias, sendo a ligua 'Portuguese' escolhida
			
			printf("### Cart�rio da EBAC ###\n\n");
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n\n");
			printf("\t4 - Sair do sistema \n\n");
			printf("Digite a op��o: ");
			
			scanf("%d", &opcao); //armazenando a escolha do usu�rio, coloca-se o operador '&' quando se est� lendo valores de tipos inteiros, caracteres individuais e floats.
			
			system("cls");
			
			switch(opcao) //instru��o switch serve para a cria��o de estruturas de controles de sele��o com v�rias op��es. Avaliando o valor da vari�vel 'opcao'
			{
				case 1:
					registro();
					break;
				
				case 2:
					consulta();
					break;
				
				case 3:
					deletar();
					break;
					
				case 4:
					printf("Obrigado por utilizar o sistema! \n");
					return 0;
					break;
				
				default:
					printf("Essa op��o n�o est� dispon�vel! \n");
					system("pause"); //esse comando serve para manter a janela do console aberta, acontece que no S.O. WINDOWS, a janela do console � fechada imediatamente ap�s a conclus�o da execu��o do programa.
					break;
			}
		}
	}

	else
		printf("Senha incorreta!");
		
}
