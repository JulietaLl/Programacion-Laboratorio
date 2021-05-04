/*
 * Clientes.c
 *
 *  Created on: 1 may. 2021
 *      Author: Llorj
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"

#define QTY_CLIENTES 100
#define NOMBRE_LEN 51
#define APELLIDO_LEN 51

static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);
static int getString(char* pResultado, int longitud);
static int get_descripcion(char* pResultado, int longitud);
static int esDescripcion(char* cadena, int longitud);

/**
 * Brief: Solicita un numero al usuario, luego de verificarlo devuelve el resultado.
 * Parametro pResultado: Puntero al espacio de memoria donde se dejará el resultado de la función.
 * Parametro mensaje: Es el mensaje a ser mostrado.
 * Parametro mensajeError: Es el mensaje de error a ser mostrado.
 * Parametro minimo: Es el numero minimo a ser aceptado.
 * Parametro máximo: Es el numero máximo a ser aceptado.
 * Return: Retorna 0 si se obtuvo el numero y -1 si no.
 */
int utn_getNumero(int* pResultado, char* mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
		printf("%s", mensaje);
		fflush(stdin);
		if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
  * Brief:  Verifica si la cadena ingresada es numerica.
  * Parametro pResultado: puntero al espacio de memoria donde se dejará el resultado de la función.
  * return Retorna 0 [EXITO] si se obtiene un numero entero y -1 [ERROR] si no.
  *
  */

 static int getInt(int* pResultado)

 {
	 int retorno = -1;
	 char bufferString [4096];

	 if (pResultado != NULL &&
		 myGets(bufferString, sizeof(bufferString)) == 0 &&
		 esNumerica(bufferString,sizeof(bufferString)))
	 {
		 retorno = 0;
		 *pResultado = atoi (bufferString);


	 }

	 return retorno;
 }

 /**
  * Brief:   Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
  * 				un maximo de longitud -1 caracteres.
  * 	Parametro pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
  * 	Parametro longitud Define el tamaño de cadena
  * 	\return retorna 0 [EXITO] si se obtiene una cadena y -1 [ERROR] si no.
  */


 int myGets (char* cadena, int longitud)
 {

 	int retorno = -1;
 	char bufferString[4096];

 	if(cadena != NULL && longitud > 0)
 	{
 		fflush(stdin);
 		if(fgets(bufferString,sizeof (bufferString), stdin) != NULL)
 		{
 			if(bufferString[strnlen(bufferString, sizeof (bufferString))-1] == '\n')
 			{
 				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';

 			}
 			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
 			{
 				strncpy(cadena,bufferString,longitud);
 				retorno = 0;
 			}



 		}

 	}
 	return retorno;

 }

 static int esNumerica (char* cadena, int limite)
  {
 	 int retorno = -1;
 	 int i = 0;

 	 if(cadena != NULL && limite > 0)
 	 {

 		 retorno = 1;
 		 for (i= 0; i<limite && cadena [i] != '\0'; i++)
 		 {
 			 if( i==0 && (cadena [i] == '+' || cadena [i] == '-'))
 			 {
 			     continue;
 			 }
 			 if(cadena [i] > '9' || cadena [i] < '0')
 			 {
 				 retorno = 0;
 				 break;
 			 }
 	     }
 	 }
 	 return retorno;
  }

 static int getString(char* pResultado, int longitud)
   {
  	 int retorno = -1;
  	 char buffer [4096];

  	 if(pResultado != NULL)
  	 {
  		 if(getString(buffer,sizeof(buffer)) == 0 &&
  			 esDescripcion(buffer,sizeof(buffer)) &&
  			 strnlen(buffer,sizeof (buffer)) < longitud)
  		 {
  			 strncpy(pResultado, buffer, longitud);
  			 retorno = 0;
  		 }


  	 }
  	 return retorno;
   }

 /**
       * Brief:Inicializa el array.
       * Parametro array. Array de clientes a ser actualizado.
       * parametro Limite, limite del array de clientes.
       * Return: Retorna 0 [EXITO]  y -1 [ERROR].
       */

 int cli_inicilizarArray(Cliente* pArray, int limite)
     {
    	 int retorno = -1;
    	 int i;
    	 if(pArray != NULL && limite > 0)
    	 {
    		 for(i = 0; i< limite; i++)
    		 {
    			 pArray[i].flagIsEmpty = 1;
    		 }
    		 retorno = 0;
    	 }
    	 return retorno;
     }

 /**
   * Brief: Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
   * Paramentro: pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
   * parametro longitud: Es la longitud del array resultado
   * parametro mensaje: Es el mensaje de error a ser mostrado
   * parametro reintentos: Cantidad de reintentos
   * return retorna 0 si se obtuvo el numero flotante y -1 si no
   */
  int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char * mensajeError, int reintentos)
  {
	  char bufferString [4096];
	  int retorno = -1;
	  while(reintentos >= 0)
	  {
		  reintentos--;
		  printf("%s",mensaje);
		  if(get_descripcion(bufferString, sizeof(bufferString)) == 0 && strnlen (bufferString, sizeof (bufferString)) < longitud)
		  {
			  strncpy(pResultado, bufferString, longitud);
			  retorno = 0;
			  break;

		  }
		  printf("%s", mensajeError);
	  }
	  return retorno;
  }

  /**
   * Brief:Verifica si la cadena ingresada es un nombre valido
   * Parametro candena :Cadena de caracteres a ser analizada
   * Return retorna 1(verdadero) si la cadena es valida y 0(falso) si no lo es
   */

 static int esDescripcion(char* cadena, int longitud)
 {
	 int i=0;
	 int retorno = -1;

	 if(cadena != NULL && longitud > 0)
	 {
		 for(i=0 ; cadena [i] != '\0' && i < longitud; i++)
		 {
			 if((cadena[i] < 'A' || cadena [i] > 'Z') && (cadena [i] < 'a' || cadena[i] > 'z'))
			 {
				 retorno = 0;
				 break;
			 }
		 }
	 }
	 return retorno;
 }

 /**
  * Brief Obtiene un string valido como descripcion
  * paramentro pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * return Retorna 0(Exito) si se obtiene un numero flotante y -1 si no.
  */

 static int get_descripcion(char* pResultado, int longitud)
 {
	 int retorno = -1;
	 char buffer [4096];

	 if(pResultado != NULL)
	 {
		 if(getString(buffer,sizeof(buffer)) == 0 &&
			 esDescripcion(buffer,sizeof(buffer)) &&
			 strnlen(buffer,sizeof (buffer)) < longitud)
		 {
			 strncpy(pResultado, buffer, longitud);
			 retorno = 0;
		 }


	 }
	 return retorno;
 }
 /**
          * Brief: Actualiza los datos de un cliente en una posicion del array.
          * Parametro array. Array de clientes a ser actualizado.
          * parametro Limite, limite del array de clientes.
          * param indice posicion a ser actualizada.
          * param id identificador a ser asignado al cliente.
          * Return: Retorna 0 [EXITO]  y -1 [ERROR].
          */

  int cli_altaArray(Cliente* array, int limite, int indice, int* id)
  {
	  int respuesta = -1;
	  Cliente bufferCliente;

	  if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	  {
		  if(utn_getDescripcion(bufferCliente.nombre, NOMBRE_LEN, "\nEscriba su nombre:\n", "\nError\n",2) == 0 &&
			utn_getDescripcion(bufferCliente.apellido, APELLIDO_LEN, "\nEscriba su Apellido:\n","\nError\n",2) == 0 &&
			utn_getNumero(&bufferCliente.cuit, "\nCuit\n", "\nError\n", 0,5,2) == 0)
		  {
			  respuesta = 0;
			  bufferCliente.idCliente = *id;
			  bufferCliente.flagIsEmpty = 0;
			  array[indice] = bufferCliente;
			  *id = *id +1;
		  }

	  }
	  return respuesta;
  }

  /**
      * Brief: Buscar primer posicion vacia.
      * Parametro array. Array de clientes.
      * parametro Limite,limite del array de clientes.
      * param indice posicion int* Puntero a la posicion del array donde se encuentra el valor buscado.
      * Return: int Retorna el indice de la posicion vacia y -1 Error.
      */

   int cli_getEmptyIndex(Cliente* array, int limite)
   {
 	  int respuesta = -1;
 	  int i;
 	  if(array != NULL && limite > 0)
 	  {
 		  respuesta = 0;
 		  for(i = 0; i < limite; i++)
 		  {
 			  if(array[i].flagIsEmpty == 1)
 			  {
 				  respuesta = i;
 				  break;
 			  }
 		  }
 	  }
 	  return respuesta;
   }

   /**
       * Brief:Imprime los datos de un cliente
       * Parametro pElemento puntero al producto que se busca imprimir.
       * Return: Retorna 0 [EXITO]  y -1 [ERROR].
       */

       int cli_imprimir(Cliente* pElemento)
       {
      	 int retorno = -1;
      	 if (pElemento != NULL && pElemento ->flagIsEmpty == 0)
      	 {
      		 retorno = 0;
      		 printf("ID:  %d - %s - %s - %d", pElemento -> idCliente, pElemento -> nombre, pElemento -> apellido, pElemento -> cuit);

      	 }
      	 return retorno;
       }


       /**
        * Brief:Imprime el array de clientes.
        * Parametro array. Array de clientes a ser actualizado.
        * parametro Limite, limite del array de clientes.
        * Return: Retorna 0 [EXITO]  y -1 [ERROR].
        */


       int cli_imprimirArray(Cliente* array, int limite)
       {
      	 int respuesta = -1;
      	 int i;
      	 if(array != NULL && limite > 0)
      	 {
      		 respuesta = 0;
      		 for(i = 0; i< limite; i++)
      		 {
      			 cli_imprimir(&array[i]);
      		 }
      	 }
      	 return respuesta;
       }

       /**
        * Brief: Actualiza los datos de un cliente en una posicion del array.
        * Parametro array. Array de clientes a ser actualizado.
        * parametro Limite, limite del array de clientes.
        * param indice posicion a ser actualizada.
        * param id identificador a ser asignado al cliente.
        * Return: Retorna 0 [EXITO]  y -1 [ERROR].
        */


          int cli_modificarArray(Cliente* array, int limite, int indice, int * id)
         {
       	  int respuesta = -1;
       	  Cliente bufferCliente;

       	  if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
       	  {
       		  if(   utn_getDescripcion(bufferCliente.nombre, NOMBRE_LEN, "\nEscriba su nombre:\n", "\nError\n",2) == 0 &&
       				utn_getDescripcion(bufferCliente.apellido, APELLIDO_LEN, "\nEscriba su Apellido:\n","\nError\n",2) == 0 &&
       				utn_getNumero(&bufferCliente.cuit, "\nCuit\n", "\nError\n", 0,5,2) == 0)
       		  {
       			  respuesta = 0;
       			  bufferCliente.idCliente =  array[indice].idCliente;
       			  bufferCliente.flagIsEmpty = 0;
       			  array[indice] = bufferCliente;
       		  }

       	  }
       	  return respuesta;
         }

          /**
             * Brief: Busca un ID en un array y devuelve la posicion en que se encuentra.
             * Parametro array. Array de cliente.
             * parametro Limite, int ta actualizada.maño de array.
             * param indice posicion int* Puntero a la posicion del array donde se encuentra el valor buscado.
             * Return: int Return [-1] si no encuentra el valor buscado o Error [Invalid lenght or NULL] O 0 si lo encuentra.
             */



            int cli_buscarId(Cliente array [], int limite, int valorBuscado)
                {
               	 int respuesta = -1;
               	 int i;
               	 if(array != NULL && limite > 0 && valorBuscado >= 0)
               	 {
               		 respuesta = 0;
               		 for(i = 0; i< limite; i++)
               		 {
               			if(array[i].idCliente == valorBuscado)
               			{
               				respuesta = i;
               				break;
               			}
               		 }
               	 }
               	 return respuesta;
                }

            /**
              	* Brief: Actualiza una posicion del array.
                * Parametro array. Array de clientes a ser actualizado.
                * parametro Limite, limite del array de clientes.
                * param indice posicion a ser actualizada.
              	* Return: Retorna 0 [EXITO]  y -1 [ERROR].
              	*/



              int cli_bajaArray(Cliente* array, int limite, int indice, int* id)
              {
            	  int respuesta = -1;

            	  if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
            	  {
            		 array[indice].flagIsEmpty = 1;
            		  respuesta = 0;

            	  }
            	  return respuesta;
              }


