# Ladelle Augustine
# Problem 10901
# Due: 04/27/2020
# Program 08
# Ferry Loading- Third Version
# Queue based approach 
import sys
import queue

def main():
    print("Hello")
    case = int(input())

    while(case > 0):
        car,t,m = map(int,input().split()) #2 10 10, 2 10 3
        print("Car:", car)
        print("Time", t)
        print("n# of lines", m) # queue
        
        total_T = [m]
        q = queue.Queue(2) # max size is two
        for i in range (0,m):
            t1, side = [int(i) if i.isdigit() else i for i in input().split()]
            print("T1:", t1)
            print("side:",side)
            if (side == "left"):
                q.put(i)
            else:
                q.put(i)
            total_T[i] = t1  
                
        side = 0
        time = 0
        
        while not q.empty() and (q.queue[0] or q.queue[1]):
            if(q.empty() and q.queue[0]):
                next_car = total_T[q.queue[1].front()]
            else:
                if (q.empty() and q.queue[1]):
                    next_car = total_T[q.queue[0].front()]
                else: 
                    next_car = min(total_T[q.queue[0].front()],total_T[q.queue[1].front()])

               
            # curr_car = 0
            # time = max(time,next_car)
            # while( not sides[side].empty() and total_T[sides[side].front()]<= time and curr_car < car):
            #     curr_car = curr_car + 1
            #     total_T[sides[side].front()]= time + t
            #     sides[side].pop()
                
            # time = time + t
            # side = (side + 1) % 2
            
        case = case - 1
        for i in range (0,m):
            print(t[i], '\n')
        if(case):
            print("\n")
      
    
    

if __name__== "__main__":
    main()
      