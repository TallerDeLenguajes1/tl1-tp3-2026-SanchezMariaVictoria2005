#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    struct Producto {
        int ProductoID; //Numerado en ciclo iterativo
        int Cantidad; // entre 1 y 10
        char *TipoProducto; // Algún valor del arreglo TiposProductos
        float PrecioUnitario; // entre 10 - 100
    }typedef Producto;
    
    struct Cliente {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
        int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
        Producto *Productos; //El tamaño de este arreglo depende de la variable
    }typedef Cliente;

    float costoTotal(int producto, float precio_unitario);
    void mostrarDatos(Cliente *clientes, int cantidadClientes);

int main (){
    srand(time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    
    int cantidadClientes;
    int n; // id de TiposProductos
    float precioTotal = 0 ;
    
    puts("ingrese la cantidad de clientes:");
    scanf("%d", &cantidadClientes);

    Cliente *clientes = (Cliente *)malloc((cantidadClientes) * sizeof(Cliente)); // +1 solo en caracteres
    

    for (int i = 0 ; i < cantidadClientes ; i++){ //for principal con los datos del cliente
        clientes->ClienteID = i;
        puts("ingrese el nombre del cliente");
        clientes->NombreCliente = (char *)malloc(100 * sizeof(char)); //usar buffer + reserva + strcpy
        fflush(stdin);
        gets(clientes->NombreCliente); //corregido
        clientes->CantidadProductosAPedir = rand() % 5 + 1;
        clientes->Productos = (Producto *)malloc((clientes->CantidadProductosAPedir) * sizeof(Producto));

            
            for (int j = 0 ; j < clientes->CantidadProductosAPedir; j++){ //for para cargar productos
                clientes->Productos->ProductoID = i;
                clientes->Productos->Cantidad = rand() % 10 + 1;
                n = rand() % 5;
                clientes->Productos->TipoProducto = TiposProductos[n]; // corregido
                clientes->Productos->PrecioUnitario = rand() % 100 + 10;
            
                precioTotal += costoTotal(clientes->Productos->Cantidad, clientes->Productos->PrecioUnitario);
                clientes->Productos++;
            }
             clientes->Productos -= clientes->CantidadProductosAPedir ;

        clientes++;
    } 


    clientes-= cantidadClientes;
   
    mostrarDatos(clientes,cantidadClientes);

    
    return 0;

}

float costoTotal(int producto, float precio_unitario)
{
    return producto * precio_unitario;
}

void mostrarDatos(Cliente *clientes, int cantidadClientes)
{
    

    for (int i = 0 ; i < cantidadClientes ; i++){
        printf("\n cantidad de productos a pedir: %d", clientes->CantidadProductosAPedir);
        printf("\n ID del cliente: %d", clientes->ClienteID);
        puts(clientes->NombreCliente);

        for (int j = 0 ; j < clientes->CantidadProductosAPedir; j++){
            printf("\n cantidad de productos: %d", clientes->Productos->Cantidad);
            printf("\n precio unitario: %f", clientes->Productos->PrecioUnitario);
            printf("\n ID del producto: %d", clientes->Productos->ProductoID);
            clientes->Productos++;
        }
        clientes++;
    }
}