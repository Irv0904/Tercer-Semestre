#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

nodo *menu_v1(nodo *i);
void *creaMemoria(int n);
nodo *creaNodo();
nodo *comienzo();
nodo *nodoFinal (nodo *i);
void recursivo (nodo *i);
void iteractivo(nodo *i);
nodo *comienzo();
nodo *insertar_despues_x(nodo *i);
nodo *insertar_antes_x(nodo *i);
nodo *insertar_final(nodo *i);
nodo *insertar_inicio(nodo *i);
nodo *elmininar_x(nodo *i);
nodo *eliminar_ultimo(nodo *i);
nodo *eliminar_primero(nodo *i);
nodo *eliminar_antes_x(nodo *i);
nodo *eliminar_despues_x(nodo *i);
nodo *busqueda_desordenada(nodo *i);
nodo *busqueda_ordenada(nodo *i);
nodo *busqueda_recursiva(nodo *i,int num);
nodo *liberiaMemoria(nodo *i);

int main()
{
	nodo *i=NULL;
	int opc,lec,num;
	do{
		system("CLS");
		system("color 01");
		printf("*****************\n*Listas enlazada*\n*****************");
		printf("\n1->Crear\n2->Insertar\n3->Eliminar\n4->Busqueda\n5->Recorrer\n6->Salir\nREspuesta: ");
		scanf("%d", &opc);
		switch(opc)
		{
			case 1:
				do
				{
					system("CLS");
					system("color 05");
					printf("****************\n*Lista enlazada*\n****************\n");
					printf("1->Crear Inicio\n2->Crear Final\n3->Regresar\nRespuesta: ");
					scanf("%d",&lec);
					system("CLS");
					switch(lec)
					{
						case 1:
							i=comienzo();
							system("PAUSE");
							break;
						case 2:
							i=nodoFinal(i);
							system("PAUSE");
							break;
						case 3:
							break;
					}
				}while(lec!=3);
				break;
			case 2:
				do
				{
					system("CLS");
					system("color 08");
					printf("*****************************\n*Insertar en listas enlazada*\n*****************************");
					printf("\n1->Inserta inicio\n2->Inserta Final\n3->Insertar antes de...");
					printf("\n4->Insertar despues de...\n5->Regresar\nRespuesta: ");
					scanf("%d",& lec);
					switch(lec)
					{
						case 1:
							i=insertar_inicio(i);
							system("PAUSE");
							break;
						case 2:
							i=insertar_final(i);
							system("PAUSE");
							break;
						case 3:
							i=insertar_antes_x(i);
							system("PAUSE");
							break;
						case 4:
							i=insertar_despues_x(i);
							system("PAUSE");
							break;
						case 5:
							break;
					}
				}while(lec!=5);	
				break;
			case 3:
				do
				{
					system("CLS");
					system("color 06");
					printf("****************************\n*Eliminar en lista enlazada*\n****************************");
					printf("\n1->Eminar el primero\n2->Eliminar ultimo\n3->Eliminar x");
					printf("\n4->eliminar antes de...\n5->Eliminar despues de...(prox.)");
					printf("\n6->Regresar\nRespuesta: ");
					scanf("%d",&lec);
					switch(lec)
					{
						case 1:
							i=eliminar_primero(i);
							system("PAUSE");
							break;
						case 2:
							i=eliminar_ultimo(i);
							system("PAUSE");
							break;
						case 3:
							i=elmininar_x(i);
							system("PAUSE");
							break;
						case 4:
							i=eliminar_antes_x(i);
							system("PAUSE");
							break;
						case 5:
							i=eliminar_despues_x(i);
							system("PAUSE");
							break;
						case 6:
							break;
					}	
				}while(lec!=6);
				break;
			case 4:
				do
				{
					
					system("CLS");
					system("Color 04");
					printf("***************************\n*Busqueda en lista enlazada*\n***************************");
					printf("\n1->Busqueda Dessordenada\n2->Busqueda Ordenada\n3->Busqueda recursiva\n4->Regresar\nRespuesta: ");
					scanf("%d",&lec);
					switch(lec)
					{
						case 1:
							i=busqueda_desordenada(i);
							break;
						case 2:
							i=busqueda_ordenada(i);
							break;
						case 3:
							printf("\nbuscar: ");
							scanf("%d",&num);
							i=busqueda_recursiva(i,num);
							break;
						case 4:	
							break;					
					}
				}while(lec!=4);
				break;
			case 5:
				do
				{
					system("CLS");
					system("color 0F");					
					printf("*************************\n*Recorrer lista enlazada*\n*************************");
					printf("\n1->Recorre Iterativo\n2->Recorre recursivo\n3->Regresar\nRespuesta: ");
					scanf("%d", &lec);
					switch(lec)
					{
						case 1:
							iteractivo (i);
							system("PAUSE");
							break;
						case 2:
							recursivo(i);
							system("PAUSE");
							break;
						case 3:
							break;
					}
				}
				while(lec!=3);
				break;
			case 6:
				break;	
					
		}
	}while(opc!=6);
}

