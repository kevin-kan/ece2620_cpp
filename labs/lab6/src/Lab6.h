//Kevin Kan
//ECE 2620-001
//Lab 6: DLL, Queues, and Stacks
//Header File for classes declarations and libraries

#ifndef _LAB6_H_
#define _LAB6_H_

#include <iostream>
#include <stdexcept>

class IntDLLNode{		//Doubly Linked List Node
	friend class IntDLList;
	public:
		IntDLLNode(){
			next = NULL;
			prev = NULL;
		};
		IntDLLNode(const int el, IntDLLNode *n = NULL, IntDLLNode *p = NULL){
			info = el;
			next = n;
			prev = p;
		};
	protected:
		int info;
		IntDLLNode *next, *prev;
};

class IntDLList{		//Doubly Linked List
	public:
		IntDLList(){
			head = NULL;
			tail = NULL;
		};
		bool isEmpty();
		void addToHead(int &el);
		void addToTail(int &el);
		int deleteFromHead();   
		int deleteFromTail();
		void remove(int el);
		void printList();
		void addSorted(int el);
		
	private:
		IntDLLNode *head, *tail;
};

#endif // _LAB6_H_

