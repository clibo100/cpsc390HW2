/*===============================================
Miguel Gotao & Sierra Clibourne
2264941 - gotao100@mail.chapman.edu
2263981 - clibo100@mail.chapman.edu

Header file of Map class.
===============================================*/

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