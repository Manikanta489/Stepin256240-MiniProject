#include "header.h"
#include<math.h>
#include<stddef.h>
error_t parameters(system_parameters* EVFCS)
{
    if (EVFCS==NULL)
    return MEMORY_ALLOCATION_ERROR;
    else if(((EVFCS->average_arrival_rate)<=0.0)||((EVFCS->average_service_rate)<=0.0)||((EVFCS->maximum_charging_piles)<=0))
    return DATA_ERROR;
    else
    {
    EVFCS->server_utilization=EVFCS->average_arrival_rate/EVFCS->average_service_rate;
    EVFCS->server_utilization_conversion=floor(EVFCS->server_utilization);
    EVFCS->total_possible_charging_piles=(EVFCS->maximum_charging_piles)-(EVFCS->server_utilization_conversion);
    return SUCESS;
    }
}