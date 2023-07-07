/*
	Name: Menu de listas doble
	Nota: 100
	Author: Irving Jhon Villarreal Lasso
	Date: 30/05/23 14:13
	Description: Se realizo un menu de todas la lista simple
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct cnodo{
	int num;
	struct cnodo *ligader;
	struct cnodo *ligaizq;
};

typedef struct cnodo nodo;


void *creaMemoria(int n);
nodo *creaNodo();
nodo *ciniciodb(int x);
nodo *cfinaldb(int x);

nodo *insertarPrimero(nodo *p,int x);
nodo *insert_final(nodo *p, nodo *f,int x);
nodo *inserta_antes_x(nodo *p, int ref, int x);
nodo *inserta_despues_x(nodo *p, int ref, int x);

nodo *eliminarPrimero(nodo *p,nodo *f);
nodo *eliminarFinal(nodo *p,nodo *f);
nodo *eliminar_antes_x(nodo *p, nodo *f, int x);
nodo *eliminar_despues_x(nodo *p,nodo *f,int x);
nodo *eliminar_x(nodo *p,nodo *f, int x);

nodo *cargarlistaFinal(nodo *p);
void guardarlistader(nodo *p);
nodo *cargarlistaInicio(nodo *p);

nodo *buscarUltimo(nodo *p);

void recorreiterativoizq(nodo *p);
void recursivoizq (nodo *p);
void recursivoder (nodo *p);
void recorreiterativoder(nodo *p);

nodo *liberamemoriadb(nodo *p);

int main()
{
	int opc, lec,x,ref;
	int j,k;
	setlocale(LC_ALL,"");
	system("color 0F");
	nodo *p = NULL;
	nodo *f = NULL;
	do
	{
		system("CLS");
		printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<\n");
		printf("\t\t\t|Listas Enlazadas dobles|\n");
		printf("\t\t\t>->->->->->->->->->->->->\n");
		printf("\n\t\t\t1->Crear\n\t\t\t2->Insertar\n\t\t\t3->Eliminar\n\t\t\t4->Guardar\n\t\t\t5->Cargar");
		printf("\n\t\t\t6->Liberar\n\t\t\t7->Recorrer\n\t\t\t8->Salir\n\t\t\tRespuestas: ");
		j=scanf("%d",& opc);
		fflush(stdin);
		if(j==1)
		{
			switch(opc)
			{
				case 1:
					do
					{
						system("CLS");
						printf("\t\t\t>->->->->->->->->->->\n");
						printf("\t\t\t|Crear Listas Dobles|\n");
						printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<\n");
						printf("\n\t\t\t1->Inicio\n\t\t\t2->Final\n\t\t\t3->Regresar\n\t\t\tRespuestas: ");
						j=scanf("%d",&lec);
						fflush(stdin);
						system("CLS");
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									if(p==NULL)
									{
										printf("Ingrese el numero, letra para terminar: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p = ciniciodb(x);
											f = buscarUltimo(p);
											recorreiterativoder(p);
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
										printf("\n\t\t\tYA HAY UNA LISTA\n");
										system("PAUSE");
										break;
									}
								case 2:
									if(p==NULL)
									{
										printf("Ingrese el numero, letra para terminar: ");
										j=scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p = cfinaldb(x);
											f = buscarUltimo(p);
											recorreiterativoder(p);
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
										printf("\n\t\t\tYA HAY UNA LISTA\n");
										system("PAUSE");
										break;
									}
								case 3:
									break;
								default:
									printf("\n\t\tDATO INGRESADO INCORRECTO\n");
									system("PAUSE");
									break;							
							}
						}
						else
						{
							printf("\n\t\t\tDATO INGRESADO INCORRECTO\n");
							system("PAUSE");
						}
					}while(lec!=3);
					break;
				case 2:
					do
					{
						if(p!=NULL)
						{
							system("CLS");
							printf("\t\t\t>->->->->->->->->->->->->->\n");
							printf("\t\t\t|Insertar en Listas Dobles|\n");
							printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<\n");
							printf("\n\t\t\t1->Inicio\n\t\t\t2->Final\n\t\t\t3->Antes de\n\t\t\t4->Despues de\n\t\t");
							printf("\t5->Regresar\n\t\t\tRepsuesta: ");
							j=scanf("%d",&lec);
							fflush(stdin);
							if(j==1)
							{
								switch(lec)
								{
									case 1:
										recorreiterativoder(p);
										printf("Ingre un numero: ");									
										j=scanf("%d",&x);
										fflush(stdin);									
										if(j==1)
										{										
											p=insertarPrimero(p,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("\n\t\tEL DATO QUE INGRESO ES INCORRECTO\n");
											system("PAUSE");
											break;
										}
									case 2:
										recorreiterativoder(p);
										printf("Ingrese un valor: ");
										j=scanf("%d",&x);
										if(j==1)
										{
											f=buscarUltimo(p);
											p=insert_final(p,f,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											system("CLS");
											printf("\t\t\tNO ES UN VALOR PARA EL NODO\n");
											system("PAUSE");
										}
									case 3:
										recorreiterativoder(p);
										printf("Ingrese el numero de referencia: ");
										scanf("%d",&ref);
										fflush(stdin);
										printf("Ingrese el nuevo numero: ");
										j = scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p=inserta_antes_x(p,ref,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("ERROR");
											system("PAUSE");
											break;
										}	
									case 4:
										recorreiterativoder(p);
										printf("Ingrese el numero de referencia: ");
										scanf("%d",&ref);
										fflush(stdin);
										printf("Ingrese el nuevo numero: ");
										j = scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p=inserta_despues_x(p,ref,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("ERROR");
											system("PAUSE");
											break;
										}
									case 5:
										break;								
								}		
							}
							else
							{
								system("CLS");
								printf("\t\tDATO INGRESADO ES INCORRECTO\n");
								system("PAUSE");
							}
						}
						else
						{
							system("CLS");
							printf("\t\t\tNO HAY LISTAS PARA INSERTAR\n");
							system("PAUSE");
							break;
						}
					}while(lec!=5);
					break;	
				case 3:
					do
					{
						if(p!=NULL)
						{
							system("CLS");
							printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<\n");
							printf("\t\t\t|Eliminar en Listas Dobles|\n");
							printf("\t\t\t>->->->->->->->->->->->->->\n");
							printf("\n\t\t\t1->Inicio\n\t\t\t2->Final\n\t\t\t3->Antes de\n\t\t\t4->Despues de\n\t\t");
							printf("\t5->x\n\t\t\t6->Regresar\n\t\t\tRepsuesta: ");
							j=scanf("%d",&lec);
							fflush(stdin);
							if(j==1)
							{
								switch(lec)
								{
									case 1:	
										recorreiterativoder(p);
										p=eliminarPrimero(p,f);
										printf("\nse elimino el número de la lista\n");
										recorreiterativoder(p);
										system("PAUSE");
										break;
									case 2:	
										recorreiterativoder(p);
										f=buscarUltimo(p);
										p=eliminarFinal(p,f);
										printf("\nse elimino el número de la lista\n");
										recorreiterativoder(p);
										system("PAUSE");
										break;
									case 3:	
										recorreiterativoder(p);
										printf("Ingrese el numero de referencia: ");
										scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											p=eliminar_antes_x(p,f,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("ERROR");
											system("PAUSE");
											break;
										}
									case 4:	
										recorreiterativoder(p);
										printf("Ingrese el numero de referencia: ");
										scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											f=buscarUltimo(p);
											p=eliminar_despues_x(p,f,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("ERROR");
											system("PAUSE");
											break;
										}
									case 5:	
										recorreiterativoder(p);
										printf("Ingrese el numero para eliminar: ");
										scanf("%d",&x);
										fflush(stdin);
										if(j==1)
										{
											f=buscarUltimo(p);
											p=eliminar_x(p,f,x);
											recorreiterativoder(p);
											system("PAUSE");
											break;
										}
										else
										{
											printf("ERROR");
											system("PAUSE");
											break;
										}
									case 6:
										break;
								}		
							}
							else
							{
								
								printf("\t\tDATO INGRESADO ES INCORRECTO\n");	
							}
						}
						else
						{
							system("CLS");
							printf("\t\t\tNO HAY LISTAS PARA ELIMINAR\n");
							system("PAUSE");
							break;	
						}
					}while(lec!=6);
					break;
				case 4:
					system("CLS");				
					printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<\n");
					printf("\t\t\t|Guardar Listas Dobles Enlazadas|\n");
					printf("\t\t\t>->->->->->->->->->->->->->->->->\n");
					guardarlistader(p);
					system("PAUSE");
					break;
				case 5:
					do{
						system("CLS");
						printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-\n");
						printf("\t\t\t|Cargar Listas Dobles Enlazadas|\n");
						printf("\t\t\t>->->->->->->->->->->->->->->->-\n");
						printf("\t\t\t1->Al inicio\n\t\t\t2->Al final\n\t\t\t3->Regresar\n\t\t\tRespuesta: ");
						j=scanf("%d", &lec);
						if(j==1)
						{
							switch(lec)
							{
								case 1:
									system("CLS");
									p=cargarlistaInicio(p);
									system("PAUSE");
									break;
								case 2:
									system("CLS");
									p=cargarlistaFinal(p);
									system("PAUSE");
									break;
								case 3:
									break;
							}
								
						}
						else
						{
							printf("\t\tDATO INGRESADO ES INCORRECTO\n");
							system("Pause");
						}
					}while(lec!=3);
					break;
				case 6:
					if(p!=NULL)
					{
						system("CLS");
						p=liberamemoriadb(p);
						printf("\n");
						system("PAUSE");
						break;
					}
					else
					{
						system("CLS");
						printf("\t\t\tNO HAY LISTAS PARA LIBERAR MEMORIA\n");
						system("PAUSE");
						break;
					}						
				case 7:
					do
					{
						if(p!=NULL)
						{
							system("CLS");
							printf("\t\t>->->->->->->->->->->->->->->->->->->\n");
							printf("\t\t|Recorrer en Listas Dobles Enlazadas|\n");
							printf("\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<\n\n");
							printf("\t\t\t1->Iterativo a la derecha\n\t\t\t2->Iterativo a la izquierda\n");
							printf("\t\t\t3->Recursivo a la derecha\n\t\t\t4->Recursivo a la izquierda\t\t\t\n");
							printf("\t\t\t5->Salir\n\t\t\tRespuesta: ");
							j=scanf("%d",&lec);
							fflush(stdin);
							if(j==1)
							{
								switch(lec)
								{
									case 1:
										recorreiterativoder(p);
										system("PAUSE");
										break;
									case 2:
										recorreiterativoizq(p);
										system("PAUSE");	
										break;
									case 3:
										printf("\n\t\t\t%s<-",p->ligaizq);
										recursivoder(p);
										printf("\n\n");
										system("PAUSE");											
										break;
									case 4:
										printf("\n\t\t\t%s<-",p->ligaizq);
										f=buscarUltimo(p);
										recursivoizq(f);
										printf("\n\n");
										system("PAUSE");											
										break;
									case 5:
										break;
								}
							}
							else
							{
								printf("\nDATO INGRESADO ES INCORRECTO\n");
								system("PAUSE");
								break;
							}
						}
						else
						{
							system("CLS");
							printf("\t\t\tNO HAY LISTAS PARA RECORRER\n");
							system("PAUSE");
							break;
						}	
					}while(lec!=5);
				
				case 8:
					break;
			}
		}
		else
		{
			printf("\n\t\t\tDATO INGRESADO INCORRECTO\n");
			system("PAUSE");
		}
	}while(opc!=8);
		
}

void *creaMemoria(int n)
{
	void *p = (int *)malloc(n);
	if(p==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}

nodo *ciniciodb(int x)
{
	nodo *p = NULL; nodo *f =NULL;
	int j;
	p = creaNodo();
	p->num = x;
	p->ligader = NULL;
	p->ligaizq = NULL;
	do
	{
		f=creaNodo();
		printf("Ingrese el numero, Letra para terminar: ");
		j = scanf("%d",&x);
		fflush(stdin);
		if(j == 1)
		{
			f->num=x;
			f->ligader=p;
			p->ligaizq=f;
			f->ligaizq=NULL;
			p=f;
		}
		else
		{
			free(f);
			break;
		}
	}while(j==1);

	return p;
}

nodo *cfinaldb(int x)
{

	nodo *p = NULL;
	nodo *t = NULL;
	nodo *f = NULL;
	int j;
	p = creaNodo();
	p->ligaizq = NULL;
	p->ligader = NULL;
	p->num = x;
	t = p;
	do
	{
		f = creaNodo();
		printf("Introduzca un numero, letra para terminar:");
		j = scanf("%d", &x);
		fflush(stdin);
		if (j == 1)
		{
			f->num = x;
			f->ligader = NULL;
			f->ligaizq = t;
			t->ligader = f;
			t = f;
		}
		else
		{
			free(f);
			break;
		}
	} while (j == 1);
	return p;
}

nodo *buscarUltimo(nodo *p)
{
	if(p!=NULL)
	{
		nodo *v=p;
		while(v->ligader!=NULL)
		{
			v = v->ligader;
		}
		return v;
	}
	return p;
}

void recorreiterativoder(nodo *p)
 {
	nodo *q;  
	if( p != NULL)
		{
			printf("\n");
			printf("\t\t\t%s<-",p->ligaizq);
		for( q=p; q != NULL; q=q->ligader)
	           printf("%d->",q->num);
			printf("%s",q);
		printf("\n\n");			
		}
	else
		    printf("\n\n\t\t La lista esta vacia");
	
	return;
 }

void recorreiterativoizq(nodo *p)
{
	nodo *q, *t;  
	if(p!=NULL)
	{
		q =p;
		printf("\n");	
		while (q->ligader != NULL)
		    q= q->ligader;	
		printf("\t\t\t%s<-",q->ligader);
		for( t= q; t != NULL; t=t->ligaizq)
	        printf("%d->",t->num);
		printf("%s",t);
		printf("\n\n");			
	}
	else
		printf("\n\n\t\t La lista esta vacia");
	return;
	
}

nodo *liberamemoriadb(nodo *p)
{
	nodo *v = NULL;
	if(p != NULL)
	{
		while(p!=NULL)
		{
			v = p;
			p = p->ligader;
			v->ligader = NULL;
			free(v);
		}
		printf("\n\t\t>->->->->->->->->-");
		printf("\n\t\t|Memoria Liberada|*");
		printf("\n\t\t<-<-<-<-<-<-<-<-<-");
	}
	else
		printf("\n\nLista vacia");
	return p;
}

nodo *insertarPrimero(nodo *p, int x)
{
	nodo *v =NULL;
	v = creaNodo();
	v -> num = x;
	v -> ligader = p;
	p -> ligaizq = v;
	v -> ligaizq = NULL;
	p = v;
	return p;
}

nodo *insert_final(nodo *p,nodo *f, int x) {
	nodo *q;
	q=creaNodo();
	q->num=x;
	f->ligader=q;
	q->ligaizq=f;
	q->ligader=NULL;
	f=q;
	printf("\n\t**INGRESANDO EL NUEVO DATO Al FINAL DE LA LISTA...**\n");
	return p;
}

nodo *inserta_antes_x(nodo *p, int ref, int x)
{
	nodo *v = NULL;
	nodo *t = NULL;
	nodo *k = NULL; 
	v=p;
	while((v->ligader != NULL)&&(v->num!=ref))
	{
		v=v->ligader;	
	}
	if(v->num==ref)
	{
		t=creaNodo();
		t->num=x;
		t->ligader=v;
		k=v->ligaizq;
		v->ligaizq=t;
		if(p==v)
		{
			p=t;
			t->ligaizq=NULL;
		}
		else
		{
			k->ligader=t;
			t->ligaizq=k;	
		}
	}
	else
		printf("\nEl elmento no se encuentra\n");
	return p;
}

nodo *inserta_despues_x(nodo *p, int ref, int x)
{
	nodo *v = NULL;
	nodo *t = NULL;
	nodo *k = NULL; 
	v=p;
	while((v->ligader != NULL)&&(v->num!=ref))
	{
		v=v->ligader;	
	}
	if(v->num==ref)
	{
		t=creaNodo();
		t->num=x;
		if(v->ligader!=NULL)
		{
			k=v->ligader;
			v->ligader=t;
			k->ligaizq=t;
			t->ligader=k;
			t->ligaizq=v;
		}
		else
		{
			t->ligader=NULL;
			t->ligaizq=v;
			v->ligader=t;
		}
	}
	else
		printf("\nEl elmento no se encuentra\n");
	return p;
}

nodo *eliminarPrimero(nodo *p,nodo *f)
{
	nodo *q=NULL;
	q=p;
	if(q->ligader!=NULL)
	{
		
		p=q->ligader;
		q->ligader=NULL;
		p->ligaizq=NULL;
	}
	else{
		p=NULL;
		f=NULL;
	}
	free(q);
	return p;
}

nodo *eliminarFinal(nodo *p,nodo *f)
{
	nodo *q=NULL;
	q=f;
	if(q->ligaizq!=NULL)
	{
		f=q->ligaizq;
		f->ligader=NULL;
	}
	else{
		f=NULL;
		p=NULL;
	}
	free(q);
	return (p);
}

nodo *eliminar_antes_x(nodo *p,nodo *f, int x)
{
	nodo *q=NULL;
	nodo *k=NULL;
	nodo *a=NULL;
	q=p;
	while((q->ligader!=NULL)&&(q->num!=x))
	{
		q=q->ligader;
	}
	if(q->num==x)
	{
		if(p==q)
		{
			printf("NO hay nodo para eliminar");	
		}	
		else
		{
			k=q->ligaizq;
			if(p==k)
			{
				p=q;
				p->ligaizq=NULL;
			}
			else
			{
				a=k->ligaizq;
				q->ligaizq=a;
				a->ligader=q;
			}
		}
		free(k);
	}
	else
	{
		printf("No se encuentra");
	}
	return (p);
}

nodo *eliminar_despues_x(nodo *p,nodo *f, int x)
{
	nodo *q = NULL;
	nodo *t = NULL;
	nodo *r = NULL; 
	q=p;
	while((q->ligader != NULL)&&(q->num!=x))
	{
		q=q->ligader;	
	}
	if(q->num==x)
	{
		if((p==q)&&(p->ligader!=NULL))
		{
			t=p->ligader;
			if(t->ligader!=NULL)
			{
				r=t->ligader;
				p->ligader=r;
				t->ligaizq=NULL;
				t->ligader!=NULL;
				r->ligaizq=p;
			}
			else
			{
				p->ligader=NULL;
				t->ligaizq=NULL;
				p->ligader!=NULL;
			}
		}
		else
		{
			if(f==q)
			{
				printf("NO hay numero, despues %d",f->num);
			}
			else
			{
				t=q->ligader;
				if(f==t)
				{
					r=q->ligaizq;
					t->ligaizq=NULL;
					q->ligader=NULL;
					q->ligaizq=r;
					r->ligader=q;
				}
				else
				{
					r=t->ligader;
					t->ligader=NULL;
					t->ligaizq=NULL;
					r->ligaizq=q;
					q->ligader=r;
				}
			}
		}
		free(t);
	}
	else
		printf("\nEl elmento no se encuentra\n");
	return p;
}

nodo *eliminar_x(nodo *p,nodo *f, int x)
{
	nodo *q = NULL;
	nodo *r = NULL;
	nodo *t = NULL;
	q=p;
	while( (q->ligader!=NULL)&& (q->num!=x) ) 
	{
		q=q->ligader;
	}
	if(q->num==x)
	{
		if((q==p)&&(q==f))
		{
		p=NULL;
		f=NULL;
		}
		else
		{
			if (q==p) 
			{
				p=q->ligader;
				p->ligaizq=NULL;
			}
			else
			{
				if(q==f)
				{
					f=q->ligaizq;
					f->ligader=NULL;
				}
				else
				{
					t=q->ligaizq;
					r=q->ligader;
					t->ligader=r;
					r->ligaizq=t;
				}
			}
		}
	free(q);
	}
	else
	{
		printf("\nElemento con informacion %d  no se encuentra en la lista\n",x);
	}
	return p;
}

void guardarlistader(nodo *p)
{
	nodo *q =p;
	char archivo[20];
	FILE *fp;
	
	printf("Introduzca el nombre del archivo");
	scanf("%s",archivo);
	fflush(stdin);
	if ( (fp = fopen(archivo,"wb")) == NULL )
	 {
	 	printf("\n No se puede habrir el archivo: %s",archivo);
	 	exit(1);
	 }
	 
	 q= p;
	 while ( q != NULL)
	 {
	 
	 printf("\n Guardando la lista... \n");
	 
	 fwrite(q, sizeof(nodo),1,fp);
	 q = q->ligader;
	 }
	 fclose(fp);
}

void recursivoder (nodo *p){
	if(p != NULL){
		printf("%d->",p->num);
		if(p->ligader!=NULL){
			recursivoder (p->ligader);
		}
		else{
			printf("%s",p->ligader);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

void recursivoizq (nodo *f){

	if(f != NULL){
		printf("%d->",f->num);
		if(f->ligaizq!=NULL){
			recursivoizq (f->ligaizq);
		}
		else{
			printf("%s",f->ligaizq);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

nodo *cargarlistaFinal(nodo *p)
{
	nodo *q, *t,*ultimo;
	char archivo[20];
	
	int i, op, e= 0;
	FILE *fp;
	
	printf("Introduzca el nombre del archivo que desea leer");
	scanf("%s",archivo);
	fflush(stdin);
	if ( (fp = fopen(archivo,"rb")) == NULL )
	{
	 	printf("\n No existe el archivo: %s",archivo);
	 //	exit(1);
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
			if ( p != NULL)  
			    p= liberamemoriadb(p); 
			printf("\n Se crea el nodo p la lista . . . ");
			p = creaNodo();
			if ( 1 != fread(p,sizeof(nodo),1,fp))
			{
				p = NULL;
				printf("\n Fracasa el read del primer nodo\n");
				printf("\n Enter para continuar!: ");
				getchar();
				return p;	 
			}
			printf("\n read el primer nodo %d . . .EXITOSO ! ",p->num);				
			p->ligaizq = NULL;
			p->ligader = NULL;
			t=p;
			printf("\n se  leen los otros nodos  del archivo  . . . ");		 
				
			while ( ! feof(fp))
			{  
				q= creaNodo();
				printf("\n fread la lista . . . ");
				if ( 1 != fread(q,sizeof(nodo),1,fp))
				{
					printf("\n falla el fread la lista . . . ");
				    t->ligader =NULL;
					free(q);
					recorreiterativoder(p);
				    recorreiterativoizq(p);
					break;
				}	
				printf("\n Exito read cargando el nodo %d . . . ",q->num);
				q->ligaizq = t;
				t->ligader = q;
				q->ligader = NULL;
				t=q;
			}	 
    	}
	  	else
		{
		 	printf("\n no se ha eliminado la lista ni cargado el archivo ! \n");
		 	getchar();
		}
    }
	else
	{
		printf("\n no se pudo abrir el archivo ! \n");
		getchar();
	}	 
	return(p);	 
}

nodo *cargarlistaInicio(nodo *p)
{
	nodo *q, *t,*ultimo;
	char archivo[20];
	
	int i, op, e= 0;
	FILE *fp;
	
	printf("Introduzca el nombre del archivo que desea leer");
	scanf("%s",archivo);
	fflush(stdin);
	if ( (fp = fopen(archivo,"rb")) == NULL )
	{
		printf("\n No existe el archivo: %s",archivo);
		//	exit(1);
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
	 	
			if ( p != NULL)   
				p= liberamemoriadb(p); 
			printf("\n Se crea el nodo p la lista . . . ");
			p = creaNodo();
			if ( 1 != fread(p,sizeof(nodo),1,fp))
			{
				p = NULL;
				printf("\n Fracasa el read del primer nodo\n");
				printf("\n Enter para continuar!: ");
				getchar();
				return p;
			}
			printf("\n Exito read cargando el primer nodo %d . . . ",p->num);		
			p->ligaizq = NULL;
			p->ligader = NULL;
			
			printf("\n se  leen los otros nodos  del archivo  . . . ");		 
			
			while ( ! feof(fp))
			{  
			    q= creaNodo();
				printf("\n fread la lista . . . ");
			 	if ( 1 != fread(q,sizeof(nodo),1,fp))
			    {
					printf("\n fallo el fread la lista . . . ");
				    free(q);
				    recorreiterativoder(p);
			        recorreiterativoizq(p);
				    break;
				}	
				printf("\n Exito read cargando el nodo q con %d . . . ",q->num);
			    q->ligader = p;
				p->ligaizq = q;
				q->ligaizq = NULL;
				p=q;
			}
		}
	  	else 
		{
		 	printf("\n no se ha eliminado la lista ni cargado el archivo ! \n");
		 	getchar();
		}
    }
	else 
	{
		printf("\n no se pudo abrir el archivo ! \n");
		getchar();
	}	 
	return(p);	 
	
}
