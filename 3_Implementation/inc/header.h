/**
 * @file header.h
 * @author Manikanta Suri (manikantaram215@gmail.com)
 * @brief Header file to find Optimal charging piles for Fast Charging Station
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __HEADER_H__
#define __HEADER_H__
/**
 * Enum which contains error codes
 * DATA_ERROR(0) indicates there is error in data entry
 * MEMORY_ALLOCATION_ERROR(1) indicates insufficient memory
 * SUCESS(2) indicates no error
 * 
 */
typedef enum
{
    DATA_ERROR,
    MEMORY_ALLOCATION_ERROR,
    SUCESS,

}error_t;
/**
 * Structure which contains the FCS parameters: Average arrival rate (number of EVs/h), Average Service rate (number of EVs/h), maximum_charging_piles (entered by user), average_waiting_time_in_FCS_threshold (in minutes, entered by user) percentage_idleness_threshold(entered by user),
 */
typedef struct
{
  float average_arrival_rate;
  float average_service_rate;
  int maximum_charging_piles;
  int average_waiting_time_in_FCS_threshold;
  int percentage_idleness_threshold;
  float server_utilization;
  int server_utilization_conversion;
  int total_possible_charging_piles;
  int minimum_optimum_charging_piles;
  int maximum_optimum_charging_piles;  
}system_parameters;
/**
 * Structure which contains the queuing model parameters
 */
typedef struct
{
    int number_of_charging_piles;
    float zero_customers_probability;
    float average_no_of_EVs_in_queue;
    int average_time_spent_by_EV_in_FCS;
    int percentage_idleness;
    int optimal;
}queuing_system;
/**
 * @brief Function to find Factorial of a number
 * 
 * @param number 
 * @return long long int 
 */
long long int factorial(int number);
/**
 * @brief Function to find the FCS parameters
 * 
 * @param EVFCS 
 * @return error_t 
 */
error_t parameters(system_parameters* EVFCS);
/**
 * @brief Function to find the possible number of charging piles for FCS
 * 
 * @param EVFCS 
 * @param FCS 
 * @return error_t 
 */
error_t possible_number_of_charging_piles(system_parameters* EVFCS,queuing_system* FCS);
/**
 * @brief Function to find the queue parameters of FCS
 * 
 * @param EVFCS 
 * @param FCS 
 * @return error_t 
 */
error_t queue_parameters(system_parameters* EVFCS,queuing_system* FCS);
/**
 * @brief Function which decides the optimal charging piles
 * 
 * @param EVFCS 
 * @param FCS 
 * @return error_t 
 */
error_t decision_making(system_parameters* EVFCS,queuing_system* FCS);
/**
 * @brief Array of function pointers which points to possible_number_of_charging_piles, queue_parameters, decision_making functions
 * 
 */
error_t (*queuing_ptr[3])(system_parameters* EVFCS, queuing_system* FCS);
#endif