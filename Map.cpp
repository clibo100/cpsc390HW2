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
	//read file and get dimension of map
	char text;
	ifstream fileIn;
	fileIn.open(file.c_str());
	fileIn >> dimensions;

	//initialize 2D array to simulate map
	char** m_Map = new char*[dimensions];
	for(int i = 0; i < dimensions; ++i)
	{
		m_Map[i] = new char[dimensions];
	}

	//read map from file and assign to 2D array
	for(int row = 0; row < dimensions; ++row)
	{
		for(int column = 0; column < dimensions; ++column)
		{
			fileIn >> text;
			m_Map[row][column] = text;
			cout << m_Map[row][column];
		}
		cout << '\n';
	}

	fileIn.close();
}