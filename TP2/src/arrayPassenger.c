
#include "arrayPassenger.h"
#include "Pasajero.h"
#include "Input.h"

int initPassengers(ePasajero* list, int tam)
{
	int retorno = -1;
    if(list != NULL && tam > 0)
    {
    for(int i = 0;i < tam; i++)
        {
    	list[i].isEmpty = 1; // se inicializan el array con el campo Isempty en 1 = vacio
        }
    	retorno = 0;
    }
    return retorno;
}

int addPassengers(ePasajero* list, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFligth){

  int retorno = -1;

    int index = BuscarPrimerEspacioLibre(list, tam);
    if(index != -1)
       {

    	list[index].id=incrementarId(2000);
        getString(list[index].name,"Ingrese nombre: ",51);
        getString(list[index].lastName,"Ingrese apellido: ", 51);
        list[index].price=flotanteValidado("Ingrese precio: ", "El precio debe ser mayor a 0", 1, 999999);
        list[index].typePassenger = enteroValidado("Ingresar tipo de pasajero: ","Error!!! \nEl pasajero puede ser 1=BEBE 2=MENOR 3=ADULTO: ", 1 , 3);
        getStringAlfaNumerico(list[index].flyCode,"Ingrese codigo de vuelo: ", 10);
        list[index].statusFligth = enteroValidado("Estado de vuelo: ","Error!!! \nEl estado puede ser 1=ACTIVO 2=ATERRIZADO: ", 1 , 2);
        list[index].isEmpty=0;
        retorno =0;

	   }
    return retorno;

}
int printPassenger(ePasajero* list, int tam)
{

	int flagListaVacia = -1;
	//printf("Id\tNombre\t\tApellido\tPrecio\t\tTipo\tCodigo\t\tEstado\n");
	for (int i = 0; i < tam; i++)
	{
		if(list[i].isEmpty == 0)
		{

			flagListaVacia = 0;
		}
	}
		if(flagListaVacia == 0)
		{
			printf("Id\tNombre\t\tApellido\tPrecio\t\tTipo\tCodigo\t\tEstado\n");
			Mostrar(list, tam);
		}
		else
		{
		puts("Lista vacia.\n");
		}
		return flagListaVacia;
}

int removePassenger(ePasajero* list, int tam, int idPasajero){
	int i;
	int auxPasajero = -1;

    idPasajero = IngresarEntero("\nIngrese el Id del pasajero a borrar: ");

	for(i=0; i<tam; i++)
	{
	    if(list[i].isEmpty==0 &&list[i].id==idPasajero)
	    {
	    	list[i].isEmpty=1;
	        auxPasajero=0;
	        printf("ID %d dado de baja", idPasajero);
	        break;
	    }
	}
	if(auxPasajero == -1)
    {
        printf("\nEl ID ingresado no existe");
    }

	return auxPasajero;
}
int findPassengerById(ePasajero* list, int len, int id)
{
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int sortPassenger(ePasajero* list, int tam, int orden)
{
	ePasajero auxApellidoPasajero;
	ePasajero auxTipo;
	int retorno = -1;

	orden=enteroValidado ( "1 para Orden Ascendente. 0 para Orden Descendente: ", "Error!! \n1 Ascendente / 0 Descendente: ", 0, 1);

	if(orden == 1){
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(strcmp(list[i].lastName, list[j].lastName)>0)
			{
				auxApellidoPasajero = list[i];
				list[i] = list[j];
				list[j] = auxApellidoPasajero;

			 }
		}

		for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if( strcmp(list[i].lastName, list[j].lastName)==0 && list[i].typePassenger > list[j].typePassenger)
			{
				auxTipo = list[i];
				list[i] = list[j];
				list[j] = auxTipo;

			 }
		}
	}
	}
	retorno = 0;
	}
	if(orden == 0){
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(strcmp(list[i].lastName, list[j].lastName)<0)
			{
				auxApellidoPasajero = list[i];
				list[i] = list[j];
				list[j] = auxApellidoPasajero;

			 }
		}

		for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if( strcmp(list[i].lastName, list[j].lastName)==0 && list[i].typePassenger < list[j].typePassenger)
			{
				auxTipo = list[i];
				list[i] = list[j];
				list[j] = auxTipo;

			 }
		}
	}
	}
	retorno = 0;
	}

	printf("\n+++++++++++++++++  Ordenado por Apellido y tipo  +++++++++++++++++++\n");
    printPassenger(list, tam);
    return retorno;
}

int sortPassengersByCode(ePasajero* list, int tam, int orden)
{
	ePasajero auxCodigo;
	ePasajero auxEstado;
	int retorno=-1;
	orden=enteroValidado ( "1 para Orden Ascendente. 0 para Orden Descendente: ", "Error!! \n1 Ascendente / 0 Descendente: ", 0, 1);
	if(orden == 1){
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(strcmp(list[i].flyCode, list[j].flyCode)>0)
			{
				auxCodigo = list[i];
				list[i] = list[j];
				list[j] = auxCodigo;

			 }
		}

		for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if( strcmp(list[i].flyCode, list[j].flyCode)==0 && list[i].statusFligth > list[j].statusFligth)
			{
				auxEstado = list[i];
				list[i] = list[j];
				list[j] = auxEstado;

			 }
		}
	}
	}
		retorno = 0;
	}
	if(orden == 0){
	for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if(strcmp(list[i].flyCode, list[j].flyCode)<0)
			{
				auxCodigo = list[i];
				list[i] = list[j];
				list[j] = auxCodigo;

			 }
		}

		for(int i=0; i<tam-1; i++)
	{
		for(int j=i+1; j<tam; j++)
		{
			if( strcmp(list[i].flyCode, list[j].flyCode)==0 && list[i].statusFligth < list[j].statusFligth)
			{
				auxEstado = list[i];
				list[i] = list[j];
				list[j] = auxEstado;

			 }
		}
	}
	}
	retorno = 1;
	}

	printf("\n+++++++++++++++++  Ordenado por Codigo y estado  +++++++++++++++++++\n");
        printPassenger(list,tam);
       return retorno ;
}

