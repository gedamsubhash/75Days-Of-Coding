#include<iostream>
using namespace std;
void selection_sort(int arr[], int i, int j, int max){
    if(i==-1){
        return;
    }
    max=i;
    if(j<=i){
        if(arr[j]>arr[max]){
            max=j;
        }
        selection_sort(arr, i, j+1, max);
    }
    if(max!=i){
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
    selection_sort(arr, i-1, 0, 0);
}

int main(){
    int arr[]={5,32,12,77,65,45,32};
    int size=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, size-1, 0, 0);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}