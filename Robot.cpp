/*===============================================
Miguel Gotao & Sierra Clibourne
2264941 - gotao100@mail.chapman.edu
2263981 - clibo100@mail.chapman.edu

Robot class in charge of traversing the map. 
===============================================*/

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
	Node** finalMap;
	rowPosition = 0;
	columnPosition = 0;
	nodeCount = 0, finalNodeCount = 0, finalCost = 0;
	dimensions = 0;
	choice = 'a';
}

Robot::~Robot()
{

}

//Find the robot's location on the map
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

	//reset variables
	cout << "\nRobot starting at (" << rowPosition << ',' << columnPosition << ')' << '\n';
	this->dimensions = dimensions;
	this->choice = choice;
	myFringe.clear();
	finalNodeCount = 0;
	nodeCount = 0;
	finalCost = 0;

}

//Set new location on map
void Robot::setLocation(int row, int column)
{
	this->rowPosition = row;
	this->columnPosition = column;
}

//Main function in charge of map traversal
bool Robot::traverseMap(Node**& map, int& dimensions)
{
	//get surrounding nodes
	Node* upNode;
	Node* downNode;
	Node* leftNode;
	Node* rightNode;

	//if the four surrounding nodes are traversable, add them to the fringe, and set the prev and the distance mod if applicable
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

	//find next node with least distance
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
	//Move the robot to the next node, remove node from fringe.
	setLocation(nextNode->getRow(), nextNode->getColumn());
	myFringe.remove(nextNode);
	// cout << "Old Location: " << '\n'
	// << "Row: " << nextNode->getPrevious()->getRow() << '\n'
	// << "Column: " << nextNode->getPrevious()->getColumn() << '\n';

	// cout << "New location: " << '\n'
	// << "Row: " << rowPosition << '\n'
	// << "Column: " << columnPosition << '\n';

	/*cout<<"\nCurrent working map: "<<endl;
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
				cout<<'+';
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
				cout<<'.';
			}
		}
		cout<<"\n";
	}*/

	//check if goal
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

//Show final path from goal node to initial position.
void Robot::showPath(Node*& goal, Node**& map)
{
	//find final path and final map and print them 
	Node* myNode = goal;
	finalNodeCount = 1;
	finalCost += myNode->getDistance();
	cout << "Following path found: " << '\n' << "GOAL" << '\n';

	finalMap = map;

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
		finalNodeCount++;
		finalCost += myNode->getDistance();
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
				cout<<'+';
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
				cout<<'.';
			}
		}
		cout<<'\n';
	}
}

//Print out all nodes currently in the fringe.
void Robot::printFringe()
{
	//prints fringe
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

//Add a node to the fringe when the robot is adjacent to it AND hasn't been visited
void Robot::addToFringe(Node**& map, Node*& node, list<Node*>& fringe)
{
	//adds node to fringe
	nodeCount++;
	node->setVisit(true);
	node->setPrevious(&(map[rowPosition][columnPosition]));
	fringe.push_front(node);
}

Node** Robot::getFinalMap()
{
	return finalMap;
}

int Robot::getNodeCount()
{
	return nodeCount;
}

int Robot::getFinalNodeCount()
{
	return finalNodeCount;
}

int Robot::getFinalCost()
{
	return finalCost;
}