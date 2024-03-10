#include<iostream>
using namespace std;
void quick_sort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int i=start, j=end, mid=start+(end-start)/2;
    int pivot=arr[mid];
    while(i<=j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<=j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, start, j);
    quick_sort(arr, i, end);
}
int main(){
    int a[]={4,3,5,7,1,9,12,43,11};
    quick_sort(a, 0, (sizeof(a)/sizeof(a[0]))-1);
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}