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
void iteractivo(nodo *i);
nodo *comienzo();
//nodo *nodoFinal (nodo *i);
//void recursivo (nodo *i);
nodo *liberiaMemoria(nodo *i);
void ordenarLista(nodo*i);
void ordenarLista_a(nodo*i);
nodo *insertar_antes_x(nodo *i);
int main(){
	//int num;
	nodo *i=NULL;
  	i= comienzo();
	iteractivo (i);
	//i=nodoFinal(i);
	//recursivo(i);
	ordenarLista(i);
	iteractivo (i);
	//ordenarLista_a(i);
	//iteractivo (i);
	i=insertar_antes_x(i);
	iteractivo (i);
	//iteractivo (i);
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

void iteractivo(nodo *i){
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
}

/*void recursivo (nodo *i){
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
}*/

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

nodo *comienzo(){
	int num,j;
	nodo *i, *v,*a;
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
		printf("\n*****creando Listas enlazada...*****\n");
	}
	else{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}

/*nodo *nodoFinal (nodo *i){
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
}*/

nodo *insertar_antes_x(nodo *i)
{
	nodo *v,*l,*k;
	int band=1,j,dato,x;
	v=i;
	printf("\nIngrese el dato de referencia: ");
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


void ordenarLista(nodo* i) {
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (i == NULL)
        return;
    
    do {
        band = 0;
        v = i;
        
        while (v->liga != l) {
            if (v->num > v->liga->num) {
                int temp = v->num;
                v->num = v->liga->num;
                v->liga->num = temp;
                band = 1;
            }
            v = v->liga;
        }
        
        l = v;
    } while (band);
}

void ordenarLista_a(nodo* i) {
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (i == NULL)
        return;
    
    do {
        band = 0;
        v = i;
        
        while (v->liga != l) {
            if (v->num < v->liga->num) {
                int temp = v->num;
                v->num = v->liga->num;
                v->liga->num = temp;
                band = 1;
            }
            v = v->liga;
        }
        
        l = v;
    } while (band);
}
