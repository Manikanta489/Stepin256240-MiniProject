#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int main()
{
    int ptr_count;
    error_t error_code;
    system_parameters* EVFCS=(system_parameters*)(malloc(sizeof(system_parameters)));
    printf("Enter the average arrival rate and average service rate of FCS respectively(seperated by unit space):\n");
    scanf("%f %f",&(EVFCS->average_arrival_rate),&(EVFCS->average_service_rate));
    printf("Enter the maximum charging piles:\n");
    scanf("%d",&(EVFCS->maximum_charging_piles));
    printf("Enter the threshold of Average waiting time of EV in FCS(in minutes) and Percentage idleness of charging piles respectively(seperated by unit space):\n");
    scanf("%d %d",&(EVFCS->average_waiting_time_in_FCS_threshold),&(EVFCS->percentage_idleness_threshold));
    printf("Enter the capacity of the system (0: infinite), (1:finite)\n");
    scanf("%d",&(EVFCS->system_capacity));
    error_code=parameters(EVFCS);
    if(error_code==0)
    {
        printf("DataError: The entered data should be positive");
        exit(0);
    }
    if(error_code==1)
    {
        printf("Memory_Allocation_Error:Unable_to_allocate_memory");
        exit(0);
    }
    printf("%d\n",EVFCS->total_possible_charging_piles);
    queuing_system *FCS=(queuing_system*)(malloc((EVFCS->total_possible_charging_piles)*sizeof(queuing_system)));
    queuing_ptr[0]=possible_number_of_charging_piles;
    queuing_ptr[1]=queue_parameters;
    queuing_ptr[2]=decision_making;
    for(ptr_count=0;ptr_count<3;ptr_count++)
    {
        error_code=(queuing_ptr[ptr_count])(EVFCS,FCS);
        if(error_code==0)
    {
        printf("DataError: The entered data should be positive");
        exit(0);
    }
    if(error_code==1)
    {
        printf("Memory_Allocation_Error: Unable_to_allocate_memory");
        exit(0);
    }
    }
    printf("The minimum and maximum optimal charging piles are:\n");
    printf("%d %d",EVFCS->minimum_optimum_charging_piles,EVFCS->maximum_optimum_charging_piles);
    free(EVFCS);
    free(FCS);
return 0;
}