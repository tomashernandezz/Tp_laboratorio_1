#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

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


int ObtenerID()
{
    static int idIncremental = 1;
    return idIncremental++;
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
