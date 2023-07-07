/*
	Name:Menu de una agenda telefonica
	Copyright:Todos los derecho reservados 
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Calificacion: 91
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agenda
{
   char contact [20];
   char number [10];
   char correo [50];
   struct agenda *liga;
}Contacto;

Contacto *creaNodo(char contact[], char number[], char correo[]);
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
      system("CLS");
      printf("\t*****Agenda Telefonica*****\n");
      printf("1->Ingresar\n2->Eliminar\n3->Buscar\n4->Liberar\n5->Ordenar\n6->Mostrar\n7->Salir\nRespuesta: ");
      scanf("%d", &menu);
      fflush(stdin);
      switch(menu)
      {
         case 1:
            listaContacto = ingresarContacto(listaContacto);
            system("CLS");
            recorrerContacto(listaContacto);
            system("PAUSE");
            break;
         case 2:
            system("CLS");
            recorrerContacto(listaContacto);
            listaContacto = eliminarContacto(listaContacto);
            system("CLS");
            recorrerContacto(listaContacto);
            system("PAUSE");
            break;
         case 3:
            system("CLS");
            recorrerContacto(listaContacto);
            listaContacto = buscarContacto(listaContacto);
            system("PAUSE");
            break;
         case 4:
            listaContacto = liberarContacto(listaContacto);
            system("PAUSE");
            break;
         case 5:
            system("CLS");
            ordenarContacto(listaContacto);
            recorrerContacto(listaContacto);
            system("PAUSE");
            break;
         case 6:
            system("CLS");
            recorrerContacto(listaContacto);
            system("PAUSE");
            break;
         case 7:
            break;
         default:
            printf("Error, Opcion escogida no se encuentra\n");
      }
   }while(menu != 7);
   return 0;
}

Contacto *creaNodo(char contact[], char number[], char correo[])
{
   Contacto * nuevoContacto = (Contacto *)malloc(sizeof(Contacto));
   strcpy(nuevoContacto->contact, contact);
   strcpy(nuevoContacto->number, number);
   strcpy(nuevoContacto->correo,correo);
   nuevoContacto->liga = NULL;
   return nuevoContacto;
}

Contacto *ingresarContacto(Contacto *listaContacto)
{
   char number[10];
   char contact[50];
   char correo[100];

   printf("Ingrese el nombre del contacto: ");
   scanf("%s", contact);

   printf("Ingrese el numero de celular: ");
   scanf("%s", number);

   printf("Ingrese el correo electronico: ");
   scanf("%s", correo);

   Contacto* nuevoContacto = creaNodo(contact,number,correo);

   if(listaContacto == NULL)
      return nuevoContacto;
   else
   {
      Contacto* contactoActual = listaContacto;
      while(contactoActual->liga != NULL)
      {
         contactoActual = contactoActual->liga;
      }
      contactoActual->liga = nuevoContacto;

      return listaContacto;
   }
}

Contacto *eliminarContacto(Contacto *listaContacto)
{
   if(listaContacto == NULL)
   {
      printf("Lista Vacia\n");
      return NULL;
   }

   char contact[50];

   printf("Ingrese el nombre para eliminar: ");
   scanf("%s", contact);

   Contacto *anteriorContacto = NULL;
   Contacto *contactoActual = listaContacto;

   while (contactoActual != NULL)
   {
      if(strcmp(contactoActual->contact, contact)==0)
      {
         if(anteriorContacto == NULL)
         {
            listaContacto = contactoActual->liga;
         }
         else
         {
            anteriorContacto->liga = contactoActual->liga;
         }
         free(contactoActual);
         printf("Contacto eliminado Satisfactoriamente\n");
         return listaContacto;
      }
      anteriorContacto = contactoActual;
      contactoActual = contactoActual->liga;
   }
   printf("El nombre sel contacto no se encuentra\n");
   return listaContacto;
}

void recorrerContacto(Contacto *listaContacto)
{
   if(listaContacto == NULL)
   {
      printf("Agenda Vacia\n");
      return;
   }

   Contacto *contactoActual = listaContacto;
   printf("La lista de contactos son:\n\n");
   while(contactoActual != NULL)
   {
      printf("Nombre del contacto: %s\n", contactoActual->contact);
      printf("Numero de contacto: %s\n", contactoActual->number);
      printf("Correo Electronico: %s\n", contactoActual->correo);
      printf("\n*****************************\n\n");
      contactoActual = contactoActual->liga;
   }
}

void ordenarContacto(Contacto *listaContacto)
{
   int intercambioContacto ;
   Contacto *contactoActual;
   Contacto *siguienteContacto = NULL;

   if(listaContacto == NULL)
   {
      return;
   }

   do
   {
      intercambioContacto = 0;
      contactoActual = listaContacto;
      while(contactoActual->liga != siguienteContacto)
      {
         if(strcmp(contactoActual->contact, contactoActual->liga->contact) > 0)
         {
            char contactTemporal[50];
            char contactTelefono[20];
            char contactCorreo[50];
            strcpy(contactTemporal, contactoActual->contact);
            strcpy(contactTelefono, contactoActual->number);
            strcpy(contactCorreo, contactoActual->correo);

            strcpy(contactoActual->contact, contactoActual->liga->contact);
            strcpy(contactoActual->number, contactoActual->liga->number);
            strcpy(contactoActual->correo, contactoActual->liga->correo);

            strcpy(contactoActual->liga->contact, contactTemporal);
            strcpy(contactoActual->liga->number, contactTelefono);
            strcpy(contactoActual->liga->correo, contactCorreo);

            intercambioContacto = 1;
         }
         contactoActual = contactoActual->liga;
      }
      siguienteContacto = contactoActual;
   } while (intercambioContacto);
   
}

Contacto *buscarContacto(Contacto *listaContacto)
{
   if(listaContacto == NULL)
   {
      printf("Lista Vacia");
      return NULL;
   }

   char contact[50];
   printf("Ingrese el nombre a buscar: ");
   scanf("%s", contact);

   Contacto *contactoActual = listaContacto;

   while(contactoActual != NULL)
   {
      if(strcmp(contactoActual->contact, contact)==0)
      {
         printf("Contacto encontrado: \n\n");
         printf("Nombre: %s\n",contactoActual->contact);
         printf("Telefono: %s\n",contactoActual->number);
         printf("Correo Electronico: %s\n",contactoActual->correo);
         return contactoActual;         
      }
      contactoActual = contactoActual->liga;
   }
   printf("El contacto llamado %s no se encontro\n",contact);
   return NULL;
}

Contacto *liberarContacto(Contacto *listaContacto)
{
   Contacto *contactoActual = listaContacto;
   while(contactoActual != NULL)
   {
      Contacto *siguienteContacto = contactoActual->liga;
      free(contactoActual);
      contactoActual = siguienteContacto;
   }
   return NULL;
}
