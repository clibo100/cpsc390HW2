#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
	Map map;
	int size;
	string file;
	char** theMap = map.initMap("map.txt", size, map);
	int** distMap = map.calculateDistances(theMap, size);

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			cout << theMap[row][column];
		}
		cout << '\n';
	}

	cout << '\n';

	for(int row = 0; row < size; ++row)
	{
		for(int column = 0; column < size; ++column)
		{
			cout << distMap[row][column];
		}
		cout << '\n';
	}

	return 0;
}