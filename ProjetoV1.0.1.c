#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>

typedef struct cliente CLIENTE;
struct cliente{
	char nome[30];
	char telefone[16];
	char sexo[1];
	int quantidade;
}cliente;

typedef struct produto PRODUTO;
struct produto{
	char nome[30];
	float valor;
	char setor[30];
	int quantidade;
	
}produto;


FILE *arquivo;

void menu_cliente();
void inputDado();
void consultar();
void buscar();
void alterar();
void excluir_cliente();

void menu_produto();
void cadastrar_produto();


int main(){
	int opcao;
	int opcao_cli;
	int opcao_prod;
	int quant = 0;
	setlocale (LC_ALL, "Portuguese");

	
	do
	{
	
	printf("---------------------------------------\n");
	printf("Escolha uma das opções seguintes :D !\n");
	printf("---------------------------------------\n");
	printf("1- Menu do cliente \n");
	printf("2 - Menu dos produtos\n");
	printf("3 - Menu de compra/venda\n");
	printf("0 - Para sair\n");
	scanf("%d", &opcao);
	system("cls");

		switch(opcao){
		
				case 1:
			
					menu_cliente();
					break;
				
				case 2:
					
					menu_produto();
					break;   
		case 3:
			printf("Bem-vindo ao menu de compra/venda! :D \n");
			break;
			
		case 0:
			system("pause");
				
		default:
			printf("Não possui essa opção\n");
	}
	
	
	
	
    } while (opcao =! 0);
	
	

	
	
	
	
	
	printf("Programa encerrado");
		
		
	
	
	}
	
	
void inputDado(){
	
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "a+b");
	
	if(arquivo == NULL){
		printf("ERRO!\n");
	}
	else{
		do{
			
			
			fflush(stdin);
			printf("Digite o nome: \n");
			gets(cliente.nome);
			
			fflush(stdin);
			printf("Digite o telefone: \n");
			gets(cliente.telefone);
			
			fflush(stdin);
			printf("Digite o sexo (M ou F): \n");
			gets(cliente.sexo);
			
			
			cliente.quantidade++;
			
			fwrite(&cliente, sizeof(CLIENTE), 1, arquivo);
			printf("Cadastro concluído com sucesso! \n ");
			getchar();
			
		} while(getche == 's');
		
		fclose(arquivo);
		
	}
	
	
	
}

void consultar(){
	int i = 1;
	int id;
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "rb");
	
	if(arquivo == NULL){
		printf("ERRO!\n");
	}
	else{
			printf("\t Lista de clientes: \n");
			printf("------------------------------------------\n");
		while(fread (&cliente, sizeof(CLIENTE), 1, arquivo) == 1 ){
			printf("Índice: %d\n", i);
			printf("Nome: %s\n", cliente.nome);
			printf("Telefone: %s\n", cliente.telefone);
			printf("Sexo: %s\n", cliente.sexo);	
			printf("------------------------------------------\n");
			i++;
		}
		
	}
	fclose(arquivo);
	
}

void buscar(){
	FILE* arquivo;
	char nome[30];
	
	arquivo = fopen("arquivo.txt", "rb");
	
	if(arquivo == NULL){
	printf("ERRO!\n");
	}
	else{
		fflush(stdin);
		printf("Digite o nome desejado: ");
		gets(nome);
		
		while( fread(&cliente, sizeof(CLIENTE), 1, arquivo) == 1 ){
			if(strcmp(nome, cliente.nome) == 0 ){
				printf("Nome: %s\n", cliente.nome);
				printf("Telefone: %s\n", cliente.telefone);
				printf("Sexo: %s\n", cliente.sexo);
				printf("------------------------------------------\n");
			}
		}
	}
	
	fclose(arquivo);
	
}	

void alterar(){
	FILE* arquivo;
	arquivo = fopen("arquivo.txt", "rb+");
	int i = 1;
	int id;
	
	if(arquivo){
	
		printf("\t Lista de clientes: \n");
		printf("------------------------------------------\n");
		
		while(fread(&cliente, sizeof(CLIENTE), 1, arquivo)){
			printf("Índice: %d\n", i );
			printf("Nome: %s\n", cliente.nome);
			printf("Telefone: %s\n", cliente.telefone);
			printf("Sexo: %s\n", cliente.sexo);
			printf("------------------------------------------\n");
			i++;
		}
		printf("Digite o índice do cliente que deseja alterar:\n\n");
		scanf("%d", &id);
		getchar();
		id--;
		
		if(id >= 0 && id < i -1){
			printf("Digite o nome: ");
			scanf("%s", &cliente.nome);
			printf("Digite o telefone: ");
			scanf("%s", &cliente.telefone);
			printf("Digite o sexo: ");
			scanf("%s", &cliente.sexo);
			
			fseek(arquivo, id * sizeof(CLIENTE), SEEK_SET);
			fwrite(&cliente, sizeof(CLIENTE), 1, arquivo);
			printf("Dados atualizados com sucesso! :D\n");
		}
		fclose(arquivo);
		
		}
	
	else{
		printf("ERRO!");
	}
	
}


