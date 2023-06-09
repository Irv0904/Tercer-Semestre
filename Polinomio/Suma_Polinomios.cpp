//PASO LA PRUEBA
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct cnodo{
	float coef;
	float expo;
	float total;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(float n);
void *creaMemoriaFloat(float w);
nodo *creaNodofloat();
nodo *creaNodo();
void ordenarLista_a(nodo* p); 
nodo *suma_polinomios(nodo *p, nodo *f, nodo *r);
void iteractivol1(nodo *p);
void iteractivolt(nodo *r);
void iteractivol2(nodo *f);
nodo *nodoFinal (nodo *p);
nodo *nodoFinaldb(nodo *f);
nodo *liberiaMemoria(nodo *p);
nodo *eliminar_ultimo(nodo *p);
int main(){
	float num;
	nodo *p=NULL;
	nodo *f=NULL;
	nodo *r=NULL;
	printf("Lista 1\n");
	p=nodoFinal(p);
	iteractivol1(p);
	printf("Lista 2\n");
	f=nodoFinaldb(f);
	iteractivol2(f);
	printf("Lista 1 y 2\n");
	iteractivol1(p);
	iteractivol2(f);
	
	r=suma_polinomios(p,f,r);
	//ordenarLista_a(p);
	iteractivolt(r);

	p=liberiaMemoria(p);
}

void *creaMemoria(float n){
	void *p=(float *)malloc(n);
	if(p==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodofloat(){
	return(nodo *)creaMemoriaFloat(sizeof(nodo));
} 

void *creaMemoriaFloat(float w){
	void *p=(float *)malloc(w);
	if(p==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodo(){
	return(nodo *)creaMemoria(sizeof(nodo));
} 

void iteractivol1(nodo *p){
	nodo *v;
	if(p!=NULL){
		printf("\n");
		for(v=p;v!=NULL;v=v->liga){
			printf("%.1fx^%.0f -> ", v->coef,v->expo);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

void iteractivol2(nodo *f)
{
	nodo *v;
	if(f!=NULL){
		printf("\n");
		for(v=f;v!=NULL;v=v->liga){
			printf("%.1fx^%.0f -> ", v->coef,v->expo);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

void iteractivolt(nodo *r)
{
	nodo *v;
	if(r!=NULL){
		printf("\n");
		for(v=r;v!=NULL;v=v->liga){
			printf("%.1fx^%.0f -> ", v->coef,v->expo);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

nodo *liberiaMemoria(nodo *p){
	nodo *v=NULL;
	if(p!=NULL){
		while(p!=NULL){
			v=p;
			p=p->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
	return(p);
}


nodo *nodoFinal (nodo *p){
	float coef;
	float expo;
	int j;
	nodo *l,*v;
	p=creaNodofloat();
	p=creaNodo();
	printf("Ingrese un coeficiente: ");
	j=scanf("%f",&coef);
	printf("Ingrese un exponente: ");
	j=scanf("%f",&expo);
	fflush(stdin);
	if(j==1){
		p->coef=coef;
		p->expo=expo;
		p->liga=NULL;
		l=p;
		do{
			v=creaNodofloat();
			v=creaNodo();
			printf("\nIngrese un coeficiente:");
			j=scanf("%f",&coef);
			printf("Ingrese un exponente: ");
			j=scanf("%f",&expo);
			fflush(stdin);
			if(j==1){
				v->coef=coef;
				v->expo=expo;
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
		free(p);
		return(NULL);
	}
	return p;
}

nodo *nodoFinaldb(nodo *f){
	float coef;
	float expo;
	int j;
	nodo *l,*v;
	f=creaNodofloat();
	f=creaNodo();
	printf("Ingrese un coeficiente: ");
	j=scanf("%f",&coef);
	printf("Ingrese un exponente: ");
	j=scanf("%f",&expo);
	fflush(stdin);
	if(j==1){
		f->coef=coef;
		f->expo=expo;
		f->liga=NULL;
		l=f;
		do{
			v=creaNodofloat();
			v=creaNodo();
			printf("\nIngrese un coeficiente:");
			j=scanf("%f",&coef);
			printf("Ingrese un exponente: ");
			j=scanf("%f",&expo);
			fflush(stdin);
			if(j==1){
				v->coef=coef;
				v->expo=expo;
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
		free(f);
		return(NULL);
	}
	return f;
}

nodo *suma_polinomios(nodo *p, nodo *f, nodo *r)
{
	float  scoef;
	nodo *t=NULL;
	nodo *q=NULL;
	nodo *x=NULL;
	nodo *z=NULL;
	q=p;
	x=f;
		if(q->expo == x->expo){
			scoef=q->coef+ x->coef;
			t=creaNodo();
			t->coef=scoef;
			t->expo=q->expo;
			
			q=q->liga;
		}
		//x=x->liga;	
	r=t;
	return r;
}


/*void ordenarLista(nodo* p) {
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (p == NULL)
        return;
    
    do {
        band = 0;
        v = p;
        
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
}*/

void ordenarLista_a(nodo* p) 
{
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (p == NULL)
        return;
    do {
        band = 0;
        v = p;
        while (v->liga != l) {
            if (v->expo < v->liga->expo) {
                int temp = v->expo;
                int temp2 = v->coef;
                v->expo=v->liga->expo;
                v->coef=v->liga->coef;
                v->liga->expo=temp;
                v->liga->coef=temp2;
                band = 1;
            }
            v = v->liga;
        }
        l = v;
    } while (band);
}
