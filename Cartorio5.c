//tarefa_exercício_modulo_4
#include <stdio.h> //inclui biblioteca stdio para uso da função printf
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das variáveis tipo string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //nessa função, não se coloca o operador '&' porque o valor a ser lido é do tipo string
	
	strcpy(arquivo, cpf); //função 'strcopy' serve para copiar strings em C. No caso, copia-se o conteúdo da str 'cpf' para a str 'arquivo'
	
	FILE *file; //declara variável "file" que é um ponteiro capaz de apontar para uma estrutura FILE. Esse tipo de declaração é comum quando você trabalha com manipulação de arquivos em C, permitindo que você crie variáveis que podem ser usadas para representar e interagir com arquivos no seu programa.
	//o que se cria aqui é uma variável chamada 'file' que vai ser usada para armazenar o endereço de memória de um arquivo durante as operações de entrada e saída
	//'FILE' é o tipo de dado que foi apontado pelo ponteiro '*' 
	
	file = fopen(arquivo, "w"); //fopen é um ponteiro para o arquivo aberto, armazenado na variável 'file'. Abre-se um arquivo chamado 'arquivo' no mode de escrita 'w' e se não existir, o arquivo será criado
	fprintf(file, cpf); //o conteúdo da variável cpf é escrito no arquivo 'file'. fprintf é igual a printf, só que ao invés da saida ser exibida na tela, a saída é direcionada no arquivo no formato especificado
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //reabre o 'arquivo', mas no modo anexar 'a', que adiciona mais dados ao final do arquivo criado
	fprintf(file, ", "); //',' é criado no final do 'file'
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
	setlocale(LC_ALL, "Portuguese"); //Tem acento na frase dentro dessa função, então tem que declarar o 'setlocale' de novo porque este estava em outra função
	
	char cpf[40]; //cria-se novamente o arquivo 'cpf' porque dentro dessa função 'consulta' não sabe-se ainda o 'cpf'
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //consultar o file em FILE
	file = fopen(cpf, "r"); //'r'de read, é o modo leitura para ler/consultar o arquivo 'cpf'
	
	if(file == NULL) //cria-se uma condicional em que retornará uma resposta caso o valor digitado não tenha sido criado
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //'while' é estrutura de loop. 'fgets' é uma função para ler uma linha de texto de um arquivo
	//'fgets recebe três argumentos: 'conteudo' é onde a linha de texto lida vai ser armazenada. '200' é o número máximo de caracteres a serem lidos
	//'file' é o ponteiro para o arquivo do qual se deseja ler. '!= NULL' serve para verificar se a função 'fgets' foi capaz de ler a linha do arquivo, se não, ele retorna resposta nula
	//em resumo: lê uma linha do arquivo apontado por 'file', armazena essa linha na variável 'conteudo' e executa o bloco de código associado enquanto houver mais linhas a serem lidas no arquivo.
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("Usuário não se encontra no sistema! \n");
		system("pause");
	}
		
}

int main() { //Início da função principal "main"
	int opcao = 0; //Declarando uma variável inteira chamada "opcao" e inicizalizando-a com valor 0
	int laco = 1; //Declarando uma variável inteira chamada "laco" e inicializando-a com valor 1
	char senhadigitada[10]="a";	
	int comparacao;
	
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de administrador! \n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

		for(laco=1; laco=1;)
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, sendo 'LC_ALL' uma constante que representa todas as categorias, sendo a ligua 'Portuguese' escolhida
			
			printf("### Cartório da EBAC ###\n\n");
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n\n");
			printf("\t4 - Sair do sistema \n\n");
			printf("Digite a opção: ");
			
			scanf("%d", &opcao); //armazenando a escolha do usuário, coloca-se o operador '&' quando se está lendo valores de tipos inteiros, caracteres individuais e floats.
			
			system("cls");
			
			switch(opcao) //instrução switch serve para a criação de estruturas de controles de seleção com várias opções. Avaliando o valor da variável 'opcao'
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
					printf("Essa opção não está disponível! \n");
					system("pause"); //esse comando serve para manter a janela do console aberta, acontece que no S.O. WINDOWS, a janela do console é fechada imediatamente após a conclusão da execução do programa.
					break;
			}
		}
	}

	else
		printf("Senha incorreta!");
		
}
