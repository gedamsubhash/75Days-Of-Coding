# def gcd(x, y):
#     val1,val2=None, None
#     if x>y:
#         val1=x
#         val2=y
#     else:
#         val1=y
#         val2=x
#     while(val2!=0):
#         temp=val2
#         val2=val1%val2
#         if(val2==0):
#             print(temp)
#         val1=temp
# gcd(98, 56);

# def gcd_recurr(a, b):
#     if(a==0):
#         return a
#     if(b==0):
#         return b
#     if(a==b):
#         return a
#     if(a>b):
#         return gcd_recurr(b, a-b)
#     return gcd_recurr(a, b-a)
# print(gcd_recurr(98, 56))

# def gcd(a,b):
#     if b==0:
#         return a
#     return gcd(b, a%b)
# print(gcd(28, 20))

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
