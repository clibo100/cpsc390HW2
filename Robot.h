/*===============================================
Miguel Gotao & Sierra Clibourne
2264941 - gotao100@mail.chapman.edu
2263981 - clibo100@mail.chapman.edu

Header file of Robot class.
===============================================*/

#include <string>
#include<list>

using namespace std;

class Robot
{
	private:
		int rowPosition, columnPosition;
		int nodeCount, dimensions, finalNodeCount, finalCost;
		char choice;
		Node** finalMap;
		list<Node*> myFringe;
	public:
		Robot();
		~Robot();

		void setLocation(int row, int column);
		void initRobot(Node**& map, int& dimensions, char choice);
		bool traverseMap(Node**& map, int& dimensions);
		void showPath(Node*& goal, Node**& map);

		void printFringe();
		void addToFringe(Node**& map, Node*& node, list<Node*>& fringe);
		int getNodeCount();
		int getFinalNodeCount();
		int getFinalCost();

		Node** getFinalMap();
};