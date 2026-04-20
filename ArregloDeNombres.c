#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mostrarNombres(char *nombres[]);
void BuscarNombre(int n, char *nombres[]);

int main (){

    char *nombres[5];
    char *buffer = (char *)malloc(100 * sizeof(char));

    for (int i = 0 ; i < 5 ; i++){
       
        printf("ingresar nombre: ");
        gets(buffer);
        nombres[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nombres[i], buffer);
    }

    mostrarNombres(nombres);

    int numero;
    printf("ingrese un numero");
    scanf("%d", &numero);
    BuscarNombre(numero, nombres);
    

    return 0 ;
}


void mostrarNombres(char *nombres[])
{
    puts("funcion para mostrar nombres:");
    for (int i = 0 ; i < 5 ; i++){
        puts(nombres[i]);
    }
}

void BuscarNombre(int n, char *nombres[])
{
    if (0 <= n  && n < 5){
        puts(nombres[n]);
    }else{
        puts("no se ha encontrado el valor buscado");
    }

}