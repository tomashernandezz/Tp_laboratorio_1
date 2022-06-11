/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[40];
	char statusFlight[30];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* lastName,char* price, char* flyCode, char* typePassenger,char* StatusFlight);

int ObtenerMayorId(char* path);
void passenger_loadTextId(int id);
int passenger_getId(Passenger* this, int* id);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

int Passenger_getters(Passenger* this, int* id, char* nombre, char* apellido, float* precio, char* tipoPasajero, char* codigoVuelo,char* statusFlight);
int Passenger_setters(Passenger* this, int id, char* nombre, char* apellido, float precio, char* tipoPasajero, char* codigoVuelo,char* statusFlight);

int passenger_findID(LinkedList* pArrayListPassenger, int id);

int ordenarPorId(void* unPassenger, void* otroPassenger);
int ordenarPorNombre(void* unPassenger, void* otroPassenger);
int ordenarPorApellido(void* unPassenger, void* otroPassenger);
int ordenarPorPrecio(void* unPassenger, void* otroPassenger);
int ordenarPorTypePassenger(void* unPassenger, void* otroPassenger);
int ordenarPorEstadoDeVuelo(void* unPassenger, void* otroPassenger);

#endif /* PASSENGER_H_ */
