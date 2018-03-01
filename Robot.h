#include <string>
#include<list>

using namespace std;

class Robot
{
	private:
		int rowPosition, columnPosition;
		list<Node*> myFringe;
	public:
		Robot();
		~Robot();

		void setLocation(int row, int column);
		void initRobot(Node**& map, int& dimensions);
		bool traverseMap(Node**& map, int& dimensions);
		void addToFringe(Node*& node, list<Node*>& fringe);
};