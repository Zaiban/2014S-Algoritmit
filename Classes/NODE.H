#pragma once

typedef char Node_entry;

struct Node {
//  data members
   Node_entry entry;
   Node *next;

//  constructors
   Node(){ next = nullptr; };
   Node(Node_entry item, Node *link = nullptr){ entry = item; next = link; };
};

