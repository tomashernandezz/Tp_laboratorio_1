#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int validacion = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_PassengerFromText(pArchivo,pArrayListPassenger);
			validacion = 1;
		}

		fclose(pArchivo);
	}

    return validacion;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int validacion = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL)
		{
			parser_PassengerFromBinary(pArchivo,pArrayListPassenger);
			validacion = 1;
		}

		fclose(pArchivo);
	}

	return validacion;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int id;
    char nombre[100];
    char apellido[100];
    float precio;
    char flycode[100];
    char tipoPasajero[100];
    char statusFlight[100];
    int retorno=0;
    int validacion=0;
    Passenger* auxPasajero=NULL;

    id = ObtenerMayorId("dataId.csv");
    PedirCadena(nombre, "Ingresar el nombre del pasajero a agregar: ", "Error.\nIngresar el nombre del pasajero a agregar:",1);
    Mayuscula(nombre);
    PedirCadena(apellido, "Ingresar el apellido del pasajero a agregar: ", "Error.\nIngresar el apellido del pasajero a agregar: ",1);
    Mayuscula(apellido);
    precio = PedirFloat("Ingresar el precio del vuelo a agregar: ", "Error.\nIngresar el precio del vuelo a agregar: ", 1000,99999);
    PedirCadena(tipoPasajero, "Ingresar el tipo de pasajero a agregar: ", "Error.\nIngrese el tipo de pasajero a agregar: ",1);
    Mayuscula(tipoPasajero);
    PedirCadena(flycode, "Ingresar el código de vuelo del pasajero a agregar: ", "Error.\nIngrese el código de vuelo del pasajero a agregar: ",0);
    strupr(flycode);
    PedirCadena(statusFlight, "Ingresar el estado del vuelo a agregar: ", "Error.\nIngresar el estado del vuelo a agregar: ",1);
    Mayuscula(statusFlight);

    auxPasajero = Passenger_new();

    validacion = Passenger_setters(auxPasajero, id, nombre, apellido, precio,tipoPasajero , flycode, statusFlight);
    if(validacion==1)
    {
        ll_add(pArrayListPassenger, auxPasajero);
        passenger_loadTextId(id);
        retorno = 1;
    }
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    int tam;
    int id;
    int index;
    char nombre[100];
	char apellido[100];
	float precio;
	char flycode[100];
	char tipoPasajero[100];
	char statusFlight[100];
	Passenger* PasajeroAModificar;
	int opcion;
	char respuesta;


	if(pArrayListPassenger != NULL)
	{
		tam = ll_len(pArrayListPassenger);
		do
		{
			id = PedirEntero("Ingrese el id del pasajero que desea modificar: ","Error.\nIngrese el id del pasajero que desea modificar: ",1,tam);
			index = passenger_findID(pArrayListPassenger,id);

			PasajeroAModificar = (Passenger*)ll_get(pArrayListPassenger,index);


			if(PasajeroAModificar != NULL)
			{
				do
				{
				printf("Ingrese el dato que desea cambiar.\n1-Nombre\n2-Apellido\n3-Precio\n4-Codigo de vuelo\n5-Tipo de pasajero\n6-Estado de vuelo\n7-Salir\n");
				opcion = PedirEntero("Ingrese el numero correspondiente: ","Error.\n Ingrese el numero correspondiente: ",1,7);
				switch(opcion)
				{
				case 1:
					printf("Nombre.\n");
					PedirCadena(nombre,"Ingrese el nombre modificado. ","Error, ingrese el nombre modificado. (solo letras.) ",1);
					Passenger_setNombre(PasajeroAModificar,nombre);
				break;

				case 2:
					printf("Apellido.\n");
					PedirCadena(apellido,"Ingrese el apellido modificado. ","Error, ingrese el apellido modificado. (solo letras.) ",1);
					Passenger_setApellido(PasajeroAModificar,apellido);
				break;

				case 3:
					printf("Precio.\n");
					precio = PedirFloat("Ingrese el precio modificado. ","Error, ingrese el precio modificado. ",1000,99999);
					Passenger_setPrecio(PasajeroAModificar,precio);
				break;

				case 4:
					printf("Codigo de vuelo.\n");
					PedirCadena(flycode,"Ingrese el codigo de vuelo modificado. ","Error, ingrese el codigo de vuelo modificado. (solo letras.) ",1);
					Passenger_setCodigoVuelo(PasajeroAModificar,flycode);
				break;

				case 5:
					printf("Tipo de pasajero.\n");
					PedirCadena(tipoPasajero,"Ingrese el codigo de vuelo modificado. ","Error, ingrese el codigo de vuelo modificado. (solo letras.) ",1);
					Passenger_setTipoPasajero(PasajeroAModificar,tipoPasajero);
				break;

				case 6:
					printf("Estado de vuelo.\n");
					PedirCadena(statusFlight,"Ingrese el estado de vuelo modificado. ","Error, ingrese el estado de vuelo modificado. ",1);
					Passenger_setStatusFlight(PasajeroAModificar,statusFlight);
				break;
				}

				}while(opcion != 7);
			}
			printf("¿Desea modificar datos de otro pasajero?\nIngrese S si desea seguir modificando. ");
			scanf("%c",&respuesta);
		}while(respuesta=='s');
	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int tam;
	int id;
	int index;
	int retorno = 0;
	char respuesta;
	Passenger* PasajeroAEliminar;

	if(pArrayListPassenger != NULL)
		{
			tam = ll_len(pArrayListPassenger);
			id = PedirEntero("Ingrese el id del pasajero que desea eliminar: ","Error.\nIngrese el id del pasajero que desea eliminar: ",1,tam);
			index = passenger_findID(pArrayListPassenger,id);

			PasajeroAEliminar = (Passenger*)ll_get(pArrayListPassenger,index);

			printf("¿Está seguro de eliminar este pasajero?\ns Si\nn No    ");
			scanf("%s",&respuesta);

			if(respuesta == 's')
			{
				Passenger_delete(PasajeroAEliminar);
				ll_remove(pArrayListPassenger,index);
				printf("Pasajero eliminado con éxito.\n");
				retorno = 1;
			}
			else
			{
				printf("Usted no ha eliminado al pasajero.\n");
			}

		}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int auxId;
	char auxName[50];
	char auxLastName[50];
	float auxPrice;
	char auxFlyCode[50];
	char auxTypePassenger[50];
	char auxStatusFlight[50];
	Passenger* auxPasajero = NULL;
	int retorno = 0;
	int len;

	if(pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);
		if(len > 0)
		{
			for(int i=0;i<len;i++)
			{
				auxPasajero = (Passenger*)ll_get(pArrayListPassenger,i);

				if(auxPasajero != NULL)
				{
					if(Passenger_getters(auxPasajero, &auxId,auxName,auxLastName,&auxPrice,auxFlyCode,auxTypePassenger,auxStatusFlight)==1)
					{
						printf("%d %s %s %.2f %s %s %s\n",auxId,auxName,auxLastName,auxPrice,auxFlyCode,auxTypePassenger,auxStatusFlight);
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;

}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int orden;
	int opcion;
	int retorno = -1;
	LinkedList* clonacion;

	if(pArrayListPassenger!=NULL)
	{
		clonacion = ll_clone(pArrayListPassenger);
		do{
		opcion = PedirEntero("Ingrese bajo que criterio desea ordenar la lista.\n"
		"1- ID\n2- Nombre\n3- Apellido\n4- Precio\n5- Tipo de pasajero\n6- Estado de vuelo\n7-Salir\n","Error. Ingrese bajo que criterio desea ordenar la lista.\n",1,7);


		if(opcion!=7)
		{
			orden = PedirEntero("Ingrese en que orden desea ordenarlo.\n"
					"0- ORDEN DESCENDENTE.\n"
					"1- ORDEN ASCENDENTE. \n","Ingrese un número nuevamente. ",0,1);
		}

		switch(opcion)
		{
		case 1:
			if(!ll_sort(clonacion,ordenarPorId,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;

		case 2:
			if(!ll_sort(clonacion,ordenarPorNombre,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;

		case 3:
			if(!ll_sort(clonacion,ordenarPorApellido,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;

		case 4:
			if(!ll_sort(clonacion,ordenarPorPrecio,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;

		case 5:
			if(!ll_sort(clonacion,ordenarPorTypePassenger,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;

		case 6:
			if(!ll_sort(clonacion,ordenarPorEstadoDeVuelo,orden))
			{
				if(orden == 0)
				{
					printf("Lista ordenada descendentemente.\n");
					controller_ListPassenger(clonacion);
				}
				else
				{
					printf("Lista ordenada ascendentemente.\n");
					controller_ListPassenger(clonacion);
				}
			}
		break;
		}
		}while(opcion != 7);
	}


	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    FILE* pFile;
    Passenger* unPasajero = NULL;
    int size;
    int validacion = 0;
    int retorno = 0;
    int id;
    char nombre[100];
    char apellido[100];
    float precio;
    char flycode[100];
    char tipoPasajero[100];
    char statusFlight[100];

    if(path!=NULL && pArrayListPassenger!=NULL)
    {
        size = ll_len(pArrayListPassenger);
        pFile = fopen(path, "w");

        if(pFile!=NULL && size>0)
        {
        	fprintf(pFile,"ID,NOMBRE,APELLIDO,PRECIO,CODIGO,TIPO,ESTADO\n");
            for(int i=0; i<size; i++)
            {
                unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

                if(unPasajero!=NULL)
                {
                    validacion = Passenger_getters(unPasajero, &id, nombre, apellido, &precio, flycode, tipoPasajero, statusFlight);

                    if(validacion == 1)
                    {
                        fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio, flycode, tipoPasajero, statusFlight);
                        retorno = 1;
                    }
                }
            }
            passenger_loadTextId(id);
        }
    }

    fclose(pFile);

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* unPasajero = NULL;
	int size;
	int validacion = 0;
	int contador = 0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		size = ll_len(pArrayListPassenger);
		pFile = fopen(path, "wb");

		if(pFile!=NULL && size>0)
		{
			for(int i=0; i<size; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					fwrite(unPasajero, sizeof(Passenger)*1, 1, pFile);
					contador++;
					validacion = 1;
				}
			}
			passenger_loadTextId(contador);
		}
	}

	fclose(pFile);

	return validacion;
}
