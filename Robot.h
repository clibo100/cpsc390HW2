#include <string>
#include<list>

using namespace std;

class Robot
{
	private:
		int rowPosition, columnPosition;
		int nodeCount, dimensions;
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

		Node** getFinalMap();
};