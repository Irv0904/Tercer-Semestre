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
nodo *comienzo();
nodo *liberiaMemoria(nodo *i);
nodo *eliminar_despues_x(nodo *i);
int main(){
	int num;
	nodo *i=NULL;
  	i= comienzo();
	iteractivo (i);
	i=eliminar_despues_x(i);
	iteractivo (i);
	i=eliminar_despues_x(i);
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
}

nodo *eliminar_despues_x(nodo *i) {
	int j, band = 1, aux;
	
	nodo *q, *r, *t;
	int num;
	float coef;
	i = creaNodo();
	
	printf("\n Introduzca el coeficiente (letra para terminar)");
	i=scanf("%f",&coef);
	fflush(stdin);
	printf("\n Introduzca la potencia (letra para terminar)");
	j=scanf("%d",&num);
	fflush(stdin);
	
	
	
	if ( i != 1 && j != 1 ) // 1
	 {
	 	free(i);
	 	i = NULL;
	 	return(i);
	 }
	  else   
	    
	    	
	    	if(coef != 0.0)
		      	{
				i->coef = coef;
				i->num = num;
				i->liga = NULL;
		     	}
			else
     	     { 
     	     free(i);
     	     i=NULL;
     	   //  return(i);
     		printf("\n El primer termino con coeficiente 0 no fue incluido: %5.2",coef );
			}
	    	
	   	do {
	      //	q= creanodo();
	      	
	printf("\n Introduzca el coeficiente (letra para terminar)");
	i=scanf("%f",&coef);
	fflush(stdin);
	printf("\n Introduzca la potencia (letra para terminar)");
	j=scanf("%d",&num);
	fflush(stdin);
	      
	        if ( i != 1 && j != 1)
	          {   
	 	      //  free(q);
	 	        band = 0;
	          }
	      	  else   // 2
	      	     {
	      	     
				 
		      if(coef != 0.0)
                 {
			      	     i = sortedInsert219052022(i, num, coef);
	             }
	             else
	                  {
	                  	printf("\n El termino con coeficiente 0 no fue incluido: %5.2",coef );
	                  	printf("\n y exponente  fue incluido: %d",num );
					
				   }
	             
			}// fin del else 2
	       }while (band == 1);
		  }// fin del else 1
	  return(i);	
}
