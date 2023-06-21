/*
	Name: Menu de listas doble
	Copyright: 2023
	Author: Irving Jhon Villarreal Lasso
	Date: 30/05/23 14:13
	Description: Se realizo un menu de todas la lista simple y doblemente ligada
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct cnodo{
	int num;
	struct cnodo *ligader;
	struct cnodo *ligaizq;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
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
nodo *eliminar_antes_xdb(nodo *p, nodo *f, int x);
nodo *eliminar_despues_xdb(nodo *p,nodo *f,int x);
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
	nodo *p =NULL;
	nodo *f=NULL;
	system("color 0F");
	int opc,lec,num;
	int x,j,k,ref;
	do{
		system("CLS");
		printf("\t\t\t<-<-<-<-<-<-<-<-<-<-<-<-<-<-<\n");
		printf("\t\t\t|Menu de simple y doble liga|\n");
		printf("\t\t\t>->->->->->->->->->->->->->->\n");
		printf("\n\t\t\t1->LISTAS DE LISGA DOBLE LIGADAS\n\t\t\t2->LISTA DE LIGA SIMPLE\n\t\t\t3->SALIR\n\t\t\tRESPUESTA: ");
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
														printf("\nse elimino el n�mero de la lista\n");
														recorreiterativoder(p);
														system("PAUSE");
														break;
													case 2:	
														recorreiterativoder(p);
														f=buscarUltimo(p);
														p=eliminarFinal(p,f);
														printf("\nse elimino el n�mero de la lista\n");
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
					break;
				case 2:
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
													printf("\n\n\t\tLa selecci�n fue incorrecto, intente de nuevo\n\n");
													system("PAUSE");
													break;
											}
										}
										else
										{
											printf("\n\n\t\tLa selecci�n fue incorrecto, intente de nuevo\n\n");
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
														printf("\nIngrese el n�mero: ");
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
													printf("\n\n\t\tLa selecci�n fue incorrecto, intente de nuevo\n\n");
													system("PAUSE");
													break;
											}
										}
										else
										{
											printf("\n\n\t\tLa selecci�n fue incorrecto, intente de nuevo\n\n");
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
													printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
													system("PAUSE");
													break;
											}
										}
										else
										{
											printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
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
													printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
													system("PAUSE");
													break;					
											}
										}
										else
										{
											printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
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
													printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
													system("PAUSE");
													break;
											}
										}
										else
										{
											printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
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
									printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
									system("PAUSE");
									break;			
							}
						}
						else
						{
							printf("\n\nLa selecci�n fue incorrecto,intente de nuevo\n\n");
							system("PAUSE");	
						}
					}while(opc!=9);
					break;
				case 3:
					break;
			}
		}
	}while(opc!=3);

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

nodo *eliminar_antes_xdb(nodo *p,nodo *f, int x)
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

nodo *eliminar_despues_xdb(nodo *p,nodo *f, int x)
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
				printf("NO hay nodo para eliminar");
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
	printf("Ingrese un n�mero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1)
	{
		p ->num = num;
		p -> liga=NULL;	
		
		do
		{
		q= creaNodo();
		printf("Ingrese un n�mero, para salir ingrese una letra: ");
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
	printf("Ingrese un n�mero, para salir ingrese una letra: ");
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
			printf("Ingrese un n�mero, para salir ingrese una letra: ");
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
	while((q->num!=ref)and(band==1))
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
			printf("\nNo hay n�mero antes de la referencia\n");
		}
		else
		{
			q=p;
			l=p;
			while((q->num!=ref)and(band==1))
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
			printf("\nEl n�mero %d Si esta en la lista\n\n",num);
		else 
			busqueda_recursiva(p->liga,num);
	}
	else	
		printf("\nEl n�mero %d NO esta en la lista\n\n", num); 
			
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
	if((q==NULL) or (q->num<x))
	{
		printf("\nEl n�mero %d NO esta en la lista\n\n",x);
	}
	else
		printf("\nEl n�mero %d SI esta en la lista\n\n",x);
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
		printf("\nEl n�mero %d NO esta en la lista\n\n", x);
	}
	else
		printf("\nEl n�mero %d SI esta en la lista\n\n", x);
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
