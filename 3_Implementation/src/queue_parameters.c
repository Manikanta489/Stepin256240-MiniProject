#include"header.h"
#include<math.h>
#include<stddef.h>
#include<stdio.h>
error_t queue_parameters(system_parameters* EVFCS,queuing_system* FCS)
 {
     int c,n,i;
     float j;
     if(EVFCS==NULL||FCS==NULL)
     return MEMORY_ALLOCATION_ERROR;
     else
     {
 for(i=0;i<(EVFCS->total_possible_charging_piles);c++,i++)
        {
            c=(FCS+i)->number_of_charging_piles;
            j=0;
            for(n=0;n<c-1;n++)
            j+=pow((EVFCS->server_utilization),n)/factorial(n);
            j+=(pow((EVFCS->server_utilization),c)/factorial(c))*(1/(1-((EVFCS->server_utilization)/c)));
            (FCS+i)->zero_customers_probability=1/j;
            (FCS+i)->average_no_of_EVs_in_queue=((pow((EVFCS->server_utilization),c+1))/((factorial(c-1))*pow(c-(EVFCS->server_utilization),2)))*(FCS+i)->zero_customers_probability;
            (FCS+i)->average_time_spent_by_EV_in_FCS=(int)(((FCS+i)->average_no_of_EVs_in_queue+(EVFCS->server_utilization))/((EVFCS->average_arrival_rate))*60);
            (FCS+i)->percentage_idleness=(int)((1-((EVFCS->server_utilization)/c))*100);
        }
        return SUCESS;
     }
 }