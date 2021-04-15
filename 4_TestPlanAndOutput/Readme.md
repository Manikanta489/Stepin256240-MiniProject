# TEST PLAN:

## Table no 1.: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01   |Check for the the data entered|(1). Arrival rate (2). Service Rate (3). Maximum number of charging piles (4). Waiting time threshold (5). Percenatge idlness threshold| Error Code  |PASS|Requirement based |



## Table no: Low level test plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |H_01|Evaluate the system parameters |Inputs desribed in H_01| Error Code and update the system_parameters structure from the calculated parameters| SUCCESS |Requirement based |
|  L_02    |H_01|Evaluate the possible charging piles for the FCS|Input stated in H_01,system_parameters, queuing_system structures |Error Code and update the system_parameters, queuing_system structures from the calculated parameters|SUCCESS|Requirement based|
|  L_03       |H_01|Evaluate the queue parameters  | Input stated in H_01,system_parameters, queuing_system structures|Error Code and update the system_parameters, queuing_system structures from the calculated parameters|SUCCESS|Requirement based|
|  L_04       |H_01|Factorial Function|Inputs from L_03|Factorial of input|SUCCESS |Requirement based|
|  L_05       |H_01|To find the optimal charging piles for the FCS|system_parameters, queuing_system structures|Optimal charging piles|SUCCESS |Requirement based|

