#include<iostream>
using namespace std;
void sorting(int arr[], int i, int j, int max){
    if(j==-1){
        return;
    }
    max=j;
    if(i<=j){
        if(arr[i]>arr[max]){
            max=i;
        }
        sorting(arr, i+1, j, max);
    }
    if(j!=max && i==j+1){
        int temp=arr[max];
        arr[max]=arr[j];
        arr[j]=temp;
    }
    sorting(arr, 0, j-1, 0);
}
int main(){
    int arr[]={5,3,7,1,8,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    sorting(arr, 0, size-1, 0);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}