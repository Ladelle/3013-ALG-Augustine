#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


struct Node
{

	string w; // word
	string d; // dictionary
	Node* Next;
/* Node()
{
	w ="hello";
    d = " A form of saying hi";

}
Node(string W, string D)
{  w = W;
   d = D;

}*/

};
class Dictionary
{
private:

	Node* head;   
	Node* tail;
	int length;
	string DisplayTen[10];
	int Found;
public:
	Dictionary()
	{
		head = NULL;
		tail = NULL;
		length = 0;

		for (int i = 0; i < 10; i++)
		{
			DisplayTen[i] = "NONE";
		}
		Found = 0;

	}
	/*     INSERT METHOD    */

	void Insert(string W, string D)
	{
        Node *temp = new Node;
	    temp->w = W;
		temp->d = D;
		temp->Next = NULL;

		// if list is empty hook in new Node
		if (head == NULL)  // insert in front
		{
			head = temp;
			length++;
		}
		else if (head->Next == NULL) // insert in middle
		{
			tail = temp;
			head->Next = tail;
			length++;
		}
		else  // insert at end
		{
			tail->Next = temp;
			tail = temp;
			length++;
		}

		temp = NULL;

	}

	void search(string x)
	{
		int r = 0;  // repeate
		int i = 0; 

		Node* temp = new Node;
		temp = head; 
		
		while (temp != NULL)
		{
			string see = temp->w;
			size_t match = see.find(x); // size_t match any data type

			if (match != string::npos) //  static const size_t npos = -1
			{
				if (i < 10)
				{
					DisplayTen[i] = temp->w;
					i++;
				}
				r++;
			}
			temp = temp->Next;
		
		}
		Found = r;
		temp = NULL;

	}
	int Itemsfound()
	{
		return Found;
	}
	// no more than 10
	void DisplayTenW()
	{
		for (int i = 0; i < 10; i++)
		{
			if (DisplayTen[i] != "NONE")
			{
				cout << DisplayTen[i] << "--> ";
			}
		
			else
			{
				cout << " NO MATCHES FOUND " << endl;
			}
		}

	}

	/* PRINTING OUT LINKED LIST */
	void Print()//ostream& out)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->w << temp->d << endl;

			/*if (temp->Next)
			{
				cout << " -> " << " " << endl;
			}*/
			temp = temp->Next;
		}

		cout << endl;
		temp = NULL;
	}



};