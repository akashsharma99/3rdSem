import itertools
import math
def countTwos(arr,n,x):
    result = 0
    s = set()
    for i in range(0,n):
        if(x^arr[i] in s):
            result = result +1
        s.add(arr[i])
    return result
t=int(input())
for x in range(t):
    n=int(input())
    arr=[i for i in range(1,n+1)]
    twooo=countTwos(arr,n,2)
    f=n*(n-1)/2
    a=int(f/2)-1
    print(a-twooo)
            
