/*
 * Pasajero.c
 *
 *  Created on: 11 may 2022
 *      Author: Compumar
 */

#include "Pasajero.h"
#include "Input.h"
#include "arrayPassenger.h"

void Mostrar(ePasajero Listado[], int tam){
char auxiliar[50];

for(int i =0; i<tam;i++){
    if(Listado[i].isEmpty == 0)
    	 {
    switch(Listado[i].typePassenger)
         {
         case BEBE:
    	 strcpy(auxiliar, "BEBE");
    	 break;
    	 case MENOR:
    	 strcpy(auxiliar, "MENOR");
    	 break;
    	 case ADULTO:
    	 strcpy(auxiliar, "ADULTO");
    	 break;
    	 }
    	 switch(Listado[i].statusFligth)
         	 {
         	 case ACTIVO:
         	 printf("\n%-d %10s %17s %15.2f %12s %8s %16s ", Listado[i].id, Listado[i].name,Listado[i].lastName, Listado[i].price, auxiliar, Listado[i].flyCode, "Activo");
         	 break;
         	 case ATERRIZADO:
         	 printf("\n%-d %10s %17s %15.2f %12s %8s %16s ", Listado[i].id, Listado[i].name,Listado[i].lastName, Listado[i].price, auxiliar, Listado[i].flyCode, "Aterrizado");
         	 break;
         	 }
        }
	}
}


int BuscarPrimerEspacioLibre(ePasajero lista[], int tam){
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(lista[i].isEmpty == 1)
		{
			index = i;
			break;
		}

	}
	if(index == -1){
		printf("La lista esta ocupada\n");
	}
	return index;
}




int incrementarId(int valor)
{
    static int id;
    static int flagValorInicial=0;
    if(flagValorInicial ==0){
        id=valor;
        flagValorInicial=1;
    }
    id++;
    return id;
}

void CalculosPasajes(ePasajero lista[], int tam)
{
	int contadorPasajero=0;
	float total=0;
	float promedio;
	int pasajerosQueSuperanPromedio=0;
	for(int i=0; i<tam; i++)
	{
			if(lista[i].isEmpty == 0)
			{
				contadorPasajero++;
				total=total + lista[i].price;
			 }
	}
	promedio = total / contadorPasajero;
	for(int i=0; i<tam; i++)
	{
			if(lista[i].isEmpty == 0 && lista[i].price > promedio)
			{
				pasajerosQueSuperanPromedio++;

			 }
	}
	printf("\n+++++++++ Se muestra el precio total , promedio por pasaje y pasajeros por encima del promedio+++++++++++\n");
	printf("\nEl precio promedio por pasaje es: $ %.2f", promedio);
	printf("\nEl precio total de todos los pasajes es: $ %.2f", total);
	printf("\nCantidad de pasajeros que superan el precio del pasaje promedio: %d", pasajerosQueSuperanPromedio);
}

/*int validar(int valorUno, int valorDos, int valor, char msjError[])
{
    int valorAux;
    while(valor <= valorUno || valor >= valorDos){
        printf("Error!!!! %s", msjError);
        valorAux=IngresarEntero("Ingrese nuevamente: ");
        valor = valorAux;
        printf("\n valor aux: %d",valorAux );
        printf("\n valor : %d",valor );

    }
     return valorAux;
}
*/






