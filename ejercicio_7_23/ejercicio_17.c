#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POSTRE 25
#define MAX_INGRE 25

typedef struct ingredientes
{
    char Ingre[MAX_INGRE];
    struct ingredientes *liga;
} Ingre;

typedef struct postres
{
    char Postre[MAX_POSTRE];
    struct postres *liga;
    struct ingredientes *lista_ingredientes;
} Postre;

void eliminarSaltoDeLinea(char *cadena)
{
    int longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n')
    {
        cadena[longitud - 1] = '\0';
    }
}

Ingre *crearingre(char *ingrediente)
{
    Ingre *nuevo = (Ingre *)malloc(sizeof(Ingre));
    strcpy(nuevo->Ingre, ingrediente);
    nuevo->liga = NULL;
    return nuevo;
}

Postre *crearpostre()
{
    Postre *nuevo = (Postre *)malloc(sizeof(Postre));
    nuevo->liga = NULL;
    nuevo->lista_ingredientes = NULL;
    return nuevo;
}

// D. Dar de alta un postre con todos sus ingredientes.
Postre *agregarPostre(Postre *postre)
{
    Postre *p = NULL;
    Postre *t = NULL;
    Postre *r = NULL;
    Ingre *q = NULL;
    Ingre *k = NULL;

    char nombre[MAX_POSTRE];
    char ingrediente[MAX_INGRE];
    int conting = 0, aux, opc;

    printf("** Nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    eliminarSaltoDeLinea(nombre);

    p = crearpostre();
    strcpy(p->Postre, nombre);

    do
    {
        system("cls");
        printf("\t\t**       INGREDIENTES        **\n");
        conting++;
        printf("%d. ", conting);
        fgets(ingrediente, sizeof(ingrediente), stdin);
        eliminarSaltoDeLinea(ingrediente);

        // Lista de ingredientes para cada postre.
        q = crearingre(ingrediente);
        if (p->lista_ingredientes == NULL)
        {
            p->lista_ingredientes = q;
            q->liga = NULL;
            k = q;
        }
        else
        {
            k->liga = q;
            q->liga = NULL;
            k = q;
        }
        printf("\n** Presione 1 para continuar: ");
        scanf("%d", &opc);
        fflush(stdin);

    } while (opc == 1);

    // Ordenamiento alfabético de los postres.
    if (postre == NULL)
    {
        postre = p;
        postre->liga = NULL;
        t = postre;
    }
    else
    {
        if (strcasecmp(p->Postre, postre->Postre) < 0)
        {
            p->liga = postre;
            postre = p;
        }
        else
        {
            if (postre->liga == NULL)
            {
                postre->liga = p;
                p->liga = NULL;
            }
            else
            {
                aux = 1;
                for (t = postre; t->liga != NULL; t = t->liga)
                {
                    r = t->liga;
                    if (strcasecmp(t->Postre, p->Postre) < 0 && strcasecmp(r->Postre, p->Postre) > 0)
                    {
                        t->liga = p;
                        p->liga = r;
                        aux = 0;
                        break;
                    }
                }
                if (aux)
                {
                    t->liga = p;
                    p->liga = NULL;
                }
            }
        }
    }

    return postre;
}

// E. Mostrar todos los postres con sus ingredientes.
void ListaPostre(Postre *postre)
{
    Postre *t = NULL;
    Ingre *q = NULL;
    int cont = 0;

    if (postre == NULL)
    {
        printf("\n** La lista esta vacia.");
    }
    else
    {
        printf("\n\t\t**  POSTRES  **");
        printf("\n---------------------------------\n");

        for (t = postre; t != NULL; t = t->liga)
        {
            printf("\n%d. Postre: %s\n", cont + 1, t->Postre);
            printf("   Ingredientes:\n");

            for (q = t->lista_ingredientes; q != NULL; q = q->liga)
            {
                printf("   - %s\n", q->Ingre);
                cont++;
            }
        }
    }
}

// F. Mostrar un postre con sus ingredientes.
void mostrar_postre(Postre *postre, int pos)
{
    Postre *t = NULL;
    Ingre *q = NULL;
    int cont = 0;

    if (postre == NULL)
    {
        printf("\n** La lista esta vacia.");
    }
    else
    {
        for (t = postre; t != NULL; t = t->liga)
        {
            cont++;
            if (cont == pos)
            {
                printf("\n%d. Postre: %s\n", cont, t->Postre);
                printf("   Ingredientes:\n");

                for (q = t->lista_ingredientes; q != NULL; q = q->liga)
                {
                    printf("   - %s\n", q->Ingre);
                }
                break;
            }
        }
        if (t == NULL)
        {
            printf("\n** No se encontro el postre en la posicion especificada.");
        }
    }
}

// G. Agregar ingredientes a un postre existente.
void agregar_ingredientes(Postre *postre, char *nombre)
{    Postre *p = postre;
    Ingre *w = NULL;
    Ingre *k = NULL;

    while (p != NULL && strcasecmp(p->Postre, nombre) != 0)
        p = p->liga;

    if (p != NULL)
    {
        char ingrediente[MAX_INGRE];
        int opc;

        do
        {
            printf(":: Ingrediente: ");
            fgets(ingrediente, sizeof(ingrediente), stdin);
            eliminarSaltoDeLinea(ingrediente);
            fflush(stdin);

            w = crearingre(ingrediente);
            k = p->lista_ingredientes;

            if (k == NULL)
            {
                p->lista_ingredientes = w;
                w->liga = NULL;
                k = w;
            }
            else
            {
                while (k->liga != NULL)
                    k = k->liga;

                k->liga = w;
                w->liga = NULL;
            }

            printf(":: Presione 1 para agregar otro ingrediente o cualquier otro número para terminar: ");
            scanf("%d", &opc);
            fflush(stdin);

        } while (opc == 1);

        printf(":: Ingredientes agregados exitosamente.\n");
        mostrar_postre(postre, nombre);
    }
    else
    {
        printf(":: El postre que desea no existe en la lista.\n");
        printf(":: No es posible agregar ingredientes.\n");
    }
}
// H. Eliminar ingredientes de un postre existente.
void eliminar_ingredientes(Postre *postre, char *nombre)
{
    Postre *t = NULL;
    Ingre *q = NULL;
    Ingre *anterior = NULL;
    char ingrediente[MAX_INGRE];
    int encontrado = 0;

    for (t = postre; t != NULL; t = t->liga)
    {
        if (strcasecmp(t->Postre, nombre) == 0)
        {
            printf("** Ingrediente a eliminar: ");
            fgets(ingrediente, sizeof(ingrediente), stdin);
            eliminarSaltoDeLinea(ingrediente);

            q = t->lista_ingredientes;
            anterior = NULL;
            encontrado = 0;

            while (q != NULL)
            {
                if (strcasecmp(q->Ingre, ingrediente) == 0)
                {
                    encontrado = 1;
                    if (anterior == NULL)
                    {
                        t->lista_ingredientes = q->liga;
                    }
                    else
                    {
                        anterior->liga = q->liga;
                    }
                    free(q);
                    break;
                }
                anterior = q;
                q = q->liga;
            }

            if (encontrado)
            {
                printf("** Ingrediente eliminado exitosamente.\n");
            }
            else
            {
                printf("** No se encontro el ingrediente especificado.\n");
            }

            return;
        }
    }

    printf("** No se encontro el postre especificado.\n");
}

int main()
{
    Postre *postre = NULL;
    int opc, pos;
    char nombre[MAX_POSTRE];

    do
    {
        system("cls");
        printf("\n\t\t**       MENU       **");
        printf("\n----------------------------------\n");
        printf("1. Dar de alta un postre con todos sus ingredientes.\n");
        printf("2. Mostrar todos los postres con sus ingredientes.\n");
        printf("3. Mostrar un postre con sus ingredientes.\n");
        printf("4. Agregar ingredientes a un postre existente.\n");
        printf("5. Eliminar ingredientes de un postre existente.\n");
        printf("6. Salir.\n");
        printf("----------------------------------\n");
        printf("** Opcion: ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            postre = agregarPostre(postre);
            printf("\n** Postre agregado exitosamente.\n");
            break;

        case 2:
            ListaPostre(postre);
            break;

        case 3:
            printf("** Ingrese la posicion del postre: ");
            scanf("%d", &pos);
            fflush(stdin);
            mostrar_postre(postre, pos);
            break;

        case 4:
            printf("** Ingrese el nombre del postre: ");
            fgets(nombre, sizeof(nombre), stdin);
            eliminarSaltoDeLinea(nombre);
            agregar_ingredientes(postre, nombre);
            break;

        case 5:
            printf("** Ingrese el nombre del postre: ");
            fgets(nombre, sizeof(nombre), stdin);
            eliminarSaltoDeLinea(nombre);
            eliminar_ingredientes(postre, nombre);
            break;

        case 6:
            printf("** Fin del programa.");
            break;

        default:
            printf("** Opcion no valida.\n");
            break;
        }

        printf("\n** Presione Enter para continuar...");
        getchar();

    } while (opc != 6);

    return 0;
}
