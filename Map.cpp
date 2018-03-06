#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
class Node;
#include "Map.h"
#include "Node.h"

using namespace std;

Map::Map()
{
	
}

Map::~Map()
{
	
}

Node** Map::initMap(string file, int& dimensions, Map& map)
{
	//read file and get dimension of map
	char text;
	ifstream fileIn;

	fileIn.open(file.c_str());
	fileIn >> dimensions;

	//initialize 2D array to simulate map
	Node** m_Map = new Node*[dimensions];
	for(int i = 0; i < dimensions; ++i)
	{
		m_Map[i] = new Node[dimensions];
	}

	//read map from file and assign to 2D array
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			fileIn >> text;
			m_Map[row][column].setRow(row);
			m_Map[row][column].setColumn(column);
			if (text == 'g')
			{
				m_Map[row][column].setGoal(true);
			}
			if (text == 'i')
			{
				m_Map[row][column].setInitial(true);
			}
			if (text == '+')
			{
				m_Map[row][column].setObstacle(true);
			}
		}
	}

	fileIn.close();

	return m_Map;
}

//calculates distance from every non-obstacle node to goal node and makes it a new 2D array
//THIS IS FOR THE MANHATTAN DISTANCE FORMULA
void Map::calcManhattan(Node**& map, int& dimensions)
{
	int goalx, goaly;
	//find goal node
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			if (map[row][column].isGoal())
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
			if (!map[row][column].isObstacle() && !map[row][column].isGoal() && !map[row][column].isInitial())
			{
				map[row][column].setDistance(abs(goalx-row)+abs(goaly-column)); 
			}
			else
			{
				map[row][column].setDistance(1000);
			}
		}
	}
}

//the same thing as the manhattan one but for euclidean
void Map::calcEuclidean(Node**& map, int& dimensions)
{
	int goalx, goaly;
	
	//find goal node
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			if (map[row][column].isGoal())
			{
				goalx = row;
				goaly = column;
			}
		}
	}

	//calculates distances from each non obstacle node to goal node using Euclidean distance formula and assigns to new array
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			if (!map[row][column].isObstacle() && !map[row][column].isGoal() && !map[row][column].isInitial())
			{
				map[row][column].setDistance(sqrt(pow((goalx-row),2)+pow((goaly-column),2))); 
			}
			else
			{
				map[row][column].setDistance(1000);
			}
		}
	}
}