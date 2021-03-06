/*===============================================
Miguel Gotao & Sierra Clibourne
2264941 - gotao100@mail.chapman.edu
2263981 - clibo100@mail.chapman.edu

Node class that populates the map. Mostly getters
and setters that are manipulated by the map and
robot.
===============================================*/

#include "Node.h"
#include <cstddef>
#include <iostream>

using namespace std;

//int distance;
//int rowPosition, columnPosition;
//Node* previousNode;
//bool visited;

Node::Node()
{
	this->rowPosition = 0;
	this->columnPosition = 0;
	this->distanceMod = 0;

	this->previousNode = NULL;

	this->visited = false;
	this->initial = false;
	this->goal = false;
	this->obstacle = false;
}

Node::~Node()
{

}

void Node::printLocation()
{
	cout << '(' << rowPosition << ',' << columnPosition << ')' << '\n';
}

void Node::setDistance(double distance)
{
	this->distance = distance;
}

void Node::setDistanceMod(int distanceMod)
{
	this->distanceMod = distanceMod;
}

void Node::setRow(int row)
{
	this->rowPosition = row;
}

void Node::setColumn(int column)
{
	this->columnPosition = column;
}

void Node::setVisit(bool visit)
{
	this->visited = visit;
}

void Node::setPrevious(Node* previous)
{
	this->previousNode = previous;
}

void Node::setInitial(bool initial)
{
	this->initial = initial;
}

void Node::setGoal(bool goal)
{
	this->goal = goal;
}

void Node::setObstacle(bool obstacle)
{
	this->obstacle = obstacle;
}

double Node::getDistance()
{
	return this->distance + this->distanceMod;
}

int Node::getDistanceMod()
{
	return this->distanceMod;
}

double Node::getActualDistance()
{
	return this->distance;
}

int Node::getRow()
{
	return this->rowPosition;
}

int Node::getColumn()
{
	return this->columnPosition;
}

bool Node::isVisited()
{
	return this->visited;
}

bool Node::isInitial()
{
	return this->initial;
}

bool Node::isObstacle()
{
	return this->obstacle;
}

bool Node::isGoal()
{
	return this->goal;
}

Node* Node::getPrevious()
{
	return this->previousNode;
}