# TEST PLAN:

## Table no 1.: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01   |Check for the the data entered|(1). Arrival rate (2). Service Rate (3). Maximum number of charging piles (4). Waiting time threshold (5). Percenatge idlness threshold| Error Code  |PASS|Requirement based |



## Table no: Low level test plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |H_01|Evaluate the system parameters |Inputs desribed in H_01| Error Code and update the system_parameters structure from the calculated parameters| SUCCESS |Requirement based |
|  L_02    |H_01|Evaluate the possible charging piles for the FCS|Input stated in H_01, Ou|Error Code and update the system_parameters, queuing_system structures from the calculated parameters|SUCCESS|Requirement based|
|  L_03       |H_01|Evaluate the queue parameters  | Input stated in H_04|Return Pointer contains the parameters(1). Sending voltage in complex form (2). Sending end current in complex form (3). Efficeincy (4). Voltage Regulation | SUCCESS |Requirement based|
|  L_04       |H_05|Computing Long line,call all complex arthematic operations functions.|      Input stated in H_05|Return Pointer contains the parameters (1). Sending voltage in complex form (2). Sending end current in complex form (3). Efficeincy (4). Voltage Regulation (5). ABCD Parameters| SUCCESS |Requirement basedl|
