#include"header.h"
#include<stddef.h>
#include<stdio.h>
error_t decision_making(system_parameters* EVFCS,queuing_system* FCS)
{
    int i;
    if(EVFCS==NULL||FCS==NULL)
    return MEMORY_ALLOCATION_ERROR;
    else if(EVFCS->average_waiting_time_in_FCS_threshold<=0||EVFCS->percentage_idleness_threshold<=0)
    return DATA_ERROR;
    else
    {
    for(i=0;i<(EVFCS->total_possible_charging_piles);i++)
    {
        if(((FCS+i)->average_time_spent_by_EV_in_FCS<=(EVFCS->average_waiting_time_in_FCS_threshold))&&((FCS+i)->percentage_idleness<=(EVFCS->percentage_idleness_threshold)))
        (FCS+i)->optimal=1;
        else
        (FCS+i)->optimal=0;
    }
    i=0;
    while((FCS+i)->optimal==0&&(i<(EVFCS->total_possible_charging_piles)))
    i++;
    if((FCS+i)->optimal==1)
    EVFCS->minimum_optimum_charging_piles=((FCS+i)->number_of_charging_piles);
    else
    EVFCS->minimum_optimum_charging_piles=-1;
    while((FCS+i)->optimal==1&&(i<(EVFCS->total_possible_charging_piles)))
    i++;
    if((FCS+i-1)->optimal==1)
    EVFCS->maximum_optimum_charging_piles=((FCS+i-1)->number_of_charging_piles);
    else
    EVFCS->maximum_optimum_charging_piles=-1;
    return SUCESS;
    }
}