
/*
Nombre: Irving Jhon Villarreal Lasso
Cedula: 8-1063-2312
Fecha: 04/07/2023
Calificación: 100 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void palindromo(char palabra[]); 
void eliminarespacios(char palabra[]); 

int main()
{
    char palabra[50]; 

    printf("Ingrese una palabra: "); 
    gets(palabra); 

    eliminarespacios(palabra); 
    printf("\n\nPalabra sin espacios: %s", palabra); 
    palindromo(palabra); 

}

void eliminarespacios(char palabra[])
{
    int i, f; 
    int length; 

    length = strlen(palabra); 

    for(i = 0; i < length; i++)
    {
        if(palabra[i] != ' ')
        {
            palabra[f] = palabra[i]; 
            f++; 
        }
    }
    palabra[f] = '\0';
}

void palindromo(char palabra[])
{
    int longitud, inicio, final; 
    int resultante = 1;
    longitud = strlen(palabra); 

    for(inicio = 0; inicio < longitud; inicio++)
    {
        palabra[inicio] = tolower(palabra[inicio]); 
    }
    
    for(inicio = 0, final = longitud-1; inicio<final; inicio++, final--){
        if(palabra[inicio] != palabra[final]){
            resultante = 0; 
            break;
        }
    }

    if(resultante == 1){
        printf("\n\nLa palabra es palindroma\n\n"); 
    }
    else
    {
        printf("\n\nNo es un palindromo\n\n"); 
    }

}

