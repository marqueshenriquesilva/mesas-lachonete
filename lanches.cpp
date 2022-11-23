#include <stdio.h>
#include <conio.h>
#define TF 5

void loaddemo(int consumo[TF][TF], double precos[TF], int &tl){
		consumo[0][0] = 0;
		consumo[0][1] = 2;
		consumo[0][2] = 3;
		consumo[0][3] = 8;
		consumo[0][4] = 9;
		
		consumo[1][0] = 7;
		consumo[1][1] = 4;
		consumo[1][2] = 5;
		consumo[1][3] = 6;
		consumo[1][4] = 1;
		
		consumo[2][0] = 2;
		consumo[2][1] = 3;
		consumo[2][2] = 4;
		consumo[2][3] = 5;
		consumo[2][4] = 6;
		
		consumo[3][0] = 1;
		consumo[3][1] = 2;
		consumo[3][2] = 1;
		consumo[3][3] = 2;
		consumo[3][4] = 3;
		
		consumo[4][0] = 5;
		consumo[4][1] = 7;
		consumo[4][2] = 8;
		consumo[4][3] = 9;
		consumo[4][4] = 0;
		
		precos[0] = 2;
		precos[1] = 1.5;
		precos[2] = 1.5;
		precos[3] = 2.8;
		precos[4] = 0.5;
		
		tl = 5;
}

void leitura(int consumo[TF][TF], int &tl){
	printf("\n");
	tl = 0;
	int i, j;
	for (j=0; j<TF; j++){
		for (i=0; i<TF; i++){
			printf("Insira consumo[%d][%d]: ", i, j);
			scanf("%d", &consumo[i][j]);
		}
		printf("\n");
		tl++;
	}
}

void leituraprecos(double precos[TF]){
	int j;
	printf("\n");
	for (j=0; j<TF; j++){
		printf("Insira preco[%d]: ", j);
		scanf("%lf", &precos[j]);
	}
}

void exibe(int consumo[TF][TF], int tl){
	int i, j;
	printf("\n-------------CONSUMO-------------\n");
	for (i=0; i<tl; i++){
		for (j=0; j<tl; j++){
			printf("%d	", consumo[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------\n");
}

void exibeprecos(double precos[TF]){
	int i;
	printf("\n---PRECOS---\n");
	for (i=0; i<TF; i++){
		printf("%.2lf\n", precos[i]);
	}
	printf("--------------\n");
}

void novoconsumo(int consumo[TF][TF], int &tl){
	int i, j, qtd;
	printf("\nInsira numero de mesa: ");
	scanf("%d", &j);
	printf("\nCodigos\n0 Refrigerante\n1 Coxinha\n2 Sorvete\n3 Cerveja\n4 Pinga");
	printf("\nInsira codigo de pedido: ");
	scanf("%d", &i);
	printf("\nInsira quantidade: ");
	scanf("%d", &qtd);
	
	consumo[i][j] = qtd;
	
	printf("\nConsumo inserido com sucesso!\n");
}

void encerrarmesa(int consumo[TF][TF], double precos[TF], char produtos[TF][20], double &faturamento){
	int numero, i;
	double valor, total;
	printf("\nInsira numero da mesa: ");
	scanf("%d", &numero);
	
	for (i=0; i<TF; i++){
		valor = consumo[i][numero] * precos[i];
		total += valor;
		printf("PRODUTO: %s	VALOR: %.2lf\n", produtos[i], valor);
		consumo[i][numero] = 0;
	}
	printf("TOTAL: %.2lf\n", total);
	faturamento += total;
	
}


int main(void){
	int consumo[TF][TF];
	double precos[TF];
	char produtos[TF][20] = {"Refrigerante", "Coxinha", "Sorvete", "Cerveja", "Pinga"};
	
	int tl = 0;
	double faturamento = 0;
	
	char demo;
	int opcao = 0;
	
	printf("Comecar programa com valores de demonstracao? (S/N)\n");
	demo = getche();
	printf("\n");
	
	if(demo == 's' || demo == 'S'){
		loaddemo(consumo, precos, tl);
	}
	
	while(opcao != 9){
		printf("\n1. Leitura de precos");
		printf("\n2. Exibicao de precos");
		printf("\n3. Leitura de mesas");
		printf("\n4. Exibicao de mesas");
		printf("\n5. Novo pedido da mesa");
		printf("\n6. Encerramento de mesa");
		printf("\n7. Faturamento geral");
		printf("\n8. Exibir tudo");
		printf("\n9. Sair");
		printf("\nSelecione a opcao: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1: leituraprecos(precos); break;
			case 2: exibeprecos(precos); break;
			case 3: leitura(consumo, tl); break;
			case 4: exibe(consumo, tl); break;
			case 5: novoconsumo(consumo, tl); break;
			case 6: encerrarmesa(consumo, precos, produtos, faturamento); break;
			case 7:	printf("\nFATURAMENTO GERAL: %.2lf\n", faturamento); break;
			case 8:
				exibeprecos(precos);
				exibe(consumo, tl);
				printf("\nFATURAMENTO GERAL: %.2lf\n", faturamento);
				break;
		}
	}
	
	printf("\nFIM\n");
	
	return 0;
}

