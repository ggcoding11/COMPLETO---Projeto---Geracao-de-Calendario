#include <stdio.h>
#include <locale.h>
#include <time.h>

int validarDataNasc(int diaNasc, int mesNasc, int anoNasc, int diaAtual, int mesAtual, int anoAtual);

int main(){
	system("color 87");
	setlocale(LC_ALL, "Portuguese");
	
	int diaNasc, mesNasc, anoNasc;
	
	time_t seg = time(NULL);
	
	struct tm tempoAtual = *(localtime(&seg));
	
	int diaAtual = tempoAtual.tm_mday;
	int mesAtual = tempoAtual.tm_mon + 1;
	int anoAtual = tempoAtual.tm_year + 1900;
	
	printf("Geracao de calendario - Por Mr. JeeJ\n\n");
	
	do {
		printf("Digite sua data de nascimento (DD MM AAAA): ");
		scanf("%d %d %d", &diaNasc, &mesNasc, &anoNasc);
	} while (validarDataNasc(diaNasc, mesNasc, anoNasc, diaAtual, mesAtual, anoAtual));
	
	int idade = anoAtual - anoNasc;
	
	if (mesAtual < mesNasc || ((mesAtual == mesNasc) && (diaAtual < diaNasc))){
		idade -= 1;
	} 	
	
	printf("Idade: %d", idade);
	
	return 0;
}

int validarDataNasc(int diaNasc, int mesNasc, int anoNasc, int diaAtual, int mesAtual, int anoAtual){
	int bissexto = 0;
	
	if (anoNasc % 4 == 0){
		if (anoNasc % 100 == 0){
			if (anoNasc % 400 == 0){
				bissexto = 1;
			}
		} else {
			bissexto = 1;
		}
	}
	
	if (diaNasc < 1 || mesNasc < 1 || anoNasc < 1){
		return 1;
	}
	
	if (mesNasc > 12){
		return 1;
	}
	
	if (anoNasc > anoAtual){
		return 1;
	}
	
	if (anoNasc == anoAtual){
		if ((mesNasc > mesAtual) || ((mesNasc == mesAtual) && (diaNasc > diaAtual))){
			return 1;
		} 
	}
	
	switch(mesNasc){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (diaNasc > 31){
				return 1;
			}
		break;
		
		case 4: case 6: case 9: case 11:
			if (diaNasc > 30){
				return 1;
			}
		break;
		
		case 2:
			if (bissexto){
				if (diaNasc > 29){
					return 1;
				}	
			} else {
				if (diaNasc > 28){
					return 1;
				}
			}
		break;
	}
	
	return 0;
}

