#include <string>

using namespace std;

class Map
{
	private:

	public:
		Map();
		~Map();

		void initMap(string file, int& dimensions, Map& map);
};