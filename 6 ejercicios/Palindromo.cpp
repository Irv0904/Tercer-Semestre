#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct cnodo{
	char pal[50];
	struct cnodo *ligaizq;
	struct cnodo *ligader;
};

typedef struct cnodo nodo;

void sin_espacio(char cadena[]) {
	char letra[50];
    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++){
        if (cadena[i] != ' '){
            letra[j++] = cadena[i];
        }
    }
    letra[j] = '\0';
    strcpy(cadena, letra);
}

void minuscula(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
	{
        cadena[i] = tolower(cadena[i]);
    }
}

void ciniciodb(char cadena[])
{
	/*nodo *p = NULL;
	nodo *f = NULL;
	nodo *q = NULL;*/
	printf("letra");
	for(int i =0 ;cadena[i] !='\0';i++)
	{
		printf("%s",cadena[i]);
	}
	printf("letra");
	
}

int main() {
    char cadena[50];
    printf("Ingresa una oracion: ");
    fgets(cadena, sizeof(cadena), stdin);

	cadena[strcspn(cadena, "\n")]='\0';
	
    //sin_espacio(cadena);
    minuscula(cadena);
    ciniciodb(cadena);
	    
    return 0;
}

/*void *creaMemoria(char n)
{
	void *i=(char *)malloc(n);
	if(i==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
} */

