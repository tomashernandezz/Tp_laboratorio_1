#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassengers.h"

void PedirDatos(Passenger listaPassengers[], int tam)
{
	int estado;
	int id;
	char name[100];
	char lastName[100];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;

	id=ObtenerID();

	PedirCadena(name,"Ingrese su nombre.\n","Error, ingrese su nombre.\n",1);
	Mayuscula(name);

	PedirCadena(lastName,"Ingrese su apellido.\n","Error, ingrese su apellido.\n",1);
	Mayuscula(lastName);

	price=PedirFloat("Ingrese el precio del vuelo","Error, ingrese un n�mero entre el 1000 y 999.999\n",1000,999999);

	PedirCadena(flycode,"Ingrese el c�digo de vuelo.\n","Error, ingrese el c�digo de vuelo\n",0);

	typePassenger=PedirEntero("Ingrese el tipo de vuelo\n 1-Turista\n 2-Primera Clase\n 3-Economico\n","Error, ingrese un n�mero entre el 1 y el 3\n",1,3);

	statusFlight=PedirEntero("Ingrese el tipo de vuelo\n 1-Activo \n 2-Demorado\n 3-Estima\n","Error, ingrese un n�mero entre el 1 y el 3\n",1,3);

	estado = AddPassengers (listaPassengers,id, name, lastName, price, flycode, typePassenger, statusFlight);

	if(estado == -1)
	{
		printf("Hubo un error en la carga, posiblemente no haya mas espacio \n");
	}
	else
	{
		printf("Se cargo todo correctamente \n");
	}
}

int InitPassengers (Passenger listaPassengers[],int sizePassengers)
{
	int resultado;
	if (sizePassengers < 0 && sizePassengers > 2000)
	{
		resultado =-1;
	}
	else
	{
		resultado=0;
	}
	for(int i=0;i<sizePassengers;i++)
	{
		listaPassengers[i].isEmpty=VACIO;
	}

	return resultado;
}

