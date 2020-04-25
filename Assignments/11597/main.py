#11597 -THE ACCEPTED ONE
# Ladelle Augustine
# 3013- Algorithms
# Due: 04/16/2020
# Program 06 - UVA 11597 
# Spanning Trees
# 
def main():
    cases = 0
    v = []
    num = -1
    while num != 0: 
        num = int(input())
        if num == 0:
            break
            EOFError
        else: 
            v.append(num)
    for i in range(len(v)):
        x = int(v[i])
        cases += 1
        m = int(x/2)
        print("Case {}: {}".format(cases,m))


 
if __name__== "__main__":
    main()
