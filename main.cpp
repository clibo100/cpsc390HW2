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
	char** theMap = map.initMap("map.txt", size, map);
	int** distMap = map.calculateDistances(theMap, size);

	//print maps to cmd line
	cout<< "initial map: " << '\n';

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			cout << theMap[row][column];
		}
		cout << '\n';
	}

	cout << '\n' << "Manhattan distances array:" << '\n';

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			if (distMap[row][column] == 1000)
			{
				cout<< theMap[row][column];
			} 
			else
			{
				cout << distMap[row][column];
			}
		}
		cout << '\n';
	}

	//initialize robot
	Robot robot;

	//Testing nodes and getting pointers
	Node foo = Node(1, 1);
	Node bar = Node(2, 2);
	foo.setDistance(5);
	bar.setPrevious(&foo);
	cout << bar.getPrevious() -> getDistance();


	//robot.traverseMap(theMap, distMap, size);
	//do this when this function actually does something 

	//TODO: the rest of the program lolol

	return 0;
}