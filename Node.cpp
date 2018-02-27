#include "Node.h"

using namespace std;

//int distance;
//int rowPosition, columnPosition;
//Node* previousNode;
//bool visited;

Node::Node()
{

}

Node::Node(int row, int column)
{
	this->rowPosition = row;
	this->columnPosition = column;
}

Node::~Node()
{

}

void Node::setDistance(int distance)
{
	this->distance = distance;
}

void Node::setVisit(bool visit)
{
	this->visited = visit;
}

void Node::setPrevious(Node* previous)
{
	this->previousNode = previous;
}

void Node::setGoal(bool goal)
{
	this->goal = goal;
}

int Node::getDistance()
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

bool Node::isGoal()
{
	return this->goal;
}

Node* Node::getPrevious()
{
	return this->previousNode;
}