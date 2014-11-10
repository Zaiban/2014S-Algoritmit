#pragma once

template <class Node_entry>
struct Node {
	//  data members
	Node_entry entry;
	Node<Node_entry> *next;

	//  constructors
	Node();
	// Muista kysyä opettajalta: miksi sijoitus "*link = NULL" ?? 
	// Constructorin toiseen argumenttiin sijoitetaan NULL, jolloin se käytännössä menettää merkityksensä; miksi constructorilla ylipäätään on toinen argumentti?
	Node(Node_entry item, Node<Node_entry> *link = NULL){ entry = item; next = link; };
};
