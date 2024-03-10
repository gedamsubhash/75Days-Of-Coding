#include<iostream>
using namespace std;
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
void merge_sort(int arr[], int start, int end){
    if(end-start==1){
        return;
    }
    int mid=start+(end-start)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid, end);
    merge(arr, start, end, mid);
}
void merge(int arr[], int start, int end, int mid){
    int i=start, j=mid, k=0;
    int ans[end-start]={0};
    while(i<mid && j<end){
        if(arr[i]<arr[j]){
            ans[k]=arr[i];
            i++;
        }else{
            ans[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<mid){
        ans[k]=arr[i];
        i++;
        k++;
    }
    while(j<end){
        ans[k]=arr[j];
        j++;
        k++;
    }
    for(int x=0; x<sizeof(ans)/sizeof(ans[0]); x++){
        arr[start+x]=ans[x];
    }
}
int main(){
    int a[]={4,3,5,7,1,9,12,43,11};
    merge_sort(a, 0, sizeof(a)/sizeof(a[0]));
    for(auto i:a)
        cout<<i<<" ";
    return 0;
}