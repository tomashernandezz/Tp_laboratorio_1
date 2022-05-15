#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void espaciadoConsola(void){
		printf("\n\n\n--------------\n\n");
	}

float pedirDato(char mensaje[]){
	float numero;
	printf("%s",mensaje);
	scanf("%f", &numero);
	return numero;
}

float PrecioDebito(float precioIngresado)
{
	float descuento;
	float resultado;

	descuento = 10;
	resultado = precioIngresado-(precioIngresado*descuento/100);

	return resultado;
}

float PrecioCredito(float precioIngresado)
{
	float interes;
	float resultado;

	interes = 25;
	resultado = precioIngresado+(precioIngresado*interes/100);

	return resultado;
}

float PrecioBitCoin(float precioIngresado)
{
	float precioBTC;
	float resultado;

	precioBTC = 4606954.55;

	resultado = precioIngresado/precioBTC;

	return resultado;
}

float PrecioUnitario(float precioIngresado, float km)
{
	float resultado;

	resultado = precioIngresado/km;

	return resultado;
}
float precioDiferencia(float precioIngresado1, float precioIngresado2)
{
	float resultado;

	if(precioIngresado1 <= precioIngresado2)
	{
		resultado = precioIngresado2-precioIngresado1;
	}
	else
	{
		resultado = precioIngresado1-precioIngresado2;
	}

	return resultado;
}
