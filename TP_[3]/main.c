#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int flagLoadText = 0;
    int flagLoadBinary = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	option = PedirEntero("==============================================================================\n"
							"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
							"2- Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
							"3- Alta de pasajero.\n"
							"4- Modificar datos de pasajero.\n"
							"5- Baja de pasajero.\n"
							"6- Listar pasajero.\n"
							"7- Ordenar pasajero.\n"
							"8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
							"9- Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n"
							"10- Salir\n"
    						"==============================================================================\nIngrese una opción: ","Ups, debe haber algún error. Ingrese una opción entre 1 y 10."
							"\n==============================================================================\n"
							"1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							"2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
							"3- Alta de empleado.\n"
							"4- Modificar datos de empleado.\n"
							"5- Baja de empleado.\n"
							"6- Listar empleados.\n"
							"7- Ordenar empleados.\n"
							"8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
							"9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
							"10- Salir\n"
							"==============================================================================\nIngrese una opción: ",1,10);
        switch(option)
        {
            case 1:
				if(ll_isEmpty(listaPasajeros) && flagLoadText == 0 && flagLoadBinary == 0)
				{
						controller_loadFromText("data.csv",listaPasajeros);
						flagLoadText = 1;
						printf("Datos cargados con éxito!\n");
				}
				else
				{
					printf("Error. Posiblemente ya se hayan cargado los datos en otro modo.");
				}
            break;

            case 2:
            	if(ll_isEmpty(listaPasajeros) && flagLoadText == 0 && flagLoadBinary == 0)
            	{
            		controller_loadFromBinary("data.bin",listaPasajeros);
            		flagLoadBinary = 1;
            		printf("Datos cargados con éxito!");
            	}
            	else
            	{
            		printf("Error. Posiblemente ya se hayan cargado los datos en otro modo.");
            	}
            break;

            case 3:
            	controller_addPassenger(listaPasajeros);
            break;

            case 4:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
            	{
            	controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("ERROR.\n");
            	}
            break;

            case 5:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Error");
            	}
            	break;
            case 6:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No se han cargado empleados.");
            	}
            break;

            case 7:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
				{
            		controller_sortPassenger(listaPasajeros);
				}
            break;

            case 8:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
				{
            		controller_saveAsText("data.csv", listaPasajeros);
				}
            break;

            case 9:
            	if(flagLoadText == 1 || flagLoadBinary == 1)
				{
            		controller_saveAsBinary("data.bin",listaPasajeros);
				}
            break;

            case 10:
            	printf("Gracias. Hasta luego!");
            break;

        }
    }while(option != 10);
    return 0;
}

