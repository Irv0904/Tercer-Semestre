//PASO LA PRUEBA
#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
//void iteractivo(nodo *i);
//nodo *comienzo();
nodo *nodoFinal (nodo *i);
void recursivo (nodo *i);
nodo *liberiaMemoria(nodo *i);
nodo *eliminar_antes_x(nodo *i);
int main(){
	int num;
	nodo *i=NULL;
	i=nodoFinal(i);
	recursivo(i);
  	//i= comienzo();
	//iteractivo (i);
	i=eliminar_antes_x(i);
	//iteractivo (i);
	printf("\n");
	recursivo(i);
	i=liberiaMemoria(i);

}

void *creaMemoria(int n){
	void *i=(int *)malloc(n);
	if(i==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodo(){
	return(nodo *)creaMemoria(sizeof(nodo));
} 

/*void iteractivo(nodo *i){
	nodo *v;
	if(i!=NULL){
		printf("\n");
		for(v=i;v!=NULL;v=v->liga){
			printf("%5d->", v->num);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}*/

void recursivo (nodo *i){
	if(i != NULL){
		printf("%5d->",i->num);
		if(i->liga!=NULL){
			recursivo (i->liga);
		}
		else{
			printf("%s",i->liga);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

nodo *liberiaMemoria(nodo *i){
	nodo *v=NULL;
	if(i!=NULL){
		while(i!=NULL){
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

/*nodo *comienzo(){
	int num,j;
	nodo *i, *v;
	i = creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1){
		i ->num = num;
		i -> liga=NULL;	
		
		do{
		v= creaNodo();
		printf("Ingrese dato: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1){
			v->num = num;
			v->liga=i;
			i=v;
		}
		else{
			free(v);
			break;
		}
		}while(j ==1);
		printf("\n\t*****creando Listas enlazada...*****\n");
	}
	else{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}*/

nodo *nodoFinal (nodo *i){
	int j,num;
	nodo *l,*v;
	i=creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		i->num=num;
		i->liga=NULL;
		l=i;
		do{
			v=creaNodo();
			printf("Ingrese digito:");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1){
				v->num=num;
				v->liga=NULL;
				l->liga=v;
				l=v;
			}
			else{
				free(v);
				break;
			}
		}while(j==1);
		printf("\n*****creando Listas enlazada...*****\n\n");
	
	}
	else{
		free(i);
		return(NULL);
	}
	return i;
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
