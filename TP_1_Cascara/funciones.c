#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Ingreso de numeros con validacion y rangos
 *
 * \param muestra un texto en pantalla
 * \param tomo el numero que el usuario ingresa y verifica que se cumpla la condicion
 * \return el valor que se ingreso verificado
 *
 */

int ingreso (char texto[],char err0r[], int min,int max)
{
    int z;

    printf("\n%s: ",texto);
    scanf("%d" ,&z);

    while(z<min||z>max||isalpha(z))
    {
        fflush(stdin);
        printf("\nERROR: Reingrese un %s : ",err0r);
        scanf("%d" ,&z);
    }

    return z;
}

/** \brief Suma de numeros
 *
 * \param suma los valores X y Y ingresados previamente
 * \param muestro el resultado en pantalla
 * \return el resultado
 *
 */

int sumar (int x, int y)
{
    int resultado;

    resultado=x+y;
    printf("\nLa Suma de los numeros ingresados es: %d\n" ,resultado);

    return resultado;
}

/** \brief Resta de numeros
 *
 * \param resta los valores X y Y ingresados previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

int restar (int x, int y)
{
    int resultado;

    resultado=x-y;
    printf("\nLa Resta de los numeros ingresados es: %d\n" ,resultado);

    return resultado;
}

/** \brief Multiplicacion de numeros
 *
 * \param multiplica los valores X y Y ingresados previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

int multiplicar (int x, int y)
{
    float resultado;

    resultado=x*y;
    printf("\nLa Multiplicacion de los numeros ingresados es: %.2f\n" ,resultado);

    return resultado;
}

/** \brief Division de numeros
 *
 * \param divide los valores X y Y ingresados previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

int dividir (int x, int y)
{
    float resultado;

    if(y==0)
    {
        printf("\nNo se puede divir por cero\n");
    }
    else
    {
        resultado=(float)x/y;
        printf("\nLa Division de los numeros ingresados es: %.2f\n" ,resultado);
    }

    return resultado;
}

/** \brief Factorial de un numero
 *
 * \param Factorea el valor de X ingresado previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

float factorial(int z)
{
    int resultado;

    if(z==0)
    {
        resultado=1;
    }
    else
    {
        resultado=z*factorial(z-1);
    }

    return resultado;
}

    /*
    float fact=1;
    int i;

    for(i=1;i<=z;i++)
    {
        fact=(float)fact*i;
    }
    return fact;
    */
