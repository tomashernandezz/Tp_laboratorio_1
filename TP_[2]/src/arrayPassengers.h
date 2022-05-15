#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

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

typedef struct
{
    int idType;
    char nombreType[21];
}typePassenger;

typedef struct
{
    int idStatus;
    char nombreStatus[21];
}statusFlight;

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

/// @brief Función que retorna la ID automáticamente sin tener que asignar
///
/// @return Retorna una ID, siendo la primera 1000
int ObtenerID();

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
/// @param id Id del pasajero a remover.
/// @return Retorna -1 si no se encuentra la id del pasajero
int RemovePassenger(Passenger listaPassengers[], int sizePassengers, int id);

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

/// @brief Pide una cadena, validando si se ingresan números.
///
/// @param cadena Valor de la cadena ingresada
/// @param mensaje Mensaje para pedir la cadena
/// @param mensaje Error Muestra el mensaje de error
/// @param validar Estado de la validacion
/// @return
int PedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar);

/// @brief Valida si algún caracter tiene una letra
///
/// @param cadena
/// @return
int ValidacionDeCaracteres (char cadena[]);

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

/// @brief Cambia el nombre del estado del vuelo
///
/// @param passenger
/// @param statusFlight
/// @param size
/// @return
int DescripcionStatus(Passenger passenger, statusFlight statusFlight[], int size);

/// @brief Cambia el nombre del tipo de pasajero
///
/// @param passenger
/// @param typePassenger
/// @param size
/// @return
int DescripcionType(Passenger passenger, typePassenger typePassenger[], int size);

/// @brief Pide un flotante
///
/// @param mensaje
/// @param error
/// @param minimo
/// @param maximo
/// @return Retorna el flotante
float PedirFloat(char mensaje[],char error[],int minimo,int maximo);

/// @brief Pide un entero
///
/// @param mensaje
/// @param error
/// @param minimo
/// @param maximo
/// @return Retorna el entero
int PedirEntero(char mensaje[],char error[],int minimo,int maximo);

/// @brief Valida un numero
///
/// @param numeros
/// @return
int ValidarNumero (char numeros[]);

/// @brief Hardecodede los datos
///
/// @param listaPassengers
/// @param sizePassengers
void CargaForzada(Passenger listaPassengers[], int sizePassengers);

/// @brief Pone la primera letra mayuscula de una cadena
///
/// @param name Cadena que se utiliza para ponerle la primera letra mayúscula.
void Mayuscula(char name []);

/// @brief Ordena pasajeros por flycode o por estado de vuelo
///
/// @param passengerList
/// @param size
/// @param order
/// @return
int sortPassengersbyFlyCode(Passenger passengerList[], int size, int order);

#endif /* ARRAYPASSENGERS_H_ */
