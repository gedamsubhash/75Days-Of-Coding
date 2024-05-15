#include<iostream>
#include<math.h>
using namespace std;
int get_digits(int n){
    if(n==0){
        return 0;
    }
    return 1+get_digits(n/10);
}
int helper(int n, int digits){
    if(n==0){
        return 0;
    }
    return (n%10)*pow(10, digits-1)+helper(n/10, digits-1);
}
int reverse_number(int n){
    int digits=get_digits(n);
    return helper(n, digits);
}
int main(){
    cout<<reverse_number(1234);
    return 0;
}