# Metro-Journey-Scheduling-Using-LinkedLists

Problem statement: 
#To get the path between two stations and the train changes required (if any).
#To get the hypothetical fare assuming the fare between any two stations to be rupees 5.

Function Descriptions: 

Input () : to scan the present location and destination location of the passenger. Includes certain display statements as well.

create() : to create empty double linked list nodes for stations.

red_line() : to create nodes for stations on the red line and initialise the station names.

blue_line() : to create nodes for stations on the blue line and initialise the station names.

search(): to search for  the locations of present and destination stations -- with respect to each other when they are on the same line and with respect to Ameerpet station (common station for the two lines) on the respective line when the present and destination stations lie on the different lines.

forward traversal(): used to traverse between two nodes(stations) and print the station names in the forward direction.

reverse_traversal(): used to traverse between two nodes (stations) and print the station names in the reverse direction.

Path_dis(): this function is used to create the path required  to reach the destination. It is used to traverse from present station to the destination station and print the stations and train changes (if any) on the way.


