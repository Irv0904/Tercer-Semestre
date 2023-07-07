/*
	Name:Menu de listas enlazadas 
	Copyright:Todos los derecho reservados 
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Description: Este codigo se usa para hacer un menu de diferentes partes de listas enlazadas
	Calificacion:100 
*/

//23/05/23 14:24

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct cnodo
{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
nodo *comienzo();
nodo *nodoFinal (nodo *p);
void recursivo (nodo *p);
void iteractivo(nodo *p);
nodo *insertar_despues_x(nodo *p, int x, int ref);
nodo *insertar_antes_x(nodo *p, int x, int ref);
nodo *insertar_final(nodo *p, int x);
nodo *insertar_inicio(nodo *p,int x);
nodo *elmininar_x(nodo *p, int x);
nodo *eliminar_ultimo(nodo *p);
nodo *eliminar_primero(nodo *p);
nodo *eliminar_antes_x(nodo *p, int ref);
nodo *eliminar_despues_x(nodo *p,int ref);
nodo *busqueda_desordenada(nodo *p, int x);
nodo *busqueda_ordenada(nodo *p, int x);
nodo *busqueda_recursiva(nodo *p,int num);
nodo *cargarlista(nodo *p);
void guardarlista(nodo *p);
nodo *liberarMemoria(nodo *p);

int main()
{
	setlocale(LC_ALL,"");
	system("color 0F");
	nodo *p=NULL;
	int opc,lec,num;
	int x,j,k,ref;
	do
	{
		system("CLS");
		printf("\t\t\t******************\n\t\t\t*Listas Enlazadas*\n\t\t\t******************\n");
		printf("\n\t\t\t1->Crear\n\t\t\t2->Insertar\n\t\t\t3->Eliminar\n\t\t\t4->Busqueda\n");
		printf("\t\t\t5->Recorrer\n\t\t\t6->Guardar\n\t\t\t7->Cargar\n\t\t\t8->Liberar Memoria\n\t\t\t9->Salir \n\t\t\tRespuesta: ");
		j=scanf("%d", &opc);
		fflush(stdin);
		if(j==1)
		{
			switch(opc)
			{
				case 1:
					do
					{
						system("CLS");
						printf("\t\t\t**************\n\t\t\t*Crear Listas*\n\t\t\t**************\n");
						printf("\n\t\t\t1->Inicio\n\t\t\t2->Final\n\t\t\t3->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d",&lec);
						fflush(stdin);
						if(j==1)
						{
							system("CLS");
							switch(lec)
							{
								case 1:
									if(p==NULL)
									{
										p=comienzo();
										iteractivo(p);
										system("PAUSE");
										break;
									}
									else
									{
										printf("\n\t\t\tYA HAY UNA LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 2:
									if(p==NULL)
									{
										p=nodoFinal(p);
										iteractivo(p);
										system("PAUSE");
										break;
									}
									else
									{
										printf("\n\t\tYA HAY UNA LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 3:
									break;
								default:
									printf("\n\n\t\tLa selecciun fue incorrecto, intente de nuevo\n\n");
									system("PAUSE");
									break;
							}
						}
						else
						{
							printf("\n\n\t\tLa selecciun fue incorrecto, intente de nuevo\n\n");
							system("PAUSE");				
						}
					}while(lec!=3);
					break;
				case 2:
					do
					{
						system("CLS");
						printf("\t\t\t******************************\n\t\t\t*Insertar en listas enlazadas*\n\t\t\t******************************\n");
						printf("\n\t\t\t1->Inicio\n\t\t\t2->Final\n\t\t\t3->Antes de...");
						printf("\n\t\t\t4->Despues de...\n\t\t\t5->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d",& lec);
						fflush(stdin);
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("\nIngrese el numero: ");
										j=scanf("%d", &x);
										fflush(stdin);
										if(j==1)
										{
											p=insertar_inicio(p,x);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\t\tERROR NO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 2:
									if(p!=NULL)
									{
									
										iteractivo(p);
										printf("\nIngrese el numero: ");
										j=scanf("%d", &x);
										fflush(stdin);
										if(j==1)
										{
											p=insertar_final(p,x);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\t\tERROR NO ES UN NUMERO\n\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 3:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("\nIngrese el numero de referencia: ");
										k=scanf("%d",&ref);
										fflush(stdin);
										printf("\nIngrese el nuevo numero: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if((j==1)&&(k==1))
										{
											p=insertar_antes_x(p,x,ref);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\t\tERROR NO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}	
								case 4:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("Ingrese el numero de referencia: ");
										k=scanf("%d",&ref);
										fflush(stdin);
										printf("Ingrese el nuevo numero: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if((k==1)&&(j==1))
										{
											p=insertar_despues_x(p,x,ref);
											iteractivo(p);
											system("PAUSE");
											break;			
										}
										else
										{
											printf("\n\t\t\tERROR NO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
		
									}
									else
									{
										printf("\n\t\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 5:
									break;
								default:
									printf("\n\n\t\tLa selecciun fue incorrecto, intente de nuevo\n\n");
									system("PAUSE");
									break;
							}
						}
						else
						{
							printf("\n\n\t\tLa selecciun fue incorrecto, intente de nuevo\n\n");
							system("PAUSE");	
						}
					}while(lec!=5);	
					break;
				case 3:
					do
					{
						system("CLS");
						printf("\t\t\t******************************\n\t\t\t*Eliminar en listas enlazadas*\n\t\t\t******************************\n");
						printf("\n\t\t\t1->Primero\n\t\t\t2->Ultimo\n\t\t\t3->x");
						printf("\n\t\t\t4->Antes de...\n\t\t\t5->Despues de...");
						printf("\n\t\t\t6->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d",&lec);
						fflush(stdin);
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									if(p!=NULL)
									{
										p=eliminar_primero(p);
										iteractivo(p);
										system("PAUSE");
										break;
									}
									else
									{
										printf("\n\t\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 2:
									if(p!=NULL)
									{
										p=eliminar_ultimo(p);
										iteractivo(p);
										system("PAUSE");
										break;
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 3:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("\n\nIngrese el dato que va a eliminar ");
										j=scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p=elmininar_x(p,x);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\tERROR NO ES UN NUMERO\n\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n\n");
										system("PAUSE");
										break;
									}
								case 4:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("Ingrese el numero de referencia: ");
										j=scanf("%d",&ref);
										fflush(stdin);
										if(j==1)
										{
											p=eliminar_antes_x(p, ref);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\tERROR NO ES UN NUMERO\n\n");
											system("PAUSE");
											break;			
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n\n");
									}
								case 5:
									if(p!=NULL)
									{
										iteractivo(p);
										printf("Ingrese el numero de referencia: ");
										j=scanf("%d",&ref);
										fflush(stdin);
										if(j==1)
										{
											p=eliminar_despues_x(p, ref);
											iteractivo(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\tERROR NO ES UN NUMERO\n\n");
											system("PAUSE");
											break;			
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n\n");
									}							
								case 6:
									break;
								default:
									printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
									system("PAUSE");
									break;
							}
						}
						else
						{
							printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
							system("PAUSE");
						}	
					}while(lec!=6);
					break;
				case 4:
					do
					{	
						system("CLS");
						printf("\t\t\t******************************\n\t\t\t*Busqueda en listas enlazadas*\n\t\t\t******************************\n");
						printf("\n\t\t\t1->Desordenada\n\t\t\t2->Ordenada\n\t\t\t3->Recursiva\n\t\t\t4->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d",&lec);
						fflush(stdin);
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									if(p!=NULL)
									{
										iteractivo (p);
										printf("\nbuscar: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p=busqueda_desordenada(p,x);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\tNO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n");
										system("PAUSE");
										break;
									}
								case 2:
									if(p!=NULL)
									{
										iteractivo (p);
										printf("\nbuscar: ");
										j=scanf("%d",&num);
										fflush(stdin);
										if(j==1)
										{
										p=busqueda_ordenada(p,x);
										system("PAUSE");
										break;
										}
										else
										{
											printf("\n\t\tNO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n");
										system("PAUSE");
										break;
									}
								case 3:
									if(p!=NULL)
									{
										iteractivo (p);
										printf("\nbuscar: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
										p=busqueda_recursiva(p,x);
										system("PAUSE");
										break;
										}
										else
										{
											printf("\n\t\tNO ES UN NUMERO\n");
											system("PAUSE");
											break;
										}
									}
									else
									{
										printf("\n\t\tNO HAY LISTAS\n");
										system("PAUSE");
										break;
									}
								case 4:	
									break;
								default:
									printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
									system("PAUSE");
									break;					
							}
						}
						else
						{
							printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
							system("PAUSE");
						}
					}while(lec!=4);
					break;
				case 5:
					do
					{
						system("CLS");
						printf("\t\t\t******************************\n\t\t\t*Recorrer en listas enlazadas*\n\t\t\t******************************\n");
						printf("\n\t\t\t1->Iterativo\n\t\t\t2->recursivo\n\t\t\t3->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d", &lec);
						fflush(stdin);
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									iteractivo(p);
									system("PAUSE");
									break;
								case 2:
									recursivo(p);
									system("PAUSE");
									break;
								case 3:
									break;
								default:
									printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
									system("PAUSE");
									break;
							}
						}
						else
						{
							printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
							system("PAUSE");
						}
					}
					while(lec!=3);
					break;
				case 6:
					system("CLS");
					printf("\t\t\t**************************");
					printf("\n\t\t\t*Guardar Listas Enlazadas*\n");
					printf("\t\t\t**************************\n\n");
					guardarlista(p);
					system("PAUSE");
					break;
				case 7:
					system("CLS");				
					printf("\t\t\t*************************");
					printf("\n\t\t\t*Cargar Listas Enlazadas*\n");
					printf("\t\t\t*************************\n\n");
					p=cargarlista(p);
					system("PAUSE");
					break;
				case 8:
					system("CLS");
					p=liberarMemoria(p);
					system("PAUSE");
					break;
				case 9:
					p=liberarMemoria(p);
					break;
				default:
					printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
					system("PAUSE");
					break;			
			}
		}
		else
		{
			printf("\n\nLa selecciun fue incorrecto,intente de nuevo\n\n");
			system("PAUSE");	
		}
	}while(opc!=9);
}

void *creaMemoria(int n)
{
	void *p=(int *)malloc(n);
	if(p==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}

void recursivo (nodo *p)
{
	if(p != NULL)
	{
		printf("%5d->",p->num);
		if(p->liga!=NULL)
		{
			recursivo (p->liga);
		}
		else
		{
			printf("%s",p->liga);
		}
	}
	else
		printf("\n*****Lista Vacia...*****\n");	
}

void iteractivo(nodo *p)
{
	nodo *q;
	if(p!=NULL)
	{
		printf("\n");
		for(q=p;q!=NULL;q=q->liga)
		{
			printf("%5d->", q->num);
		}
		printf("%s", q);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n\n");
	return;
}

nodo *liberarMemoria(nodo *p)
{
	nodo *q=NULL;
	if(p!=NULL)
	{
		while(p!=NULL)
		{
			q=p;
			p=p->liga ;
			q->liga= NULL;
			free(q);
		}
		
		printf("\n\n\t\t*****MEMORIA LIBERADA...*****\n\n");
	}
	else
	{
		
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	}
	//free(p);	
	return p;
}

nodo *comienzo()
{
	int num,j;
	nodo *p, *q;
	p = creaNodo();
	printf("Ingrese un numero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1)
	{
		p ->num = num;
		p -> liga=NULL;	
		
		do
		{
		q= creaNodo();
		printf("Ingrese un numero, para salir ingrese una letra: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1)
		{
			q->num = num;
			q->liga=p;
			p=q;
		}
		else
		{
			free(q);
			break;
		}
		}while(j ==1);
		printf("\n*****Creando Listas enlazada...*****\n");
		printf("\n");
		q=p;
		return p;
	}
	else
	{
		free(p);
		return (NULL);
	}	
}

nodo *nodoFinal (nodo *p)
{
	int j,num;
	nodo *l,*q;
	p=creaNodo();
	printf("Ingrese un numero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1)
	{
		p->num=num;
		p->liga=NULL;
		l=p;
		do
		{
			q=creaNodo();
			printf("Ingrese un numero, para salir ingrese una letra: ");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1)
			{
				q->num=num;
				q->liga=NULL;
				l->liga=q;
				l=q;
			}
			else
			{
				free(q);
				break;
			}
		}while(j==1);
		printf("\n*****Creando Listas enlazada...*****");
		printf("\n");
		return p;
	}
	else
	{
		free(p);
		return(NULL);
	}
}

nodo *insertar_inicio(nodo *p, int x) 
{
	nodo *q;
	q=creaNodo();
	q->liga=p;
	q->num=x;
	p= q;
	printf("\n\t*****Ingresando nuevo dato al inicio...*****\n");
	return p;
}

nodo *insertar_final(nodo *p,int x) 
{
	nodo *q,*l;
	l=p;
	q=creaNodo();
	while(l->liga!=NULL)
	{
		l=l->liga;
	}
	q->num=x;
	q->liga=NULL;
	l->liga=q;
	printf("\n\t*****Ingresando el nuevo dato al final...*****\n");
	return p;
}

nodo *insertar_despues_x(nodo *p, int x, int ref)
{
	nodo *q,*l;
	int band=1;
	q=p;
	while((q->num!=ref)&&(band==1))
	{
		if(q->liga!=NULL)
		{
			q=q->liga;
		}
		else
		{
			band=0;
		}
	}
	if(band==1)
	{
		l=creaNodo();
		l->num=x;
		l->liga=q->liga;
		q->liga=l;
	}
	else
	{
		printf("\ndado como referencia es nulo\n");
	}
	
	return p;	
}

nodo *insertar_antes_x(nodo *p,int x,int ref)
{
	nodo *q,*l,*k;
	int band=1;
	q=p;
	while((q->num!=ref)&&(band==1))
	{
		if(q->liga!=NULL)
		{
			l=q;
			q=q->liga;
		}
		else
		{
			band=0;
		}	
	}
	if(band==1)
	{
		k=creaNodo();
		k->num=x;
		if(p==q)
		{
			k->liga=p;
			p=k;
		}
		else
		{
			l->liga=k;
			k->liga=q;
		}
	}
	else
		printf("El nodo dado no se encuentra");
	
	return p;
}

nodo *elmininar_x(nodo *p, int x)
{
	nodo *q,*l;	
	int band =1;
	q=p;
	while((q->num!=x)&&(band == 1))
	{
		if(q->liga!=NULL)
		{
			l=q;
			q=q->liga;
		}
		else
			band=0;	
	}
	if(band==0)
		printf("\n\nEl dato %d no se encuentra para eliminar\n",x);
	else
	{
		if(p==q)
			p=q->liga;
		else
		{
			l->liga=q->liga;
			printf("\n\t*****Actualizando lista enlazada...*****\n");
		}
	}
	free(q);
	return(p);
					
}

nodo *eliminar_primero(nodo *p)
{
	nodo *q,*l;
	q=p;
	printf("\n\t*****Elminando el primer nodo...*****\n");
	p=q->liga;
	free(q);
	return(p);

}

nodo *eliminar_despues_x(nodo *p, int ref) 
{
	nodo *q,*l,*t;
	int band=1;
	q=p;
	while((q->num !=ref)&&(band==1))
	{
		if(q->liga!=NULL)
		{
			l=q;
			q=q->liga;
		}
		else
		{
			band=0;
			break;
		}
	}
	if(band==0)
		printf("No existe numero despues...");
	else
	{					
		t=q;
		q=q->liga;
		if(t->liga!=NULL)
		{
			t->liga=q->liga;
			q->liga=t;
			free (q);
		}
		else
		{
			printf("\nNo hay numero despues de la referencia\n");
			
		}
		
	}
	return p;
}

nodo *eliminar_ultimo(nodo *p)
{
	nodo *q,*l;
	q=p;
	printf("\n\n\t*****Eliminado el ultimo nodo...*****\n\n");
	fflush(stdin);
    if(p->liga==NULL) 
        p=NULL;
    else
	{
    	while(q->liga!=NULL)
		{
			l=q;
			q=q->liga;
		}
		l->liga=NULL;
	}
	free(q);
	return(p);
}

nodo *eliminar_antes_x(nodo *p, int ref)
{
	nodo *q,*l,*a;
	int band=1;
		if(p->num==ref)
		{
			printf("\nNo hay numero antes de la referencia\n");
		}
		else
		{
			q=p;
			l=p;
			while((q->num!=ref)&&(band==1))
			{
				if(q->liga!=NULL
				){
					a=l;
					l=q;
					q=q->liga;
				}
				else
					band=0;
			}
			if(band==0)
			{
				printf("no");
			}
			else
			{
				if(p->liga==q)
					p=q;
				else
					a->liga=q;
				free(l);
			}
		}
	return p;
}

nodo *busqueda_recursiva(nodo *p,int num) 
{
	if(p!=NULL)
	{
	
		if(p->num==num)
			printf("\nEl numero %d Si esta en la lista\n\n",num);
		else 
			busqueda_recursiva(p->liga,num);
	}
	else	
		printf("\nEl numero %d NO esta en la lista\n\n", num); 
			
	return(p);
}

nodo *busqueda_ordenada(nodo *p, int x) 
{
	nodo *q;	
	q=p;

	while((q!=NULL)&&(q->num != x))
	{
		q=q->liga;
	}
	if((q==NULL) || (q->num<x))
	{
		printf("\nEl numero %d NO esta en la lista\n\n",x);
	}
	else
		printf("\nEl numero %d SI esta en la lista\n\n",x);
	return(p);
}

nodo *busqueda_desordenada(nodo *p, int x) 
{
	nodo *q;	
	q=p;
	while((q!=NULL)&&(q->num != x))
	{
		q=q->liga;
	}
	if(q==NULL)
	{
		printf("\nEl numero %d NO esta en la lista\n\n", x);
	}
	else
		printf("\nEl numero %d SI esta en la lista\n\n", x);
	return(p);
}


void guardarlista(nodo *p)
{
	nodo *q =p;
	char archivo[20];
	FILE *fp;
	
	printf("Introduzca el nombre del archivo: ");
	scanf("%s",archivo);
	fflush(stdin);
	if ( (fp = fopen(archivo,"wb")) == NULL )
	{
		printf("\n No se puede abrir el archivo: %s",archivo);
		exit(1);
	}
	
	q= p;
	while ( q != NULL)
	{
		printf("\n Guardando la lista... \n");
		fwrite(q, sizeof(nodo),1,fp);
		q = q->liga;
	}
	fclose(fp);
}

nodo *cargarlista(nodo *p)
{
	nodo *q, *l;
	char archivo[20];
	
	int z, op, e;
	FILE *fp;
	
	printf("Introduzca el nombre del archivo que desea leer: ");
	scanf("%s",archivo);
	fflush(stdin);
	if ( (fp = fopen(archivo,"rb")) == NULL )
	{
		printf("\n No existe el archivo: %s",archivo);
		exit(1);
		e= 1;
	}
	 
	if ( e != 1)
	{
		
		printf("\n La lista actual se elimina para cargar la del archivo");
		printf("\nDesea continuar presione el numero uno 1: ");
		scanf("%d",&op);
		fflush(stdin);
		
		if ( op == 1 )
		{
			while( p != NULL )
			{
				q=p;
				p=p->liga;
				free(q);
			}	 
			printf("\n Cargando la lista . . . ");
			p = creaNodo();
			q = p;	 
			while ( ! feof(fp))
			{
				if ( 1 != fread(q,sizeof(nodo),1,fp))	
				break;
				q->liga = creaNodo();
				l = q;
				q = q->liga;
			}	 
			l->liga=NULL;
			free(q);
			fclose(fp);	 
		}
	}
	return(p);
}
