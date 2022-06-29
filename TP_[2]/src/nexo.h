#ifndef NEXO_H_
#define NEXO_H_

#include "arrayPassengers.h"
#include "input.h"
#include "StatusFlight.h"
#include "TypePassenger.h"

/// @brief Funcion para mostrar un pasajero, que se itera con la siguiente función
///
/// @param UnPasajero Datos de un pasajero
/// @param statusFlight Estado de vuelo
/// @param statusSize
/// @param typePassenger
/// @param typeSize
void MostrarUnPasajero(Passenger UnPasajero, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize);

/// @brief Con la función anterior, muestra todos los pasajeros.
///
/// @param listaPassengers
/// @param sizePassengers
/// @param statusFlight
/// @param statusSize
/// @param typePassenger
/// @param typeSize
void PrintPassenger(Passenger listaPassengers[], int sizePassengers, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize);

#endif /* NEXO_H_ */
