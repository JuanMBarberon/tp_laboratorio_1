/*
 * arrayPassenger.h
 *
 *  Created on: 14 may 2022
 *      Author: Compumar
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


#define BEBE 1
#define MENOR 2
#define ADULTO 3

#define ACTIVO 1
#define ATERRIZADO 2



struct{
    int id;
    char name[51];
    char lastName[51];
    float price;
    int typePassenger;
    char flyCode[10];
    int statusFligth;
    int isEmpty;
}typedef ePasajero;

/// @brief carga datos de un pasajero en un array siempre y cuando tenga lugar disponible
///
/// @param list lista en cual se va a agregar
/// @param tam tama�an de la lista
/// @param id numero que identica al pasajero
/// @param name nombre de pasajer
/// @param lastName apellido de pasajero
/// @param price precio que pago por pasaje
/// @param typePassenger tipo de pasaje , bebe, menor, adulto
/// @param flyCode codigo de vuelo, es gral es alfa numerico
/// @param statusFligth estado del viaje, puede ser activo o ateriizado
/// @return retorna -1 si no se pudo cargar, retorna 0 si se pudo cargar correctamente
int addPassengers(ePasajero* list, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFligth);
/// @brief incializa el array, el campo isEmpty en 1
///
/// @param list array a inicializar
/// @param tam tama�o del array
/// @return retona -1 si no lo pudo inicializar, 0 si lo pudo inicializar
int initPassengers(ePasajero* list, int tam);
/// @brief ordena la lista de pasajeros por codigo de vuelo y estado
///
/// @param list array que recorre y ordena
/// @param tam tama�an del array
/// @param orden con ordenda 0 de manera descendente, con 1 de manera ascendente
/// @return retorna -1 si no pudo ordenar, retorna 0 si lo ordena
int sortPassengersByCode(ePasajero* list, int tam, int orden);
/// @brief ordena la lista de pasajeros por apellido y tipo de pasajero
///
/// @param list array que recorre y ordena
/// @param tam tama�an del array
/// @param orden con ordenda 0 de manera descendente, con 1 de manera ascendente
/// @return retorna -1 si no pudo ordenar, retorna 0 si lo ordena
int sortPassenger(ePasajero* list, int tam, int orden);
/// @brief imprime array encolumnado
///
/// @param list array a mostrar
/// @param tam tama�o de array
/// @return -1 si el array esta vacio, 0 si tiene algo en array para imprimir en pantalla
int printPassenger(ePasajero* list, int tam);
/// @brief busca un id y lo da de baja poniendo libre su posicion
///
/// @param list array donde se buscara el id
/// @param tam tama�o de array
/// @param idPasajero id de pasajero a dar de baja
/// @return -1 si el ID no existe, 0 si lo pudo dar de baja
int removePassenger(ePasajero* list, int tam, int idPasajero);
/// @brief busca un pasajero por numero de ID
///
/// @param list array donde busca
/// @param len tama�o de array
/// @param id que se busca dentro del array
/// @return -1 si no hay nada en el array, >0 si encontro el numero del id
int findPassengerById(ePasajero* list, int len, int id);
/// @brief busca si hay algun pasajero en lista y modifica el campo que se elije
///
/// @param lista array que recorre
/// @param tam tama�o
/// @return  -1 si no encontro Id para modificar, 1 si lo encontro y lo modifico
int modificarPasajero(ePasajero lista[], int tam);
/// @brief realiza la carga de 5 pasajeros y sus datos correspondientes
///
/// @param Listado array donde se va a agregar
void altaForzada(ePasajero* Listado);



#endif /* ARRAYPASSENGER_H_ */
