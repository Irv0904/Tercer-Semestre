#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct cnodo
{
	char palabra ;
	struct cnodo *ligader;
	struct cnodo *ligaizq;
};
typedef struct cnodo nodo;

nodo *creaMemoria();

//nodo *buscar_palindromo(nodo *p);
nodo *cinicio(char pal[]);
void reorrerLista(nodo *p);

int main() {
	nodo *p=NULL;
	nodo *f=NULL;
	
    char pal[50];
    printf("Ingresa una palabra de caracteres: ");
	gets(pal);
    pal[strcspn(pal, "\n")] = '\0';  // Eliminar el salto de línea al final

    printf("\nCadena original: %s\n", pal);

    
    printf("\nProcesando...\n");

    p=cinicio(pal);    
    //p=buscar_palindromo(p);
	reorrerLista(p);
    return 0;
}


nodo *creaMemoria(){
	nodo *p=(nodo *)malloc(sizeof(nodo));
	if(p==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *cinicio(char pal[]) 
{
	nodo *r = NULL;
   	nodo *q = NULL;
    for (int i = 0; pal[i] != '\0'; i++) 
	{
     char caracter = tolower(pal[i]);
      // verfiicar si es un caracter alfabetica (mayusculas o minuscula)
      if (isalpha(caracter))
      {
         nodo *f = creaMemoria();
         f->palabra = caracter;
         f->ligader = NULL;
         f->ligaizq = q;

         if (q != NULL)
         {
            q->ligader = f;
         }
         else
         {
            r = f;
         }

         q = f;
      }
   }
   return r;
}

void reorrerLista(nodo *p)
{
   nodo *q = p;
   printf("\nNULL ");
   while (q != NULL)
   {
      printf("<- %s ->", q->palabra);
      q = q->ligader;
   }
   printf(" NULL");
}

/*nodo *buscar_palindromo(nodo *p)
{
	nodo *v=NULL;
	nodo *q=NULL;

	q=p;
	int band = 1;
    while(q->ligader!=NULL)
	{
		printf("a");
		q=q->ligader;
	}
	return (p);
}*/