void excluir_cliente(){
	FILE* arquivo = fopen("arquivo.txt", "rw");
    FILE* novoArquivo = fopen("temporario.txt", "w");
    char nome[50];
	
	consultar();
	
	
	printf("Digite o nome do usuário a ser excluido: ");
	scanf("%s", &nome);
				
	while(!feof(arquivo)){
	  fread(&cliente, sizeof(cliente), 1, arquivo);
		    if(strcmp(nome, cliente.nome)){
		          fwrite(&cliente, sizeof(cliente), 1, novoArquivo);
		       }
		   }
		    fclose(novoArquivo);
		    fclose(arquivo);
		    remove("arquivo.txt");
		    rename("temporario.txt", "arquivo.txt");
		    cliente.quantidade--;
		    printf("Cliente removido com sucesso!\n");
		    
}


void menu_cliente(){
		int opcao_cli;
		
		system("cls");
		printf("\t\t     ---------------------------------------\n");
		printf("\t\t\tBem-vindo ao menu do cliente! :D \n");
		printf("\t\t      ---------------------------------------\n");
		printf("Escolha uma das opções seguintes: \n");			
		printf("1 - Cadastro \n");
		printf("2 - Remover cadastro\n");
		printf("3 - Atualizar cadastro\n");
		printf("4 - Consultar dados\n");
		printf("5 - Buscar por cliente\n");
		printf("6 - Verificar quantidade de clientes");
		printf("0 - Voltar para o menu anterior\n");
		scanf("%d", &opcao_cli);

		switch(opcao_cli){
				
					case 1:
						system("cls");
						inputDado();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
					
					case 2:
						system("cls");
						excluir_cliente();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 3:
						system("cls");
						alterar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 4:
						system("cls");
						consultar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;
				
					case 5:
						system("cls");
						buscar();
						printf("Aperte qualquer tecla para continuar!\n");
						getch();
						system("cls");
						break;	
					
					case 6:
						system("cls");
						printf("Quantidade de clientes cadastrados: %d\n", cliente.quantidade);
						getch();
						system("cls");
						break;	
					
					case 0:
						system("cls");
				
			
			}						
	}

void menu_produto(){
		int opcao_prod;
		
		system("cls");
		printf("\t\t     ---------------------------------------\n");
		printf("\t\t\tBem-vindo ao menu dos produtos ! :D \n");
		printf("\t\t      ---------------------------------------\n");
		printf("Escolha uma das opções seguintes: \n");
		printf("1 - Cadastro de produtos \n");
		printf("2 - Remover produto\n");
		printf("3 - Atualizar produto\n");
		printf("4 - Listagem dos produtos\n");
		printf("5 - Voltar para o menu anterior \n");
		scanf("%d", &opcao_prod);
		
			switch(opcao_prod){
				
				case 1:
					system("cls");
					cadastrar_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;
								
				case 4:
					system("cls");
					listar_produto();
					printf("Aperte qualquer tecla para continuar!\n");
					getch();
					system("cls");
					break;
			}
}
			

void cadastrar_produto(){
	
	FILE* arquivoProduto;
	arquivoProduto = fopen("arquivoProduto.txt", "a+b");
	
	if(arquivoProduto == NULL){
		printf("ERRO!\n");
	}
	else{
		do{
			
			
			fflush(stdin);
			printf("Digite o nome: \n");
			gets(produto.nome);
			
			fflush(stdin);
			printf("Digite o valor: \n");
			scanf("%d", &produto.valor);
			
			fflush(stdin);
			printf("Digite o setor: \n");
			gets(produto.setor);
			
			fflush(stdin);
			printf("Digite a quantidade: \n");
			scanf("%d", &produto.quantidade);
			
			
			fwrite(&produto, sizeof(PRODUTO), 1, arquivoProduto);
			printf("Cadastro de produtos concluído com sucesso! \n ");
			getchar();
			
		} while(getche == 's');
		
		fclose(arquivoProduto);
		
	}
	
	
	
}
	

void listar_produto(){
	int i = 1;
	int id;
	FILE* arquivoProduto;
	arquivoProduto = fopen("arquivoProduto.txt", "rb");
	
	if(arquivoProduto == NULL){
		printf("ERRO!\n");
	}
	else{
			printf("\t Lista de produtos: \n");
			printf("------------------------------------------\n");
		while(fread (&produto, sizeof(PRODUTO), 1, arquivoProduto) == 1 ){
			printf("Índice: %d\n", i);
			printf("Nome: %s\n", produto.nome);
			printf("Valor: %.2f\n", produto.valor);
			printf("Setor: %s\n", produto.setor);	
			printf("Quantidade: %d\n", produto.quantidade);
			printf("------------------------------------------\n");
			i++;
		}
		
	}
	fclose(arquivo);
	
}
	
	
	
	
		
	







		
	

	

