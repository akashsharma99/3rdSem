import math
import itertools
n=1000000
prime=[True for i in range(n+1)]#initialising array prime with True
p=2
while(p*p<=n):
    if(prime[p]==True):
        x=p*2
        while(x<=n):
            prime[x]=False
            x+=p;
    p+=1
# printing the prime numbers
t=int(input())
for x in range(t):
    n=int(input())
    m=int(input())
    count=0
    arr=[i for i in range(n,m+1)]
    pairs=[p for p in itertools.combinations(arr,2)]
    for z in pairs:
        if(prime[z[0]]==True && prime[z[1]]==True):
            if(gcd(z[0],z[1])==1):
                count=count+1
"""t=2
while(i<=n):
    if(prime[i]==True):
        print(i,end=" ")
    i+=1
"""
