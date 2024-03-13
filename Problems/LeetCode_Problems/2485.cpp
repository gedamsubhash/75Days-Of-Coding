class Solution {
public:
    int pivotInteger(int n) {
        int totalSum=0, preSum=0;
        for(int i=1; i<=n; i++)
            totalSum+=i;
        for(int i=1; i<=n; i++){
            preSum+=i;
            if((totalSum-preSum+i)==preSum)
                return i;
        }
        return -1;
    }
};