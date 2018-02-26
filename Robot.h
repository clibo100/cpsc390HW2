#include <string>

using namespace std;

class Robot
{
	private:

	public:
		Robot();
		~Robot();

		void initRobot(char**& map, int& dimensions);
		void traverseMap(char**& map, int**& distMap, int& dimensions);
};