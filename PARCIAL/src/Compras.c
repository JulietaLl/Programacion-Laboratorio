/*
 * Compras.c
 *
 *  Created on: 1 may. 2021
 *      Author: Llorj
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compras.h"


 int comp_inicilizarArray(Compra* pArray, int limite)
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

