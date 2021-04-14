#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include "unity.h"
#include "unity_internals.h"
#include<stddef.h>
void setUp(){}
void tearDown(){}
void test_factorial(void)
{
    TEST_ASSERT_EQUAL(1,factorial(0));
    TEST_ASSERT_EQUAL(720,factorial(6));
}
void test_parameters_data_error(void)
{
    system_parameters EVFCS={6.9,-2,-5,45,50};
    TEST_ASSERT_EQUAL(0,parameters(&EVFCS));
    EVFCS.average_arrival_rate=-7;
    TEST_ASSERT_EQUAL(0,parameters(&EVFCS));
}
void test_parameters_null(void)
{
    TEST_ASSERT_EQUAL(1,parameters(NULL));
}
void test_parameters(void)
{
     system_parameters EVFCS={6.9,2.0,5,45,50};
     TEST_ASSERT_EQUAL(2,parameters(&EVFCS));
     TEST_ASSERT_EQUAL_FLOAT(3.45,EVFCS.server_utilization);
     
}
void test_possible_number_of_charging_piles_null(void)
{
    system_parameters EVFCS;
    queuing_system FCS[2];
    TEST_ASSERT_EQUAL(1,possible_number_of_charging_piles(&EVFCS,NULL));
    TEST_ASSERT_EQUAL(1,possible_number_of_charging_piles(NULL,NULL));
    TEST_ASSERT_EQUAL(1,possible_number_of_charging_piles(NULL,FCS));
}
void test_possible_number_of_charging_piles(void)
{
   system_parameters EVFCS={6.9,2.0,5,45,50,3.45,3};
    queuing_system FCS[2];  
    TEST_ASSERT_EQUAL(2,possible_number_of_charging_piles(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(4,FCS[0].number_of_charging_piles);
    TEST_ASSERT_EQUAL(5,FCS[1].number_of_charging_piles);
}
void queue_parameters_null(void)
{
    system_parameters EVFCS;
    queuing_system FCS[2];
    TEST_ASSERT_EQUAL(1,queue_parameters(&EVFCS,NULL));
    TEST_ASSERT_EQUAL(1,queue_parameters(NULL,NULL));
    TEST_ASSERT_EQUAL(1,queue_parameters(NULL,FCS));
}
void queue_parameters_test(void)
{
    system_parameters EVFCS={6.9,2,5,45,50,3.45,3,2};
    queuing_system FCS[2];
    FCS[0].number_of_charging_piles=4;
    FCS[1].number_of_charging_piles=5;
    TEST_ASSERT_EQUAL(2,queue_parameters(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(73,FCS[0].average_time_spent_by_EV_in_FCS);
    TEST_ASSERT_EQUAL(13,FCS[0].percentage_idleness);
    TEST_ASSERT_EQUAL(38,FCS[1].average_time_spent_by_EV_in_FCS);
    TEST_ASSERT_EQUAL(31,FCS[1].percentage_idleness);
}
void decision_making_null(void)
{
    system_parameters EVFCS;
    queuing_system FCS[2];
    TEST_ASSERT_EQUAL(1,decision_making(&EVFCS,NULL));
    TEST_ASSERT_EQUAL(1,decision_making(NULL,NULL));
    TEST_ASSERT_EQUAL(1,decision_making(NULL,FCS));
}
void decision_making_data_error(void)
{
    system_parameters EVFCS;
    queuing_system FCS[2];
    EVFCS.average_waiting_time_in_FCS_threshold=-10;
    EVFCS.percentage_idleness_threshold=30;
    TEST_ASSERT_EQUAL(0,decision_making(&EVFCS,FCS));
    EVFCS.percentage_idleness_threshold=-20;
    TEST_ASSERT_EQUAL(0,decision_making(&EVFCS,FCS));
}
void decision_making_test(void)
{
    system_parameters EVFCS;
    queuing_system FCS[2];
    EVFCS.average_waiting_time_in_FCS_threshold=75;
    EVFCS.percentage_idleness_threshold=50;
    EVFCS.total_possible_charging_piles=2;
    FCS[0].average_time_spent_by_EV_in_FCS=73;
    FCS[0].percentage_idleness=13;
    FCS[1].average_time_spent_by_EV_in_FCS=38;
    FCS[1].percentage_idleness=31;
    FCS[0].number_of_charging_piles=4;
    FCS[1].number_of_charging_piles=5;
    TEST_ASSERT_EQUAL(2,decision_making(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(4,EVFCS.minimum_optimum_charging_piles);
    TEST_ASSERT_EQUAL(5,EVFCS.maximum_optimum_charging_piles);
    EVFCS.average_waiting_time_in_FCS_threshold=40;
    EVFCS.percentage_idleness_threshold=50;
    TEST_ASSERT_EQUAL(2,decision_making(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(5,EVFCS.minimum_optimum_charging_piles);
    TEST_ASSERT_EQUAL(5,EVFCS.maximum_optimum_charging_piles);
    EVFCS.average_waiting_time_in_FCS_threshold=80;
    EVFCS.percentage_idleness_threshold=20;
    TEST_ASSERT_EQUAL(2,decision_making(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(4,EVFCS.minimum_optimum_charging_piles);
    TEST_ASSERT_EQUAL(4,EVFCS.maximum_optimum_charging_piles);
    EVFCS.average_waiting_time_in_FCS_threshold=45;
    EVFCS.percentage_idleness_threshold=25;
    TEST_ASSERT_EQUAL(2,decision_making(&EVFCS,FCS));
    TEST_ASSERT_EQUAL(-1,EVFCS.minimum_optimum_charging_piles);
    TEST_ASSERT_EQUAL(-1,EVFCS.maximum_optimum_charging_piles);
}
int main()
{
///Initiate the Unity Test Framework
UNITY_BEGIN();
RUN_TEST(test_factorial);
RUN_TEST(test_parameters_data_error);
RUN_TEST(test_parameters_null);
RUN_TEST(test_parameters);
RUN_TEST(test_possible_number_of_charging_piles_null);
RUN_TEST(test_possible_number_of_charging_piles);
RUN_TEST(queue_parameters_null);
RUN_TEST(queue_parameters_test);
RUN_TEST(decision_making_null);
RUN_TEST(decision_making_data_error);
RUN_TEST(decision_making_test);
/// Close the Unity Test Framework
UNITY_END();
return 0;
}
