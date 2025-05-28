#include <stdio.h>
#include <locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int diaNasc, mesNasc, anoNasc;
	
	printf("Geracao de calendario - Por Mr. JeeJ\n\n");
	
	printf("Digite sua data de nascimento (DD MM AAAA): ");
	scanf("%d %d %d", &diaNasc, &mesNasc, &anoNasc);
	
	
	
	return 0;
}

