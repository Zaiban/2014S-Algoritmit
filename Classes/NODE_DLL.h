template <class Node_entry>
struct Node {
	//  data members
	Node_entry entry;
	Node<Node_entry> *next;
	Node<Node_entry> *back;
	//  constructors
	Node(){ next = nullptr; };
	Node(Node_entry item, Node<Node_entry> *link_back = nullptr, Node<Node_entry> *link_next = nullptr)
	{ entry = item; back = link_back; next = link_next; };
};