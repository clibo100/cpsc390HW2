#include <string>
#include <fstream>
#include <iostream>
#include "Map.h"

using namespace std;

Map::Map(){
	
}

Map::~Map(){
	
}

void Map::initMap(string file, int& dimensions, Map& map){
	char text;
	ifstream fileIn;
	fileIn.open(file.c_str());
	fileIn >> dimensions;
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			fileIn >> text;
			cout << text;
			//map[row][column] = text;
		}
		cout << '\n';
	}

	fileIn.close();
}