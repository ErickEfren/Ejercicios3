#include <stdio.h>
#include <stdlib.h>

int main(int num_par, char **par_cad){

    //Variables
    FILE *p; //apuntador para direccion de archivo
    float *A, n;
    int i=0;

    //Verificar que el usuario ingrese 3 parámetros: archivo a ejecutar, n, fichero
    if(num_par!=3)
        exit(1);
    
    // Designamos tamaño del arreglo
    n=atoi(par_cad[1]);
    A=(float*)malloc(n*sizeof(int));

    //Lectura del archivo
    if(!(p=fopen(par_cad[2],"r"))) // Verificamos que el archivo exista
    {
        printf("\nError al abrir el fichero");
        exit(1); // Abandonamos el programa
    }
    while(!feof(p) && i<n) // Llenar el arreglo mientras i < n y no haya fin de archivo
    {
        fscanf(p, "%f", &A[i]); // Leemos los números y guardamos en el arreglo
        i++;
    }
    fclose(p);

    //Calculo del promedio
    int prom=0;
    for(i=0;i<n;i++)
        prom+=A[i];
	printf("real (Tiempo total)  %.10f s\n",  prom/n);
	printf("\n");

    //Liberamos memoria
    free(A);

    return 0;
}
