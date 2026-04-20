#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (){

    char *nombres[5];
    char *buffer = (char *)malloc(100 * sizeof(char));

    for (int i = 0 ; i < 5 ; i++){
       
        printf("ingresar nombre: ");
        gets(buffer);
        nombres[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nombres[i], buffer);
    }
    

    return 0 ;
}