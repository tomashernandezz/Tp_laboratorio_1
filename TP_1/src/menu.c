#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void menu(void)
{
	setbuf(stdout,NULL);
	int opcion;
	// Variable de tipo entero para determinar que función usar.
	int opcionPrecio;
	float x = 0;
	// Variable los kilómetros del viaje.
	float y = 0;
	// Variable de tipo flotante para guardar el precio de Aerolíneas.
	float z = 0;
	// Variable de tipo flotante para guardar el precio de LATAM.
	float precioDebitoAero;
	// Variable para guardar el precio de con débito de Aerolíneas.
	float precioCreditoAero;
	// Variable para guardar el precio de con crédito de Aerolíneas.
	float precioBTCAero;
	// Variable para guardar el precio en Bitcoin de Aerolíneas.
	float precioUnitarioAero;
	// Variable para guardar el precio por kilómetro de Aerolíneas.
	float precioDebitoLATAM;
	// Variable para guardar el precio de con débito de LATAM.
	float precioCreditoLATAM;
	// Variable para guardar el precio de con crédito de LATAM.
	float precioBTCLATAM;
	// Variable para guardar el precio en Bitcoin de LATAM.
	float precioUnitarioLATAM;
	// Variable para guardar el precio por kilómetro de LATAM.
	float diferenciaDePrecio;
	// Variable para guardar y calcular la diferencia de precio entre los dos viajes.

	printf("¡Bienvenido/a!\n");

	do
	{
		printf("1.Ingresar KM:");
		printf("\n2.Ingresar Precio de Vuelos:");
		printf("\n3.Calcular todos los costos.");
		printf("\n4.Informar Resultados.");
		printf("\n5.Carga forzada de datos.");
		printf("\n6.Salir.\n");
		fflush(stdin);
		scanf("%d",&opcion);
		void espaciadoConsola();

		switch(opcion)
		{
			case 1:
				x = pedirDato("Ingrese los kilómetros:\n");
				while(x <= 0)
				{
					printf("Error, ingrese un dato mayor a 0\n");
					x = pedirDato("Ingrese los kilómetros:\n");
				}
				espaciadoConsola();
			break;

			case 2:

				y = 0;
				z = 0;

				do
				{
					printf("\n1. Ingresar precio de Aerolíneas\n");
					printf("2. Ingresar precio de LATAM\n");
					scanf("%d",&opcionPrecio);

					if(opcionPrecio == 1)
					{
						y = pedirDato("Ingresar precio de Aerolíneas\n");
					}
					else
					{
						if(opcionPrecio == 2)
						{
							z = pedirDato("Ingresar precio de LATAM\n");
						}
						else
						{
							printf("Opción inválida, ingrese 1 o 2.");
						}
					}

				}while(y == 0 || z == 0);


			break;

			case 3:
				if(x == 0 || y == 0 || z == 0)
				{
					printf("El precio de los vuelos no puede ser 0 o menor a 0.");
					espaciadoConsola();
					menu();
				}
				else
				{
					precioDebitoAero = PrecioDebito(y);
					precioDebitoLATAM = PrecioDebito(z);
					precioCreditoAero = PrecioCredito(y);
					precioCreditoLATAM = PrecioCredito(z);
					precioBTCAero = PrecioBitCoin(y);
					precioBTCLATAM = PrecioBitCoin(z);
					precioUnitarioAero = PrecioUnitario(y,x);
					precioUnitarioLATAM = PrecioUnitario(z,x);

					diferenciaDePrecio = precioDiferencia(y,z);
					printf("\nSe han calculado todos los costos.\n");
					espaciadoConsola();
				}
			break;

			case 4:
				if(x == 0 && y == 0 && z == 0)
				{
					printf("El precio de los vuelos o la distancia en KM no puede ser menor o igual a 0");
					espaciadoConsola();
					menu();
				}
				else
				{
					printf("\nTotal de kilómetros: %.1f\n\n",x);
					printf("Precio de LATAM: %.1f\n\n",y);
					printf("1- El precio con débito de LATAM es de %.2f\n",precioDebitoLATAM);
					printf("2- El precio con débito de LATAM es de %.2f\n",precioCreditoLATAM);
					printf("3- El precio en BTC de LATAM es de %.4f\n",precioBTCLATAM);
					printf("4- El precio unitario de LATAM es de %.2f\n\n",precioUnitarioLATAM);

					printf("Precio de Aerolíneas: %.1f\n\n",z);
					printf("1- El precio con débito de Aerolíneas es de %.2f\n",precioDebitoAero);
					printf("2- El precio con crédito de Aerolíneas es de %.2f\n",precioCreditoAero);
					printf("3- El precio en BTC de Aerolineas es de %.4f\n",precioBTCAero);
					printf("4- El precio unitario de Aerolíneas es de %.2f\n\n",precioUnitarioAero);
					printf("La diferencia de precio entre los vuelos es de %.2f\n",diferenciaDePrecio);

					espaciadoConsola();
				}

			break;

			case 5:
				printf("\n\nCarga forzada de datos.\n\n");
				x = 7090;
				z = 162965;
				y = 159339;

				precioDebitoAero = PrecioDebito(y);
				precioDebitoLATAM = PrecioDebito(z);
				precioCreditoAero = PrecioCredito(y);
				precioCreditoLATAM = PrecioCredito(z);
				precioBTCAero = PrecioBitCoin(y);
				precioBTCLATAM = PrecioBitCoin(z);
				precioUnitarioAero = PrecioUnitario(y,x);
				precioUnitarioLATAM = PrecioUnitario(z,x);

				diferenciaDePrecio = precioDiferencia(y,z);

				printf("Precio de LATAM: 162.965\n\n");
				printf("1- El precio con débito de LATAM es de %.2f\n",precioDebitoLATAM);
				printf("2- El precio con débito de LATAM es de %.2f\n",precioCreditoLATAM);
				printf("3- El precio en BTC de LATAM es de %.4f\n",precioBTCLATAM);
				printf("4- El precio unitario de LATAM es de %.2f\n\n",precioUnitarioLATAM);

				printf("Precio de Aerolíneas: 159.339\n\n");
				printf("1- El precio con débito de Aerolíneas es de %.2f\n",precioDebitoAero);
				printf("2- El precio con crédito de Aerolíneas es de %.2f\n",precioCreditoAero);
				printf("3- El precio en BTC de Aerolineas es de %.4f\n",precioBTCAero);
				printf("4- El precio unitario de Aerolíneas es de %.2f\n\n",precioUnitarioAero);
				printf("La diferencia de precio entre los vuelos es de %.2f\n",diferenciaDePrecio);

				x = 0;
				y = 0;
				z = 0;

				espaciadoConsola();
			break;

			default:
				printf("\n\nSaliendo...\n\n");
				espaciadoConsola();
			break;
		}

		while(opcion > 6)
		{
			printf("Opción no válida, vuelva a ingresar una nueva.");
			scanf("%d",&opcion);
			void espaciadoConsola();
			menu();
		}

	}while(opcion != 6);


}
