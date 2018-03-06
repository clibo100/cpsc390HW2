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
	Node** theMap = map.initMap("map.txt", size, map);

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
	return 0;
}