#include "nexo.h"

void PrintPassenger(Passenger listaPassengers[], int sizePassengers, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize)
{
	for(int i=0; i<sizePassengers; i++)
	{
		if(listaPassengers[i].isEmpty == OCUPADO)
		{
			MostrarUnPasajero(listaPassengers[i], statusFlight,statusSize, typePassenger, typeSize);
		}
	}
}

void MostrarUnPasajero(Passenger UnPasajero, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize)
{
	int typeNombre;
	int statusNombre;

	typeNombre = DescripcionType(UnPasajero, typePassenger, typeSize);
	statusNombre = DescripcionStatus(UnPasajero, statusFlight, statusSize);

	printf("%-6d|%-10s|%-13s|%-9.1f|%-16s|%-16s|%s\n",UnPasajero.id,UnPasajero.name,UnPasajero.lastName,UnPasajero.price,UnPasajero.flycode,typePassenger[typeNombre].nombreType,statusFlight[statusNombre].nombreStatus);
}
