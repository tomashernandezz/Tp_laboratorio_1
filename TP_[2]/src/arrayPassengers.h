#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

#include "input.h"
#define TAM 2000
struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}typedef Passenger;

#define TAM 2000
#define TAMTYPE 3
#define TAMSTATUS 3


#define VACIO 0
#define OCUPADO 1

/// @brief Pide los datos a cada pasajero.
///
/// @param listaPassengers
/// @param tam
void PedirDatos(Passenger listaPassengers[], int tam);

/// @brief Los datos son agregados a cada pasajero
///
/// @param listaPassengers Lista de pasajeros
/// @param id ID del pasajero
/// @param name Nombre del pasajero
/// @param lastName Apellido del pasajero
/// @param price Precio del vuelo
/// @param flycode Codigo del vuelo
/// @param typePassenger Tipo de vuelo/pasajero
/// @param statusFlight Estado del vuelo
/// @return
int AddPassengers (Passenger listaPassengers[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight);

/// @brief
///
/// @param listaPassengers
/// @param sizePassengers
/// @return
int InitPassengers(Passenger listaPassengers[], int sizePassengers);

/// @brief Encuentra la posición del pasajero por su id
///
/// @param listaPassengers Lista de pasajeros
/// @param sizePassengers Cantidad de pasajeros
/// @param id ID del pasajero
/// @return
int FindPassengerById(Passenger listaPassengers[], int sizePassengers,int id);

/// @brief Busca un espacio libre en la lista
///
/// @param listaPassengers Lista de pasajeros
/// @param sizePassengers Cantidad de pasajeros
/// @return Retorna la primera posicion libre
int BuscarEspacioLibre(Passenger listaPassengers[], int sizePassengers);

/// @brief Modifica algún dato del pasajero
///
/// @param listaPassengers Lista de pasajero
/// @param sizePassengers Cantidad de pasajeros
/// @return Retorna -1 si no se encuentra la id del pasajero.
int ModificarPassenger(Passenger listaPassengers[], int sizePassengers);

/// @brief Elimina algún pasajero
///
/// @param listaPassengers Lista de pasajeros
/// @param sizePassengers Cantidad de pasajeros
/// @return Retorna -1 si no se encuentra la id del pasajero
int RemovePassenger(Passenger listaPassengers[], int sizePassengers);

/// @brief Ordena a todos los pasajeros
///
/// @param listaPassengers
/// @param sizePassengers
/// @param orden Parametro para determinar el orden.
/// @return
int sortPassengers(Passenger listaPassengers[],int sizePassengers, int orden);

/// @brief Calcula el total del precio de todos los vuelos
///
/// @param listaPassengers
/// @param sizePassengers
/// @return Retorna todos los precios sumados a una variable
float CalcularTotal(Passenger listaPassengers[], int sizePassengers);

/// @brief Muestra el promedio de todos los vuelos y la cantidad de pasajeros que superan el promedio
///
/// @param total
/// @param promedio
/// @param listaPassengers
/// @param sizePassengers
void MostrarPromedio(int total, float promedio,Passenger listaPassengers[], int sizePassengers);

/// @brief Calcula el promedio de todos los precios.
///
/// @param listaPassengers
/// @param sizePassengers
/// @return Retorna el promedio
float CalcularPromedio(Passenger listaPassengers[], int sizePassengers);

/// @brief Hardecodede los datos
///
/// @param listaPassengers
/// @param sizePassengers
void CargaForzada(Passenger listaPassengers[], int sizePassengers);

/// @brief Ordena pasajeros por flycode o por estado de vuelo
///
/// @param passengerList
/// @param size
/// @param order
/// @return
int sortPassengersbyFlyCode(Passenger passengerList[], int size, int order);

#endif /* ARRAYPASSENGERS_H_ */
