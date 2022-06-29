#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_
#define TAMSTATUS 3

typedef struct
{
    int idStatus;
    char nombreStatus[21];
}statusFlight;

/// @brief Matchea el ID del statusFlight
///
/// @param passenger Pasa la lista
/// @param statusFlight Campo del statusFlight
/// @param size Tamaño de la estructura
/// @return return Retorna la posición del statusFlight
int DescripcionStatus(Passenger passenger, statusFlight statusFlight[], int size);

#endif /* STATUSFLIGHT_H_ */
