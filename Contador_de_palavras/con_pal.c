/*
Solução do tamanho dos vetores é que poder ser informardo pelo usuario!!

*/
//Qualquer coisa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void retorno(char a[20], int b);

int main(int argc, char *argv[])
{
	FILE *arq;
	char banco[20][20];
	char b[20];
	int i,cont_p = 0,j = 0;
	int c_banco[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int flag_1,flag_2;

	arq = fopen(strcat(argv[1],".txt"),"r");
	if(arq == NULL)
	{
		printf("Arquivo não encontrado");
		exit(1);
	}
	else
	{
		while(fscanf(arq,"%s",b) != EOF)
		{
			for(i = 0; i <= j; i++)
			{
				flag_1 = strcmp(b,banco[i]);
				if(flag_1 == 0)
				{
					c_banco[i]++;
					flag_2 = 1;
					break;
				}
				else
				{
					flag_2 = 0;
				}
			}
			if(flag_2 == 0)
			{
				strcpy(banco[cont_p],b);
				c_banco[cont_p]++;
				cont_p++;
			}
			j = cont_p;
		}
		fclose(arq);
	}
	FILE *saida;
	saida = fopen("saida.txt","w");
	fprintf(saida,"Classe Frequencia\n");
	fclose(saida); 
	for(i=0;i < cont_p;i++)
	{
		printf("%s %d\n",banco[i],c_banco[i]);
		retorno(banco[i],c_banco[i]);
	}

	return 0;
}


void retorno(char a[20], int b)
{
	FILE *saida;
	saida = fopen("saida.txt","a");
	fprintf(saida,"%s %d\n",a,b);
	fclose(saida);
}