int modificarPasajero(ePasajero lista[], int tam)
{
    int i;
    int pasajeroAModificar;
    float precioAcambiar;
    int tipoACambiar;
    char nombreACambiar[51];
    char apellidoACambiar[51];
    char codigoACambiar[10];
    int retorno;
    int opcionMenu;
    int contador=0;

    retorno = -1;

    pasajeroAModificar = IngresarEntero("\nIngrese el ID del pasajero a modificar: ");

    for(i=0;i<tam;i++)
    {
       if(lista[i].isEmpty==0 && lista[i].id==pasajeroAModificar)
            {

            do{


            printf("\n1. Modificar Nombre\n");
            printf("2. Modificar Apellido\n");
            printf("3. Modificar Precio\n");
            printf("4. Modificar Tipo de Pasajero\n");
            printf("5. Modificar Codigo de vuelo \n");
            printf("6. Volver al menu\n");
            opcionMenu=enteroValidado("Seleccione opcion: ", "Se puede seleccionar del 1 al 6 ",1,6);

            switch(opcionMenu){
                case 1:
                    getString(nombreACambiar,"Ingrese nuevo nombre: ",51);
                    strcpy(lista[i].name,nombreACambiar);
                    retorno = 1;
                    printf("ID %d modificado ", pasajeroAModificar);
                    contador++;
                    break;
                case 2:
                    getString(apellidoACambiar,"Ingrese nuevo apellido: ",51);
                    strcpy(lista[i].lastName,apellidoACambiar);
                    retorno = 1;
                    printf("ID %d modificado ", pasajeroAModificar);
                    contador++;
                    break;
                case 3:
                    precioAcambiar= flotanteValidado("\nIngrese nuevo precio: ", "El precio debe ser mayor a 0", 1, 999999);
                    lista[i].price = precioAcambiar;
                    retorno = 1;
                    printf("ID %d modificado ", pasajeroAModificar);
                    contador++;
                    break;
                case 4:
                    tipoACambiar= enteroValidado("Ingresar nuevo tipo de pasajero: ","Error!!! \nEl pasajero puede ser 1=BEBE 2=MENOR 3=ADULTO: ", 1 , 3);
                    lista[i].typePassenger = tipoACambiar;
                    retorno = 1;
                    printf("ID %d modificado ", pasajeroAModificar);
                    contador++;
                    break;
                case 5:
                    getString(codigoACambiar,"Ingrese nuevo codigo: ",10);
                    strcpy(lista[i].flyCode,codigoACambiar);
                    retorno = 1;
                    printf("ID %d modificado ", pasajeroAModificar);
                    contador++;
                    break;
                case 6:
                    printf("Volviste al menu\n");
                    retorno = 1;
                    contador++;
                    break;
            }
            }while(contador != 1);
        }
    }
    if(retorno == -1)
    {
        printf("\nEl ID ingresado no existe");
    }
   return retorno;
}

void altaForzada(ePasajero* Listado){

			Listado[0].id=2000;
	        strcpy(Listado[0].name,"Coty");
	        strcpy(Listado[0].lastName,"Tucci");
	        Listado[0].price=120;
	        Listado[0].typePassenger = ADULTO;
	        strcpy(Listado[0].flyCode,"ABC103");
	        Listado[0].statusFligth = ACTIVO;
	        Listado[0].isEmpty=0;

	        Listado[1].id=2001;
	        strcpy(Listado[1].name,"Manuel");
	        strcpy(Listado[1].lastName,"Barberon");
	        Listado[1].price=150;
	        Listado[1].typePassenger = MENOR;
	        strcpy(Listado[1].flyCode,"ABC103");
	        Listado[1].statusFligth = ACTIVO;
	        Listado[1].isEmpty=0;

	        Listado[2].id=2002;
	        strcpy(Listado[2].name,"Ricardo");
	        strcpy(Listado[2].lastName,"Lopez");
	        Listado[2].price=100;
	        Listado[2].typePassenger = ADULTO;
	        strcpy(Listado[2].flyCode,"ABC104");
	        Listado[2].statusFligth = ATERRIZADO;
	        Listado[2].isEmpty=0;

	        Listado[3].id=2003;
	        strcpy(Listado[3].name,"Alberto");
	        strcpy(Listado[3].lastName,"Lopez");
	        Listado[3].price=110;
	        Listado[3].typePassenger = BEBE;
	        strcpy(Listado[3].flyCode,"ABC105");
	        Listado[3].statusFligth = ACTIVO;
	        Listado[3].isEmpty=0;

	        Listado[4].id=2004;
	        strcpy(Listado[4].name,"Cristiano");
	        strcpy(Listado[4].lastName,"Nadal");
	        Listado[4].price=90;
	        Listado[4].typePassenger = ADULTO;
	        strcpy(Listado[4].flyCode,"ABC105");
	        Listado[4].statusFligth = ACTIVO;
	        Listado[4].isEmpty=0;
}