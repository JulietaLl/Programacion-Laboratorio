/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Compras.h"
#include "Informes.h"

#define MENU " Seleccione una opcion: \n1)Alta de Cliente \n2)Modificar datos de Cliente \n3)Baja de Cliente \n4)Realizar compra \n5)Pagar compra \n6)Cancelar Compra \n7)Imprimir Clientes \n8)Informes"

#define QTY_CLIENTES 100
#define QTY_COMPRAS 1000


int main(void) {

	    Cliente arrayClientes[QTY_CLIENTES];
	    Compra arrayCompras[QTY_COMPRAS];

	     cli_inicilizarArray(arrayClientes,QTY_CLIENTES);
	     comp_inicilizarArray(arrayCompras,QTY_COMPRAS);

		setbuf(stdout,NULL);
		int opcion;
		int respuesta;
		int idCliente;
		int indiceLugarLibre;
		int auxiliarIndice;
		int auxiliarId;

		do
		{
		respuesta = utn_getNumero(&opcion, MENU, "Error al ingresar opcion" , 1, 8, 2);
		 if (!respuesta)
		 {

			switch(opcion)
			{
			case 1: indiceLugarLibre = cli_getEmptyIndex(arrayClientes,QTY_CLIENTES);
						if(indiceLugarLibre >= 0)
						{
							if(cli_altaArray(arrayClientes, QTY_CLIENTES, indiceLugarLibre, &idCliente) == 0)
									   {
								           printf("%s-%s -%d-%d",  arrayClientes -> nombre,
													               arrayClientes -> apellido,
													               arrayClientes -> cuit,
													               arrayClientes -> idCliente);
									   }
						}

				break;

			case 2: if(utn_getNumero(&auxiliarId,"\nIngrese ID del cliente a modificar","\nInvalido",0, idCliente,0) == 0)
						{
							auxiliarIndice = cli_buscarId(arrayClientes, QTY_CLIENTES,auxiliarId);
							if(auxiliarIndice >= 0 && cli_modificarArray(arrayClientes, QTY_CLIENTES,auxiliarIndice,&idCliente) == 0)
							{
								printf("\nModificacion realizada con exito");
							}
						}
				break;

			case 3:
					if(utn_getNumero(&auxiliarId,"\nID Cliente:","\nError",0,100,0) == 0 &&
						cli_buscarId(arrayClientes,QTY_CLIENTES,auxiliarId) == -1)
					{
						cli_imprimirArray(arrayClientes,QTY_CLIENTES);
						cli_bajaArray(arrayClientes, QTY_CLIENTES, auxiliarIndice, &idCliente);

					}
					else
					{
						printf("El ID del cliente no existe");
					}




				break;

			case 4: // Realizar una compra
				break;

			case 5: //Pagar Compra
				// primero se pide ID de la venta
				//Se imprime la info del cliente a la que pertenece
				//Se ingresa el importe pagado por el cliente y pedirá la confirmacion para cambiar a "COBRADO"

				break;

			case 6: // Cancelar compra
				break;

			case 7: //Imprimir Clientes
				break;

			case 8: //Informes
				break;
			}
		}

		}while (opcion != 9);


}
