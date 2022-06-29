#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Funci�n que retorna la ID autom�ticamente sin tener que asignar
///
/// @return Retorna una ID, siendo la primera 1000
int ObtenerID();

/// @brief Pide una cadena, validando si se ingresan n�meros.
///
/// @param cadena Valor de la cadena ingresada
/// @param mensaje Mensaje para pedir la cadena
/// @param mensaje Error Muestra el mensaje de error
/// @param validar Estado de la validacion
/// @return
int PedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar);

/// @brief Valida si alg�n caracter tiene una letra
///
/// @param cadena
/// @return
int ValidacionDeCaracteres (char cadena[]);

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

/// @brief Pone la primera letra mayuscula de una cadena
///
/// @param name Cadena que se utiliza para ponerle la primera letra may�scula.
void Mayuscula(char name []);

/// @brief Valida un numero
///
/// @param numeros
/// @return
int ValidarNumero (char numeros[]);

#endif /* INPUT_H_ */
