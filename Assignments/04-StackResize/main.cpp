///////////////////////////////////////////////////////////////////////////////
//
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            04-P01
// Title:			 Assignment 4 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack and Resizes the 
//       Stack, if the stack is full or half empty.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <exception>




using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
	int *A;                // pointer to array of int's
	int size;			   // current max stack size
	int top;               // top of stack 
	int G;                 // # of array growth
	int Rcount;             // counting shrink & growth

public:
	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor no params
	 *
	 * Params:
	 *     - None
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
		G = 0;
		Rcount = 0;
	}

	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor size param
	 *
	 * Params:
	 *     - int size
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack(int s) {
		size = s;
		A = new int[s];
		top = -1;
		G = 0;
		Rcount = 0;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Stack empty?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 *
	 * Description:
	 *      Stack full?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 *
	 * Description:
	 *      Returns top value without altering the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop()
	{


		if (!Empty()) {

			CheckResize();           // call to resize check

			return A[top--];
		}

		return -99;                  // some sentinel value
					                 // not a good solution
	}



	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack and calls CheckResize function.
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x) {


		if (Full()) {

			CheckResize();            // calling resize check
		}
		if (!Full())
		{
			CheckResize();            // calling resize check

			A[++top] = x;
			return true;
		}

		return false;

	}
	/**
 * Public void: ContainerGrow
 *
 * Description:
 *      Resizes the container for the stack by increasing the stack by 1.75
 *      when the stack becomes full.
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */

	void ContainerGrow()
	{
		G++;                                // counting growing stack
		
    	int newSize = (size * 1.75);        // size * 1.75

			int *B = new int[newSize];          // creates new array.

			for (int i = 0; i < size; i++) {
				B[i] = A[i-1];
			}

			 	delete[] A; // deletes array
			size = newSize;
			A = B;                              // resets array pointer
			


			Rcount++;                            // counting resize amount
		
	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description:
	 *      Resizes the container for the stack by decreasing the stack by .5
	 *      when the stack becomes half empty, after at least gettin full once.
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerShrink()
	{

		int newSize;
		newSize = (size * 0.5);      // shrinks size.

		int *B = new int[newSize];  // CREATES NEW ARRAY

		for (int i = 0; i < size; i++)
		{
			B[i] = A[i-1];
		}
		A = 0;
		delete[] A; 
		size = newSize;

		A = B;
		
		Rcount++; // counting resize amount

	}
		/**
		 * Public void: CheckResize
		 *
		 * Description:
		 *      Checks the Resizes for array if stack is full, if stack is half full
		 *       and if stack has been full at least once to shrink it.
		 *       It calls the containerGrow and containershrink functions.
		 *
		 * Params:
		 *      NULL
		 *
		 * Returns:
		 *      NULL
		 */
	void CheckResize()
	{

		if (Full())
		{
			ContainerGrow();
		}
		else if ((top + 1) <= (size / 2))
		{
			if (G >= 1 && size > 1)                  // checks if array has been full at least once.
			{
				ContainerShrink();
			}
		}
		else //if (((top + 1) / size) >= 1)
		{
			ContainerGrow();
		}


	}


	/**
 * Public void: Print
 *
 * Description:
 *      Prints stack to standard out
 *
 * Params:
 *      NULL
 *
 * Returns:
 *      NULL
 */
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		// MUST HAVE IN CODE
		cout << "################################################### " << endl;
		cout << "Assignment 4 - Resizing the Stack" << endl;
		cout << "CMPS 3013" << endl;
		cout << "Ladelle Augustine" << endl;
		cout << " Max Stack Size: " << G << endl; //NEED TO PLACE VALUE
		cout << " Stack Resized: " << Rcount << " times" << endl; // NEED TO PLACE AMOUNT OF TIME
		cout << " End Stack Size: " << size << endl; // NEED TO PLACE VALUE

		cout << "################################################### " << endl;
	}
	~ArrayStack() // destructor maybe might help free up space
	{
		delete[] A;
	}
};
// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{


	ifstream infile("nums.dat");                  // opening file
	ofstream outfile("output.txt");              //   putting in ouput file

	ArrayStack stack;

	short k;
	char c;

	if (!infile.eof())
	{
		while (infile >> c)
		{
			switch (c)
			{
			case'1':

				k = c - '0';

				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}
				break;

			case'2':

				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}
				break;

			case '3':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case '4':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case '5':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case'6':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case'7':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case'8':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case '9':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			case '0':
				k = c - '0';
				if (k % 2 == 0)
				{
					stack.Push(k);
				}
				else
				{
					stack.Pop();
				}

				break;

			default:printf("Not a Number");




			}
		}

	}

	stack.Print();

	infile.close();
	outfile.close();
	system("pause");
	return 0;

}