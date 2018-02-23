#include <iostream>
#include "Map.h"

using namespace std;

int main(){
	Map map;
	int size;
	string file;
	map.initMap("map.txt", size, map);

	return 0;
}