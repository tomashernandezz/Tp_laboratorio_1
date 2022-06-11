#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

Passenger* Passenger_new()
{
	Passenger* UnPasajero = NULL;

	UnPasajero = (Passenger*) malloc(sizeof(Passenger)*1);

	return UnPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* lastName,char* price, char* flyCode, char* typePassenger,char* StatusFlight)
{
	Passenger* UnPasajero = NULL;

	UnPasajero = Passenger_new();

	if(UnPasajero != NULL && idStr != NULL && lastName != NULL && price != NULL && flyCode != NULL && typePassenger != NULL && StatusFlight != NULL)
	{
		Passenger_setId(UnPasajero,atoi(idStr));
		Passenger_setNombre(UnPasajero,nombreStr);
		Passenger_setApellido(UnPasajero,lastName);
		Passenger_setPrecio(UnPasajero,atof(price));
		Passenger_setTipoPasajero(UnPasajero,typePassenger);
		Passenger_setCodigoVuelo(UnPasajero,flyCode);
		Passenger_setStatusFlight(UnPasajero,StatusFlight);
	}

	return UnPasajero;
}

void passenger_loadTextId(int id)
{
	FILE* pArchivo;

	pArchivo = fopen("dataId.csv","w");

	if(pArchivo!=NULL)
	{
		fprintf(pArchivo,"%d\n",id);
	}

	fclose(pArchivo);
}

int ObtenerMayorId(char* path)
{
	char id[100];
	int idAux;
	FILE* pArchivo;

	pArchivo = NULL;

	pArchivo = fopen(path,"r");

	if(pArchivo!=NULL)
	{
		fscanf(pArchivo,"%[^\n]\n",id);
		idAux= atoi(id);
	}

	fclose(pArchivo);

	return idAux+1;
}

int passenger_getId(Passenger* this, int* id)
{
	int retorno = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;

	if(this!=NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
   int retorno = 0;

   if(this!=NULL && id != NULL)
   {
		*id = this->id;
		retorno = 1;
	}

   return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this!=NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

	if(this!=NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

	if(this!=NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this!=NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this!=NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;

	if(this!=NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;

	if(this!=NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;

	if(this!=NULL)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;

	if(this!=NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno = 0;

	if(this!=NULL && statusFlight != NULL)
	{
		strcpy(this->statusFlight, statusFlight);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno = 0;

	if(this!=NULL && statusFlight != NULL)
	{
		strcpy(statusFlight, this->statusFlight);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getters(Passenger* this, int* id, char* nombre, char* apellido, float* precio, char* tipoPasajero, char* codigoVuelo,char* statusFlight)
{
	int retorno = 0;

	if(Passenger_getId(this,id) == 1 &&
	Passenger_getNombre(this,nombre) == 1 &&
	Passenger_getApellido(this,apellido) == 1 &&
	Passenger_getCodigoVuelo(this,codigoVuelo) == 1 &&
	Passenger_getTipoPasajero(this,tipoPasajero) == 1 &&
	Passenger_getPrecio(this,precio) == 1 &&
	Passenger_getStatusFlight(this,statusFlight) == 1)
	{
		retorno = 1;
	}



	return retorno;
}

int Passenger_setters(Passenger* this, int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo,char* statusFlight)
{
	int retorno = 0;

	if(Passenger_setId(this,id) == 1 &&
	Passenger_setNombre(this,nombre) == 1 &&
	Passenger_setApellido(this,apellido) == 1 &&
	Passenger_setCodigoVuelo(this,codigoVuelo) == 1 &&
	Passenger_setTipoPasajero(this,tipoPasajero) == 1 &&
	Passenger_setPrecio(this,precio) == 1 &&
	Passenger_setStatusFlight(this,statusFlight) == 1)
	{
		retorno = 1;
	}



	return retorno;
}

void Passenger_Id(int id)
{
	FILE* pArchivo;

	pArchivo = fopen("dataId.csv","w");

	fprintf(pArchivo,"%d\n",id);

	fclose(pArchivo);
}

int passenger_findID(LinkedList* pArrayListPassenger, int id)
{
	int i;
	int len;
	int index;
	Passenger* auxiliar;

	if(pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Passenger*)ll_get(pArrayListPassenger,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
		{
			free(this);
			this=NULL;
		}
}

int ordenarPorId(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    int Id;
    int otroId;

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if((Passenger_getId(unPassengerAux, &Id) == 1) && (Passenger_getId(otroPassengerAux, &otroId)) == 1)
        {
            if(Id > otroId)
            {
                validacion = 1;
            }
            else
            {
                if(Id < otroId)
                {
                    validacion = -1;
                }
            }
        }
    }

    return validacion;
}

int ordenarPorPrecio(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    float precio;
    float otroPrecio;

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if(Passenger_getPrecio(unPassengerAux, &precio) == 1 && (Passenger_getPrecio(otroPassengerAux, &otroPrecio)) == 1)
        {
            if(precio > otroPrecio)
            {
                validacion = 1;
            }
            else
            {
                if(precio < otroPrecio)
                {
                    validacion = -1;
                }
            }
        }
    }

    return validacion;
}


int ordenarPorTypePassenger(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    char type[50];
    char otroType[50];

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if((Passenger_getTipoPasajero(unPassengerAux, type) == 1) && (Passenger_getTipoPasajero(otroPassengerAux, otroType) == 1))
        {
        	validacion = strcmp(type,otroType);
        }
    }

    return validacion;
}

int ordenarPorNombre(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    char nombre[50];
    char otroNombre[50];

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if((Passenger_getNombre(unPassengerAux, nombre) == 1) && (Passenger_getNombre(otroPassengerAux, otroNombre) == 1))
        {
        	validacion = strcmp(nombre,otroNombre);
        }
    }

    return validacion;
}

int ordenarPorApellido(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    char apellido[50];
    char otroApellido[50];

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if((Passenger_getApellido(unPassengerAux, apellido) == 1) && (Passenger_getApellido(otroPassengerAux, otroApellido) == 1))
        {
        	validacion = strcmp(apellido,otroApellido);
        }
    }

    return validacion;
}

int ordenarPorEstadoDeVuelo(void* unPassenger, void* otroPassenger)
{
    int validacion = 0;
    Passenger* unPassengerAux = NULL;
    Passenger* otroPassengerAux = NULL;

    char statusFlight[50];
    char otrostatusFlight[50];

    if(unPassenger != NULL && otroPassenger != NULL)
    {
        unPassengerAux = (Passenger*) unPassenger;
        otroPassengerAux = (Passenger*) otroPassenger;

        if(Passenger_getTipoPasajero(unPassengerAux, statusFlight) == 1 && (Passenger_getTipoPasajero(otroPassengerAux, otrostatusFlight)) == 1)
        {
        	validacion = strcmp(statusFlight,otrostatusFlight);
        }
    }

    return validacion;
}
