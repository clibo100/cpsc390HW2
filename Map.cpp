#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()
{
	
}

Map::~Map()
{
	
}

//reads in file and initializes array from it
char** Map::initMap(string file, int& dimensions, Map& map)
{
	//read file and get dimension of map
	char text;
	ifstream fileIn;
	fileIn.open(file.c_str());
	fileIn >> dimensions;

	//initialize 2D array to simulate map
	char** m_Map = new char*[dimensions];
	for(int i = 0; i < dimensions; ++i)
	{
		m_Map[i] = new char[dimensions];
	}

	//read map from file and assign to 2D array
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			fileIn >> text;
			m_Map[row][column] = text;
		}
	}

	fileIn.close();

	return m_Map;
}

//calculates distance from every non-obstacle node to goal node and makes it a new 2D array
//THIS IS FOR THE MANHATTAN DISTANCE FORMULA
int** Map::calculateDistances(char**& map, int& dimensions)
{
	//make new 2D array a copy of old one
	int** distMap = new int*[dimensions];
	for(int i = 0; i < dimensions; ++i)
	{
		distMap[i] = new int[dimensions];
	}

	int goalx, goaly;
	//find goal node
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			if (map[row][column] == 'g')
			{
				goalx = row;
				goaly = column;
			}
		}
	}

	//calculates distances from each non obstacle node to goal node using manhattan distance formula and assigns to new array
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			if (map[row][column] != 'x' && map[row][column] != 'g' && map[row][column] != 'i')
			{
				distMap[row][column] = abs(goalx-row)+abs(goaly-column); 
			}
			else
			{
				distMap[row][column] = 0;
			}
		}
	}

	return distMap;
}