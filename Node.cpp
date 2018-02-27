#include "Node.h"

using namespace std;

int rowPosition, columnPosition;
Node* previousNode;
bool visited;

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

void Node::setVisit(bool visit)
{
	this->visited = visit;
}

void Node::setPrevious(Node* previous)
{
	this->previousNode = previous;
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

Node* Node::getPrevious()
{
	return this->previousNode;
}