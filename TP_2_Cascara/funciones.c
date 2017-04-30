#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "funciones.h"
#define CANT 20

void ObtenerEspacioLibre(EPersona lista[] ,int cantidad)
{
    int i;
    int contador = 0;
    int DNIrepetido;
    int DNIrespuesta;
    char auxnombre[64];
    char auxdni[9];
    char auxedad[64];

    printf("\n*********Carga de Personas*********\n\n");

    for(i=0 ;i<CANT; i++)
    {

        if(lista[i].estado!=1)
        {
            //DNI
            printf("Ingrese DNI |8 digitos|: ");
            IngresoDNI(auxdni);
            //Verificacion de DNI en la lista
            DNIrepetido = atoi(auxdni);
            DNIrespuesta = NumeroRepetido(lista ,cantidad ,DNIrepetido);
            if(DNIrespuesta != -1)
            {
                printf("\nERROR: El DNI %d fue ingresado anteriormente, Reingrese denuevo.\n" ,DNIrepetido);
                break;
            }
            else
            {
                lista[i].dni = DNIrepetido;
                //Nombres
                fflush(stdin);
                IngresoNombre("Ingrese Nombre: " ,auxnombre);
                strcpy(lista[i].nombre, auxnombre);
                //Edad
                printf("Ingrese Edad: ");
                IngresoEntreRango(auxedad ,"Edad" ,1 ,120);
                lista[i].edad = atoi(auxedad);
                //Estado de la Persona
                lista[i].estado = 1;
                break;
            }
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

void BajaDePersonas(EPersona lista[] ,int cantidad)
{
    int i;
    int busqueda;
    char resp;
    int reingreso = 0;

    printf("*********Baja de Personas*********\n");
    printf("Ingrese DNI: ");
    scanf("%d" ,&busqueda);

    for(i=0 ;i<CANT; i++)
    {
        if(busqueda == 0)
        {
            break;
        }
        else
        {
            if(busqueda == lista[i].dni)
            {
                printf("\n*Persona encontrada*\n\n");
                printf("Nombre: %s\nEdad: %d\nDNI: %d\n" ,lista[i].nombre ,lista[i].edad,lista[i].dni);

                printf("\nDesea Borrar a %s?\n" ,lista[i].nombre);
                do{
                printf("Ingrese S/N: ");
                fflush(stdin);
                scanf("%c" ,&resp);
                resp = tolower(resp);
                switch(resp)
                {
                    case 's':
                        lista[i].estado = 0;
                        lista[i].dni = 0;
                        printf("\nBorrado Exitoso!\n");
                        reingreso = 0;
                        break;

                    case 'n':
                        printf("\nOperacion Cancelada\n");
                        reingreso = 0;
                        break;

                    default:
                        printf("\nERROR: Ingrese una opcion valida!\n");
                        reingreso = 1;
                        break;
                }
                }while(reingreso == 1);
                break;
            }
        }
    }
    if(busqueda!=lista[i].dni && lista[i].dni>1)
    {
        printf("\nDNI no encontrado\n");
    }
}

void OrdenamientoDePersonas(EPersona lista[] ,int cantidad)
{
    int i ,j;
    cantidad = CANT;
    EPersona auxnombre;
    int vacio = 0;

    for(i=0 ;i<CANT; i++)
    {
        if(lista[i].estado == 1)
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
        else
        {
            vacio++;
        }
    }

    if(vacio == CANT)
    {
        printf("\nLista de Personas Vacia\n");
    }
    else
    {
        for(i=0 ;i<CANT; i++)
        {

            if(lista[i].estado == 1)
            {
                printf("\n-----------------\nNombre: %s\nEdad: %d\nDNI: %d\n" ,lista[i].nombre,lista[i].edad,lista[i].dni);
            }
        }
    }
    printf("\n");
}


void GraficoDePersonas(EPersona lista[] ,int cantidad)
{
    cantidad = CANT;
    int i = 0;
    int mayor;
    int bajo = 0; //hasta 18 años
    int medio = 0; //de 19 años a 35
    int alto = 0; //mayores de 35
    int flag = 0;
    char barra = 219;

    for(i=0 ;i<cantidad; i++)
    {
        if(lista[i].estado == 1)
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

    if(bajo>=medio && bajo>=alto)
    {
        mayor = bajo;
    }
    else
    {
        if(medio>=bajo && medio>=alto)
        {
            mayor = medio;
        }
        else
        {
            mayor = alto;
        }
    }

    printf("\n");

    for(i=mayor ;i>0; i--)
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
            printf(" %c" ,barra);
        }
        if(i<=medio)
        {
            flag = 1;
            printf("\t  %c" ,barra);
        }
        if(i<=alto)
        {
            if(flag == 0)
            {
                printf("\t\t %c" ,barra);
            }
            if(flag == 1)
            {
                printf("\t %c" ,barra);
            }
        }
        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35 ---Edades");
    printf("\n    %d\t  %d\t %d  ---Personas\n" ,bajo ,medio ,alto);
}

/**
Detectar numero repetido
*/

int NumeroRepetido(EPersona lista[], int tamanio, int numero)
{
    int indice = -1;
    int i;

    for(i=0; i<tamanio; i++)
    {
        if(lista[i].dni == numero)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/**
Ingrese de Nombres
*/
char* IngresoNombre(char texto[] ,char nombres[])
{
    printf("%s" ,texto);
    fflush(stdin);
    gets(nombres);

    while((!EsLetra(nombres)) || (esEspacio(nombres)))
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

char* IngresoDNI(char dni[])
{
    int tamanio;
    int i;

    fflush(stdin);
    gets(dni);

    while((EsLetra(dni)) || (strlen(dni)!=8) || (dni[0]=='-'))
    {
        printf("ERROR: Reingrese denuevo el DNI: ");
        fflush(stdin);
        gets(dni);
    }

    tamanio=strlen(dni);

    for(i=0 ;i<tamanio; i++)
    {
        while(isalpha(dni[i]))
        {
            printf("ERROR: Reingrese denuevo el DNI: ");
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

    while(EsLetra(valor) || (valor[0]=='-'))
    {
        fflush(stdin);
        printf("ERROR: reingrese %s: " ,texto);
        gets(valor);
    }

    valoraux = atoi(valor);

    while(valoraux<minimo || valoraux>maximo || valoraux =='-')
    {
        fflush(stdin);
        printf("ERROR: Reingrese %s entre %d-%d: " ,texto ,minimo ,maximo);
        scanf("%d" ,&valoraux);
    }

    sprintf(valor ,"%d", valoraux);

    return valor;
}

/**
Capitalizacion de letras
*/

char* Mayusculas(char caracter[])
{
    int i;
    int tamanio = strlen(caracter);
    int contador = 0;

    for(i=0 ;i<tamanio; i++)
    {
        if(isspace(caracter[i]))
        {
            contador = 0;
        }

        if(isalpha(caracter[i]) && !isspace(caracter[i]) && contador==0)
        {
            caracter[i] = toupper(caracter[i]);
            contador = 1;
        }
    }

    return caracter;
}

/**
Verificador de Letras
*/

int EsLetra(char ingreso[])
{
    int i = 0;
    int tamanio;
    int flag = 1;

    tamanio=strlen(ingreso);

    for(i=0 ;i<tamanio; i++)
    {
        if((ingreso[i]!=' ') && (ingreso[i]<'a'||ingreso[i]>'z') && (ingreso[i]<'A'||ingreso[i]>'Z'))
        {
            flag = 0;
        }
    }

    return flag;
}

/**
Verificador de Espacio
*/
int esEspacio(char ingreso[])
{
    int i = 0;

    while(ingreso[i]!='\0')
    {
        if((ingreso[i]!=' '))
        {
            return 0;
        }
        i++;
    }

    return 1;
}
