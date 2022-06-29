#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassengers.h"
#include "input.h"
#include "StatusFlight.h"
#include "TypePassenger.h"
#include "nexo.h"



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
