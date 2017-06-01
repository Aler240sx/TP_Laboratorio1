#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "funciones.h"

/**
Funcion para guardar una pelicula en un archivo binario.
*/

int guardarPelicula(EMovie* pelicula)
{
    FILE* documento;

    documento=fopen("peliculas.dat","ab+");

    if(documento==NULL)
    {
        printf("ERROR: No Hay Memoria disponible");
        return 0;
    }

    fwrite(pelicula,sizeof(EMovie),1,documento);

    fclose(documento);
    return 1;
}

/**
Funcion para agregar una pelicula a una lista en un archivo binario.
*/

int agregarPelicula(EMovie* pelicula)
{
    char auxDuracion[32];
    char auxPuntacion[32];

    printf("******** CARGA DE PELICULAS ********\n");

    printf("Ingrese Titulo de la Pelicula: ");
    fflush(stdin);
    gets(pelicula->titulo);
    printf("Ingrese Genero de la Pelicula: ");
    fflush(stdin);
    gets(pelicula->genero);
    printf("Ingrese Duracion de la Pelicula: ");
    IngresoEntreRango(auxDuracion, "Tiempo" ,1,10000,"en minutos");
    pelicula->duracion = atoi(auxDuracion);
    printf("Ingrese Descripcion de la Pelicula: ");
    fflush(stdin);
    gets(pelicula->descripcion);
    printf("Ingrese Puntaje de la Pelicula: ");
    IngresoEntreRango(auxPuntacion, "Puntaje", 1,100 ,"");
    pelicula->puntaje = atoi(auxPuntacion);
    printf("Ingrese Link de la Pelicula: ");
    fflush(stdin);
    gets(pelicula->linkImagen);

    return guardarPelicula(pelicula);
}

/**
Funcion para borrar una pelicula dentro de un archivo binario.
*/

int borrarPelicula(EMovie *peliculab ,int opcion, char buscarF[])
{
    char buscar[20];


    FILE* Documento;
    FILE* PreCarga;

    if(opcion!=0)
    {
        printf("******** ELIMINAR PELICULA ********\n");

        printf("Ingrese el Titulo de la pelicula a borrar: ");
        fflush(stdin);
        gets(buscar);
    }
    else
    {
        strcpy(buscar, buscarF);
    }

    peliculab = buscarPelicula(buscar);

    if(peliculab!=NULL)
    {
        PreCarga=fopen("PreCargar.dat","wb+");
        Documento=fopen("peliculas.dat","rb");

        EMovie pelicula;

        while(fread(&pelicula, sizeof(EMovie),1, Documento) != 0)
        {
            if (strcmp(buscar, pelicula.titulo))
            {
                fwrite(&pelicula, sizeof(EMovie),1, PreCarga);
            }
        }

        fclose(Documento);
        fclose(PreCarga);

        PreCarga=fopen("PreCargar.dat","rb");
        Documento=fopen("peliculas.dat","wb");

        while(fread(&pelicula, sizeof(EMovie),1, PreCarga))
        {
            fwrite(&pelicula, sizeof(EMovie),1, Documento);
        }

        fclose(Documento);
        fclose(PreCarga);

        if(opcion!=0)
        {
            printf("\nPelicula Borrada!\n");
        }
        else
        {

        }
    }
    else
    {
        printf("La Pelicula %s no existe en la lista\n\n" ,buscar);
    }

    return 1;
}

/**
Funcion para Modificar los datos de una pelicula en un archivo binario
*/

