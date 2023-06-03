//YA ESTA LISTO PARA USARLO

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
void iteractivo2(nodo *r);
nodo *comienzo();
nodo *comienzo2();
void ordenarLista(nodo*i);
void megaLista(nodo **i, nodo** r);
nodo *liberiaMemoria(nodo *i);
nodo *liberiaMemoria2(nodo *r);
int main(){
	nodo *i=NULL;
	nodo *r=NULL;
  	i= comienzo();
  	printf("\t\tPrimera lista: \n");
  	iteractivo (i);
	r= comienzo2();
	printf("\t\tSegunda lista\n");
	iteractivo2 (r);
	megaLista(&i,&r);
	ordenarLista(i);
	printf("\t\tLista Ordenada\n");
	iteractivo (i);
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

void iteractivo2(nodo *r){
	nodo *v;
	if(r!=NULL){
		printf("\n");
		for(v=r;v!=NULL;v=v->liga){
			printf("%5d->", v->num);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
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
		printf("\n\n*****MEMORIA LIBERADA DE LA PRIMERA LISTA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA DE LA PRIMERA LISTA...*****\n\n");
	return(i);
}

nodo *liberiaMemoria2(nodo *r){
	nodo *v=NULL;
	if(r!=NULL){
		while(r!=NULL){
			v=r;
			r=r->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA DE LA SEGUNDA LISTA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA DE LA SEGUNDA LISTA...*****\n\n");
	return(r);
}

nodo *comienzo(){
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
		//printf("\n\t*****creando Listas enlazada...*****\n");
	}
	else{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}

nodo *comienzo2(){
	int num,j;
	nodo *r, *v;
	r = creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1){
		r ->num = num;
		r -> liga=NULL;	
		
		do{
		v= creaNodo();
		printf("Ingrese dato: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1){
			v->num = num;
			v->liga=r;
			r=v;
		}
		else{
			free(v);
			break;
		}
		}while(j ==1);
		//printf("\n\t*****creando Listas enlazada...*****\n");
	}
	else{
		free(r);
		return (NULL);
	}
	v=r;
	return r;	
}	

void megaLista(nodo** i, nodo** r) {
    if (*i == NULL) {
        *i = *r;
        return;
    }

    nodo *v = *i;
    while (v->liga != NULL) {
        v = v->liga;
    }

    v->liga = *r;
    *r = NULL;
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
