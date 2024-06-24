#include<bits/stdc++.h>
using namespace std;
void hash_set_approach(int *, int);
void optimal_for_2ndLar(int *, int );
int main(){
    int arr[]={6,5,1,4,7,3,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    hash_set_approach(arr, size);
    return 0;
}
void hash_set_approach(int arr[], int size){
    int n;
    cout<<"Enter the Nth largest number you want to find: ";
    cin>>n;
    int largestIndex;
    unordered_set<int> uset;
    for(int i=0; i<n; i++){
        largestIndex=-1;
        for(int j=0; j<size; j++){
            if((largestIndex==-1 || arr[j]>arr[largestIndex]) && uset.find(arr[j]) == uset.end()){
                largestIndex=j;
            }
        }
        uset.insert(arr[largestIndex]);
    }
    for(auto ele: uset){
        cout<<ele<<" ";
    }
    cout<<"The "<<n<<"th largest number in array is: "<<arr[largestIndex]<<endl;
}
