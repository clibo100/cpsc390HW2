#include <string>

using namespace std;

class Robot
{
	private:
		int rowPosition, columnPosition;
	public:
		Robot();
		~Robot();

		void initRobot(Node**& map, int& dimensions);
		void traverseMap(Node**& map, int& dimensions);
};