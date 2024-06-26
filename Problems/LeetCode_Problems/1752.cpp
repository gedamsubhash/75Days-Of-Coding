#include<iostream>
using namespace std;
bool bruteForce_Approach(int *, int );
bool optimal_Approach(int *, int);
int main(){
    int arr[]={3,4,5,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    // cout<<bruteForce_Approach(arr, size);
    cout<<optimal_Approach(arr, size);
    return 0;
}
bool bruteForce_Approach(int arr[], int size){
    if(arr[size-1]<=arr[0]){
        int count=0;
        for(int i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                count++;
                if(count>1){
                    return false;
                }
            }
        }
        return true;
    }else{
        for(int i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        return true;
    }
}
bool optimal_Approach(int arr[], int size){
    int count=0;
    for(int i=1; i<size; i++){
        if(arr[i]<arr[i-1])
            count++;
    }
    if(arr[size-1]>arr[0])
        count++;
    return count<=1;
}