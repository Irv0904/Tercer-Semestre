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
void recursivo (nodo *i);
void recursivo2 (nodo *r);
//void iteractivo(nodo *i);
//void iteractivo2(nodo *r);
nodo *comienzo();
nodo *comienzo2();
void ordenarLista_a(nodo*i);
void ordenarLista(nodo*i);
void ordenarLista2(nodo*r);
void megaLista(nodo **i, nodo** r);
nodo *liberiaMemoria(nodo *i);
nodo *liberiaMemoria2(nodo *r);
int main(){
	int num;
	nodo *i=NULL;
	nodo *r=NULL;
  	i= comienzo();
  	printf("\t\tPrimera lista: \n");
  	ordenarLista(i);
	recursivo(i);
	r= comienzo();
	printf("\t\tSegunda lista\n");
	ordenarLista2(r);
	recursivo2 (r);
	printf("\n\nLista Unida\n");
	megaLista(&i,&r);
	ordenarLista_a(i);
	recursivo (i);
	//iteractivo (i);
	//ordenarLista(i);
	//printf("\t\tLista Ordenada\n");
	//iteractivo (i);
	i=liberiaMemoria(i);
	r=liberiaMemoria2(r);

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


void recursivo2 (nodo *r){
	if(r != NULL){
		printf("%5d->",r->num);
		if(r->liga!=NULL){
			recursivo (r->liga);
		}
		else{
			printf("%s",r->liga);
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

nodo *liberiaMemoria2(nodo *r){
	nodo *v=NULL;
	if(r!=NULL){
		while(r!=NULL){
			v=r;
			r=r->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
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

void ordenarLista2(nodo* r) {
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (r == NULL)
        return;
    
    do {
        band = 0;
        v = r;
        
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
