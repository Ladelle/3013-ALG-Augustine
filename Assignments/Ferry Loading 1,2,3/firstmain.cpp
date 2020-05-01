//accepted 04/27/2020 @8:16pm
/*   10261 - UVA -ACCEPTED
    Ladelle Augustine 
    3013 - Algorithms
    Due: 04/27/2020 @ 11:59 pm
    Program 08 - UVA 10261 
    Ferry 1,2,3 
*/


#include <cstdio>
#include <cstring>
 
void checking(int curr, int length);

using namespace std;

bool dp[2004][10007];  // 1 or 0 
int length_car[2004],pre[2004][10007];
 
int main()
 {
  int cases;
 // reads in cases 
  scanf("%d", &cases);

  while (cases--)
   {

    int length_ferry;
    // reads in length of ferry in meters # between 1 to 100
    scanf("%d", &length_ferry);

    length_ferry = length_ferry * 100;

    memset(dp, false, sizeof(dp));

    // setting to true
    dp[0][0] = true;

    int curr = 1;
    int sum = 0;
    int last = 0;
    int length;

    // while reading in the length of the cars 
    while (scanf("%d", &length_car[curr]) && length_car[curr]) 
    {
      sum = sum + length_car[curr];
      //decides which side the car should be loaded.
      for (int i = 0; i <= length_ferry; i++) 
      {
        // T & T
        if(dp[curr-1][i] && sum - i <= length_ferry)
        {
          // loads on right

          dp[curr][i] = true;
          pre[curr][i] = i;
          length = i;
          last = curr;
        }
         // loads on left
         else if(dp[curr -1][i - length_car[curr] && i >= length_car[curr]])
         {

          dp[curr][i] = true;

          pre[curr][i] = i - length_car[curr];

          length = i;

          last = curr;
          
        }

      }

      curr++; // increment
    }

    printf("%d\n", last);

    checking(last, length);

    if (cases) 
    {
      puts("");
    }

  }

  return 0;
}
void checking(int curr, int length) 
{
  if (!curr) 
  {
    return;
  }
  checking(curr - 1, pre[curr][length]);

  puts(pre[curr][length] == length ? "starboard" : "port");
}