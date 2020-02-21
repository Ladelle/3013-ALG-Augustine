#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/**
 * Node
 *
 * Description:
 *         This is a struct Node that contains two strings (word and definitions).
 *         This struct also hold the Next pointer.
 *
 * Public Methods:
 *      string 					w
 *		string 					d
 *		Node* 					Next
 *
 * Private Methods:
 *      None
 *
 * Usage:
 * 		Node Temp;				
 *
 */
struct Node
{

	string w;                                // word
	string d;                                // dictionary
	Node* Next;

};

/**
 * Dictionary
 *
 * Description:
 *
 *
 * Public Methods:
 *                              Dictionary()
 *     void                     Insert(String W, String D)
 *     void                     Remove()
 *     void                     search (string x)
 *     int                      ItemsFound()
 *     int                      getSize()
 *     void                     DisplayTenW()
 *     void                     Print()
 *
 * Private Methods:
 *		Node* 					head
 *		Node* 					tail
 *      int                     Size
 *      string                  DisplayTen[10]
 *      int                     Found
 * Usage:
 * 		List.Dictionary;        				
 *      List.Insert(word, def);
 *      List.search(var);
 *      List.ItemsFound();
 *      List.DisplayTenW();
 */

class Dictionary                                // class Dictionary 
{
private:

	Node* head;
	Node* tail;
	int Size;
	string DisplayTen[10];
	int Found;

public:

 /**
 * Constructor: 
 * @description:
 *     holds private member variables with default values
 * 
 * @param  
 *          None
 * @return              
 *         None
*/
	Dictionary()
	{
		head = NULL;
		tail = NULL;
		Size = 0;
		for (int i = 0; i < 10; i++)
		{
			DisplayTen[i] = "NONE";
		}
		Found = 0;


	}
	 /**
 * Insert: 
 * @description:
 *     Inserts the string values into the linked list.
 * 
 * @param  
 *          string W
 *          string D
 * @return              
 *         None
*/
/*               INSERT METHOD                       */

	void Insert(string W, string D)
	{


		Node* temp = new Node;
		temp->w = W;
		temp->d = D;
		temp->Next = NULL;

		                                          // if list is empty put in new Node

		if (head == NULL)                         // insert in front

		{
			head = temp;
			Size++;
		}
		else if (head->Next == NULL)              // insert @ middle
		{
			tail = temp;
			head->Next = tail;
			Size++;
		}
		else                                      // insert @ end
		{
			tail->Next = temp;
			tail = temp;
			Size++;

		}
		temp = NULL;
	}

/**
 * Remove: 
 * @description:
 *     Removes item from list
 * 
 * @param  
 *          None
 * @return              
 *          None
*/
	void Remove()
	{
		if (head != NULL)
		{
			Node* temp = head;
			head = head->Next;
			delete temp;
			temp = NULL;
			Size--;


		}
		else
		{
			cout << " LIST IS EMPTY .";
		}

	}
 /**
 * search: 
 * @description:
 *     searches for string value in list and see's
 *     if it can be found or not.
 * 
 * @param  
 *          string x
 * @return              
 *          None
*/	
	void search(string x)
	{
		int tr = 0;  // time read
		int i = 0;
		Node* temp = new Node;
		temp = head;

		while (temp != NULL)
		{
			string see = temp->w;

			size_t match = see.find(x); // size_t match any data type

			if (match != string::npos) //  -1 static const size_t npos = -1
			{
				if (i < 10)
				{
					DisplayTen[i] = temp->w;
					i++;
				}
				tr++;
			}
			temp = temp->Next;

		}
		Found = tr;
		temp = NULL;
		delete temp;

	}

/**
 * ItemsFound: 
 * @description:
 *     shows how much items were found in the list.
 * 
 * @param  
 *         None
 * @return              
 *         Found
*/
	int Itemsfound()                           // return items found
	{
		return Found;
	}
 /**
 * getSize: 
 * @description:
 *     gets the Size and returns it.
 * 
 * @param  
 *         None
 * @return              
 *         Size
*/
	int getSize()                              // Size of the current linked list
	{

		return Size;
	}
/**
 * DisplayTenW: 
 * @description:
 *     Displays up to ten Words.
 * 
 * @param  
 *         None
 * @return              
 *         None
*/                                                     // no more than 10
	void DisplayTenW()
	{
		for (int i = 0; i < 10; i++)
		{
			if (DisplayTen[i] != "NONE")
			{
				
					cout << DisplayTen[i] << " ";
				
			}

			else
			{
				cout << " NO MATCHES FOUND " << endl;
			}
		}

	}
 /**
 * Print: 
 * @description:
 *     Prints out the dictionary
 * 
 * @param  
 *         None
 * @return              
 *         None
*/
	void Print()
	{
		Node* temp = new Node;
		temp = head;


		while (temp != NULL)
		{

			cout << " { " << temp->w << "-> " << temp->d << endl;
			temp = temp->Next;

		}


	}

};