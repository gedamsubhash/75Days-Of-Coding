#include<bits/stdc++.h>
using namespace std;

int binary_search_using_iteration(int arr[], int i, int j, int target){
    int mid;
    while(i<=j){
        mid=i+(j-i)/2;
        if(target<arr[mid])
            j=mid-1;
        else if(target>arr[mid])
            i=mid+1;
        else
            return mid;
    }
    return -1;
}

int binary_search_using_iteration(int arr[], int size, int target){
    int i=0, j=size-1, mid;
    while(i<=j){
        mid=i+(j-i)/2;
        if(target<arr[mid])
            j=mid-1;
        else if(target>arr[mid])
            i=mid+1;
        else
            return mid;
    }
    return -1;
}

int agnostic_binary_search(int arr[], int size, int target){
    int i=0, j=size-1, mid;
    bool ascend=(arr[0]<arr[j]);
    while(i<=j){
        mid=i+(j-i)/2;
        if(arr[mid]==target)
            return mid;
        if(ascend){
            if(target<arr[mid])
                j=mid-1;
            else
                i=mid+1;
        }
        else{
            if(target>arr[mid])
                j=mid-1;
            else
                i=mid+1;
        }
    }
    return -1;
}

int binary_search_on_rotated_array(int arr[], int size, int target){
    int i=0, j=size-1, mid;
    while(i<j){
        mid=i+(j-i)/2;
        if(arr[i]<=arr[mid]){
            if(arr[mid]>arr[mid+1]){
                j=mid;
            }else{
                i=mid+1;
            }
        }else{
            j=mid-1;
        }
    }
    int res=binary_search_using_iteration(arr, 0, i, target);
    if(res!=-1){
        return res;
    }else{
        return binary_search_using_iteration(arr, i+1, size-1, target);
    }
}

int main(){
    int a[]={2,5,8,9,12,16,18,21,25,27,32,37,47}, target, res;
    int a2[]={4,5,6,7,1,2,3};
    int size=sizeof(a)/sizeof(a[0]);
    int option;
    do{
        cout<<"\n1.Normal Binary Search\n2.Agnostic Binary Search\n3.Rotated Binary Search\n4.Search in Rotated Array\n";
        cin>>option;
        if(option==0){
            break;
        }
        cout<<"Enter the element you want to search: ";
        cin>>target;
        if(option==1)
            res=binary_search_using_iteration(a, size, target);
        else if(option==2)
            res=agnostic_binary_search(a, size, target);
        else if(option==4)
            size=sizeof(a2)/sizeof(a2[0]);
            res=binary_search_on_rotated_array(a2, size, 2);
        if(res!=-1)
            cout<<"Element found at index "<<res<<endl;
        else
            cout<<"Element not found in array"<<endl;
    }while(option!=0);
    return 0;
}