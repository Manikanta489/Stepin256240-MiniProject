#include"header.h"
#include<stddef.h>
#include<stdio.h>
error_t possible_number_of_charging_piles(system_parameters* EVFCS,queuing_system* FCS)
{
    int c,i;
    if(EVFCS==NULL||FCS==NULL)
    return MEMORY_ALLOCATION_ERROR;
    else
    {
    if(EVFCS->system_capacity==0)
    {
    for(c=((EVFCS->server_utilization_conversion)+1),i=0;c<=(EVFCS->maximum_charging_piles);c++,i++)
    ((FCS+i)->number_of_charging_piles)=c;
    }
    else
    {
    for(i=0;i<(EVFCS->maximum_charging_piles);i++)
    ((FCS+i)->number_of_charging_piles)=i+1;
    }
    return SUCESS;
    }
}