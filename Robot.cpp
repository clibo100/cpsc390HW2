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

Robot::Robot()
{
	list<Node*> myFringe;
	rowPosition = 0;
	columnPosition = 0;
	nodeCount = 0;
	dimensions = 0;
	choice = 'a';
}

Robot::~Robot()
{

}

void Robot::initRobot(Node**& map, int& dimensions, char choice)
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

	cout << "\nRobot starting at (" << rowPosition << ',' << columnPosition << ')' << '\n';
	this->dimensions = dimensions;
	this->choice = choice;
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
			if (choice == 'c' || choice == 'd')
			{
				if (map[rowPosition][columnPosition].getDistanceMod() == 0)
				{
					upNode->setDistanceMod(1);
				}
				else
				{
					upNode->setDistanceMod(map[rowPosition][columnPosition].getDistanceMod()+1);
				}
			}
			addToFringe(map, upNode, myFringe);
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
			if (choice == 'c' || choice == 'd')
			{
				if (map[rowPosition][columnPosition].getDistanceMod() == 0)
				{
					downNode->setDistanceMod(1);
				}
				else
				{
					downNode->setDistanceMod(map[rowPosition][columnPosition].getDistanceMod()+1);
				}
			}
			addToFringe(map, downNode, myFringe);
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
			if (choice == 'c' || choice == 'd')
			{
				if (map[rowPosition][columnPosition].getDistanceMod() == 0)
				{
					leftNode->setDistanceMod(1);
				}
				else
				{
					leftNode->setDistanceMod(map[rowPosition][columnPosition].getDistanceMod()+1);
				}
			}
			addToFringe(map, leftNode, myFringe);
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
			if (choice == 'c' || choice == 'd')
			{
				if (map[rowPosition][columnPosition].getDistanceMod() == 0)
				{
					rightNode->setDistanceMod(1);
				}
				else
				{
					rightNode->setDistanceMod((map[rowPosition][columnPosition].getDistanceMod())+1);
				}
			}
			addToFringe(map, rightNode, myFringe);
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
	//printFringe();

	setLocation(nextNode->getRow(), nextNode->getColumn());
	myFringe.remove(nextNode);
	nodeCount--;
	// cout << "Old Location: " << '\n'
	// << "Row: " << nextNode->getPrevious()->getRow() << '\n'
	// << "Column: " << nextNode->getPrevious()->getColumn() << '\n';

	// cout << "New location: " << '\n'
	// << "Row: " << rowPosition << '\n'
	// << "Column: " << columnPosition << '\n';

	cout<<"\nCurrent working map: "<<endl;
	for (int i = 0; i < dimensions; ++i)
	{
		for (int j = 0; j < dimensions; ++j)
		{
			if (map[i][j].isInitial())
			{
				cout<<'i';
			}
			else if (map[i][j].isObstacle())
			{
				cout<<'x';
			}
			else if(map[i][j].isGoal())
			{
				cout<<'g';
			}
			else if(map[i][j].isVisited())
			{
				cout<<'o';
			}
			else
			{
				cout<<'-';
			}
		}
		cout<<"\n";
	}

	if(nextNode->isGoal())
	{
		cout << "Goal found at ";
		nextNode->printLocation();
		showPath(nextNode, map);
		return 1;
	}
	else
	{
		cout << "Moving towards ";
		nextNode->printLocation();

		/*cout<<"actual distance = "<<nextNode->getActualDistance()<<endl;
		cout<<"distance mod = "<<nextNode->getDistanceMod()<<endl;
		cout<<"distance plus mod = "<<nextNode->getDistance()<<endl;*/

		return 0;
	}
}

void Robot::showPath(Node*& goal, Node**& map)
{
	Node* myNode = goal;
	cout << "Following path found: " << '\n' << "GOAL" << '\n';

	Node** finalMap = map;

	for (int i = 0; i < this->dimensions; ++i)
	{
		for (int j = 0; j < this->dimensions; ++j)
		{
			finalMap[i][j].setVisit(false);
		}
	}

	myNode->printLocation();

	finalMap[myNode->getRow()][myNode->getColumn()].setVisit(true);
	
	while(!myNode->isInitial())
	{
		myNode = myNode->getPrevious();
		//myNode->printLocation();
		cout <<'('<<myNode->getRow() << ',' << myNode->getColumn()<< ')' << '\n';
		finalMap[myNode->getRow()][myNode->getColumn()].setVisit(true);
	}
	
	cout << "START" << '\n'<<endl;

	for (int i = 0; i < this->dimensions; ++i)
	{
		for (int j = 0; j < this->dimensions; ++j)
		{
			if (finalMap[i][j].isInitial())
			{
				cout<<'i';
			}
			else if (finalMap[i][j].isObstacle())
			{
				cout<<'x';
			}
			else if(finalMap[i][j].isGoal())
			{
				cout<<'g';
			}
			else if(finalMap[i][j].isVisited())
			{
				cout<<'o';
			}
			else
			{
				cout<<'-';
			}
		}
		cout<<'\n';
	}
}

void Robot::printFringe()
{
	if(nodeCount == 0) return;
	else
	{
		cout << "Nodes in fringe: " << nodeCount << '\n';
		Node* myNode = NULL;
		list<Node*>::iterator i;
		for(i = myFringe.begin(); i != myFringe.end(); ++i)
		{
			myNode = *i;
			myNode->printLocation();
		}
	}
}

void Robot::addToFringe(Node**& map, Node*& node, list<Node*>& fringe)
{
	nodeCount++;
	node->setVisit(true);
	node->setPrevious(&(map[rowPosition][columnPosition]));
	fringe.push_front(node);
}
