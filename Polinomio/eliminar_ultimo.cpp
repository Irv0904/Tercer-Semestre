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
nodo *ordenarLista_a(nodo* i); 
nodo *suma_polinomio(nodo *i);
void iteractivo(nodo *i);
nodo *nodoFinal (nodo *i);
void iteractivoTotal(nodo *i);
nodo *liberiaMemoria(nodo *i);
nodo *eliminar_ultimo(nodo *i);

float evaluar (nodo *i, float x);

int main(){
	float num, expo, x, res;
	nodo *i=NULL;
	i=nodoFinal(i);
	iteractivo (i);
	//i=ordenarLista_a(i);
	printf("Ingrese el valor de x: ");
	scanf("%f",&x);
	fflush(stdin);
	res=evaluar(i,x);
	//i=suma_polinomio(i);
	//iteractivoTotal(i);
	printf("El reultado es: %.1f ", res);
	i=liberiaMemoria(i);
}

void *creaMemoria(float n){
	void *i=(float *)malloc(n);
	if(i==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodofloat(){
	return(nodo *)creaMemoriaFloat(sizeof(nodo));
} 

void *creaMemoriaFloat(float w){
	void *i=(float *)malloc(w);
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
			printf("%.1fx^%.0f -> ", v->coef,v->expo);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

void iteractivoTotal(nodo *i)
{
	nodo *v;
	if(i!=NULL){
		printf("\n");
		for(v=i;v!=NULL;v=v->liga){
			printf("%.1f->",v->total);
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
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
	return(i);
}


nodo *nodoFinal (nodo *i){
	float coef;
	float expo;
	int j;
	nodo *l,*v;
	i=creaNodofloat();
	i=creaNodo();
	printf("Ingrese un coeficiente: ");
	j=scanf("%f",&coef);
	printf("Ingrese un exponente: ");
	j=scanf("%f",&expo);
	fflush(stdin);
	if(j==1){
		i->coef=coef;
		i->expo=expo;
		i->liga=NULL;
		l=i;
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
		free(i);
		return(NULL);
	}
	return i;
}


/*nodo *suma_polinomio(nodo *i)
{
	float x;
	int j;
	float total, pre;
	float acumula, acumula1;
	nodo *l=NULL;
	l=i;
	printf("Ingrese el valor de x: ");
	j=scanf("%f",&x);
	fflush(stdin);
	if(j==1)
	{
		total=pow(x,l->expo);
		pre=l->coef*total;
		acumula=acumula+pre;
		while(l->liga!=NULL)
		{
			if(l->expo==0)
			{
				pre=l->coef*x;
			}
			else
			{
				l=l->liga;
				total=pow(x,l->expo);
				pre=l->coef*total;
				acumula=acumula+pre;	
			}
		}
		l->total=acumula+pre;
	}
	else{
		free(l);
		return(NULL);
	}
	i=l;
	return i;
}*/

float evaluar(nodo *i, float x)
{
	nodo *q=i;
	float res;
	if(q != NULL)
	{
		res=q->coef*pow(x,q->expo);
		res += evaluar(q->liga,x);
	}
	
	return res;
}


/*void ordenarLista(nodo* i) {
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
}*/

/*void ordenarLista_a(nodo* i) 
{
    int band;
    nodo* v;
    nodo* l = NULL;
    
    if (i == NULL)
        return;
    
    do {
        band = 0;
        v = i;
        
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
}*/
