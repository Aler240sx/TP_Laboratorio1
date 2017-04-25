#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int dni;
    char nombre[50];
    int edad;
    int estado;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
void ObtenerEspacioLibre(EPersona[] ,int);

/**
 * Busca por medio del DNI ingresado en el array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
void BajaDePersonas(EPersona[] ,int);

/**
 * Ordena los Datos Ingresados si se encuentran activos
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
void OrdenamientoDePersonas(EPersona[] ,int);

/**
 * Realiza un grafico en barras formadas por astericos clasificaos en 3 columnas con un rango de edades en cada una.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
void GraficoDePersonas(EPersona lista[] ,int cantidad);

/**
 * Detecta si hay letras en una cadena de caracteres
 */
int EsLetra(char ingreso[]);

/**
 * Detecta si hay un espacio en una cadena de caracteres
 */
int esEspacio(char ingreso[]);

/**
 * Toma una cadena de caracteres en formato DNI numerico
 * ingresado por el usuario y valida que cumpla las condiciones que un DNI debe tener
 */
char* IngresoDNI(char dni[]);

/**
 * Toma una cadena de caracteres en formato char de numeros para su validacion, pide un texto para avisarle al
 * usuario de lo que debe ingresar, toma el rango minimo y el rango maximo a cumplir
 */
char* IngresoEntreRango(char valor[] ,char texto[],int minimo,int maximo);

/**
 * Toma una cadena de caracteres y el mensaje a ser mostrado antes de ingresar la cadena
 */
char* IngresoNombre(char texto[], char nombres[]);

/**
 * Toma una cadena de caracteres y capitaliza la primera letra en cada palabra encontrada en el char
 */
char* Mayusculas(char a[]);

/**
 * Verifica si un numero fue ingresado anteriormente en un Array
 */
int NumeroRepetido(EPersona lista[], int tamanio, int numero);

#endif // FUNCIONES_H_INCLUDED
