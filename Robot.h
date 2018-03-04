#include <string>
#include<list>

using namespace std;

class Robot
{
	private:
		int rowPosition, columnPosition;
		int nodeCount;
		list<Node*> myFringe;
	public:
		Robot();
		~Robot();

		void setLocation(int row, int column);
		void initRobot(Node**& map, int& dimensions);
		bool traverseMap(Node**& map, int& dimensions);

		void printFringe();
		void addToFringe(Node*& node, list<Node*>& fringe);
};