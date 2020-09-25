#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int leer_archivo(FILE*);
int imprimir(pila);

int main(int argc, char *argv[]) {
	
	FILE*archivo;
	leer_archivo(archivo); 
	return 0;
}

int leer_archivo(FILE* archivo){

	int con=0;
	NODO A;	
	NODO B;
	pila ptr;
	pila ptr2;
	pila ptr3;
	char n;
	char suma;
	char acarreo;
	char sobra=0;
	
	ini_pila(&ptr);
	ini_pila(&ptr2);
	ini_pila(&ptr3);	
	
	archivo = fopen("Numeros.txt","r");

	if (archivo == NULL){	
		printf("\nError de apertura del archivo. \n\n");
    }
	else{
	    while (n!=EOF)
	    {
			n = fgetc(archivo);
			switch(n){
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					A.num=n-48;
					if(con==0){
						push(&ptr,A);
					}
					else{
						push(&ptr2,A);
					}
					break;
				case'\n':
					con++;
					break;
			}
		}
	}
	fclose(archivo);

	archivo = fopen("Numeros.txt","a");
	while(!empty(ptr)&&!empty(ptr2)){
	suma=pop(&ptr).num+pop(&ptr2).num+sobra;
	if(suma>=10){
		acarreo=suma%10;
		sobra=suma/10;
		A.num=acarreo;
		push(&ptr3,A);
	}
	else{
		A.num=suma;
		push(&ptr3,A);
		if(sobra>0){
		    sobra=0;
		}
	}
	}
		fprintf(archivo,"\n");
	while(!empty(ptr3)){
		fprintf(archivo,"%d",pop(&ptr3).num);
	}
	liberar_pila(&ptr);
	liberar_pila(&ptr2);
	liberar_pila(&ptr3);
	fclose(archivo);	
}

