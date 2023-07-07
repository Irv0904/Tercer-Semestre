/*
realizado por: Irving Jhon Villarreal Lasso
Cedula: 8-1063-2312
fecha de sustentacion: 08/7/2023
calificacion:*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct datos{
	int num;
	struct datos *liga;
};

typedef struct datos nodo;
void octal();
void decimal_octal();
void octal_decimal();
void hexadecimal();
void decimal_hexadecimal();
void hexadecimal_decimal();
void binarios();
void decimal_binario();
void binario_decimal();

int main(){
	int opcion,s;
	do{
		system("cls");	
		printf("\t\t\t*Binario, Octall, Gexadecimal a Decimal o Viceversa*\n");
		printf("\n\t1->octall\n\t2->hexadecimal\n\t3->binario\n\t4->salir\n\topcion: ");
		s=scanf("%d", &opcion);
		fflush(stdin);
		if(s==1){
		system("CLS");
		switch(opcion){
			case 1:
				octal();
				printf("\n\n");	
				system("PAUSE");
				break;
			case 2:
				hexadecimal();
				printf("\n\n");	
				system("PAUSE");
				break;
			case 3:
				binarios();
				printf("\n\n");	
				system("PAUSE");
				break;
			case 4:
				break;
			default:
				printf("Opcion invalida, ingrese otro numero que esta en la lista");
			}
		}else{
		printf("\nopcion invalida. ingrese una opcion numerica de la lista.\n");
		system("PAUSE");
	}
	}while(opcion!=4);
	return 0;
}

void octal(){
int opcion,s;
	do{
		system("cls");	
		printf("\t\t\t*Decimal a octall o Viceversa*\n");
		printf("\n\t1->Decimal a octall\n\t2->Octall a decimal\n\t3->salir\n\topcion: ");
		s=scanf("%d", &opcion);
		fflush(stdin);
		if(s==1){
		system("CLS");
		switch(opcion){
			case 1:
				decimal_octal();
				printf("\n\n");	
				system("PAUSE");
				break;
			case 2:
				octal_decimal();
				printf("\n\n");	
				system("PAUSE");
				break;
			case 3:
				break;
			}
		}else{
		printf("\nopcion invalida. ingrese una opcion numerica de la lista.\n");
		system("PAUSE");
	}
	}while(opcion!=3);
	return;	
}

void hexadecimal(){
int opcion,s;
do{
	system("cls");	
	printf("\t\t\t*Decimal a Hexadecimal o Viceversa*\n");
	printf("\n\t1->Decimal a hexadecimal\n\t2->hexadecimal a decimal\n\t3->salir\n\topcion: ");
	s=scanf("%d", &opcion);
	fflush(stdin);
	if(s==1){
	system("CLS");
	switch(opcion){
		case 1:
			decimal_hexadecimal();
			printf("\n\n");	
			system("PAUSE");
			break;
		case 2:
			hexadecimal_decimal();
			printf("\n\n");	
			system("PAUSE");
			break;
		case 3:
			break;
		}
	}else{
	printf("\nopcion invalida. ingrese una opcion numerica de la lista.\n");
	system("PAUSE");
}
}while(opcion!=3);
return;	
}

void binarios(){
int opcion,s;
do{
	system("cls");	
	printf("\t\t\t*Decimal a Binario o Viceversa*\n");
	printf("\n\t1->Decimal a binario\n\t2->binario a decimal\n\t3->salir\n\topcion: ");
	s=scanf("%d", &opcion);
	fflush(stdin);
	if(s==1){
	system("CLS");
	switch(opcion){
		case 1:
			decimal_binario();
			printf("\n\n");	
			system("PAUSE");
			break;
		case 2:
			binario_decimal();
			printf("\n\n");	
			system("PAUSE");
			break;
		case 3:
			break;
		}
	}else{
	printf("\nopcion invalida. ingrese una opcion numerica de la lista.\n");
	system("PAUSE");
}
}while(opcion!=3);
return;		
}

void decimal_octal(){
	int octnum=0, temp=1;
	int num;
	printf("ingrese un decimal: ");
	scanf("%d",&num);
	fflush(stdin);
	while(num!=0){
		octnum=octnum+(num%8)*temp;
		num=num/8;
		temp=temp*10;
	}
	printf("\nel numero convertido a octal es: %d",octnum);
	return;
}

void octal_decimal(){
	int decinum=0, octnum, expo=0;
	printf("ingrese un numero octal: ");
	scanf("%d",&octnum);
	fflush(stdin);
	while(octnum>0){
		decinum=decinum+(octnum%10*pow(8, expo));
		octnum=octnum/10;
		expo++;
	}
	printf("\nel numero convertido a decimal es: %d",decinum);
	return;
}

void decimal_hexadecimal(){
	int num, i = 0, hexanum[999]; 
    printf("Ingresa un numero decimal: ");
    scanf("%i",&num);
	while (num!=0){
		hexanum[i] = num%16; 
		num = num /16; 
		i++;
	}
	i--;
	printf("Resultado en Hexadecimal: ");
	while (i>=0){
		switch(hexanum[i]){
							case 10:
								printf("A");
							break;
							case 11:
								printf("B");
							break;
							case 12:
								printf("C");
							break;
							case 13:
								printf("D");
							break;
							case 14:
								printf("E");
							break;
							case 15:
								printf("F");
							break;
							default:
								printf("%i",hexanum[i]); 
							break;
		} 
		i--;
	}printf("\n");
	return;
}

void hexadecimal_decimal(){
char hex[8];
int sum=0, i=0, j=7;
for(i=0; i<8; i++){
	hex[i]=0;
}	
i=-1;
printf("Escriba un numero hexadecimal: ");
scanf("%s",hex);
fflush(stdin);
for(j=7; j>=0; j--){
	switch(hex[j]){
		case '0':
			i++;
			sum+=0*pow(16, i);
			break;
		case 1:
			i++;
			sum+=1*pow(16, i);
			break;
		case 2:
			i++;
			sum+=2*pow(16, i);
			break;
		case 3:
			i++;
			sum+=3*pow(16, i);
			break;
		case 4:
			i++;
			sum+=4*pow(16, i);
			break;
		case 5:
			i++;
			sum+=5*pow(16, i);
			break;
		case 6:
			i++;
			sum+=6*pow(16, i);
			break;
		case 7:
			i++;
			sum+=7*pow(16, i);
			break;
		case 8:
			i++;
			sum+=8*pow(16, i);
			break;
		case 9:
			i++;
			sum+=9*pow(16, i);
			break;
		case 'A':
			i++;
			sum+=10*pow(16, i);
			break;
		case 'B':
			i++;
			sum+=11*pow(16, i);
			break;
		case 'C':
			i++;
			sum+=12*pow(16, i);
			break;
		case 'D':
			i++;
			sum+=13*pow(16, i);
			break;
		case 'E':
			i++;
			sum+=14*pow(16, i);
			break;
		case 'F':
			i++;
			sum+=15*pow(16, i);
			break;
	}
}
printf("el numero convertido en decimal es: %d", sum);
return;
}

void decimal_binario(){
	int decinum, j, i, a[100000];
	i=0;
	printf("Ingrese un decimal: ");
	scanf("%d",&decinum);
	fflush(stdin);
	while(decinum>0){
		a[i]=decinum%2;
		decinum/=2;
		++i;
	}
	for(j=i-1; j>=0; --j)
		printf("%d", a[j]);
	printf("\n");
	return ;
}

void binario_decimal() {
    int binanum, decinum, posicion = 0, resultado = 0;
    printf("Ingrese un numero binario: ");
    scanf("%d", &binanum);

    while (binanum > 0) {
        decinum = binanum % 10;
        if (decinum == 1) {
            resultado = resultado + (1 << posicion);
        }
        posicion++;
        binanum = binanum / 10;
    }

    printf("El numero convertido a decimal es: %d\n", resultado);
}