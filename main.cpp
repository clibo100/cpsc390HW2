#include <iostream>
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
	map.calcManhattan(theMap, size);

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
				cout<<"x";
			}
			else
			{
				cout<<'-';
			}
		}
		cout << '\n';
	}

	cout << '\n' << "Manhattan distances array:" << '\n';

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			if (!theMap[row][column].isObstacle() && !theMap[row][column].isGoal() && !theMap[row][column].isInitial())
			{
				cout<<theMap[row][column].getDistance();
			}
			else if(theMap[row][column].isObstacle())
			{
				cout<<'x';
			}
			else if(theMap[row][column].isInitial())
			{
				cout<<'i';
			}
			else if(theMap[row][column].isGoal())
			{
				cout<<'g';
			}
		}
		cout << '\n';
	}

	//initialize robot
	Robot robot;
	robot.initRobot(theMap, size);
	bool goalReached = false;
	while(!goalReached)
	{
		goalReached = robot.traverseMap(theMap, size);
		cin.ignore();
	}
	//Testing nodes and getting pointers
	/*Node foo = Node();
	Node bar = Node();
	foo.setDistance(5);
	bar.setPrevious(&foo);
	cout << bar.getPrevious() -> getDistance();*/


	//robot.traverseMap(theMap, distMap, size);
	//do this when this function actually does something 

	//TODO: the rest of the program lolol

	return 0;
}