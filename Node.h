using namespace std;

class Node
{
	private:
		int distance;
		int rowPosition, columnPosition;
		Node* previousNode;
		bool visited, goal;

	public:
		Node();
		Node(int row, int column);
		~Node();

		void setDistance(int distance);
		void setVisit(bool visit);
		void setPrevious(Node* previous);
		void setGoal(bool goal);

		int getDistance();
		int getRow();
		int getColumn();
		bool isVisited();
		bool isGoal();
		Node* getPrevious();
};