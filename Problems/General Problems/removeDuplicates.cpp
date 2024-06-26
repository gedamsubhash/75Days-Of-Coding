#include<bits/stdc++.h>
using namespace std;
void approach1(int *, int);
void approach2(int *, int);
void approach3(int *, int);
int main(){
    int arr[]={1,1,2,2,2,3,3,4,5,5,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    approach3(arr, size);
    return 0;
}
void approach1(int arr[], int size){
    set<int> ord_set;
    for(int i=0; i<size; i++){
        ord_set.insert(arr[i]);
    }
    for(auto ele: ord_set){
        cout<<ele<<" ";
    }
}
void approach2(int arr[], int size){
    int i=0, j=1;
    while(i<size && j<size){
        if(arr[i]==arr[j]){
            j++;
        }else{
            i++;
            arr[i]=arr[j];
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
void approach3(int arr[], int size){
    int i=1;
    for(int j=1; j<size; j++){
        if(arr[j]!=arr[j-1]){
            arr[i]=arr[j];
            i++;
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}