#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar la información del contacto
typedef struct {
    char nombre[50];
    char apellido[50];
    char telefono[20];
} Contacto;

// Nodo de la lista enlazada
typedef struct Nodo {
    Contacto contacto;
    struct Nodo* liga;
} Nodo;

// Función para insertar un contacto al final de la lista
void insertarContacto(Nodo** Agenda, Contacto nuevoContacto) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->contacto = nuevoContacto;
    nuevoNodo->liga = NULL;
    
    if (*Agenda == NULL) {
        *Agenda = nuevoNodo;
    } else {
        Nodo* temp = *Agenda;
        while (temp->liga != NULL) {
            temp = temp->liga;
        }
        temp->liga = nuevoNodo;
    }
    
    printf("Contacto insertado con exito.\n");
}

// Función para eliminar un contacto de la lista
void eliminarContacto(Nodo** Agenda, char nombre[]) {
    if (*Agenda == NULL) {
        printf("La lista está vacia.\n");
        return;
    }
    
    Nodo* temp = *Agenda;
    Nodo* prev = NULL;
    
    if (strcmp(temp->contacto.nombre, nombre) == 0) {
        *Agenda = temp->liga;
        free(temp);
        printf("Contacto eliminado con exito.\n");
        return;
    }
    
    while (temp != NULL && strcmp(temp->contacto.nombre, nombre) != 0) {
        prev = temp;
        temp = temp->liga;
    }
    
    if (temp == NULL) {
        printf("No se encontro el contacto.\n");
        return;
    }
    
    prev->liga = temp->liga;
    free(temp);
    printf("Contacto eliminado con exito.\n");
}

// Función para mostrar todos los contactos en la lista
void mostrarContactos(Nodo* Agenda) {
    if (Agenda == NULL) {
        printf("La lista está vacia.\n");
        return;
    }
    
    Nodo* temp = Agenda;
    
    printf("Lista de contactos:\n");
    while (temp != NULL) {
        printf("Nombre y Apellido: %s %s\n", temp->contacto.nombre, temp->contacto.apellido);
        printf("Telefono: %s\n", temp->contacto.telefono);
        printf("-----------------\n");
        temp = temp->liga;
    }
}

// Función para buscar un contacto por nombre
void buscarContacto(Nodo* Agenda, char nombre[]) {
    if (Agenda == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    
    Nodo* temp = Agenda;
    
    while (temp != NULL) {
        if (strcmp(temp->contacto.nombre, nombre) == 0) {
            printf("Nombre y Apellido: %s %s\n", temp->contacto.nombre, temp->contacto.apellido);
            printf("Teléfono: %s\n", temp->contacto.telefono);
            return;
        }
        temp = temp->liga;
    }
    
    printf("No se encontro el contacto.\n");
}

// Función para guardar los contactos en un archivo
void guardarContactos(Nodo* Agenda, char archivo[]) {
    FILE* file = fopen(archivo, "w");
    
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    Nodo* temp = Agenda;
    
    while (temp != NULL) {
        fprintf(file, "%s,%s,%s\n", temp->contacto.nombre,temp->contacto.apellido, temp->contacto.telefono);
        temp = temp->liga;
    }
    
    fclose(file);
    printf("Contactos guardados en el archivo con exito.\n");
}

// Función para cargar los contactos desde un archivo
void cargarContactos(Nodo** Agenda, char archivo[]) {
    FILE* file = fopen(archivo, "r");
    
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    char nombre[50];
    char apellido[50];
    char telefono[20];
    
    while (fscanf(file, "%[^,],%s,%s\n", nombre, apellido,telefono) == 2) {
        Contacto nuevoContacto;
        strcpy(nuevoContacto.nombre, nombre);
        strcpy(nuevoContacto.apellido, apellido);
        strcpy(nuevoContacto.telefono, telefono);
        
        insertarContacto(Agenda, nuevoContacto);
    }
    
    fclose(file);
    printf("Contactos cargados desde el archivo con exito.\n");
}

// Función para liberar la memoria de la lista enlazada
void liberarMemoria(Nodo* Agenda) {
    Nodo* temp;
    
    while (Agenda != NULL) {
        temp = Agenda;
        Agenda = Agenda->liga;
        free(temp);
    }
}

// Función principal
int main() {
    Nodo* Agenda = NULL;
    int opcion;
    
    do {
        system("CLS");
        printf("\nAgenda Telefonica\n");
        printf("1. Insertar \n");
        printf("2. Eliminar \n");
        printf("3. Mostrar \n");
        printf("4. Buscar \n");
        printf("5. Guardar \n");
        printf("6. Cargar \n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                Contacto nuevoContacto;
                printf("Ingrese el nombre: ");
                scanf("%s", nuevoContacto.nombre);
                printf("Ingrese el apellido: ");
                scanf("%s", nuevoContacto.apellido);
                printf("Ingrese el telefono: ");
                scanf("%s", nuevoContacto.telefono);
                insertarContacto(&Agenda, nuevoContacto);
                system("PAUSE");
                break;
            }
            case 2: {
                char nombre[50];
                printf("Ingrese el nombre del contacto a eliminar: ");
                scanf("%s", nombre);
                eliminarContacto(&Agenda, nombre);
                system("PAUSE");
                break;
            }
            case 3:
                mostrarContactos(Agenda);
                system("PAUSE");
                break;
            case 4: {
                char nombre[50];
                printf("Ingrese el nombre del contacto a buscar: ");
                scanf("%s", nombre);
                buscarContacto(Agenda, nombre);
                system("PAUSE");
                break;
            }
            case 5: {
                char archivo[100];
                printf("Ingrese el nombre del archivo para guardar los contactos: ");
                scanf("%s", archivo);
                guardarContactos(Agenda, archivo);
                system("PAUSE");
                break;
            }
            case 6: {
                char archivo[100];
                printf("Ingrese el nombre del archivo para cargar los contactos: ");
                scanf("%s", archivo);
                cargarContactos(&Agenda, archivo);
                system("PAUSE");
                break;
            }
            case 7:
                liberarMemoria(Agenda);
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 7);
    
    return 0;
}
