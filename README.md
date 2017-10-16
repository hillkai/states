# states
This program reads information (using file i/o) about states and their counties, sorts through the information and either prints it to the 
screen or writes it to a file. The program finds the state with the largest population, the county with the largest population, the 
counties with an income above a specific amount (decided by the user), the average household cost for all counties in each state, the 
states in sorted order by name, the counties within states sorted by population, and the counties withing states sorted by name.

To run program you must make an executable by running the makefile. The program also requires command line arguments. Put a -s followed by 
how many states you want to use (the file I provided has 10 states) then a -f followed by the name of the file you want to read from. Ex: 
state_facts -s 3 -f states.txt
