/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Input.h"
#include "Pasajero.h"
#include "arrayPassenger.h"
#define TAM 2000

int main(void) {
	setbuf(stdout, NULL);
	    int id = 0;
	    char nombre[51];
	    char apellido[51];
	    float precio = 0;
	    int tipo = 0;
	    int estado = 0;
	    char codigo[10];
	    int opcionInformeA = 0;
	    int opcionInformeC = 0;
	    int idDarBaja=0;
	    int opcion = 0;
	    char informe;
	    int contadorSalida = 0;
	    ePasajero Lista[TAM];
	    /*ePasajero Lista[5]= {{100 ,"Jean" ,"Barberon",110 ,MENOR,"abc102",ACTIVO,0},
	    				{200,"Manuel","Perez",105,ADULTO,"abc100",ATERRIZADO,0},
	    				{400,"Gaston","Alvarez",180,BEBE,"abc100",ACTIVO,0},
	    				{500,"Coty","Perez",90,BEBE,"abc100",ATERRIZADO,0},
	    				{600,"Ricardo","Alvarez",100,MENOR,"abc102",ACTIVO,0}};*/
	    initPassengers(Lista, TAM);
	    do{
	    printf("\n++++++++++++++++++++++ MENU ++++++++++++++++++++++\n");
	    printf("\n1. Altas\n");
	    printf("2. Modificar\n");
	    printf("3. Baja\n");
	    printf("4. Informar\n");
	    printf("5. Alta forzada\n");
	    printf("6. Salir \n");

	    opcion=enteroValidado("Elija una opcion: ","La opcion debe ser del 1 al 5: ", 1,5);

	    switch(opcion){
	    case 1:
	    if(addPassengers(Lista, TAM, id, nombre, apellido, precio, tipo, codigo, estado) != -1){

	        	puts("El pasajero se cargo exitosamente\n");
	        }else{
	        	puts("El pasajero no pudo cargarse\n");
	        }
	    break;
	    case 2:
	    if(printPassenger(Lista, TAM)== -1){
	    	puts("Se debe cargar algun pasajero");
	    }
	    else{
	    modificarPasajero(Lista,TAM);
	    }
	    break;
	    case 3:
	    if(printPassenger(Lista, TAM)== -1)
	    	{
	    puts("Se debe cargar algun pasajero");
	    	}
	    else{
	    removePassenger(Lista,TAM,idDarBaja);
	    	}
	    break;
	    case 4:
	    printPassenger(Lista, TAM);
	    int contador = 0;
	        do{

	        printf("\na. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.\n");
	        printf("b. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio.\n");
	        printf("c. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�.\n");

	        informe=IngreseCaracter("\nIngrese opcion de informe: ");

	        switch(informe){
	        case 'a':
	        sortPassenger(Lista,TAM,opcionInformeA);
	        contador++;
	        break;
	        case 'b':
	        CalculosPasajes(Lista,TAM);
	        contador++;
	        break;
	        case 'c':
	        sortPassengersByCode(Lista,TAM,opcionInformeC);
	        contador++;
	        break;
	        }
	        }while(contador!=1);
	    break;
	    case 5:
	    altaForzada(Lista);
	    break;
	    case 6:
	    contadorSalida++;
	    break;
	    }
	}while(contadorSalida!=1);

	return EXIT_SUCCESS;
}
