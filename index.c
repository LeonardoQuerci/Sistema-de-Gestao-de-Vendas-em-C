#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

float totalGeral=0;
int cont_venda=0;

typedef struct {
	char filial[4];
	char nomeVendedor[16];
	float totalVendido;
}Venda;

void troca(Venda v[], int i, int j){
	Venda aux;
	aux=v[i];
	v[i]=v[j];
	v[j]=aux;
}

void bubbleSortNomes(Venda v[], int quantidade){
	int i=0,j=0;
	for(i=0;i<quantidade-1;i++){
		for(j=0;j<quantidade-i-1;j++){
			int comp1=strcmp(v[j].filial,v[j+1].filial)==0;
			int comp2=strcmp(v[j].nomeVendedor,v[j+1].nomeVendedor)>0;
			if (comp1 && comp2){
				troca(v,j,j+1);
			}
		}
	}
}

void bubbleSortFilial(Venda v[], int quantidade){
	int i=0,j=0;
	for(i=0;i<quantidade-1;i++){
		for(j=0;j<quantidade-i-1;j++){
			if (strcmp(v[j].filial,v[j+1].filial)>0){
				troca(v,j,j+1);
			}
		}
	}
}

void registrarVenda(Venda v[]){
	while(true){
		if (cont_venda<20){
			system("cls");
			printf("\nDigite o codigo da Filial ou 000 para sair -->");
			scanf("%s",v[cont_venda].filial);
			if (strcmp(v[cont_venda].filial,"000")==0)return;
			printf("\nDigite o nome do Vendedor -->");
			scanf("%s",v[cont_venda].nomeVendedor);
			printf("\nDigite o valor total das vendas -->");
			scanf("%f",&v[cont_venda].totalVendido);
			cont_venda++;
		}else{
			printf("\n****Total maximo de vendas registradas****\n");
			return;
		}	
	}
}
void imprimirLinha() {
	int i;
    for(i = 0; i < 55; i++) {
        printf("-");
    }
    printf("\n");
}

void mostrarRelatorio(Venda v[]){
	totalGeral=0;
	bubbleSortFilial(v,cont_venda);
	bubbleSortNomes(v,cont_venda);
	system("cls");
	int i =0; 
	printf("%-15s %-20s %12s\n", "*****", "RELATORIO MENSAL DE VENDAS", "*****");
	printf("%-15s %-20s %12s\n", " ", "FEVEREIRO DE 2026", " ");
	imprimirLinha();
	printf("%-15s %-20s %18s\n", "FILIAL", "VENDEDOR", "VENDAS");
	imprimirLinha();
	while(i<cont_venda){
		printf("%-15s\n",v[i].filial);
		char filialAtual[4];
		strcpy(filialAtual,v[i].filial);
		float subTotalFilial=0;
		while(i<cont_venda && (strcmp(v[i].filial,filialAtual))==0){
			printf("%-15s %-20s %18.2f\n"," ",v[i].nomeVendedor, v[i].totalVendido);
			subTotalFilial+=v[i].totalVendido;
			i++;
		}
		char labelSB[20];
		sprintf(labelSB,"SubTotal Filial %s",v[i-1].filial);
		printf("\n%-15s %-20s %18.2f\n\n"," ",labelSB, subTotalFilial);
		totalGeral+=subTotalFilial;
	}	
	imprimirLinha();
	printf("%-15s %-20s %18.2f\n"," ","Total Geral", totalGeral);
	imprimirLinha();	
}

int menu(){
	int escolha;
	printf("\n1-REGISTRAR VENDAS\n");
	printf("2-MOSTRAR RELATORIO DE VENDAS\n");
	printf("3-SAIR DO PROGRAMA\n");
	printf("DIGITE A OPCAO DESEJADA E APERTE <ENTER> -->");
	scanf("%d",&escolha);
	return escolha;
}
int main(){
	Venda vendas[20];
	int desejo=menu();
	while(desejo!=3){
		switch(desejo){
			case 1:
				registrarVenda(vendas);
				break;
			case 2:
				mostrarRelatorio(vendas);
				break;
			default:
				printf("\n****OPCAO INVALIDA****");
				break;
		}
		desejo=menu();
	}
	return 0;
}
