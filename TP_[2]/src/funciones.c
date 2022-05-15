#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassengers.h"

int ObtenerID()
{
    static int idIncremental = 1000;
    return idIncremental++;
}

int ValidacionDeCaracteres (char cadena[])
{
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++)
	{
		if (isdigit(cadena[i]) || isalpha(cadena[i]) == 0)
		{
			validacion=0;
		}
	}
	return validacion;
}

void PedirDatos(Passenger listaPassengers[], int tam)
{
	int estado;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;

	id=ObtenerID();

	PedirCadena(name,"Ingrese su nombre.\n","Error, ingrese su nombre.\n",1);
	Mayuscula(name);

	PedirCadena(lastName,"Ingrese su apellido.\n","Error, ingrese su apellido.\n",1);
	Mayuscula(lastName);

	price=PedirFloat("Ingrese el precio del vuelo","Error, ingrese un número entre el 1000 y 999.999\n",1000,999999);

	printf("Ingrese el código del vuelo\n");
	fflush(stdin);
	gets(flycode);

	typePassenger=PedirEntero("Ingrese el tipo de vuelo\n 1-Turista\n 2-Primera Clase\n 3-Economico\n","Error, ingrese un número entre el 1 y el 3\n",1,3);

	statusFlight=PedirEntero("Ingrese el tipo de vuelo\n 1-Activo \n 2-Demorado\n 3-Estima\n","Error, ingrese un número entre el 1 y el 3\n",1,3);

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

int FindPassengerById(Passenger listaPassengers[], int sizePassengers,int id) //FUNCIÓN OBLIGATORIA
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

			printf("Ingrese la opción que desea modificar:\n"
					"1- Nombre.\n"
					"2- Apellido. \n"
					"3- Precio \n"
					"4- Tipo de vuelo \n"
					"5- Código de vuelo\n"
					"6- Si no desea modificar nada.\n"
					"Opcion: ");

				scanf("%d", &opcion);
				while(opcion < 1 || opcion > 7)
					{
						printf("Error, vuelva a ingresar una opción. \n");
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
						printf("Se cambió correctamente el nombre\n");
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

						price=PedirFloat("Ingrese el precio.","Error ingrese un número entre el 1000 y 999999",1000,999999);
						aux.price=price;
					break;

					case 4:
						typePassenger=PedirEntero("Ingrese el tipo de vuelo\n 1-Turista\n 2-Primera Clase\n 3-Economico\n","Error, ingrese un número entre el 1 y el 3",1,3);
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

int RemovePassenger(Passenger listaPassengers[], int sizePassengers, int id) //FUNCIÓN OBLIGATORIA
{
	int index;
	int retornoEstado=-1;
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

void MostrarUnPasajero(Passenger UnPasajero, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize)
{
	int typeNombre;
	int statusNombre;

	typeNombre = DescripcionType(UnPasajero, typePassenger, typeSize);
	statusNombre = DescripcionStatus(UnPasajero, statusFlight, statusSize);

	printf("%-6d|%-10s|%-13s|%-9.1f|%-16s|%-16s|%s\n",UnPasajero.id,UnPasajero.name,UnPasajero.lastName,UnPasajero.price,UnPasajero.flycode,typePassenger[typeNombre].nombreType,statusFlight[statusNombre].nombreStatus);
}

void PrintPassenger(Passenger listaPassengers[], int sizePassengers, statusFlight statusFlight[], int statusSize, typePassenger typePassenger[], int typeSize)
{
	for(int i=0; i<sizePassengers; i++)
	{
		if(listaPassengers[i].isEmpty == OCUPADO)
		{
			MostrarUnPasajero(listaPassengers[i], statusFlight,statusSize, typePassenger, typeSize);
		}
	}
}

int PedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar)
{
    int retorno = -1;
    char buffer[256];
    int validacion;

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        if(validar==1)
        {
		  validacion=ValidacionDeCaracteres (buffer);
		  while(validacion==0)
			{
				printf("%s", mensajeError);
				scanf("%s", buffer);
				validacion=ValidacionDeCaracteres (buffer);
			}
        }



        strcpy(cadena, buffer);
        retorno = 0;
    }

    return retorno;
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

int DescripcionStatus(Passenger passenger, statusFlight statusFlight[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(passenger.statusFlight==statusFlight[i].idStatus)
        {
            index=i;
            break;
        }
    }
    return index;
}

int DescripcionType(Passenger passenger, typePassenger typePassenger[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(passenger.typePassenger==typePassenger[i].idType)
        {
            index=i;
            break;
        }
    }
    return index;
}

float PedirFloat(char mensaje[],char error[],int minimo,int maximo)
{
	float numero;
	char numeroIngresado[50];
	int validacion;

	printf("%s",mensaje);
	fflush(stdin);
	gets(numeroIngresado);
	validacion=ValidarNumero(numeroIngresado);
	while(validacion==0)
	{
		printf("%s",error);
		fflush(stdin);
		gets(numeroIngresado);
		validacion=ValidarNumero(numeroIngresado);
	}

	numero = atof(numeroIngresado);

	while(numero < minimo || numero > maximo)
	{
		printf("%s",error);
		fflush(stdin);
		gets(numeroIngresado);
		numero=atof(numeroIngresado);
	}
	return numero;
}

int PedirEntero(char mensaje[],char error[],int minimo,int maximo)
{
	int numero;
	char numeroIngresado[50];
	int validacion;

	printf("%s",mensaje);
	fflush(stdin);
	gets(numeroIngresado);
	validacion=ValidarNumero(numeroIngresado);
	while(validacion==0)
	{
		printf("%s",error);
		fflush(stdin);
		gets(numeroIngresado);
		validacion=ValidarNumero(numeroIngresado);
	}

	numero = atoi(numeroIngresado);

	while(numero < minimo || numero > maximo)
	{
		printf("%s",error);
		fflush(stdin);
		gets(numeroIngresado);
		numero=atoi(numeroIngresado);
	}
	return numero;
}

int ValidarNumero (char numeros[])
{
    int validacion=-1;
    for(int i=0;i<strlen(numeros);i++)
    {
        if(!(numeros[i] == 46 || (numeros[i]>=48 && numeros[i]<=57)))
        {
            validacion=0;
        }
    }
    return validacion;
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

	printf("\nCarga forzada realizada con éxito.\n");
}

void Mayuscula(char name [])
{
    int i;
    int size;

    size= strlen(name);
    strlwr(name);

    for(i= 0; i<size; i++)
    {
        if(name[i-1]==32 || i==0)
        {
            name[i] = toupper(name[i]);
        }
    }

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
