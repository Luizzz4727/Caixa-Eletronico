/*
	Name: CaixaRecursivo.cpp
	Author: luiz.ribeiro
	Date: 06/11/20 15:36
	Description: Programa que faz operações de um caixa eletrônico usando funções recursivas.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h> // Arquivo que possibilita a localização de programas.

//Sessão de Prototipação
//void validarNumConta(int)
//void validarSenha(int);
void menuOperacoes();
void deposito();
void saque();
void saldo();
void trocaSenha();
int validarNumConta();
int validarSenha(int);

//Variáveis globais
float dadosContas[5][3];
int erros[5];


/*
 *
 */

main()
{
	//Declaração de variáveis
	
	dadosContas[0][0] = 21659;
	dadosContas[0][1] = 0.00;
	dadosContas[0][2] = 159;
	
	dadosContas[1][0] = 98765;
	dadosContas[1][1] = 0.00;
	dadosContas[1][2] = 357;
	
	dadosContas[2][0] = 65498;
	dadosContas[2][1] = 0.00;
	dadosContas[2][2] = 649;
	
	dadosContas[3][0] = 48762;
	dadosContas[3][1] = 0.00;
	dadosContas[3][2] = 825;
	
	dadosContas[4][0] = 67954;
	dadosContas[4][1] = 0.00;
	dadosContas[4][2] = 346;
	
	for(int i = 0; i < 5; i++)
		erros[i] = 3;
	
	
	//INÍCIO
	setlocale(LC_ALL,""); // Configura a localidade do programa para a localidade padrão do sistema operacional, assim, nesse caso, possibilitando o uso de acentos da língua portuguesa.
	//Inicializando Variáveis
	
	//Desenvolvimento do Algoritmo
	
	menuOperacoes();
	
	
}//Fim

// Funções

void menuOperacoes()
{
	
	int escolha = 0;
	printf("===================================\n"
		   "Qual operação abaixo deseja fazer?\n\n"
		   "1 - Depósito\n"
		   "2 - Saque\n"
		   "3 - Saldo\n"
		   "4 - Troca de Senha\n"
		   "0 - Sair\n"
		   "===================================\n");
	scanf("%d", &escolha);
	
	switch(escolha)
	{
		
		case 1: deposito();
				break;
			
		case 2: saque();
				break;
			
		case 3: saldo();
				break;
			
		case 4: trocaSenha();
				break;
			
		case 0: exit(0);
				break;
			
		default: printf("Você digitou uma opção inexistente!\n"
						"Aguarde e escolha uma opção válida.");
				 Sleep(4000);
				 system("cls");
				 menuOperacoes();
				
	}
	
}

void deposito()
{
	
	system("cls");
	float numConta = 0.0, valor = 0.0;
	printf("==============================================\n\n"
		   "Você escolheu a operação de DEPÓSITO!!\n\n"
		   "Digite o número da conta para depósito: "); scanf("%f", &numConta);
	printf("\nDigite o valor do depósito: "); scanf("%f", &valor);
	
 	for(int i = 0; i < 5; i++)
	{
	 	
	 	if(dadosContas[i][0] == numConta)
	 	{
			dadosContas[i][1] =  dadosContas[i][1] + valor;
			printf("\nSeu depósito foi realizado com sucesso!!!\n"
				   "Finalizando...\n\n"
				   "==============================================");
			
			Sleep(5000);
			system("cls");
			menuOperacoes();
		}			
	}
	
	printf("\nSeu depósito foi realizado com sucesso!!!\n"
		   "Finalizando...\n\n"
		   "==============================================");
	Sleep(5000);
	system("cls");
	menuOperacoes();	
	
}

void saque()
{
	
	int i;
	float valor;
	system("cls");
	printf("========================================\n\n"
		   "Você escolheu a operação de SAQUE!!\n");
	
	i = validarNumConta();
	
	printf("========================================\n\n"
		   "Digite a quantia do seu saque: "); scanf("%f", &valor);
	
	if(dadosContas[i][1] >= valor)
	{
	
		dadosContas[i][1] = dadosContas[i][1] - valor;
		printf("\nSaque realizado com sucesso!!\n"
			   "Finalizando...\n\n"
		  	   "========================================");
   	    Sleep(3000);
		system("cls");
		menuOperacoes();
		
	}
	else
	{

		printf("\nVocê não possui saldo suficiente para realizar um saque dessa quantia!!\n"
			   "Por favor, verifique seu saldo!\n"
			   "Finalizando...\n\n"
		  	   "========================================");
		Sleep(6000);
		system("cls");
		menuOperacoes();	
		
	}
	
}

