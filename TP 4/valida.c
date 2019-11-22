#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "valida.h"


/** \brief pide ingreso de un char, lo valida entre dos opciones posibles
 *
 * \param mensaje es un puntero a cadena de char, mensaje para pedir datos
 * \param mensajeError es un puntero a cadena de char, mensaje para pedir datos tras error de ingreso de caracter
 * \param resp1 es el primer char valido
 * \param resp2 es el segundo char valido
 * \return devuelve char de resp1 o resp2 segun corresponda
 *
 */
char validaChar2 (char* mensaje, char* mensajeError, char resp1, char resp2)
{
    char respuesta;

    printf("%s",mensaje);
    fflush(stdin);
    respuesta = getchar();
    respuesta = tolower(respuesta);

    while (respuesta!=resp1 && respuesta!=resp2)
    {
        printf("\r%s",mensajeError);
        fflush(stdin);
        respuesta = getchar();

    }
    return respuesta;

}

/** \brief pide ingreso de una cadena de char, valida que no supere largo maximo, lo carga en otro vector auxiliar
 *
 * \param mensaje es puntero a char, texto pidiendo el dato a ingresar
 * \param mensajeError es puntero a char, texto informando ingreso de dato invalido
 * \param maxStrLen es int, cantidad maxima de caracteres +1 ('/0') para el vector
 * \param auxiliar es vector de char, es el vector donde se cargara la cadena ya validada
 * \return devuelve 1 si cargo bien el puntero, 0 si no pudo
 *
 */
int validaString (char* mensaje, char* mensajeError, int maxStrLen, char* auxiliar)
{

    int todoOk = 0;
    char aux[500];
    int numeros;

    printf("%s", mensaje);
    fflush(stdin);
    gets(aux);
    numeros = atoi(aux) ;
    if (strlen(aux)<=maxStrLen || numeros == 0)
    {
        todoOk = 1;
    }

    while (strlen(aux)>maxStrLen || numeros != 0 )
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(aux);
        numeros = atoi(aux) ;
        if (strlen(aux)<=maxStrLen || numeros == 0)
        {
            todoOk = 1;
        }

    }

    strcpy(auxiliar,aux);


    return todoOk;
}

/** \brief Recibe una cadena de caracteres y pasa a myuscula la primera letra de cada palabra
 *
 * \param nombre es un vector de char.
 *
 */
void poneMayuscula (char* nombre)
{
    int tam;

    tam = strlen(nombre);

    for (int i=0; i<tam; i++)
    {
        nombre[i] = tolower(nombre[i]);
    }

    for (int i=0; i<tam; i++)
    {
        if (i==0 || nombre[i-1]==' ')
        {
            nombre[i] = toupper(nombre[i]);
        }

    }

}

/** \brief Muestra mensaje para pedir un float y lo valida
 *
 * \param char* mensaje para pedir numero
 * \param char* mensaje en caso que se ingrese dato erroneo
 * \param int determina si acepta numeros negativos (1 para si, 0 para no)
 * \param float* puntero a variable a cargar tras validacion
 * \return devuelve 1 si valido OK, 0 si no.
 */
int validaFloat (char* mensaje, char* mensajeError, int negativos, float* Pauxiliar)
{

    int todoOK = 0;
    int esNumero;

    printf("%s",mensaje);
    fflush(stdin);
    esNumero = scanf("%f",Pauxiliar);

    if (!negativos)
    {
        while ((*Pauxiliar) < 0 || !esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%f",Pauxiliar);

        }
        todoOK = 1;
    }
    else if (negativos)
    {

        while (!esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%f",Pauxiliar);

        }
        todoOK = 1;

    }


    return todoOK;
}

/** \brief Muestra mensaje para pedir un int y lo valida
 *
 * \param char* mensaje para pedir numero
 * \param char* mensaje en caso que se ingrese dato erroneo
 * \param int determina si acepta numeros negativos (1 para si, 0 para no)
 * \param int* puntero a variable a cargar tras validacion
 * \return devuelve 1 si valido OK, 0 si no.
 */
int validaInt (char* mensaje, char* mensajeError, int negativos, int* Pauxiliar)
{

    int todoOK = 0;
    int esNumero;

    printf("%s",mensaje);
    fflush(stdin);
    esNumero = scanf("%d",Pauxiliar);
    //printf("%d", esNumero);

    if (negativos == 0)
    {
        while ((*Pauxiliar) < 0 || !esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);

        }
        todoOK = 1;

    }
    else if (negativos == 1)
    {
        while (!esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);

        }
        todoOK = 1;
    }

    return todoOK;
}
