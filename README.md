# Artificial Intelligence HW#01 - Best-First Robot Navigation

Miguel Gotao & Sierra Clibourne

2264941 - gotao100@mail.chapman.edu

2263981 - clibo100@mail.chapman.edu

---

###Program Details

This program simulates multiple search methods of an AI on a square, node-based grid, including calculations for Euclidean distance, Manhattan distance, and Best-First search based on the two former.

This program is written in C++ and must be run from the commandline. The executable for this project is named 'a.exe'
Once run, the program will ask for the name of the map file, which in this project is named "map.txt". Other map files may
be used so long as they follow the same formatting, with the first line containing the dimensions of the grid, followed by the map proper. 

Map entities are as follows:

--*i - initial state where the robot will begin

--*g - goal state that the robot will traverse towards

--*+ - obstacle on the map that the robot will need to maneuver around

--*. - empty space on the map, the robot may move to this space

---

###Files included

+main.cpp
+Map.cpp
+Map.h
+Node.cpp
+Node.h
+Robot.cpp
+Robot.h
+map.txt
+output.txt
+makefile
