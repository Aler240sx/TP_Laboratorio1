#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EMovie pelis;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar Pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(&pelis);
                break;
            case 2:
                borrarPelicula(&pelis,1,"");
                break;
            case 3:
                modificarPelicula(&pelis);
               break;
            case 4:
                generarPagina(pelis);
               break;
            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
