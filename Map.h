#include <string>
class Node;

using namespace std;

class Map
{
	private:

	public:
		Map();
		~Map();

		Node** initMap(string file, int& dimensions, Map& map);
		void calcManhattan(Node**& map, int& dimensions);
		void calcEuclidean(Node**& map, int& dimensions);

};