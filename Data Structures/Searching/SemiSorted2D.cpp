#include<iostream>
using namespace std;
int main(){
    int arr[4][4], size=4;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin>>arr[i][j];
        }
    }
    int i=0, j=size-1, target=34;
    while(i<size and j>=0){
        if(arr[i][j]==target){
            cout<<i<<" "<<j<<endl;
            break;
        }
        else if(arr[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"The entered matrix is: "<<endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}