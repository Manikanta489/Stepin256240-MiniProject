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
if(EVFCS->system_capacity==0)
{
 for(i=0;i<(EVFCS->total_possible_charging_piles);i++)
        {
            c=(FCS+i)->number_of_charging_piles;
            j=0;
            for(n=0;n<=c-1;n++)
            j+=pow((EVFCS->server_utilization),n)/factorial(n);
            j+=(pow((EVFCS->server_utilization),c)/factorial(c))*(1/(1-((EVFCS->server_utilization)/c)));
            (FCS+i)->zero_customers_probability=1/j;
            (FCS+i)->average_no_of_EVs_in_queue=((pow((EVFCS->server_utilization),c+1))/((factorial(c-1))*pow(c-(EVFCS->server_utilization),2)))*(FCS+i)->zero_customers_probability;
            (FCS+i)->average_time_spent_by_EV_in_FCS=(int)(((FCS+i)->average_no_of_EVs_in_queue+(EVFCS->server_utilization))/((EVFCS->average_arrival_rate))*60);
            (FCS+i)->percentage_idleness=(int)((1-((EVFCS->server_utilization)/c))*100);
        }
}
else
{
    double a,b,d;
for(i=0;i<(EVFCS->total_possible_charging_piles);i++)
{
    c=(FCS+i)->number_of_charging_piles;
    j=0;
    for(n=0;n<=c-1;n++)
    j+=pow((EVFCS->server_utilization),n)/factorial(n);
    if(EVFCS->server_utilization/c!=1.0)
    j+=(pow((EVFCS->server_utilization),c)/factorial(c))*(1/(1-((EVFCS->server_utilization)/c)))*(1-(pow((EVFCS->server_utilization/c),((EVFCS->maximum_charging_piles)-c+1))));
    else
    j+=(pow((EVFCS->server_utilization),c)/factorial(c))*(EVFCS->maximum_charging_piles-c+1);
    (FCS+i)->zero_customers_probability=1/j;
    (FCS+i)->N_customers_probability=(FCS+i)->zero_customers_probability*(pow((EVFCS->server_utilization),EVFCS->maximum_charging_piles))*(1/(factorial(c)*(pow(c,(EVFCS->maximum_charging_piles-c)))));
    (FCS+i)->effective_arrival_rate=(1-((FCS+i)->N_customers_probability))*(EVFCS->average_arrival_rate);
    a=pow(EVFCS->server_utilization,c+1)/((factorial(c-1))*(pow(c-(EVFCS->server_utilization),2)));
    b=(1-(pow(((EVFCS->server_utilization)/c),((EVFCS->maximum_charging_piles)-c+1))));
    d=((EVFCS->maximum_charging_piles)-c+1)*(1-(EVFCS->server_utilization/c))*(pow((EVFCS->server_utilization)/c,(EVFCS->maximum_charging_piles)-c));
    if(EVFCS->server_utilization/c!=1.0)
    (FCS+i)->average_no_of_EVs_in_queue=a*(b-d)*(FCS+i)->zero_customers_probability;
    else
    (FCS+i)->average_no_of_EVs_in_queue=(pow(EVFCS->server_utilization,c))*(EVFCS->maximum_charging_piles-c)*(EVFCS->maximum_charging_piles-c+1)*(1/(2*factorial(c)))*(FCS+i)->zero_customers_probability;
    (FCS+i)->average_time_spent_by_EV_in_FCS=(int)(((((FCS+i)->average_no_of_EVs_in_queue)+(((FCS+i)->effective_arrival_rate)/(EVFCS->average_service_rate)))/((FCS+i)->effective_arrival_rate))*60);
    (FCS+i)->percentage_idleness=(int)((1-(((FCS+i)->effective_arrival_rate)/(c*(EVFCS->average_service_rate))))*100);
     }
}
    return SUCESS;
     }
}