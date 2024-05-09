#include <stdio.h> //biblioteca de comunicacção com o usuário
#include <stdlib.h> // biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsável por cuidar da strings

	int registro() //função responsável por cadastrar os usuários no sistema
	{
		//início da criação de variáveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da criação de variáveis
		
		printf("Digite o CPF a ser cadastrado:\n"); //coletando informações do usuário
		scanf("%s", cpf); // "%s" refere-se 'a string
		
		strcpy(arquivo,cpf); //responsável po copiar o valor das strings
		
		FILE *file; //cria o arquivo no banco de dados
		file = fopen(arquivo, "w");
		fprintf(file, cpf); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,", "); //insere uma vígula entre as informações
		fclose(file);
		
		printf("Digite o nome a ser cadastrado:\n");
		scanf("%s", nome); //coleta o nome
		
		file = fopen(arquivo, "a"); //abre o criado anteriormente arquivo para armazenar a informação nome 
		fprintf(file, nome); //arquiva o nome
		fclose(file); //fecha o arquivo que acabou de ser aberto para receber a função
		
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
		
		char cpf[40]; //criação da variável string "cpf"
		char conteudo[200]; //criação da variável string "conteúdo"
		
		printf("Digite o CPF a ser consultado:\n");
		scanf("%s", cpf);//coleta o cpf que será deletado
		
		FILE *file; // acessa a função file e especifica o parâmetro (no caso, tambem "file")
		file = fopen(cpf,"r"); //especifica que o parâmetro "file" é a leitura/"read" da string CPF (arquivo/string , "o que vamos fazer com o arquivo")
		
		if(file == NULL) //SE (função) o CPF (arquivo/string) for nulo...
		{
			printf("Arquivo não localizado.\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		fclose(file);
	}
	
	int deletar() //POR FAVOR TUTOR ME AJUDA MEU CODIGO NÃO TÁ DELETANDO :-((
	{
		char cpf[40]; //criação da variável string "cpf"
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf); //coleta o cpf que será deletado
		
		remove(cpf); //função que efetivamente deleta a informação
		
		FILE *file; // acessa a função file e especifica o parâmetro (no caso, tambem "file")
		file = fopen(cpf,"r"); //especifica que o parâmetro "file" é a leitura/"read" da string CPF (arquivo/string , "o que vamos fazer com o arquivo")
		
		if(file == NULL) //SE (função) o CPF (string) for nulo... 
		{
			printf("O registro foi deletado.\n\n");
			system("pause");
		}
		
		fclose(file);
	}
	
	
	
	int main()
	{
		setlocale(LC_ALL, "Portuguese");
		
		int opcao=0; //definindo as variéveis
		int laco=1;
		char senhadigitada[]="a";
		int comparacao;	
		
		printf("--- Cartório EBAC---\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada); 
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao ==0)
		{
			system ("cls");
			for(laco=1;  laco=10;)
			{ //início da seleção
		
			
				setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
				
				printf("### Cartório da EBAC ###\n\n"); //início do menu
				printf("Escolha a opção desejada do menu:\n\n");
				printf("\t1-Registrar nomes\n");
				printf("\t2-Consultar nomes\n");
				printf("\t3-Deletar nomes\n"); 
				printf("\t4-Sair do sistema.\n\n");
				printf("Opção:"); //fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usuário
			
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
					printf("Essa opção não esá disponível\n");
					system("pause");
					break;		
				}//fim da seleção
			}
		}
		else printf("Senha incorreta.");
	}


