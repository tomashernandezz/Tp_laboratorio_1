#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nexo.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int contadorPasajeros;
	int retornoEstado;
	int suma;
	int opcionLista;
	float promedio;
	int orden;
	int cargaForzadaContador = 0;
	contadorPasajeros = 0;
	Passenger listaPassengers[TAM];
	typePassenger typeList[TAMTYPE] = {{1, "TURISTA"} , {2, "PRIMERA CLASE"} , {3, "ECONOMICO"}};
	statusFlight statusList[TAMSTATUS] = {{1, "ACTIVO"} , {2, "DEMORADO"} , {3, "ESTIMA"}};

	InitPassengers(listaPassengers,TAM);

	do{
		opcion = PedirEntero("===============INGRESE UNA OPCIÓN=================\n"
				"1.ALTA \n2.MODIFICACION \n3.BAJA \n4.LISTADO \n5.CARGA FORZADA DE DATOS.\n6.SALIR\n"
				"==================================================\n"
				,"Error, ingrese un número del 1 al 6\n===============INGRESE UNA OPCIÓN=================\n"
				"1.ALTA \n2.MODIFICACION \n3.BAJA \n4.LISTADO \n5.CARGA FORZADA DE DATOS.\n6.SALIR\n"
				"==================================================\n",1,6);
		switch(opcion){
		case 1:
			contadorPasajeros++;
			PedirDatos(listaPassengers,TAM);
		break;

		case 2:
			if(contadorPasajeros>0)
			{
				PrintPassenger(listaPassengers, TAM, statusList, TAMSTATUS, typeList, TAMTYPE);
				ModificarPassenger(listaPassengers, TAM);
			}
			else
			{
				printf("Error, no se ha ingresado ningún dato aún.\n"
					   "Para modificar debe ingresar un dato.\n");
			}

		break;

		case 3:
			if(contadorPasajeros>0)
			{
				PrintPassenger(listaPassengers, TAM, statusList, TAMSTATUS, typeList, TAMTYPE);
				retornoEstado = RemovePassenger(listaPassengers, TAM);
				if(retornoEstado==-1)
				{
					contadorPasajeros--;
				}
			}
			else
			{
				printf("Error, no se ha ingresado ningún dato aún.\n"
					   "Para eliminar debe ingresar un dato.\n");
			}

		break;

		case 4:
			if(contadorPasajeros>0)
			{
				printf("\n\n===========================================================================\n"
						"1. Ordenar los pasajeros por apellido y por tipo de vuelo.\n"
						"2. Mostrar el listado de pasajeros ordenado por flycode y estado de vuelo activo.\n"
						"3. Calcular y mostrar el promedio.\n"
						"===========================================================================\n");
				scanf("%d",&opcionLista);
				switch(opcionLista)
				{
				case 1:
					printf("-1 Para ordenar de manera descendente.\n"
							"1 Para ordenar de manera ascendente\n");
					scanf("%d",&orden);

					if(orden == 1 || orden == -1)
					{
						sortPassengers(listaPassengers,TAM,orden);
						printf("ID=====NOMBRE====APELLIDO======PRECIO====CODIGO DE VUELO==TIPO DE VUELO===ESTADO DE VUELO\n");
						PrintPassenger(listaPassengers, TAM, statusList, 4, typeList, 3);
						printf("=======================================================================================\n\n\n");
					}
					else
					{
						printf("Error, ingrese una opción que sea 1 o -1\n");
					}

				break;

				case 2:
					printf("-1 Para ordenar de manera descendente.\n"
							"1 Para ordenar de manera ascendente\n");
					scanf("%d",&orden);

					if(orden == 1 || orden == -1)
					{
						sortPassengersbyFlyCode(listaPassengers,TAM,orden);
						printf("ID=====NOMBRE=====APELLIDO======PRECIO====CODIGO DE VUELO==TIPO DE VUELO===ESTADO DE VUELO\n");
						PrintPassenger(listaPassengers, TAM, statusList, TAMSTATUS, typeList, TAMTYPE);
						printf("=======================================================================================\n\n\n");
					}
					else
					{
						printf("Error, ingrese una opción que sea 1 o -1\n");
					}

				break;

				case 3:
					suma = CalcularTotal(listaPassengers,TAM);
					promedio = CalcularPromedio(listaPassengers,TAM);
					MostrarPromedio(suma,promedio,listaPassengers,TAM);
				break;

				default:
					printf("\nError.\n");
				break;

				}
			}
			else
			{
				printf("Error, no se ingresó ningún pasajero\n");
			}
		break;

		case 5:
			if(cargaForzadaContador == 0)
			{
			CargaForzada(listaPassengers,5);
			contadorPasajeros = contadorPasajeros + 5;
			cargaForzadaContador++;
			}
			else
			{
				printf("Error, ya se realizó la carga forzada\n");
			}
		break;

		case 6:
			printf("Saliendo...");
			system("pause");
		break;
		}
	}while(opcion != 7);
}
