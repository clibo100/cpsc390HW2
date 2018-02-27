using namespace std;

class Node
{
	private:
		int rowPosition, columnPosition;
		Node* previousNode;
		bool visited;

	public:
		Node();
		Node(int row, int column);
		~Node();

		void setVisit(bool visit);
		void setPrevious(Node* previous);

		int getRow();
		int getColumn();
		bool isVisited();
		Node* getPrevious();
};