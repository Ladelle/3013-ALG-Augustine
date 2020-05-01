// accepted 04/27/2020 @ 7:50 pm
/*   10901 - UVA -ACCEPTED
    Ladelle Augustine 
    3013 - Algorithms
    Due: 04/27/2020 @ 11:59 pm
    Program 08 - UVA 10901 
    Ferry 1,2,3 
*/

#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>

#define MAX 10044



using namespace std;

int arrive[MAX];
int leaving[MAX];

int main() 
{
	int cases; 
    cin >> cases;

	bool first_car = true;
    

	while (cases > 0) 
    {
		if (!first_car) 
        {
            cout << endl;
        }
		else 
        
        first_car = false;

		memset(arrive,0,sizeof(arrive));
		memset(leaving,0,sizeof(leaving));

		int capacity,time,m_lines; 

        cin >> capacity >> time >> m_lines;
        // Queue size 2 ( 0 or 1 ; left or right)
        queue<int> q[2];
		
		for(int i = 0;i < m_lines; i++)
        {
			int t1; string side;

			cin >> t1 >> side;
			// if side is left push 
			if (side == "left") 
            {
                q[0].push(i);
            }
			// if side right 
			else
             q[1].push(i);
			arrive[i] = t1;
		}

		int now = 0;
		int now_Side = 0; 
		// while not empty
		while (!q[0].empty() || !q[1].empty()) 
        {
			
			int next_T = 0;
			if (q[0].empty())
            {
             		next_T = arrive[ q[1].front() ];
            }
			else if (q[1].empty()) 	
            {
                next_T = arrive[q[0].front()];
            }
			else
            {					
                next_T = min( arrive[ q[0].front()],arrive[ q[1].front()]);
            }

			now = max(now ,next_T);

			int count = 0;

			while ((!q[now_Side].empty()) && (now >= arrive[q[now_Side].front()]) && (count < capacity))
            {
				leaving[ q[now_Side].front()] = now + time;

				q[now_Side].pop(); 

                count++;
			}
			now += time; 
			now_Side ^= 1; 
		}
		for(int i = 0; i< m_lines; i++)
        {
			//time when car is unloaded
			cout << leaving[i] << endl;
		}
        cases = cases - 1;

	}
	return 0;
}