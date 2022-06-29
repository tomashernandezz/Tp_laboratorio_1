#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_
#define TAMTYPE 3
typedef struct
{
    int idType;
    char nombreType[21];
}typePassenger;

/// @brief Matchea el ID del TypePassenger
///
/// @param passenger Pasa lista de pasajeros
/// @param typePassenger Campo del tipo de pasajero
/// @param size Tamaño de la estructura
/// @return Retorna la posición del typePassenger
int DescripcionType(Passenger passenger, typePassenger typePassenger[], int size);

#endif /* TYPEPASSENGER_H_ */
