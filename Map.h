#include <string>
class Node;

using namespace std;

class Map
{
	private:

	public:
		Map();
		~Map();

		char** initMap(string file, int& dimensions, Map& map);
		void calculateDistances(Node**& map, int& dimensions);
		Node** initMapNode(string file, int& dimensions, Map& map);
};