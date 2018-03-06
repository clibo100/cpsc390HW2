/*===============================================
Miguel Gotao & Sierra Clibourne
2264941 - gotao100@mail.chapman.edu
2263981 - clibo100@mail.chapman.edu

Main file in charge of running the program. Takes in
map.txt and initializes the robot for traversal. The
robot will execute the four search strategies, which
the final found path will be printed to the output
file, along with the total distance of each path.
===============================================*/

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Robot.h"
#include "Node.h"

using namespace std;

int main()
{
	//read in map and calculate the distance map
	Map map;
	int size;
	string file;
	cout<<"enter file name: (ex. file.txt)"<<endl;
	cin>>file;
	Node** theMap = map.initMap(file, size, map);

	//print maps to cmd line
	cout<< "initial map: " << '\n';

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			if (theMap[row][column].isInitial())
			{
				cout<<'i';
			}
			else if (theMap[row][column].isGoal())
			{
				cout<<'g';
			}
			else if (theMap[row][column].isObstacle())
			{
				cout<<"+";
			}
			else
			{
				cout<<'.';
			}
		}
		cout << '\n';
	}

	map.calcManhattan(theMap, size);
	cout<<"\nManhattan: "<<endl;
	char choice = 'a';
	//initialize robot
	Robot robot;
	robot.initRobot(theMap, size, choice);
	bool goalReached = false;
	while(!goalReached)
	{
		goalReached = robot.traverseMap(theMap, size);
	}

	Node** finalMap = robot.getFinalMap();

	ofstream output;
	output.open ("output.txt");

	output<<"Manhattan: "<<endl;

	//output to file
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (finalMap[i][j].isInitial())
			{
				output<<'i';
			}
			else if (finalMap[i][j].isObstacle())
			{
				output<<'+';
			}
			else if(finalMap[i][j].isGoal())
			{
				output<<'g';
			}
			else if(finalMap[i][j].isVisited())
			{
				output<<'o';
			}
			else
			{
				output<<'.';
			}
		}
		output<<'\n';
	}

	output<<"Total Nodes Seen : "<<robot.getNodeCount()<<endl;
	output<<"Nodes in Final Path : "<<robot.getFinalNodeCount()<<endl<<endl;;

	cout<<"\nEuclidean: "<<endl;
	theMap = map.initMap(file, size, map);
	map.calcEuclidean(theMap, size);
	choice = 'b';
	robot.initRobot(theMap, size, choice);

	goalReached = false;
	while(!goalReached)
	{
		goalReached = robot.traverseMap(theMap, size);
	}

	finalMap = robot.getFinalMap();

	output<<"Euclidean: "<<endl;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (finalMap[i][j].isInitial())
			{
				output<<'i';
			}
			else if (finalMap[i][j].isObstacle())
			{
				output<<'+';
			}
			else if(finalMap[i][j].isGoal())
			{
				output<<'g';
			}
			else if(finalMap[i][j].isVisited())
			{
				output<<'o';
			}
			else
			{
				output<<'.';
			}
		}
		output<<'\n';
	}

	output<<"Total Nodes Seen : "<<robot.getNodeCount()<<endl;
	output<<"Nodes in Final Path : "<<robot.getFinalNodeCount()<<endl<<endl;;

	cout<<"\nManhattan with Distance from Initial: "<<endl;
	theMap = map.initMap(file, size, map);
	map.calcManhattan(theMap, size);
	choice = 'c';
	robot.initRobot(theMap, size, choice);

	goalReached = false;
	while(!goalReached)
	{
		goalReached = robot.traverseMap(theMap, size);
	}

	finalMap = robot.getFinalMap();

	output<<"Manhattan with Distance from Initial: "<<endl;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (finalMap[i][j].isInitial())
			{
				output<<'i';
			}
			else if (finalMap[i][j].isObstacle())
			{
				output<<'+';
			}
			else if(finalMap[i][j].isGoal())
			{
				output<<'g';
			}
			else if(finalMap[i][j].isVisited())
			{
				output<<'o';
			}
			else
			{
				output<<'.';
			}
		}
		output<<'\n';
	}

	output<<"Total Nodes Seen : "<<robot.getNodeCount()<<endl;
	output<<"Nodes in Final Path : "<<robot.getFinalNodeCount()<<endl<<endl;

	cout<<"\nEuclidean with Distance from Initial: "<<endl;
	theMap = map.initMap(file, size, map);
	map.calcEuclidean(theMap, size);
	choice = 'd';
	robot.initRobot(theMap, size, choice);

	goalReached = false;
	while(!goalReached)
	{
		goalReached = robot.traverseMap(theMap, size);
	}

	finalMap = robot.getFinalMap();

	output<<"Euclidean with Distance from Initial: "<<endl;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (finalMap[i][j].isInitial())
			{
				output<<'i';
			}
			else if (finalMap[i][j].isObstacle())
			{
				output<<'+';
			}
			else if(finalMap[i][j].isGoal())
			{
				output<<'g';
			}
			else if(finalMap[i][j].isVisited())
			{
				output<<'o';
			}
			else
			{
				output<<'.';
			}
		}
		output<<'\n';
	}

	output<<"Total Nodes Seen : "<<robot.getNodeCount()<<endl;
	output<<"Nodes in Final Path : "<<robot.getFinalNodeCount()<<endl<<endl;

	cout<<"\nResults in file output.txt"<<endl;

	return 0;
}