#include<stdio.h>//biblioteca de comunicacao
#include<stdlib.h>//biblioteca espaco de memoria
#include<locale.h>//biblioteca de texto por regiao
#include<string.h>//biblioteca string

int registro()
{
	//começo da criaçao de variavel
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçao de variavel
	
	printf("Digite o CPF a ser cadastrado: ");//registrando os dados dos clientes
	scanf("%s", cpf);//"%s" para salvar uma string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o W significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	 setlocale(LC_ALL,"portuguese");
	 
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o cpf a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r");//"r" para ler o arquivo
	 if(file == NULL)
	 {
	 	printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL);
	 {
	 	printf("\nEssas sao as informaçoes do usuario\n");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 	
	 	system("pause");
	 }
	 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//para excluir os dados 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		printf("O usuario foi deletado com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("O usuario nao foi encontrado!\n");
		system("pause");
	}
	
	
}


int main()
    {
	int opcao=0;//definindo variaveis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
	   
	   system("cls");
	  
	   setlocale(LC_ALL,"portuguese");
	
	   printf("Arquivo da EBAC\n\n");
	   printf("Selecione o numero desejado:\n\n");
	   printf("\t1 Registrar nomes:\n");
	   printf("\t2 Consultar nomes:\n");
	   printf("\t3 Deletar nomes:\n");
	   printf("opçao: ");
	
	   scanf("%d",&opcao);//armazenando a escolha do usuario
	
	   system("cls");//reponsavel por limpar a tela
	  
	   
	   switch (opcao)//inicio da seleçao do menu
	   {
	   	    case 1:
	   	    registro();//chamada de funçoes
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opçao nao esta disponivel!\n");
			system("pause");
			break;//final da seleçao do menu
	   }
    } 
}
