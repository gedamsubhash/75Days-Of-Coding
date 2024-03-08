#include<iostream>
#if !defined ARRAY_H
#define ARRAY_H
using namespace std;

void printArray(int arr[], size_t size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

#endif