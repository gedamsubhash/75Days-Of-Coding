#include<iostream>
using namespace std;
void bubble_sort(int arr[], int i, int j){
    if(i==-1){
        return;
    }
    if(j<=i){
        if(arr[j]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        bubble_sort(arr, i, j+1);
    }
    bubble_sort(arr, i-1, 0);
}
int main(){
    int arr[]={5,3,17,5,9,21,16};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, size-1, 0);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}