#include"header.h"
#include<stddef.h>
error_t possible_number_of_charging_piles(system_parameters* EVFCS,queuing_system* FCS)
{
    int c,i;
    if(EVFCS==NULL||FCS==NULL)
    return MEMORY_ALLOCATION_ERROR;
    else
    {
    for(c=((EVFCS->server_utilization_conversion)+1),i=0;c<=(EVFCS->maximum_charging_piles);c++,i++)
    ((FCS+i)->number_of_charging_piles)=c;
    return SUCESS;
    }
}