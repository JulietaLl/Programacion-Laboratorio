/*
 * Compras.h
 *
 *  Created on: 1 may. 2021
 *      Author: Llorj
 */


#ifndef COMPRAS_H_
#define COMPRAS_H_

#define PENDIENTE_COBRAR 0
#define COBRADO          1

typedef struct{

	int idCliente;
	int cantidadBarbijos;
	char direccionEntrega[65];
	char color [33];
	int flagIsEmpty;
	int estado;

}Compra;

int comp_inicilizarArray(Compra* pArray, int limite);






#endif /* COMPRAS_H_ */
