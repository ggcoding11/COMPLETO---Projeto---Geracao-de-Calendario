#include <stdio.h>
#include <locale.h>
#include <time.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int diaNasc, mesNasc, anoNasc;
	
	printf("Geracao de calendario - Por Mr. JeeJ\n\n");
	
	printf("Digite sua data de nascimento (DD MM AAAA): ");
	scanf("%d %d %d", &diaNasc, &mesNasc, &anoNasc);

	time_t seg = time(NULL);
	
	struct tm tempoAtual = *(localtime(&seg));
	
	int diaAtual = tempoAtual.tm_mday;
	int mesAtual = tempoAtual.tm_mon + 1;
	int anoAtual = tempoAtual.tm_year + 1900;
	
	int idade = anoAtual - anoNasc;
	
	if (mesAtual < mesNasc || ((mesAtual == mesNasc) && (diaAtual < diaNasc))){
		idade -= 1;
	} 	
	
	printf("Idade: %d", idade);
	
	//Ver sobre ano bissexto - Como funciona?
	
	return 0;
}

