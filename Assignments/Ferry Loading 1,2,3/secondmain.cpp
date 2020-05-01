// accepted 04/27/2020 @ 10:07 pm
/*   10440 - UVA -ACCEPTED
    Ladelle Augustine 
    3013 - Algorithms
    Due: 04/27/2020 @ 11:59 pm
    Program 08 - UVA 10440 
    Ferry 1,2,3 
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int cases; 
    int capacity;
    int m_lines;
    int time; 
    int location;
    int results;
    int trips[1444]; //setting array size to 1444 as 1440 is in uva instructions

    // reads in the  test cases
    scanf("%d", &cases);
    
   
    for(int i = 0; i < cases; i++)
    {
        // reading in number of cars to take across river.
        // reading in time it takes to go and return 
        // reading in lines to follow 
        scanf("%d %d %d", &capacity, &time, &m_lines);
        
        for(int i = 0; i < m_lines; i++)
            // reading in the trips
            scanf("%d", &trips[i]);
            sort(trips, trips + m_lines);
            // setting results and location to 0
            results = 0 ;
            location = 0;
        
       
        if (m_lines % capacity == 0) 
        {
            results = trips[capacity- 1] + 2 * time;
            location = capacity;
        }
        else
        {
            results = trips[m_lines % capacity - 1] + 2 * time;
            location = m_lines % capacity;
        }
        for(;location < m_lines; location = location + capacity)
        {
            if(results >= trips[location + capacity - 1])
            {
                results = results + 2 * time;
            }
            else
            {

             results = trips[location + capacity - 1] + 2 * time;
            }
            
        }
        results = results - time;
        // time in minutes and minimum number of trips made by the ferry
        printf("%d %d\n", results,(m_lines + capacity - 1)/capacity);
    }
    return 0;
}