# Simulating a shipping company

A shipping company is hired by multiple sources in order to ship some cargos. The shipping depends on some criteria that is affected by some factors. A simulation respects those criteria and expresses real time procedures in form of **Console ouput** and **Output .txt file**
through 3 main modes.

## Simulation modes

### Interactive mode

This mode requires the user to press the "Enter" key in order to proceed in simulation and advance to next hour

### Step-by-step mode

This mode automatically advances an hour in the simulation every second in real life

### Silent mode

This mode doesn't show simulation steps, just overwrites **Output** file

## Simulation running depends mainly on 5 classes

Cargo class - 
Truck class - 
Company class - 
Events class - 
UI class

### Cargo and Truck classes

contains members that are related to each class, e.g: **Truck speed** for trucks and **Cargo capacity** for cargos

### Company class

A class that connects everything together
Responsible for choosing the appropriate **DATA STRUCTURES** for each list in simulation

### Events class

Base class for 3 deived class .. **Ready event**, **Cancel event** and **Promote event**

**Ready events** bring in new cargos to be loaded

**Cancel events** cancel normal cargos before being loaded

**Promote events** promotes normal cargos to VIP cargos

## Output file

After running simulation a file is created that holds some statisitics for the shipment simulation ran, e.g: **Total number of delivered cargos** , **Arrival times of cargos** and etc

Sample output and input files at the end of README.md


## Factors affecting shipping conditions

### Cargos come in 3 types (priorities)

Normal cargos - Special cargos - VIP cargos

### Depending on the cargo type the cargo is loaded to the suitable truck 

Normal trucks - Special trucks - VIP trucks

### The time of arrival of cargo

Cargos are handled in **First come first served** manner

**Exceptions can be made according to cargos with higher priorities**

### Availabilty of trucks in company 

Avaialbilty of trucks of certain types may affect the decision taken on what cargo type to be loaded

### Waiting times

How much time has each cargo waited to be loaded ?

### And other factors are also to be taken into consideration

## Input file

The input is taken in a specific format in order to be correctly understood

Sample of input and output file at end of README.md

## Cargo assignmenet criteria

### Normal cargos

Assigned to **Normal** trucks .. If no normal trucks available then assign to **VIP** trucks

### Special cargos

Assigned to **Special** trucks only

### VIP cargos

Assigned to **VIP** trucks .. If no VIP trucks available then assign to **Normal** trucks .. If no normal trucks then assign to **Special** trucks

# Data structures

The simulation is done by the interactions that take place between a number of lists

Each list is chosen in a certain data structure in order to maximize efficeincy and runtime

Data strcutures used are **Priority Queues** - **Queues** - **Linked Lists**

Data structures explicitly implemented, No STLs included

# Take a deeper dive !

In order to fully experience simulation, test it out with your desired input file !

There are alot of **details** .. e.g :

**Truck maintenance**

**Maximum waiting times**

**Auto-Promotions**

**Average wait times**

**etc**

# Sample input file


![Screenshot (117)](https://user-images.githubusercontent.com/98777495/174675129-eb2734e2-30d1-43dd-8878-ad7230966347.png)

# Sample output file for the shown input

![Screenshot (118)](https://user-images.githubusercontent.com/98777495/174675655-206d43ff-d036-4db9-b65b-91ff23f30c6d.png)

