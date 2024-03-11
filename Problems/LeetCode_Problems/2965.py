class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        l=[]
        ans=[]
        for i in grid:
            for j in i:
                l.append(j)
        l.sort()
        for i in range(1, len(l)):
            if l[i-1]==l[i]:
                ans.append(l[i-1])
                l.pop(i-1)
                break
        total=sum(l)
        n=len(l)+1
        ans.append((n*(n+1)//2)-total)
        return ans