#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

int ProductoDosMayores(int *A, int n){
    int mayor1, mayor2, i = 0;
    if(A[0] > A[1]){
        mayor1 = A[0];
        mayor2 = A[1];
    }
    else{
        mayor1 = A[1];
        mayor2 = A[0];
    }
    i = 2;

    while (i < n){
        if (A[i] > mayor1){
            mayor2 = mayor1;
            mayor1 = A[i];
        }else if (A[i] > mayor2) {
            mayor2 = A[i];
        }
        i = i + 1;
    }

    return (mayor1 * mayor2);
}


void func (int *A, int n){	
	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i; //Variables para loops
		
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento	
	uswtime(&utime0, &stime0, &wtime0);
		
	//Algoritmo	
        ProductoDosMayores(A, n);
	
	//Evaluar los tiempos de ejecución 
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("\n");
}

int main(int num_par, char **par_cad){

    //Variables
    FILE *p; //apuntador para direccion de archivo
    int *A, n, i=0;

    //verificar que el usuario ingrese 3 parametros: archivo a ejecutar, n, fichero
    if(num_par!=3)
        exit(1);
    
    // designamos tamaño del arreglo
    n=atoi(par_cad[1]);
    A=(int*)malloc(n*sizeof(int));

    //Lectura del archivo
    if(!(p=fopen(par_cad[2],"r")))//verificamos que el archivo exista
    {
        printf("\nError al abrir el fichero");
        exit(1); // abandonamos el programa
    }
    while(!feof(p) && i<n)// llenar el arreglo mientras i < n y no haya fin de archivo
    {
        fscanf(p, "%d", &A[i]); //leemos los numeros y guardamos en el arreglo
        i++;
    }
    fclose(p);

    //Ejecucion del algoritmo
    func(A, n);

    //liberamos memoria
    free(A);

    return 0;
}
