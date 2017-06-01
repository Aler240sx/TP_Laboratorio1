#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[128];
}EMovie;

/**
 *  Guarda los datos de una pelicula en un archivo binario
 *  @param movie la estructura a ser guardada en el archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo guardar la pelicula o no
 */

int guardarPelicula(EMovie* peli);

/**
 *  Busca una pelicula en una lista guardada en un archivo binario
 *  @param char tituloPelicula, toma el titulo de la pelicula a buscar
 *  @return retorna 1 o 0 de acuerdo a si pudo encontrar la pelicula o no
 */

EMovie* buscarPelicula(char* tituloPelicula);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* peli);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *peliculab ,int opcion, char buscarF[]);

/**
 *  Modica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */

int modificarPelicula(EMovie* peli);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie peli);

/**
 * Detecta si hay letras en una cadena de caracteres
 */
int EsLetra(char ingreso[]);

/**
 * Toma una cadena de caracteres en formato char de numeros para su validacion, pide un texto para avisarle al
 * usuario de lo que debe ingresar, toma el rango minimo y el rango maximo a cumplir
 */
char* IngresoEntreRango(char valor[] ,char texto[] ,int minimo ,int maximo, char texttime[]);

#endif // FUNCIONES_H_INCLUDED
