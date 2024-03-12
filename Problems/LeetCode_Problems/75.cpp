class Solution {
public:
    void swap(int *a, int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void sortColors(vector<int>& arr) {
        int i=0, mid=0, j=arr.size()-1;
        while(mid<=j){
            if(arr[mid]==0){
                swap(&arr[mid], &arr[i]);
                i++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(&arr[mid], &arr[j]);
                j--;
            }
        }
    }
};