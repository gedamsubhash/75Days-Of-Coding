#include<iostream>
using namespace std;
int search(int arr[], int n){
    int i=0;
    while(i<n){
        if(arr[i]<n && arr[i]!=i){
            int temp=arr[i];
            arr[i]=arr[temp];
            arr[temp]=temp;
        }else{
            i++;
        }
    }
    for(int j=0; j<n; j++){
        if(arr[j]!=j){
            return j;
        }
    }
    return n;
}
int find_duplicates(int arr[], int n){
    int i=0;
    while(i<n){
        if(arr[i]!=i+1){
            int correct=arr[i]-1;
            if(arr[i]!=arr[correct]){
                int temp=arr[i];
                arr[i]=arr[correct];
                arr[correct]=temp;
            }else{
                return arr[i];
            }
        }else{
            i++;
        }
    }
    return -1;
}
int main(){ 
    int arr[]={1,3,4,2,2};
    cout<<find_duplicates(arr, 5);
    return 0;
}