int AddPassengers (Passenger listaPassengers[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight)
{
	int index;
	int retornoEstado=-1;

	index = BuscarEspacioLibre(listaPassengers,TAM);
	if(index !=-1)
	{
		strcpy(listaPassengers[index].name,name);
		strcpy(listaPassengers[index].lastName,lastName);
		strcpy(listaPassengers[index].flycode,flycode);
		listaPassengers[index].price=price;
		listaPassengers[index].typePassenger=typePassenger;
		listaPassengers[index].id=id;
		listaPassengers[index].isEmpty=OCUPADO;
		listaPassengers[index].statusFlight=statusFlight;
		retornoEstado =0;
	}

	return retornoEstado;
}


int BuscarEspacioLibre(Passenger listaPassengers[], int sizePassengers)
{
	int index;
	index = -1;
	for(int i=0; i<sizePassengers; i++)
	{
		if(listaPassengers[i].isEmpty != OCUPADO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int FindPassengerById(Passenger listaPassengers[], int sizePassengers,int id) //FUNCI�N OBLIGATORIA
{
    int index = -1;

    for(int i=0;i<sizePassengers;i++)
    {
        if(listaPassengers[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

int ModificarPassenger(Passenger listaPassengers[],int sizePassengers)
{
		int index;
		int opcion;
		int id;
		int validacion;
		int retorno =-1;
		char name[51];
		char lastName[51];
		char flycode[10];
		float price;
		int typePassenger;
		Passenger aux;

		printf("ingrese el id del pasajero: ");
		scanf("%d", &id);

		index = FindPassengerById(listaPassengers, sizePassengers, id);
		if(index!=-1)
		{
			retorno= 0;
			aux=listaPassengers[index];

			printf("PASAJERO: %s %s\n", listaPassengers[index].name,listaPassengers[index].lastName);

			printf("Ingrese la opci�n que desea modificar:\n"
					"1- Nombre.\n"
					"2- Apellido. \n"
					"3- Precio \n"
					"4- Tipo de vuelo \n"
					"5- C�digo de vuelo\n"
					"6- Si no desea modificar nada.\n"
					"Opcion: ");

				scanf("%d", &opcion);
				while(opcion < 1 || opcion > 7)
					{
						printf("Error, vuelva a ingresar una opci�n. \n");
						scanf("%d", &opcion);
					}

				switch(opcion)
					{
					case 1:
						printf("Ingrese su nombre: \n");
						fflush(stdin);
						gets(name);
						validacion= ValidacionDeCaracteres(name);
						Mayuscula(name);
						while(validacion==0)
						{
							printf("Error, vuelva a ingresar su nombre: \n");
							fflush(stdin);
							gets(name);
							validacion= ValidacionDeCaracteres(name);
							Mayuscula(name);
						}
						strcpy(aux.name,name);
						printf("Se cambi� correctamente el nombre\n");
					break;

					case 2:

						printf("Ingrese su apellido: \n");
						fflush(stdin);
						gets(lastName);
						validacion= ValidacionDeCaracteres(lastName);
						Mayuscula(lastName);
						while(validacion==0)
						{
							printf("Error, vuelva a ingresar su apellido: \n");
							gets(lastName);
							validacion= ValidacionDeCaracteres(lastName);
							Mayuscula(lastName);
						}
						strcpy(aux.lastName,lastName);
						printf("%s",lastName);
					break;

					case 3:

						price=PedirFloat("Ingrese el precio.","Error ingrese un n�mero entre el 1000 y 999999",1000,999999);
						aux.price=price;
					break;

					case 4:
						typePassenger=PedirEntero("Ingrese el tipo de vuelo\n 1-Turista\n 2-Primera Clase\n 3-Economico\n","Error, ingrese un n�mero entre el 1 y el 3",1,3);
						aux.typePassenger=typePassenger;
					break;

					case 5:
						printf("Ingrese el codigo de vuelo:\n ");
						fflush(stdin);
						scanf("%s", flycode);
						strcpy(aux.flycode,flycode);
					break;

					case 6:
						printf("Saliendo...\n");
					break;

					}
				if(retorno == 0)
				{
				listaPassengers[index] = aux;
				}
				else
				{
					retorno = -1;
				}
		}
		else
		{
			printf("No se ha encontrado el id\n");
			retorno = -1;
		}


		return retorno;
}

int RemovePassenger(Passenger listaPassengers[], int sizePassengers) //FUNCI�N OBLIGATORIA
{
	int index;
	int id;
	int retornoEstado=-1;
	printf("Ingresar el ID que busca:\n");
	scanf("%d",&id);
	index=FindPassengerById(listaPassengers,sizePassengers,id);
	if (index != -1)
	{
		printf("El usuario %s %s ha sido eliminado.\n",listaPassengers[index].name,listaPassengers[index].lastName);
		listaPassengers[index].isEmpty = VACIO;
	}
	else
	{
		printf("Pasajero no encontrado \n");
		retornoEstado = 0;
	}

	return retornoEstado;
}

int sortPassengers(Passenger passengerList[], int size, int order)
{
    int retorno = -1;

    Passenger auxiliar;
    for(int i=0; i<size-1; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(strcmp(passengerList[i].lastName, passengerList[j].lastName) == order)
            {
                auxiliar = passengerList[i];
                passengerList[i] = passengerList[j];
                passengerList[j] = auxiliar;
                retorno = 0;
            }
            else
            {
                if(strcmp(passengerList[i].lastName, passengerList[j].lastName) == 0)
                {
                    if(order<0)
                    {
                        if(passengerList[i].typePassenger < passengerList[j].typePassenger)
                        {
                            auxiliar=passengerList[i];
                            passengerList[i]=passengerList[j];
                            passengerList[j]=auxiliar;
                        }
                    }
                    else
                    {
                        if(passengerList[i].typePassenger > passengerList[j].typePassenger)
                        {
                            auxiliar=passengerList[i];
                            passengerList[i]=passengerList[j];
                            passengerList[j]=auxiliar;
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

float CalcularTotal(Passenger listaPassengers[], int sizePassengers)
{
	float suma = 0;

	for(int i=0;i<sizePassengers;i++)
	{
		if(listaPassengers[i].isEmpty == OCUPADO)
		{
			suma = suma+listaPassengers[i].price;
		}
	}

	return suma;
}

float CalcularPromedio(Passenger listaPassengers[], int sizePassengers)
{
	int cantidad = 0;
	int suma = 0;
	int promedio;

	for(int i=0;i<sizePassengers;i++)
		{
			if(listaPassengers[i].isEmpty == OCUPADO)
			{
				suma = suma+listaPassengers[i].price;
				cantidad++;
			}
		}
	promedio = suma/cantidad;

	return promedio;
}

void MostrarPromedio(int total, float promedio,Passenger listaPassengers[], int sizePassengers)
{
	int cantidad = 0;

	printf("\nEl total de todos los pasajeros es %d\n",total);
	printf("El promedio total de los precios es %.2f\n",promedio);

	for(int i=0;i<sizePassengers;i++)
	{
		if(listaPassengers[i].isEmpty == OCUPADO && listaPassengers[i].price > promedio)
		{
			cantidad++;
		}
	}
	printf("El total de pasajeros que superan el promedio es %d\n\n",cantidad);
}

void CargaForzada(Passenger listaPassengers[], int sizePassengers)
{
	int id[] = {3001, 3002, 3003, 3004, 3005};
	char name[][51] = {"Tomas","Lucas","Julian","Alejandro","Victoria"};
	char lastName[][51] = {"Hernandez","Righi","Alvarez","Gutierrez","Hernandez"};
	float price[]={150000,23000,43000,21000,5000};
	char flycode[][10]={"35F","12A","3F","435J","40Z"};
	int typePassenger[]={2,2,1,1,3};
	int statusFlight[]={1,2,3,1,1};

	for(int i=0;i<sizePassengers;i++)
	{
		listaPassengers[i].id=id[i];
		strcpy(listaPassengers[i].name,name[i]);
		strcpy(listaPassengers[i].lastName,lastName[i]);
		listaPassengers[i].price=price[i];
		strcpy(listaPassengers[i].flycode,flycode[i]);
		listaPassengers[i].typePassenger=typePassenger[i];
		listaPassengers[i].statusFlight=statusFlight[i];
		listaPassengers[i].isEmpty=OCUPADO;
	}

	printf("\nCarga forzada realizada con �xito.\n");
}

int sortPassengersbyFlyCode(Passenger passengerList[], int size, int order)
{
    int retorno = -1;

    Passenger auxiliar;
    for(int i=0; i<size-1; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(strcmp(passengerList[i].flycode, passengerList[j].flycode) == order)
            {
                auxiliar = passengerList[i];
                passengerList[i] = passengerList[j];
                passengerList[j] = auxiliar;
                retorno = 0;
            }
            else
            {
                if(strcmp(passengerList[i].flycode, passengerList[j].flycode) == 0)
                {
                    if(order<0)
                    {
                        if(passengerList[i].statusFlight < passengerList[j].statusFlight)
                        {
                            auxiliar=passengerList[i];
                            passengerList[i]=passengerList[j];
                            passengerList[j]=auxiliar;
                        }
                    }
                    else
                    {
                        if(passengerList[i].statusFlight > passengerList[j].statusFlight)
                        {
                            auxiliar=passengerList[i];
                            passengerList[i]=passengerList[j];
                            passengerList[j]=auxiliar;
                        }
                    }
                }
            }
        }
    }

    return retorno;
}
