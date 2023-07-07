/*
	Name:Crear Arbol con dintistos recorrido
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Description: Este codigo se usa para hacer un arbol con distinto recorridos
	Calificacion:
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct datos
{
    int info;
    struct datos *ligader;
    struct datos *ligaizq;
}Arbol;

typedef enum{false, true} bool;

void *crearMemoria(int n);
Arbol *creaNodo();

Arbol *creaArbol(Arbol *apNodo);

void preOrden(Arbol *apNodo);
void inOrden(Arbol *apNodo);
void posOrden(Arbol *apNodo);

Arbol *busqueda_ABB(Arbol *apNodo, int info);
Arbol *busqueda_v1_ABB(Arbol *apNodo, int info);

Arbol *insercion_ABB(Arbol *apNodo, int info);
Arbol *insercion_v1_ABB(Arbol *apNodo, int info);

Arbol *eliminacion_ABB(Arbol **apNodo, int info);


int main()
{
    Arbol *apNodo = NULL;
    int info , resp, subdato;
    do
    {
        system("CLS");
        printf("\t\t\t*****************\n\t\t\t*Menu de Arboles*\n\t\t\t*****************\n");
        printf("\t\t\t1->Crear\n\t\t\t2->Ingresar\n\t\t\t3->Eliminar\n\t\t\t4->Busqueda\n\t\t\t5->Salir\n\t\t\tRespuesta: ");
        scanf("%d", & resp);
        fflush(stdin);
        switch (resp)
        {
            case 1:
                system("CLS");
                apNodo = creaNodo();
                printf("Ingrese La raiz principal: ");
                apNodo=creaArbol(apNodo);
                printf("\nArbol en PreOrden\n\n");
                preOrden(apNodo);
                printf("\n\nArbol en InOrden\n\n");
                inOrden(apNodo);
                printf("\n\nArbol en PosOrden\n\n");
                posOrden(apNodo);
                printf("\n");
                system("PAUSE");
                break;
            case 2:
                system("CLS");
                printf("Insercion en un arbol, elija una opcion");
                printf("\n1->Insercion\n2->Insercion v1\n3->Salir\nRespuesta: ");
                scanf("%d",&subdato);
                fflush(stdin);
                switch (subdato)
                {
                    do
                    {
                        case 1:
                            printf("\n\nIngrese la informacion a ingresar: ");
                            scanf("%d", &info);
                            fflush(stdin);
                            apNodo = insercion_ABB(apNodo, info);
                            printf("\nArbol en PreOrden\n\n");
                            preOrden(apNodo);
                            printf("\n\nArbol en InOrden\n\n");
                            inOrden(apNodo);
                            printf("\n\nArbol en PosOrden\n\n");
                            posOrden(apNodo);
                            printf("\n");
                            system("PAUSE");
                            break;
                        case 2:
                            printf("\n\nIngrese la informacion a ingresar: ");
                            scanf("%d", &info);
                            fflush(stdin);
                            apNodo = insercion_v1_ABB(apNodo, info); 
                            printf("\nArbol en PreOrden\n\n");
                            preOrden(apNodo);
                            printf("\n\nArbol en InOrden\n\n");
                            inOrden(apNodo);
                            printf("\n\nArbol en PosOrden\n\n");
                            posOrden(apNodo); 
                            printf("\n");
                            system("PAUSE");
                            break;
                        case 3:
                            break;
                        default:
                            printf("ERROR, el dato ingresado es incorrecto");
                            break;
                    }while(subdato != 3);
                    break;
                }
                break;
            case 3:
                system("CLS");
                printf("\n\nIngrese la informacion a eliminar: ");
                scanf("%d", &info);
                fflush(stdin);
                eliminacion_ABB(&apNodo, info);
                printf("\nArbol en PreOrden\n\n");
                preOrden(apNodo);
                printf("\n\nArbol en InOrden\n\n");
                inOrden(apNodo);
                printf("\n\nArbol en PosOrden\n\n");
                posOrden(apNodo);  
                printf("\n");
                system("PAUSE");
                break;
            case 4:
                system("CLS");
                printf("Busqueda en arbol, elija una opcion");
                printf("\n1->Busqueda\n2->Busqueda v1\n3->Salir\nRespuesta: ");
                scanf("%d",&subdato);
                fflush(stdin);
                switch (subdato)
                {
                    do
                    
                    {
                        case 1:
                            printf("\n\nIngrese la informacion a buscar: ");
                            scanf("%d", &info);
                            fflush(stdin);
                            apNodo = busqueda_ABB(apNodo,info);
                            system("PAUSE");
                            break;
                        case 2:
                            printf("\n\nIngrese la informacion a buscar: ");
                            scanf("%d", &info);
                            fflush(stdin);
                            apNodo = busqueda_v1_ABB(apNodo,info);
                            system("PAUSE");
                            break;
                        case 3:
                            break;
                        default:
                            printf("ERROR, el dato ingresado es incorrecto");
                            break;
                    }while(subdato != 3);
                    break;
                }
                break;
            case 5:
                break;
            default:
                break;
        }
    }while(resp != 5);
}

void *crearMemoria(int n)
{
    void *p = (int *)malloc(n);
    if(p == NULL)
    {
        printf("NO HAY MEMORIA, PARA CREAR NODO");
        getchar();
        exit(1);
    }
    return p;
}

Arbol *creaNodo()
{
    return(Arbol *)crearMemoria(sizeof(Arbol));
}

void preOrden(Arbol *apNodo)
{
    if(apNodo != NULL)
    {
        printf("%5d ",apNodo->info);
        preOrden(apNodo->ligaizq);
        preOrden(apNodo->ligader);
    }
}

void inOrden(Arbol *apNodo)
{
    if(apNodo != NULL)
    {
        inOrden(apNodo->ligaizq);
        printf("%5d ",apNodo->info);
        inOrden(apNodo->ligader);
    }
}

void posOrden(Arbol *apNodo)
{
    if(apNodo != NULL)
    {
        posOrden(apNodo->ligaizq);
        posOrden(apNodo->ligader);
        printf("%5d ",apNodo->info);
    }
}

Arbol *creaArbol(Arbol *apNodo)
{
    Arbol *otroArbol;
    int resp;

    scanf("%d", &(apNodo->info));

    printf("\nExiste nodo por izquierda de %d?\n1->Si \t 2->No: ",apNodo->info);
    scanf("%d", &resp);
    fflush(stdin);
    if (resp == 1) 
    {
        otroArbol = creaNodo();
        printf("\nIngrese la informacion del nodo: ");
        apNodo->ligaizq =otroArbol;
        creaArbol(apNodo->ligaizq);
    } 
    else 
    {
        apNodo->ligaizq = NULL;
    }

    printf("\nExiste nodo por derecha de %d?\n1->Si \t 2->No: ", apNodo->info);
    scanf("%d", &resp);
    fflush(stdin);
    if (resp == 1) 
    {
        otroArbol = creaNodo();
        printf("\nIngrese la informacion del nodo: ");
        apNodo->ligader = otroArbol;
        creaArbol(apNodo->ligader);
    } 
    else
    {
        apNodo->ligader = NULL;
    }

    return apNodo;
}

Arbol *busqueda_ABB(Arbol *apNodo, int info)
{
    if(info < apNodo->info)
    {
        if(apNodo->ligaizq == NULL)
            printf("\nLa informacion dada no se encuentra en el arbol\n");
        else
            busqueda_ABB(apNodo->ligaizq, info);
    }
    else
    {
        if(info > apNodo->info)
        {
            if(apNodo->ligader == NULL)
            printf("\nLa informacion dada no se encuentra en el arbol\n");
            else
            busqueda_ABB(apNodo->ligader, info);
        }
        else
            printf("\nLa informacion dada si esta en el arbol\n");
    }
    return apNodo;
}

Arbol *busqueda_v1_ABB(Arbol *apNodo, int info)
{
    if(apNodo != NULL)
    {
        if(info < apNodo->info)
            busqueda_v1_ABB(apNodo->ligaizq, info);
        else
        {
            if(info > apNodo->info)
            busqueda_v1_ABB(apNodo->ligader, info);
            else
            printf("\nLa inforamacion dada si se encuentra en el arbol\n");
        }
    }
    else
        printf("\nLa informacion dada no se encuentra en el Arbol\n");

    return apNodo;
}

Arbol *insercion_ABB(Arbol *apNodo, int info)
{
    if(info < apNodo->info)
    {
        if(apNodo->ligaizq == NULL)
        {
         Arbol *otroArbol = creaNodo();
            otroArbol->ligaizq = NULL;
            otroArbol->ligader = NULL;
            otroArbol->info = info;
            apNodo->ligaizq = otroArbol;
        }
        else
            insercion_ABB(apNodo->ligaizq, info);
    }
    else
    {
        if(info > apNodo->info)
        {
            if(apNodo->ligader == NULL)
            {
                Arbol *otroArbol = creaNodo();
                otroArbol->ligaizq = NULL;
                otroArbol->ligader = NULL;
                otroArbol->info = info;
                apNodo->ligader = otroArbol;
            }
            else
            insercion_ABB(apNodo->ligader, info);
        }
        else
            printf("\nLa informacion dada ya se encuentra en el Arbol\n");
    }
    return apNodo;
}

Arbol* insercion_v1_ABB(Arbol* apNodo, int info)
{
    if (apNodo != NULL)
    {
        if (info < apNodo->info)
            apNodo->ligaizq = insercion_v1_ABB(apNodo->ligaizq, info);
        else if (info > apNodo->info)
            apNodo->ligader = insercion_v1_ABB(apNodo->ligader, info);
        else
            printf("La informacion dada ya se encuentra en el arbol\n");
    }
    else
    {
        Arbol* otroArbol = creaNodo();
        otroArbol->ligaizq = NULL;
        otroArbol->ligader = NULL;
        otroArbol->info = info;
        apNodo = otroArbol;
    }
    return apNodo;
}
Arbol* eliminacion_ABB(Arbol **apNodo, int info)
{
    if (*apNodo == NULL)
    {
        printf("La información dada para eliminar no se encuentra en el árbol");
        return NULL;
    }

    if (info < (*apNodo)->info)
        (*apNodo)->ligaizq = eliminacion_ABB(&((*apNodo)->ligaizq), info);
    else
    {
        if (info > (*apNodo)->info)
            (*apNodo)->ligader = eliminacion_ABB(&((*apNodo)->ligader), info);
        else
        {
            Arbol *otroArbol = *apNodo;
            if (otroArbol->ligader == NULL)
                *apNodo = otroArbol->ligaizq;
            else
            {
                if (otroArbol->ligaizq == NULL)
                    *apNodo = otroArbol->ligader;
                else
                {
                    Arbol *arbolAux = otroArbol->ligaizq;
                    Arbol *arbolAux_1 = NULL;
                    bool bo = false;
                    while (arbolAux->ligader != NULL)
                    {
                        arbolAux_1 = arbolAux;
                        arbolAux = arbolAux->ligader;
                        bo = true;
                    }
                    if (bo)
                        arbolAux_1->ligader = arbolAux->ligaizq;
                    else
                        (*apNodo)->ligaizq = arbolAux->ligaizq;
                }
            }
            free(otroArbol);
        }
    }
    return *apNodo;
}