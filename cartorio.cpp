#include <stdio.h> //biblioteca de comunicac��o com o usu�rio
#include <stdlib.h> // biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar da strings

	int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
	{
		//in�cio da cria��o de vari�veis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da cria��o de vari�veis
		
		printf("Digite o CPF a ser cadastrado:\n"); //coletando informa��es do usu�rio
		scanf("%s", cpf); // "%s" refere-se 'a string
		
		strcpy(arquivo,cpf); //respons�vel po copiar o valor das strings
		
		FILE *file; //cria o arquivo no banco de dados
		file = fopen(arquivo, "w");
		fprintf(file, cpf); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,", "); //insere uma v�gula entre as informa��es
		fclose(file);
		
		printf("Digite o nome a ser cadastrado:\n");
		scanf("%s", nome); //coleta o nome
		
		file = fopen(arquivo, "a"); //abre o criado anteriormente arquivo para armazenar a informa��o nome 
		fprintf(file, nome); //arquiva o nome
		fclose(file); //fecha o arquivo que acabou de ser aberto para receber a fun��o
		
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado:\n");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado:\n");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause"); // interrompe a rotina 
		
	}
	
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40]; //cria��o da vari�vel string "cpf"
		char conteudo[200]; //cria��o da vari�vel string "conte�do"
		
		printf("Digite o CPF a ser consultado:\n");
		scanf("%s", cpf);//coleta o cpf que ser� deletado
		
		FILE *file; // acessa a fun��o file e especifica o par�metro (no caso, tambem "file")
		file = fopen(cpf,"r"); //especifica que o par�metro "file" � a leitura/"read" da string CPF (arquivo/string , "o que vamos fazer com o arquivo")
		
		if(file == NULL) //SE (fun��o) o CPF (arquivo/string) for nulo...
		{
			printf("Arquivo n�o localizado.\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		fclose(file);
	}
	
	int deletar() //POR FAVOR TUTOR ME AJUDA MEU CODIGO N�O T� DELETANDO :-((
	{
		char cpf[40]; //cria��o da vari�vel string "cpf"
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf); //coleta o cpf que ser� deletado
		
		remove(cpf); //fun��o que efetivamente deleta a informa��o
		
		FILE *file; // acessa a fun��o file e especifica o par�metro (no caso, tambem "file")
		file = fopen(cpf,"r"); //especifica que o par�metro "file" � a leitura/"read" da string CPF (arquivo/string , "o que vamos fazer com o arquivo")
		
		if(file == NULL) //SE (fun��o) o CPF (string) for nulo... 
		{
			printf("O registro foi deletado.\n\n");
			system("pause");
		}
		
		fclose(file);
	}
	
	
	
	int main()
	{
		setlocale(LC_ALL, "Portuguese");
		
		int opcao=0; //definindo as vari�veis
		int laco=1;
		char senhadigitada[]="a";
		int comparacao;	
		
		printf("--- Cart�rio EBAC---\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada); 
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao ==0)
		{
			system ("cls");
			for(laco=1;  laco=10;)
			{ //in�cio da sele��o
		
			
				setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
				
				printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1-Registrar nomes\n");
				printf("\t2-Consultar nomes\n");
				printf("\t3-Deletar nomes\n"); 
				printf("\t4-Sair do sistema.\n\n");
				printf("Op��o:"); //fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usu�rio
			
				system("cls");
				
				switch(opcao)
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
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
						
					default:
					printf("Essa op��o n�o es� dispon�vel\n");
					system("pause");
					break;		
				}//fim da sele��o
			}
		}
		else printf("Senha incorreta.");
	}


