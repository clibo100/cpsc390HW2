#include <string>

using namespace std;

class Map
{
	private:

	public:
		Map();
		~Map();

		char** initMap(string file, int& dimensions, Map& map);
		char** calculateDistances(char**& map, int& dimensions);
};