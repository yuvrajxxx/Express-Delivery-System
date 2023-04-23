# Express-Delivery-System
Finding the shortest path from various nodes for the delivery pf items using Dijkstra's algorithm

Delivery Optimization using Dijkstra Algorithm

This project is a delivery optimization system that calculates the shortest path to deliver an item from the nearest warehouse. The Dijkstra algorithm is used to calculate the shortest path between nodes.

Requirements
GCC
SDL2 (for GUI)
Usage
Clone the repository to your local machine
Compile the project using make command
Run the program using ./delivery_optimization
Enter the necessary details such as the number of nodes, edges, source node, destination node, and edge details.
The program will output the shortest distance and the path between the source and destination nodes.
To use the GUI, run the program using ./delivery_optimization gui command.
Files
main.c - main program file that takes input from the user and performs the shortest path calculation using the Dijkstra algorithm.
dijkstra.h - header file containing function declarations for the Dijkstra algorithm implementation.
dijkstra.c - implementation of the Dijkstra algorithm.
gui.c - implementation of the graphical user interface using SDL2 library.
gui.h - header file containing function declarations for the graphical user interface implementation.
graph.h - header file containing the Graph data structure and function declarations to create a graph and add edges to it.
graph.c - implementation of the Graph data structure and functions to create a graph and add edges to it.
Makefile - contains commands for compiling the project.
Acknowledgments
This project was inspired by the Dijkstra algorithm implementation in "Data Structures and Algorithms in C" by Michael T. Goodrich, Roberto Tamassia, and David M. Mount.
