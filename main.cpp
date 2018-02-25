#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
	Map map;
	int size;
	string file;
	char** newMap = map.initMap("map.txt", size, map);

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			cout << newMap[row][column];
		}
		cout << '\n';
	}

	return 0;
}