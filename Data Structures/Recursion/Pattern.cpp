#include<iostream>
using namespace std;
void pattern1(int i, int j){
    if(i==0){
        return;
    }
    if(j<i){
        cout<<"*";
        pattern1(i, j+1);
    }else{
        cout<<endl;
        pattern1(i-1, 0);
    }
}
void pattern2(int i, int j){
    if(i==0){
        return;
    }
    if(j<i){
        pattern2(i, j+1);
        cout<<"*";
    }else{
        pattern2(i-1, 0);
        cout<<endl;
    }
}
int main(){
    pattern1(4,0);
    pattern2(4,0);
    return 0;
}
