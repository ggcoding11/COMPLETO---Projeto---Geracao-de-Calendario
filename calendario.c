#include <stdio.h>
#include <locale.h>
#include <time.h>

int validarDataNasc(int diaNasc, int mesNasc, int anoNasc, int diaAtual, int mesAtual, int anoAtual);
int diasNoMes(int mes, int ano);
void mostrarCalendario(int diaNasc, int mesNasc, int anoNiver);

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
	
	printf("Idade: %d\n\n", idade);
	
	printf("Calendario do proximo aniversario: \n\n");
	
	int anoNiver = anoAtual;
	
	if ((mesAtual > mesNasc) || ((mesAtual == mesNasc) && (diaAtual > diaNasc))){
		anoNiver++;	
	}
	
	mostrarCalendario(diaNasc, mesNasc, anoNiver);
	
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

int diasNoMes(int mes, int ano) {
    if (mes == 2) { 
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            return 29; 
        } else {
            return 28;
        }
    }
    
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    
    return 31;
}

void mostrarCalendario(int diaNasc, int mesNasc, int anoNiver){
	printf(" D   S   T   Q   Q   S   S\n");
	
	struct tm data = {0};
	
	data.tm_mday = 01;
	data.tm_mon = mesNasc - 1;
	data.tm_year = anoNiver - 1900;
	
	mktime(&data);
	
	int diaSemana = data.tm_wday;
	
	int qntdDias = diasNoMes(mesNasc, anoNiver);
	
	int i;
	
	for (i = 0; i < diaSemana; i++){
		printf("    ");
	}
	
	for (i = 1; i <= qntdDias; i++){
		if (i == diaNasc){
		    printf("(%2d)", i);
		} else {
		    printf(" %2d ", i);
		}
	
		diaSemana++;
		
		if (diaSemana == 7){
			printf("\n");
			diaSemana = 0;
		}
	}
}

