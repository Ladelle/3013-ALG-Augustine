#include <iostream>

using namespace std; 

/*Class Function for a Min Heap*/
class MinHeap
{
private:
    /* data */
    int size;                  // current size of the Array
    int *H;                  // array pointer H
    int end;                // 1 past the last item in the array

    // returns the parent index.
    int Parent(int index){return index/2;}

    // return left child index.
    int LeftChild(int index ){return 2*index;}

    // return right child index.
    int RightChild (int index){return 2*index +1 ;}

    // swapping two values in heap
     void Swap(int i, int j) 
     {  
        int temp = H[i]; // setting temp to the value of H[index]

        H[i] = H[j];     // swapping the values in H[i] and H[j]

        H[j] = temp;    // setting H[j] to the value in temp.
     }

     bool OnHeap(int index)
     {
         return index < end; // if index is off the or on the heap 

         /*      0 = off heap            1 = on heap      */

     }


  /*Puts one value into its proper place in the HEAP*/   
void BubbleUp(int index)
{
       
        if (Parent(index) >= 1)        // if parent is not @ beginning of array.
        {
            /*   index is on array and value is less than parent         */
            while (index > 1 && H[index] < H[Parent(index)])
            {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
}

/* Methods to fix bubble down/ heapify, pick child and ect. */

void BubbleDown(int index)
{

}
 int PickChild(int index) 
{

}
void Heapify(int *A , int s) //size and pointer is passed
{
    H = A; // setting point H = to whater A is pointing at

}

public:
  MinHeap() /* Heap Constructor */
    {
        size = 100;
        H = new int[size];
        end = 1;
    } 

  MinHeap(int s) // Size of Heap 
   {
        size = s;
        H = new int[s];
        end = 1;
   }
 

   /* Adds value to the heap */
   void Insert(int x)
   {
       H[end] = x;
        BubbleUp(end);
        end++;
   }

   /* Removes item from the TOP of the heap - implies the heap is sorted */
   int Remove() 
   {
       int temp = H[1];
        H[1] = H[end]; 
        --end;

        return temp;

   }

   /*Prints out values in array */
   void Print()
   {
       for (int i = 1; i <= end - 1; i++)
        {
            cout << H[i];
            if (i < end - 1) 
            {
                cout << "->";
            }
        }
   }
};


/*Main Method*/
int main()
{

MinHeap Test1;

// inserting 6  elements into heap
Test1. Insert(25);
Test1.Insert(22);
Test1.Insert(18);
Test1.Insert(28);
Test1.Insert(1);
Test1.Insert(30);
// printing Test1
Test1.Print();

    system("pause");
    return 0;
}