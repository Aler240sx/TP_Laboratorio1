#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#include "ctype.h"
#define CANT 3

void obtenerEspacioLibre(EPersona lista[],int cantidad)
{
    int i;
    int contador = 0;
    char auxnombre[64];
    char auxdni[64];
    char auxedad[64];

    printf("*********Carga de Personas*********\n");

    for(i=0 ;i<CANT; i++)
    {

        if(lista[i].estado!=1)
        {
            //Nombres
            fflush(stdin);
            ingresonombre("Ingrese Nombre: ",auxnombre);
            strcpy(lista[i].nombre, auxnombre);
            //Edad
            printf("Ingrese Edad: ");
            IngresoEntreRango(auxedad ,"Edad" ,1 ,120);
            lista[i].edad = atoi(auxedad);
            //DNI
            printf("Ingrese DNI |8 digitos|: ");
            ingresodni(auxdni);
            lista[i].dni = atoi(auxdni);
            //Estado de la Persona
            lista[i].estado = 1;
            //contadores;
            break;
        }
        else
        {
            contador++;
        }

        if(contador == CANT)
        {
            printf("\nNo Hay Espacio Disponible\n");
        }
    }
}

void BajaDePersonas(EPersona lista[],int cantidad)
{
    int i;
    int busqueda;
    char resp;

    printf("*********Baja de Personas*********\n");
    printf("Ingrese DNI: ");
    scanf("%d" ,&busqueda);

    for(i=0 ;i<CANT; i++)
    {
        if(busqueda == lista[i].dni)
        {
            printf("\n*Persona encontrada*\n\n");
            printf("Nombre: %s\nEdad: %d\nDNI: %d\n" ,lista[i].nombre,lista[i].edad,lista[i].dni);

            printf("\nDesea Borrar a %s?\n" ,lista[i].nombre);
            printf("Ingrese S/N: ");
            fflush(stdin);
            scanf("%c" ,&resp);
            switch(resp)
            {
                case 's':
                case 'S':
                    lista[i].estado = 0;
                    printf("\nBorrado!\n");
                    break;

                case 'n':
                case 'N':
                    printf("\nOperacion Cancelada\n");
                    break;

                default:
                    printf("\nERROR Ingrese S o N\n");
                    break;
            }
            break;
        }
    }
    if(busqueda!=lista[i].dni)
    {
        printf("\nDNI no encontrado\n");
    }
}

void OrdenamientoDePersonas(EPersona lista[] ,int cantidad)
{
    int i;
    int j;
    int opcion;

    EPersona auxnombre;

    printf("\nOrdenamiento:\n1-A a Z\n2-Z a A\n\n");
    printf("Ingrese Ordenamiento: ");
    scanf("%d" ,&opcion);

    switch(opcion)
    {
        case 1:
            for(i=0 ;i<CANT; i++)
            {
                for(j=i+1 ;j<CANT; j++)
                {
                    if(strcmp(lista[i].nombre , lista[j].nombre)>0)
                    {
                        auxnombre = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxnombre;
                    }
                }
            }
            break;
        case 2:
            for(i=0 ;i<CANT; i++)
            {
                for(j=i+1;j<CANT;j++)
                {
                    if(strcmp(lista[i].nombre , lista[j].nombre)<0)
                    {
                        auxnombre = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxnombre;
                    }
                }
            }
            break;
        default:
            printf("\nIngrese una opcion del menu!\n");
            break;
    }

    for(i=0 ;i<CANT; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n-----------------\nNombre: %s\nEdad: %d\nDNI: %d\n" ,lista[i].nombre,lista[i].edad,lista[i].dni);
        }

    }
    printf("\n\n");
}

void GraficoDePersonas(EPersona lista[] ,int cantidad)
{
    cantidad=CANT;
    int i=0;
    int mayor;
    int bajo=0; //hasta 18 años
    int medio=0; //de 19 años a 35
    int alto=0; //mayores de 35
    int flag=0;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].edad<=18)
            {
                bajo++;
            }
            else if(lista[i].edad>=19 && lista[i].edad<=35)
            {
                medio++;
            }
            else if(lista[i].edad>35)
            {
                alto++;
            }
        }
    }

    if(bajo>=medio&&bajo>=alto)
    {
        mayor=bajo;
    }
    else
    {
        if(medio>=bajo&&medio>=alto)
        {
            mayor=medio;
        }
        else
        {
            mayor=alto;
        }
    }
    for(i=mayor;i>0;i--)
    {
        if(i<cantidad)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }
        if(i<=bajo)
        {
            printf("*");
        }
        if(i<=medio)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=alto)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35 ----->Rango de Edades");
    printf("\n   %d\t%d\t%d -----> Personas\n", bajo, medio, alto);
}

/**
Ingrese de Nombres
*/
char* ingresonombre(char texto[], char nombres[])
{
    printf("%s" ,texto);
    fflush(stdin);
    gets(nombres);

    while((!esletra(nombres)) || (esEspacio(nombres)))
    {
        fflush(stdin);
        printf("ERROR: Reingrese Nombre: ");
        gets(nombres);
    }

    strlwr(nombres);
    Mayusculas(nombres);

    return nombres;
}

/**
Ingreso de DNI
*/

char* ingresodni(char dni[])
{
    int tamanio;
    int i;

    fflush(stdin);
    gets(dni);

    while((esletra(dni)) || (strlen(dni)!=8))
    {
        printf("ERROR: Reingrese denuevo el dni: ");
        fflush(stdin);
        gets(dni);
    }

    tamanio=strlen(dni);

    for(i=0 ;i<tamanio; i++)
    {
        while(isalpha(dni[i]))
        {
            printf("ERROR: Reingrese denuevo el dni: ");
            fflush(stdin);
            gets(dni);
            i++;
        }
    }

    return dni;
}

/**
Ingreso de Edad
*/

char* IngresoEntreRango(char valor[] ,char texto[],int minimo,int maximo)
{
    int valoraux;

    fflush(stdin);
    gets(valor);

    while(esletra(valor))
    {
        fflush(stdin);
        printf("ERROR: reingrese %s: " ,texto);
        gets(valor);
    }

    valoraux = atoi(valor);

    while(valoraux<minimo || valoraux>maximo)
    {
        fflush(stdin);
        printf("ERROR: Reingrese %s entre 1-%d: " ,texto ,maximo);
        scanf("%d" ,&valoraux);
    }

    sprintf(valor, "%d" ,valoraux);

    return valor;
}

/**
Capitalizacion de letras
*/

char* Mayusculas(char a[])
{
    int i;
    int tamanio = strlen(a);
    int contador = 0;

    for(i=0 ;i<tamanio; i++)
    {
        if(isspace(a[i]))
        {
            contador = 0;
        }

        if(isalpha(a[i]) && !isspace(a[i]) && contador==0)
        {
            a[i] = toupper(a[i]);
            contador = 1;
        }
    }

    return a;
}

/**
Verificador de Letras
*/

int esletra(char ingreso[])
{
    int i = 0;
    int tamanio;
    int flag=1;

    tamanio=strlen(ingreso);

    for(i=0;i<tamanio;i++)
    {
        if((ingreso[i]!=' ') && (ingreso[i]<'a'||ingreso[i]>'z') && (ingreso[i]<'A'||ingreso[i]>'Z'))
        {
            flag=0;
        }
    }

    return flag;
}

int esEspacio(char ingreso[])
{
    int i = 0;

    while(ingreso[i]!='\0')
    {
        if((ingreso[i]!=' '))
        return 0;
        i++;
    }

    return 1;
}
