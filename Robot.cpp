#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
class Node;
#include "Robot.h"
#include "Node.h"

using namespace std;

int rowPosition, columnPosition;

Robot::Robot()
{
	
}

Robot::~Robot()
{

}

void Robot:: initRobot(Node**& map, int& dimensions)
{
	//find initial node and set robot location to it
	for (int row = 0; row<dimensions; ++row)
	{
		for (int column = 0; column<dimensions; ++column)
		{
			if (map[row][column].isInitial())
			{
				rowPosition = row;
				columnPosition = column;
			}
		}
	}
}

void Robot:: traverseMap(Node**& map, int& dimensions)
{
	//get distances of surrounding nodes
	int upDistance, downDistance, leftDistance, rightDistance;
	if (rowPosition != 0 && !map[rowPosition-1][columnPosition].isObstacle())
	{
		upDistance = map[rowPosition-1][columnPosition].getDistance();
	}
	else
	{
		upDistance = 1000;
	}
	if (rowPosition < dimensions-1 && !map[rowPosition+1][columnPosition].isObstacle())
	{
		downDistance = map[rowPosition+1][columnPosition].getDistance();
	}
	else
	{
		downDistance = 1000;
	}
	if (columnPosition != 0 && !map[rowPosition][columnPosition-1].isObstacle())
	{
		leftDistance = map[rowPosition][columnPosition-1].getDistance();
	}
	else
	{
		leftDistance = 1000;
	}
	if (columnPosition <dimensions-1 && !map[rowPosition][columnPosition+1].isObstacle())
	{
		rightDistance = map[rowPosition][columnPosition+1].getDistance();
	}
	else
	{
		rightDistance = 1000;
	}
}