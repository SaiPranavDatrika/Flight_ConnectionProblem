# Flight_ConnectionProblem
Problem Statement:
n number of cities (numbered from 1 to n) are connected by m number of 2-way flights.
Connectivity factor of a city is calculated as, the number of cities which are reachable from that city. 
Two cities i and j are reachable, if you can reach from city i to j via direct or sequence of any number of flights.
Overall connectivity factor is sum of connectivity factors of all cities.
After few years, due to some financial crisis, 2 flights needs to shut down. We need to shut down the flights such that overall connectivity factor is maximized.
Given the details of flights (without any shut down), you need to find and print the updated overall connectivity factor after 2 shut downs, which is maximum.
Note : All Pairs Of Cities Don't Have To Be Reachable After Shut Down Of Flights.

8 7
1 2
2 3
4 6
5 7
3 7
6 8
1 3

IDEA:
Using Graph Algorithm you can crack this problem.It's DFS Based solution.
The idea of this problem is to detect a cycle in undirected graph and shut down those routes to make maximum overall connectivity.
If their is no cycle present in the graph, try to search for the node where the connectivity is minimum and shut down those routes.
The time complexity of this problem is:
O(n+m) where n is number of cities and m is the number of two way flights.
