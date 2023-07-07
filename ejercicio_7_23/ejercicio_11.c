#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
nodo *nodoFinal(nodo *p);

nodo *insertainicioCircular(nodo *p,int dato);
int recorreiterativoCircular(nodo *p);

int cuantos= 0;
int cuantos2 = 0;

int main(){
	nodo *p = NULL;
    int dato;
	p = nodoFinal(p);
    recorreiterativoCircular(p);   
    printf("\n\n\tIntroduzca el valor del nodo a insertar: ");
	scanf("%d",&dato);
	fflush(stdin);    	
	p=insertainicioCircular(p,dato);

	recorreiterativoCircular(p);
}

void *creaMemoria(int n){
	void *p = malloc(n);
	if(p == NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return p;
}

nodo *creaNodo(){
	return (nodo *)creaMemoria(sizeof(nodo));
} 

nodo *nodoFinal(nodo *p){
	int j, num;
	nodo *l, *v;
	p = creaNodo();
	printf("\nIngrese un digito: ");
	j = scanf("%d", &num);
	fflush(stdin);
	if(j == 1){
		p->num = num;
		p->liga = NULL;
		l = p;
		do{
			v = creaNodo();
			printf("Ingrese un digito: ");
			j = scanf("%d", &num);
			fflush(stdin);
			if(j == 1){
				v->num = num;
				v->liga = NULL;
				l->liga = v;
				l = v;
			}
			else{
				free(v);
				break;
			}
		}while(j == 1);
		// Hacer la lista enlazada circular
		l->liga = p;
		printf("\n*****Creando Lista Enlazada Circular...*****\n\n");
	}
	else{
		free(p);
		return NULL;
	}
	return p;
}

int recorreiterativoCircular(nodo *p)
{
    nodo *temp;  
    int j =0;
    if( p == NULL)
    {
        printf("\n\n\t\t La lista esta vacia");
        return 0;
    }
    printf("\n");
    if ( p == p->liga)
    {
        printf("%d->",p->num);
        printf("%d",p->num);
        j=1;
        return j;
    }
    else
    {
        j++; 
        temp = p;
        do
        {
            printf("   %d-> ", temp->num);
            j++; //APN
            temp=temp->liga;
        }while(temp !=p );
        printf("%d",p->num);
        printf("\n");
    }
return j;
	
}


nodo *insertainicioCircular(nodo *p,int dato)
{
	
	nodo *q, *ptr;
	
	q = creaNodo();
	
	q->num = dato;
	
	ptr = p;
	
	while ( ptr->liga != p)
        ptr= ptr->liga; 
	ptr->liga = q;
	
	q->liga = p;
	
	p=q;	
	cuantos++;
	cuantos2 = cuantos;
	
	return p;
}