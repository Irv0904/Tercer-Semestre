#include <stdio.h>
#include <stdlib.h>

struct cnodo{
	float coef;
	float expo;
	struct cnodo* liga;
};

typedef struct cnodo nodo;

nodo* creaNodo(float coeficiente, float exponente);
nodo* multiplicarPolinomios(nodo* p, nodo* f);
void iterarLista(nodo* p);
nodo* crearPolinomio();
void ordenarLista(nodo* p);
nodo* sumaPolinomios(nodo* p, nodo* f);
nodo* liberarMemoria(nodo* p);

int main() {
	nodo* p = NULL;
	nodo* f = NULL;
	nodo* r = NULL;

	printf("\n\t*****Polinomio 1*****\n");
	p = crearPolinomio();
	ordenarLista(p);
	printf("\n\n\t*****Resultado del polinomio 1*****\n\t");
	iterarLista(p);

	printf("\n\t*****Polinomio 2*****\n");
	f = crearPolinomio();
	ordenarLista(f);
	printf("\n\n\t*****Resultado del polinomio 2*****\n\t");
	iterarLista(f);

	printf("\n\t*****Suma de los Polinomios*****\n");
	r = sumaPolinomios(p, f);
	iterarLista(r);

	printf("\tpolinomio 1 ");
	p = liberarMemoria(p);
	printf("\tpolinomio 2 ");
	f = liberarMemoria(f);
	printf("\tSuma de polinomio ");
	r = liberarMemoria(r);

	return 0;
}

nodo* creaNodo(float coeficiente, float exponente) {
	nodo* q = (nodo*)malloc(sizeof(nodo));
	if (q == NULL) {
		printf("No hay memoria disponible.\n");
		exit(1);
	}
	q->coef = coeficiente;
	q->expo = exponente;
	q->liga = NULL;
	return q;
}

void iterarLista(nodo* p) {
	nodo *v;
	if(p!=NULL){
		printf("\n");
		for(v=p;v!=NULL;v=v->liga){
			if(v->expo==0)
				printf("%.1fx-> ", v->coef);
			else
				printf("%.1fx^%.0f -> ", v->coef,v->expo);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

nodo* crearPolinomio() {
	nodo* inicio = NULL;
	nodo* final = NULL;
	float coef, expo;
	int j;
	do {
		printf("\nIngrese un coeficiente: ");
		j = scanf("%f", &coef);
		printf("Ingrese un exponente: ");
		j = scanf("%f", &expo);
		fflush(stdin);
		if (j == 1) {
		nodo* nuevo = creaNodo(coef, expo);
		if (inicio == NULL)
			inicio = nuevo;
		else
			final->liga = nuevo;
		final = nuevo;
		}
	} while (j == 1);
	return inicio;
}

nodo* sumaPolinomios(nodo* p, nodo* f) {
	nodo* resultado = NULL;
	nodo* ultimo = NULL;

	while (p != NULL && f != NULL) {
		nodo* temp = NULL;

		if (p->expo == f->expo) {
			temp = creaNodo(p->coef + f->coef, p->expo);
			p = p->liga;
			f = f->liga;
		}
		else if (p->expo > f->expo) {
			temp = creaNodo(p->coef, p->expo);
			p = p->liga;
		}
		else {
			temp = creaNodo(f->coef, f->expo);
			f = f->liga;
		}

		if (resultado == NULL) {
			resultado = temp;
			ultimo = temp;
		}
		else {
			ultimo->liga = temp;
			ultimo = temp;
		}
	}

	if (p != NULL) {
		if (resultado == NULL)
			resultado = p;
		else
			ultimo->liga = p;
	}
	else if (f != NULL) {
		if (resultado == NULL)
			resultado = f;
		else
			ultimo->liga = f;
	}

	return resultado;
}

nodo* liberarMemoria(nodo* p) {
	nodo* temp;
	while (p != NULL) {
		temp = p;
		p = p->liga;
		free(temp);
	}
	printf("Liberado\n\n");
	return NULL;
}

void ordenarLista(nodo* p) {
	if (p == NULL || p->liga == NULL) {
		// No es necesario ordenar una lista vacía o con un solo elemento
		return;
	}

	int intercambiado;
	nodo* actual;
	nodo* siguiente = NULL;

	do {
		intercambiado = 0;
		actual = p;

		while (actual->liga != siguiente) {
            if (actual->expo < actual->liga->expo) {
                // Intercambiar los nodos si están en el orden incorrecto
					float tempCoef = actual->coef;
					float tempExpo = actual->expo;
					actual->coef = actual->liga->coef;
					actual->expo = actual->liga->expo;
					actual->liga->coef = tempCoef;
					actual->liga->expo = tempExpo;
					intercambiado = 1;
            }
            actual = actual->liga;
		}
		siguiente = actual;
	} while (intercambiado);
}