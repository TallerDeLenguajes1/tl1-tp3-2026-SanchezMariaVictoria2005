#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mostrarNombres(char *nombres[]);
void BuscaNombrePorId(int n, char *nombres[]);
int BuscaNombrePorPalabra (char *palabraClave, char *nombres[]);

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

    int opcionMenu;
    int numero;
    puts("menu de busqueda de nombre:");
    puts("1-buscar nombre por id");
    puts("2-buscar por nombre");
    puts("elejir opcion:");
    scanf("%d", &opcionMenu);

    switch(opcionMenu)
    {
        case 1:
            printf("ingrese un numero");
            scanf("%d", &numero);
            BuscaNombrePorId(numero, nombres);
        break;
        case 2:
            puts("ingrese una palabra clave:");
            gets(buffer);
    
            if ((BuscaNombrePorPalabra (buffer,nombres)) == -1){
                puts("no se ha encontrado el nombre");
            }else{
                puts(nombres[BuscaNombrePorPalabra (buffer,nombres)]);
            }
            break;
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

void BuscaNombrePorId(int n, char *nombres[])
{
    if (0 <= n  && n < 5){
        puts(nombres[n]);
    }else{
        puts("no se ha encontrado el valor buscado");
    }

}

int BuscaNombrePorPalabra (char *palabraClave, char *nombres[])
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