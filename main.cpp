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

	char choice;
	bool correct;
	cout<<"\nWhich distance function would you like to use?\n a) Euclidean\n b) Manhattan\n c) Euclidean including distance from initial\n d) Manhattan including distance fromm initial\n";
	cin>>choice;

	while (!correct)
	{
		if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')
		{
			correct = true;
		}
		else
		{
			cout<<"\nThat is not a valid option. Please enter either a, b, c, or d\n";
			cin>>choice;
		}
	}

	//cout << '\n' << "Manhattan distances array:" << '\n';

	if (choice == 'b' || choice == 'd')
	{
		map.calcManhattan(theMap, size);
		cout<<"\nManhattan Distances Array\n";
	}
	else
	{
		map.calcEuclidean(theMap, size);
		cout<<"\nEuclidean Distances Array\n";
	}

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			if (!theMap[row][column].isObstacle() && !theMap[row][column].isGoal() && !theMap[row][column].isInitial())
			{
				cout<<theMap[row][column].getDistance()<<" ";
			}
			else if(theMap[row][column].isObstacle())
			{
				cout<<'x' << " " ;
			}
			else if(theMap[row][column].isInitial())
			{
				cout<<'i' << " " ;
			}
			else if(theMap[row][column].isGoal())
			{
				cout<<'g' << " " ;
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

	return 0;
}