#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mostrarNombres(char *nombres[]);
int BuscarNombre (char *palabraClave, char *nombres[]);

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
    puts("ingrese una palabra clave:");
    gets(buffer);
    
    if ((BuscarNombre (buffer,nombres)) == -1){
        puts("no se ha encontrado el nombre");
    }else{
        puts(nombres[BuscarNombre (buffer,nombres)]);
    }
    

    return 0 ;
}


void mostrarNombres(char *nombres[])
{
    puts("funcion para mostrar nombres:");
    for (int i = 0 ; i < 5 ; i++){
        puts(nombres[i]);
    }
}

int BuscarNombre (char *palabraClave, char *nombres[])
{
    char *aux = NULL;
    int indice = -1;
    for (int i = 0 ; i < 5; i++){
        aux = strstr(nombres[i],palabraClave);
        if (aux != NULL){
            indice = i;
        }
    }
        return indice;
}