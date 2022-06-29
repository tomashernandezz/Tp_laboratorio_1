#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassengers.h"
#include "input.h"
#include "StatusFlight.h"
#include "TypePassenger.h"
#include "nexo.h"

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
