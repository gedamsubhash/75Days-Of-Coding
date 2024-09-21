def gcf(a, b):
    if(b==0):
        return a
    return gcf(b, a%b)

def lcm(arr):
    ans=arr[0]
    for i in range(1, len(arr)):
        ans=((arr[i]*ans)/gcf(arr[i], ans))
    return ans

print(lcm([ 2, 7, 3, 9, 4 ]))
