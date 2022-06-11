#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char auxId[20];
	char auxName[51];
	char auxLastName[51];
	char auxPrice[50];
	char auxFlyCode[50];
	char auxTypePassenger[50];
	char auxStatusFlight[50];
	int retorno = 0;
	Passenger* auxPasajero = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxLastName,auxPrice,auxFlyCode,auxTypePassenger,auxStatusFlight);
		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxLastName,auxPrice,auxFlyCode,auxTypePassenger,auxStatusFlight);
			auxPasajero = Passenger_newParametros(auxId,auxName,auxLastName,auxPrice,auxFlyCode,auxTypePassenger,auxStatusFlight);
			if(auxPasajero != NULL)
			{
				ll_add(pArrayListPassenger,auxPasajero);
				retorno = 1;
			}
		}while(!feof(pFile));
		passenger_loadTextId(atoi(auxId));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
		int retorno = 0;
		Passenger* nuevoPasajero = NULL;

			if(pFile != NULL &&  pArrayListPassenger != NULL)
			{
				    while(!feof(pFile))
				        {
				            nuevoPasajero = Passenger_new();
				            if(nuevoPasajero != NULL)
				            {
				            	if(fread(nuevoPasajero,sizeof(Passenger),1,pFile) != 0)
				            	{
				            		ll_add(pArrayListPassenger, nuevoPasajero);
				            	}
				            }
				        }
				    retorno = 1;
			}
	    return retorno;
}
