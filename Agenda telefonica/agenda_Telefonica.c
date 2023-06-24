#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agenda
{
   char contact [20];
   char number [10];
   struct agenda *liga;
}Contacto;

Contacto *creaNodo(char contact[], char number[]);
void recorrerContacto(Contacto *listaContacto);
Contacto *liberarContacto(Contacto *listaContacto);
void ordenarContacto(Contacto *listaContacto);

Contacto *ingresarContacto(Contacto *listaContacto);
Contacto *eliminarContacto(Contacto *listaContacto);
Contacto *buscarContacto(Contacto *listaContacto);

int main()
{
   int menu;
   Contacto *listaContacto = NULL;

   do
   {
      printf("\t*****Agenda Telefonica*****\n");
      printf("1->Ingresar\n2->Eliminar\n3->Buscar\n4->Liberar\n5->Ordenar\n6->Salir");
      scanf("%d", &menu);
      fflush(stdin);
      switch(menu)
      {
         case 1:
            ingresarContacto(listaContacto);
            break;
         case 2:
            eliminarContacto(listaContacto);
            break;
         case 3:
            buscarContacto(listaContacto);
            break;
         case 4:
            liberarContacto(listaContacto);
            break;
         case 5:
            ordenarContacto(listaContacto);
            break;
         case 6:
            break;
         default:
            printf("Error, Opcion escogida no se encuentra\n");
      }
   }while(menu != 6);
}

Contacto *creaNodo(char contact[], char number[])
{
   Contacto * nuevoContacto = (Contacto *)malloc(sizeof(Contacto));
   strcpy(nuevoContacto->contact, contact);
   strcpy(nuevoContacto->number, number);
   nuevoContacto->liga = NULL;
   return nuevoContacto;
}

Contacto *ingresarContacto(Contacto *listaContacto)
{
   char number[10];
   char contact[50];

   printf("Ingrese el nombre del contacto: ");
   scanf("%s", &contact);

   printf("Ingrese el numero de celularL: ");
   scanf("%s", &number);

   Contacto* nuevoContacto = creaNodo(number,contact);

   Contacto* contactoActual = listaContacto;
   while(contactoActual->liga != NULL)
   {
      contactoActual = contactoActual->liga;
   }
   contactoActual->liga = nuevoContacto;

   return listaContacto;
}