int modificarPelicula(EMovie* pelicula)
{
    int opcion;
    int respuesta = 0;
    char resp='s';
    char buscar[20];
    char auxDuracion[32];
    char auxPuntacion[32];

    printf("Ingrese el Titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(buscar);

    pelicula = buscarPelicula(buscar);

    if(pelicula!=NULL)
    {
        while(resp=='s')
        {
            system("cls");
            printf("******** MODIFICAR PELICULA ********\n");
            printf("1- Titulo: %s\n", pelicula->titulo);
            printf("2- Genero: %s\n", pelicula->genero);
            printf("3- Duracion: %d minutos\n", pelicula->duracion);
            printf("4- Descripcion: %s\n", pelicula->descripcion);
            printf("5- Puntaje: %d\n", pelicula->puntaje);
            printf("6- Imagen URL: %s\n\n", pelicula->linkImagen);
            printf("7- Salir sin modificar nada\n");
            printf("8- Guardar y Salir\n\n");

            printf("Opcion: ");
            scanf("%d" ,&opcion);

            switch(opcion)
            {
                case 1:
                    printf("Ingrese Titulo de la Pelicula: ");
                    fflush(stdin);
                    gets(pelicula->titulo);
                    break;
                case 2:
                    printf("Ingrese Genero de la Pelicula: ");
                    fflush(stdin);
                    gets(pelicula->genero);
                    break;
                case 3:
                    printf("Ingrese Duracion de la Pelicula: ");
                    IngresoEntreRango(auxDuracion, "Tiempo" ,1,10000,"en minutos");
                    pelicula->duracion = atoi(auxDuracion);
                    break;
                case 4:
                    printf("Ingrese Descripcion de la Pelicula: ");
                    fflush(stdin);
                    gets(pelicula->descripcion);
                    break;
                case 5:
                    printf("Ingrese Puntaje de la Pelicula: ");
                    IngresoEntreRango(auxPuntacion, "Puntaje", 1,100 ,"");
                    pelicula->puntaje = atoi(auxPuntacion);
                    break;
                case 6:
                    printf("Ingrese Link de la Pelicula: ");
                    fflush(stdin);
                    gets(pelicula->linkImagen);
                    break;
                case 7:
                    resp = 'n';
                    printf("\nNo se realizaron cambios!\n");
                    break;
                case 8:
                    resp = 'n';
                    borrarPelicula(pelicula, 0,buscar);
                    guardarPelicula(pelicula);
                    respuesta = 1;
                    printf("\nPelicula Guardada!\n");
                    break;
                default:
                    printf("ERROR: Ingreso una opcion invalida\n");
                    break;
            }
        }
    }
    else
    {
        printf("El titulo de la pelicula no fue encontrado\n\n");
    }

    return respuesta;
}

/**
Funcion para Generar una pagina con los datos guardados de peliculas de un archivo binario.
*/

void generarPagina(EMovie peliculas)
{
    FILE* Pagina;
    FILE* PaginaWeb;

    char header[1081]="<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head>    <meta charset='utf-8'>    <meta http-equiv='X-UA-Compatible' content='IE=edge'>    <meta name='viewport' content='width=device-width, initial-scale=1'>    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->    <title>Lista peliculas</title>    <!-- Bootstrap Core CSS -->    <link href='css/bootstrap.min.css' rel='stylesheet'>    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->    <link href='css/custom.css' rel='stylesheet'>    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->    <!--[if lt IE 9]>        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>    <![endif]--></head><body>    <div class='container'>        <div class='row'>";
    char endh[401]="</div>        <!-- /.row -->    </div>    <!-- /.container -->    <!-- jQuery -->    <script src='js/jquery-1.11.3.min.js'></script>    <!-- Bootstrap Core JavaScript -->    <script src='js/bootstrap.min.js'></script>	<!-- IE10 viewport bug workaround -->	<script src='js/ie10-viewport-bug-workaround.js'></script>	<!-- Placeholder Images -->	<script src='js/holder.min.js'></script></body></html>";


    Pagina=fopen("peliculas.dat" ,"rb");
    PaginaWeb=fopen("./template/index.html" ,"w+");

    if(Pagina == NULL || PaginaWeb == NULL)
    {
        printf("\nERROR: Al abrir la lista o pagina web\n");
        exit(1);
    }

    fprintf(PaginaWeb, header);
    while(fread(&peliculas, sizeof(EMovie),1, Pagina) != 0)
    {
        fprintf(PaginaWeb, "\n");
        fprintf(PaginaWeb, "<article class='col-md-4 article-intro'>                <a href='#'>                    <img class='img-responsive img-rounded' src='%s' alt=''>                </a>                <h3>                    <a href='#'>%s</a>                </h3>				<ul>					<li>Genero:%s</li>					<li>Puntaje:%d</li>					<li>Duracion:%d</li>				</ul>                <p>%s</p>            </article>",peliculas.linkImagen,peliculas.titulo,peliculas.genero,peliculas.puntaje,peliculas.duracion,peliculas.descripcion);
        fprintf(PaginaWeb, "\n");

    }
    fprintf(PaginaWeb, endh);

    fclose(Pagina);
    fclose(PaginaWeb);
}

/**
Funcion para buscar una pelicula en una lista de un archivo binario.
*/

EMovie* buscarPelicula(char* tituloPelicula)
{
    int encontrado = 0;

    FILE* documento;
    documento=fopen("peliculas.dat","rb");

    if(documento==NULL)
    {
        printf("ERROR: No se pudo abrir el archivo\n\n");
        return NULL;
    }

    EMovie* pelicula = malloc(sizeof(EMovie));

    while(fread(pelicula, sizeof(EMovie),1, documento) != 0)
    {
        if(strcmp(tituloPelicula, pelicula->titulo) == 0)
        {
            encontrado = 1;
            break;
        }
    }

    fclose(documento);

    if(encontrado == 1)
    {
        return pelicula;
    }

    free(pelicula);

    return NULL;
}

/**
Ingreso entre Rango
*/

char* IngresoEntreRango(char valor[] ,char texto[],int minimo,int maximo, char texttime[])
{
    int valoraux;

    fflush(stdin);
    gets(valor);

    while(EsLetra(valor) || (valor[0]=='-'))
    {
        fflush(stdin);
        printf("ERROR: reingrese %s %s: " ,texto,texttime);
        gets(valor);
    }

    valoraux = atoi(valor);

    while(valoraux<minimo || valoraux>maximo || valoraux =='-')
    {
        fflush(stdin);
        printf("ERROR: Reingrese %s entre %d-%d %s: " ,texto ,minimo ,maximo,texttime);
        scanf("%d" ,&valoraux);
    }

    sprintf(valor ,"%d", valoraux);

    return valor;
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
