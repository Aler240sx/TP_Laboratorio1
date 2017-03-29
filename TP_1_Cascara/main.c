#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int operando1=0;
    int operando2=0;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        if(operando1==0)
        {
            printf("1- Ingresar 1er operando (A)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%d)\n" ,operando1);
        }

        if(operando2==0)
        {
            printf("2- Ingresar 2do operando (B)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n" ,operando2);
        }

        if(operando1==0&&operando2==0)
        {
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
        }
        else
        {
            printf("3- Calcular la suma (%d+%d)\n" ,operando1,operando2);
            printf("4- Calcular la resta (%d-%d)\n" ,operando1,operando2);
            printf("5- Calcular la division (%d/%d)\n" ,operando1,operando2);
            printf("6- Calcular la multiplicacion (%d*%d)\n" ,operando1,operando2);
            printf("7- Calcular el factorial (%d!)\n" ,operando1);
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
        }

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                operando1=ingreso("Ingrese Primer Numero" ,"numero",0 ,10000);
                break;
            case 2:
                operando2=ingreso("Ingrese Segundo Numero" ,"numero",0 ,10000);
                break;
            case 3:
                sumar(operando1,operando2);
                break;
            case 4:
                restar(operando1,operando2);
                break;
            case 5:
                dividir(operando1,operando2);
                break;
            case 6:
                multiplicar(operando1,operando2);
                break;
            case 7:
                printf("\nLa Factorial del Ingreso A es: %f\n" ,factorial(operando1));
                break;
            case 8:
                sumar(operando1,operando2);
                restar(operando1,operando2);
                dividir(operando1,operando2);
                multiplicar(operando1,operando2);
                printf("\nLa Factorial del Ingreso A es: %f\n" ,factorial(operando1));
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("\nERROR: Ingrese un numero entre 1-9\n");
                break;
        }//switch
        system("\npause");
        system("\ncls");
    }//while
    return 0;
}//main
