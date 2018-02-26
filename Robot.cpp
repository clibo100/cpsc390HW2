#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include "Robot.h"

using namespace std;

int xposition, yposition;

Robot::Robot()
{
	
}

Robot::~Robot()
{

}

void Robot:: initRobot(char**& map, int& dimensions)
{
	//find initial node and set robot location to it
	for (int row = 0; row<dimensions; ++row)
	{
		for (int column = 0; column<dimensions; ++column)
		{
			if (map[row][column] == 'i')
			{
				xposition = row;
				yposition = column;
			}
		}
	}
}

void Robot:: traverseMap(char**& map, int**& distMap, int& dimensions)
{
	/*
	i hope this is where all the good shit happens. 
	like, what i'm thinking is that this will be the function that you call
	when you have the initial maps and you just straight up want the 
	final path. so like all of the calculation functions should also
	be in this class and implemented by this function if
	that makes sense?
	*/
}