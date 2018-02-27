#include <string>
class Node;

using namespace std;

class Map
{
	private:

	public:
		Map();
		~Map();

		void calcManhattan(Node**& map, int& dimensions);
		Node** initMap(string file, int& dimensions, Map& map);
};