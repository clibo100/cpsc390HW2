using namespace std;

class Node
{
	private:
		double distance;
		int rowPosition, columnPosition, distanceMod;
		Node* previousNode;
		bool visited, initial, goal, obstacle;

	public:
		Node();
		~Node();

		void printLocation();

		void setDistance(double distance);
		void setDistanceMod(int distanceMod);
		void setRow(int row);
		void setColumn(int column);
		void setVisit(bool visit);
		void setPrevious(Node* previous);
		void setInitial(bool initial);
		void setGoal(bool goal);
		void setObstacle(bool obstacle);

		double getDistance();
		int getDistanceMod();
		double getActualDistance();
		int getRow();
		int getColumn();
		bool isVisited();
		bool isInitial();
		bool isGoal();
		bool isObstacle();
		Node* getPrevious();
};