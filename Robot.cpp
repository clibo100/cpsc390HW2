#include <string>
#include <list>
#include <fstream>
#include <cmath>
#include <cstddef>
#include <iostream>
class Node;
#include "Robot.h"
#include "Node.h"

using namespace std;

//int rowPosition, columnPosition;

Robot::Robot()
{
	list<Node*> myFringe;
	rowPosition = 0;
	columnPosition = 0;
}

Robot::~Robot()
{

}

void Robot::initRobot(Node**& map, int& dimensions)
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

void Robot::setLocation(int row, int column)
{
	this->rowPosition = row;
	this->columnPosition = column;
}

bool Robot::traverseMap(Node**& map, int& dimensions)
{
	//get surrounding nodes
	Node* upNode;
	Node* downNode;
	Node* leftNode;
	Node* rightNode;

	if (rowPosition != 0 && !map[rowPosition-1][columnPosition].isObstacle())
	{
		upNode = &(map[rowPosition-1][columnPosition]);
		if(!upNode->isVisited())
		{
			addToFringe(upNode, myFringe);	
		}
	}
	else
	{
		upNode = NULL;
	}
	if (rowPosition < dimensions-1 && !map[rowPosition+1][columnPosition].isObstacle())
	{
		downNode = &(map[rowPosition+1][columnPosition]);
		if(!downNode->isVisited())
		{
			addToFringe(downNode, myFringe);
		}
	}
	else
	{
		downNode = NULL;
	}
	if (columnPosition != 0 && !map[rowPosition][columnPosition-1].isObstacle())
	{
		leftNode = &(map[rowPosition][columnPosition-1]);
		if(!leftNode->isVisited()) 
		{
			addToFringe(leftNode, myFringe);
		}
	}
	else
	{
		leftNode = NULL;
	}
	if (columnPosition <dimensions-1 && !map[rowPosition][columnPosition+1].isObstacle())
	{
		rightNode = &(map[rowPosition][columnPosition+1]);
		if(!rightNode->isVisited()) 
		{
			addToFringe(rightNode, myFringe);
		}
	}
	else
	{
		rightNode = NULL;
	}

	Node* nextNode = NULL;
	list<Node*>::iterator i;
	for(i = myFringe.begin(); i != myFringe.end(); ++i)
	{
		Node* curr = *i;
		if(curr->isGoal())
		{
			nextNode = curr;
			break;
		}
		else if(nextNode == NULL || nextNode->getDistance() > curr->getDistance()) 
		{
			nextNode = curr;
		}
	}
	nextNode->setPrevious(&(map[rowPosition][columnPosition]));
	setLocation(nextNode->getRow(), nextNode->getColumn());

	cout << "Old Location: " << '\n'
	<< "Row: " << nextNode->getPrevious()->getRow() << '\n'
	<< "Column: " << nextNode->getPrevious()->getColumn() << '\n';

	cout << "New location: " << '\n'
	<< "Row: " << rowPosition << '\n'
	<< "Column: " << columnPosition << '\n';

	if(nextNode->isGoal()) return 1;
	else return 0;
}

void Robot::addToFringe(Node*& node, list<Node*>& fringe)
{
	node->setVisit(true);
	fringe.push_front(node);
}