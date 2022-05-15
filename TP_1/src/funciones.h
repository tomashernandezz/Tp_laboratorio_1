#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn Funci�n para abrir el men�.
void menu();

/// @fn Funci�n para hacer un espaciado en la consola.
void espaciadoConsola(void);

/// @fn Funci�n para solicitar un dato.
/// @param Mensaje para mostrar lo que se est� pidiendo.
/// @return
float pedirDato(char mensaje[]);

/// @fn Funci�n para calcular el precio en d�bito
/// @param Precio a calcular.
/// @return
float PrecioDebito(float precioIngresado);

/// @fn float PrecioCredito(float)
/// @param Precio a calcular.
/// @return
float PrecioCredito(float precioIngresado);

/// @fn float PrecioBitCoin(float)
/// @param Precio a calcular.
/// @return
float PrecioBitCoin(float precioIngresado);

/// @fn float PrecioUnitario(float, float)
/// @param Precio a calcular.
/// @param Kil�metros para calcular el precio unitario.
/// @return
float PrecioUnitario(float precioIngresado, float km);

/// @fn float precioDiferencia(float, float)
/// @param Precio a calcular.
/// @param Precio a calcular/comparar con el anterior.
/// @return
float precioDiferencia(float precioIngresado1, float precioIngresado2);

#endif /* FUNCIONES_H_ */
