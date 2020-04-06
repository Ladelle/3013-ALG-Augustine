///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            10-PO5
// Title:            STL Maps 
// Course:           3013-Algorithm
// Semester:         Spring 2020
//
// Description:
//       This program is based on STL Maps and using "key" value pairs. 
// Usage:
//       This program removes duplicates from a sequence of integers and prints
//       the list of unique integers occuring in the input sequence, with the
//       number of occurrences.
//
// Files:            input.txt
//                   input2.txt
// Accepted: 04/05/2020 1:24am
/////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include<vector>
#include<map>


#define endl "\n"

using namespace std;

map<int, int>dict; // holds dictionary
vector<int>input; // holds input


int main()
{
    int size;
    int nums = 0;
    while (cin >> nums)
     {

        if (dict.find(nums) == dict.end()) // if not found
         {
            input.push_back(nums);
            dict[nums] = 1;
            // not found  
         }
        else
        {
            dict[nums] = dict[nums] + 1;
            //found
        }
     }

        size = input.size();
        for (int i = 0; i < size; i++)
        {
            cout << input[i] << " " << dict[input[i]] << "\n";           
        }
        
    return 0;
}