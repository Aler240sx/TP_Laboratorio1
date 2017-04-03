#include <stdio.h>
#include "funciones.h"

/** \brief Ingreso de numeros con validacion y rangos
 *
 * \param muestra un texto en pantalla
 * \param tomo el numero que el usuario ingresa y verifica que se cumpla la condicion
 * \return el valor que se ingreso verificado
 *
 */

float ingreso (char texto[],char err0r[])
{
    float z;

    printf("\n%s: ",texto);
    while(scanf("%f" ,&z)!=1)
    {
        fflush(stdin);
        printf("\nERROR-Ingrese un %s no letras! : ",err0r);
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

float sumar (float x, float y)
{
    float resultado;

    resultado=x+y;
    printf("\nLa Suma de los numeros ingresados es: %.2f\n" ,resultado);

    return resultado;
}

/** \brief Resta de numeros
 *
 * \param resta los valores X y Y ingresados previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

float restar (float x, float y)
{
    float resultado;

    resultado=x-y;
    printf("\nLa Resta de los numeros ingresados es: %.2f\n" ,resultado);

    return resultado;
}

/** \brief Multiplicacion de numeros
 *
 * \param multiplica los valores X y Y ingresados previamente
 * \param muestra el resultado en pantalla
 * \return el resultado
 *
 */

float multiplicar (float x, float y)
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

float dividir (float x, float y)
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
    int auxnum;
    int resultado;

    auxnum=(int)z;

    if(z<=0)
    {
        resultado=1;
    }
    else
    {
        resultado=auxnum*factorial(z-1);
    }

    return resultado;
}