void *creaMemoria(int n)
{
	void *i=(int *)malloc(n);
	if(i==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}

 void recursivo (nodo *i)
 {
	if(i != NULL)
	{
		printf("%5d->",i->num);
		if(i->liga!=NULL)
		{
			recursivo (i->liga);
		}
		else
		{
			printf("%s",i->liga);
		}
	}
	else
		printf("\n*****Lista Vacia...*****\n");	
}

void iteractivo(nodo *i)
{
	nodo *v;
	if(i!=NULL)
	{
		printf("\n");
		for(v=i;v!=NULL;v=v->liga)
		{
			printf("%5d->", v->num);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

nodo *liberiaMemoria(nodo *i)
{
	nodo *v=NULL;
	if(i!=NULL)
	{
		while(i!=NULL)
		{
			v=i;
			i=i->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
	return(i);
}

nodo *comienzo()
{
	int num,j;
	nodo *i, *v;
	i = creaNodo();
	printf("Ingrese un digito: ");
	j=scanf("%d",&num);
	//fflush(stdin);
	if(j == 1)
	{
		i ->num = num;
		i -> liga=NULL;	
		
		do
		{
		v= creaNodo();
		printf("Ingrese dato: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1)
		{
			v->num = num;
			v->liga=i;
			i=v;
		}
		else
		{
			free(v);
			break;
		}
		}while(j ==1);
		printf("\n\t*****creando Listas enlazada...*****\n\n");
	}
	else
	{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}

nodo *nodoFinal (nodo *i)
{
	int j,num;
	nodo *l,*v;
	i=creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1)
	{
		i->num=num;
		i->liga=NULL;
		l=i;
		do
		{
			v=creaNodo();
			printf("Ingrese digito:");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1)
			{
				v->num=num;
				v->liga=NULL;
				l->liga=v;
				l=v;
			}
			else
			{
				free(v);
				break;
			}
		}while(j==1);
		printf("\n*****creando Listas enlazada...*****\n");
	}
	else
	{
		free(i);
		return(NULL);
	}
	printf("\n");
	return i;
}

nodo *insertar_inicio(nodo *i) {
	nodo *v;
    int j,dato;
    v=creaNodo();
    printf("\nIntroduzca un dato: ");
    j=scanf("%d",&dato);
    fflush(stdin);
    if(j==1) {
        v->liga=i;
        v->num=dato;
        i= v;
        }
    printf("\n\t*****Ingresando nuevo dato al inicio...*****\n");
    return i;
}

nodo *insertar_final(nodo *i) {
	nodo *v,*l;
	int dec,j;
	l=i;
	v=creaNodo();
	printf("\nIngrese: "); 
	j=scanf("%d",&dec);
	fflush(stdin);
	if(j==1){
		while(l->liga!=NULL){
			l=l->liga;
		}
		v->num=dec;
		v->liga=NULL;
		l->liga=v;
	}
	printf("\n\t*****Ingresando el nuevo dato al final...*****\n")
	;return i;
}

nodo *insertar_despues_x(nodo *i)
{
	nodo *v,*l;
	int band=1,j,dato,x;
	v=i;
	printf("\nIngrese el numero de referencia: ");
	scanf("%d", &x);
	printf("\nIngrese el numero: ");
	j=scanf("%d", &dato);
	if(j==1)
	{
		while((v->num!=x)and(band==1)){
			if(v->liga!=NULL){
				v=v->liga;
			}
			else{
				band=0;
			}
		}
		if(band==1){
			l=creaNodo();
			l->num=dato;
			l->liga=v->liga;
			v->liga=l;
		}
		else{
			printf("\ndado com referencia es nulo");
		}
	}
	return i;	
}

nodo *insertar_antes_x(nodo *i)
{
	nodo *v,*l,*k;
	int band=1,j,dato,x;
	v=i;
	printf("\n\n\nIngrese el dato de referencia: ");
	scanf("%d",&x);
	printf("Ingrese el numero: ");
	j=scanf("%d",&dato);
	if(j==1)
	{
		while((v->num!=x)&&(band==1)){
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else{
				band=0;
			}	
		}
		if(band==1){
			k=creaNodo();
			k->num=dato;
			if(i==v){
				k->liga=i;
				i=k;
			}
			else{
				l->liga=k;
				k->liga=v;
			}
		}
		else
			printf("El nodo dado no se encuentra");
	}
	return i;
}

nodo *elmininar_x(nodo *i) {
	nodo *v,*l;	
	int j,num;
	int band =1;
	v=i;
	printf("\n\nIngrese el dato que va a eliminar ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		while((v->num!=num)&&(band == 1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else
				band=0;	
		}
		if(band==0)
			printf("\n\nEl dato %d no se encuentra para eliminar",num);
		else{
			if(i==v){
				i=v->liga;
			}
			else{
				l->liga=v->liga;
				printf("\n\t*****Actualizando lista enlazada...*****\n");
			}
		}
		return(i);
		free(v);				
	}
}

nodo *eliminar_primero(nodo *i) {
	nodo *v,*l;
	v=i;
	printf("\n\t*****Elminando el primer nodo...*****\n");
	i=v->liga;
	free(v);
	return(i);

}

nodo *eliminar_despues_x(nodo *i) {
	nodo *v,*l,*t;
	int band=1,x,j;
	v=i;
	printf("Ingrese el numero de referencia: ");
	j=scanf("%d", &x);
	if(j==1){
		while((v->num!=x)&&(band=1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else
			{
				band=0;
			}
		}
		if(band==0){
			printf("No existe numero despues...");
		}
		else
		{					
			t=v;
			v=v->liga;
			if(t->liga!=NULL)
			{
				t->liga=v->liga;
				v->liga=t;
			}
			else
			{
				printf("\nNo hay numero despues de la referencia\n");
			}
		}
		free (v);
	}
	return i;	
}

nodo *eliminar_ultimo(nodo *i) {
	nodo *v,*l;
	v=i;
	printf("\n\n\t*****Elminando ultimo nodo...*****\n\n");
    if(i->liga==NULL) 
        i=NULL;
    else{
    	while(v->liga!=NULL){
		l=v;
		v=v->liga;
		}
		l->liga=NULL;
	}
	free(v);
	return(i);
}

nodo *eliminar_antes_x(nodo *i) {
	nodo *v,*l,*a;
	int band=1,x,j;
	printf("\nIngrese el numero de referencia: ");
	j=scanf("%d", &x);
	if(j==1){
		if(i->num==x){
			printf("No existe");
		}
		else{
			v=i;
			l=i;
			while((v->num!=x)and(band=1)){
				if(v->liga!=NULL){
					a=l;
					l=v;
					v=v->liga;
				}
				else{
					band=0;
				}
			}
			if(band==0)
			{
				printf("no");
			}
			else
			{
				if(i->liga==v){
					i=v;
				}
				else
				{
					a->liga=v;
				}
				free(l);
			}
		}
	}
	return i;	
}

nodo *busqueda_recursiva(nodo *i,int num) {
	if(i!=NULL){
	
		if(i->num==num)
			printf("Se encuentra en la lista");
		else 
			busqueda_recursiva(i->liga,num);
	}
	else	
		printf("No se encuentra"); 
			
	return(i);
}

nodo *busqueda_ordenada(nodo *i) {
	nodo *v;	
	int j,num;
	v=i;
	printf("\n\nIngrese el dato que va a buscar: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		while((v!=NULL)&&(v->num != num))
		{
			v=v->liga;
		}
		if((v==NULL) or (v->num<num)){
			printf("\nEl dato que ingreso no esta en esta lista");
		}
		else
			printf("\nEl dato que ingreso si esta en la lista");
	}
	return(i);
}

nodo *busqueda_desordenada(nodo *i) {
	nodo *v;	
	int j,num;
	v=i;
	printf("\n\nIngrese el dato que va a buscar: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		while((v!=NULL)&&(v->num != num))
		{
			v=v->liga;
		}
		if(v==NULL){
			printf("\nEl dato que ingreso no esta en esta lista");
		}
		else
			printf("\nEl dato que ingreso si esta en la lista");
	}
	return(i);
}