void saldo()
{
	
	int i = 0, exit;
	system("cls");
	printf("========================================\n\n"
		   "Você escolheu a operação de SALDO!!\n");
	
	i = validarNumConta();
	
	printf("======================================\n\n"
		   "Seu saldo é: %.2f\n\n"
		   "Digite 0 para sair: ", dadosContas[i][1]); scanf("%d", &exit);
	
	if(exit == 0)
	{
		printf("\nRetornando ao menu de operações..."
			   "\n\n======================================");
		Sleep(2000);
		system("cls");
		menuOperacoes();
	}
		
}

void trocaSenha()
{
	
	int i = 0;
	float senhaAtual = 0.0, senhaNova = 0.0, confirmaSenhaNova = 0.0;
	system("cls");
	printf("========================================\n\n"
		   "Você escolheu a operação de TROCA DE SENHA!!\n");
	
	i = validarNumConta();
	
	printf("======================================\n\n"
		   "Digite sua senha atual: "); scanf("%f", &senhaAtual);
	printf("\nDigite sua nova senha: "); scanf("%f", &senhaNova);
	printf("\nConfirme a sua nova senha: "); scanf("%f", &confirmaSenhaNova);
	
	if(dadosContas[i][2] != senhaAtual)
	{
		
		printf("\n\nA sua senha atual não está correta!\n"
			   "Por segurança, recomece!"
			   "\n\n======================================");
		Sleep(4000);
		system("cls");
		trocaSenha();
		
	}
	else if(senhaNova != confirmaSenhaNova)
	{
		
		printf("\n\nA sua nova senha não está coincidindo com a confirmação digitada!\n"
			   "Por segurança, recomece!"
			   "\n\n======================================");
		Sleep(4000);
		system("cls");
		trocaSenha();
		
	}
	else
	{
		
		dadosContas[i][2] = senhaNova;
		printf("\n\nTroca de senha realizada com sucesso!!\n"
			   "Encerrando operação!..."
			   "\n\n======================================");
		Sleep(3000);
		system("cls");
		menuOperacoes();
		
	}
		   
}

int validarNumConta()
{
	
	float numConta = 0.0;
	printf("\nDigite o número da sua conta: "); scanf("%f", &numConta);
	
	for(int i = 0; i < 5; i++)
	{	
	 	if(dadosContas[i][0] == numConta)
	 		if(validarSenha(i) == i)
	 			return i;		 					
	}
	
	printf("\nO número da conta não existe!\n");	
	validarNumConta();
	
}

int validarSenha(int i)
{
	
	float senha = 0.0;
	if(erros[i] == 0)
	{
		puts("\nEssa conta está bloqueada!!\n"
			 "Sua operação se encerrará!"
			 "\n\n========================================");
		Sleep(4000);
		system("cls");
		menuOperacoes();	
	}
	else
	{	
		printf("\nDigite a senha da sua conta: "); scanf("%f", &senha);
		
		if(dadosContas[i][2] == senha)
		{
			erros[i] = 3;
			printf("\nProcessando todos os dados... \n\n"
				   "========================================");
			Sleep(3000);
			system("cls");
			return i;
		}
		else
		{
			erros[i]--;
			
			switch(erros[i])
			{	
				case 2: puts("\nVocê têm 2 tentativas!!");
						validarSenha(i);
						break;
				
				case 1: puts("\nÉ sua última tentativa!!");
						validarSenha(i);
						break;
						
				case 0: puts("\nAcesso Bloqueado!!\n"
							 "Sua operação se encerrará!"
							 "\n\n========================================");
						Sleep(4000);
						system("cls");
						menuOperacoes();
						break;
			}	
		}
	}	
}
