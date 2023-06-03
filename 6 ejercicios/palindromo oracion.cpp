#include <stdio.h>
#include <string.h>
#include <ctype.h>

void quitarEspacios(char cadena[]) {
    char cadenaSinEspacios[50];
    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {
            cadenaSinEspacios[j++] = cadena[i];
        }
    }
    cadenaSinEspacios[j] = '\0';
    strcpy(cadena, cadenaSinEspacios);
}

/*void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}*/

int main() {
    char cadena[50];
    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';  // Eliminar el salto de línea al final

    printf("Cadena original: %s\n", cadena);

    printf("Procesando...\n");
    quitarEspacios(cadena);
    //convertirMinusculas(cadena);
    //separarLetras(cadena);

    return 0;
}

