# Requirements
## Introduction
The rise in population across the globe has created a lot of opportunities in the transportation sector. Electric Vehicle (EV) is the sustainable solution to mitigate the emission of green house gases from the internal combustion engine vehicles. Thus, Fast Charging Stations (FCS) are gaining a lot of importance from the EV sector. The battery inside the EV gets refulled at the FCS in a quicker pace. However, the EV has to wait in queue before getting into the service as the charging time of the battery is not in fraction of seconds. Thus, the FCS has to plan its service so as to minimize the waiting time of the EV user in the station. This guarantees the quality of service to the EV users. The number of charging piles determines the level of service for a FCS. Any service station can be represented using a queuing model. Queuing theory is the branch of the Operations Research which formulates various queuing models. Queuing models arise from two independent models: (1) Pure birth model , (2) Pure deadth model. In pure birth model, only arrivals can occur whereas, in pure deadth model only the departures can take place. The combination of these two models can accurately represent any service station, where both arrivals and departures occur. 

In general, a queuing model is represented as:

                                                              (A/B/C) :( D/E/F)
                                                              
Where,

A- Distribution of number of arrivals per unit time

B- Service time distribution

C- Number of parallel servers

D- Queue discipline

E- Capacity of the system (Finite/Infinite)

F- Size of calling population (Finite/Infinite)


In queuing theory, arrivals are distributed using Poission probability function. Thus, it is worth to follow exponential probability distibution function for service time.The queuing models for a Fast Charging Station evaluates various queue measures such as Average number of EVs in the queue, Average number of EVs in the FCS, Average time spent by EV in the queue, Average time spent by EV in the FCS and probability of finding EVs in the FCS. However, the average arrival rate at FCS and average service time in FCS should be known to formulate the queue measures as arrivals and service time follows Poisson and exponential service distribution respectively. The number of parallel servers determines the service level in the FCS. Generally, First In First Out queue discipline is followed across all queuing models to show faith on the first customer. The capacity of the system is the area of the service station. The size of calling population determines which type of customers can arrive to the service station. 

The optimum level of service guarantees good quality of service and it can be evaluated using two models : (1) Cost Model and (2) Aspiration level model. Both model proves taht a higher service level reduces the waiting time of customers in a service station, but higher service level increases the costs of the station. Thus the goal is to strike the balance between the service level and the waiting time of customers in the system. The main aim of the cost model is to minimize the sum of facility costs and waiting time costs. Generally these parameters are difficult to estimate. Thus, there is a necessity to evaluate the optimum service level for a service station which does not require any estimation of parameters.Aspiration level model is an another decision making model which allievates this problem by limiting the time spent by EV in FCS and percentage idleness of charging piles in FCS. Minimizing the time spent by EV in FCS maximizes the customer's satisfaction and minimizing the percenatge idlness of charging piles shows faith in money utilized in purchasing the charging piles. Aspiration level model is used in preplan the Fast Charging Stations in EV developing countries like India, as it has less dependency on the data.
# Research
## Costs and Features
## Defining the system
Fast Charging Station in Beijing is considered for the case stduy. The following table lists out the parameters for the FCS.
|Parameter|Value|Parameter|Value|
|----------|---------|-----------|----------|
|Average Arrival Rate |6.9 EVs/h| Electricity Consumed|0.2 kWh/km|
|Average Service rate|2 EVs/h|Capcity of the battery|30 kWh|
|Radius of FCS|1.24 km|Electricity charging speed|40kW|
|Density of EV's| 150EV/km2| Total operatinh hours of FCS| 16h|
|Distance travelled by EV before recharging|50 km| Incoming SOC of EV|0.3|

The parameters of the aspiration level model depends upon the average arrival rate of EVs at the FCS, average charging rate and the system capacity of the FCS. The system capacity of the FCS can be either finite or infinite. According to the system data given, the average time spent by the EV in FCS and percentage idlness of the charging piles are calculated and based on the thresholds for the same given, the aspiration level model gives out the optimal number of charging piles for the FCS which helps in providing good quality of service to the EV users.
## SWOT ANALYSIS
![swot analysis](https://user-images.githubusercontent.com/61261829/114737418-9fe7ef80-9d64-11eb-8c99-46665f1886e1.png)

# 4W's and 1'H
## Who:
The solution of the aspiration level model helps the FCS in providing quality of service to the EV users.
## What:
The aspiration level model is one of the decision making model which is used to find the suitable service level for the Fast Charging Stations.
## When:
The aspiration level model is used during the pre-planning of the Fast Charging Stations.
## Where:
The aspiration level model is used in many service centers such as Fast Charging Stations.
## How:
The aspiration level model determines the optimal number of charging piles for a FCS so that it can give the best serice to the EV users.
# Detail Requirements
## High Level Requirements
| ID | Description|Category|Status| 
| ------ | ------ |------|--------|
HR01|To provide quality of service to the EV users|Technical|Not Implemented
## Low Level Requirements
| ID | Description|HLR ID|Status| 
| ------ | ------ |------|-----|
LR01|To solve the aspiration level model for the given system parameters|HR01|Not Implemented
