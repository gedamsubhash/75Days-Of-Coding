#include<bits/stdc++.h>
using namespace std;
vector<int> minAnd2ndMin(int *, int);
int main(){
    int a[]={4,2,6,1,7};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int> result=minAnd2ndMin(a, n);
    for(auto ele: result){
        cout<<ele<<" ";
    }
    return 0;
}
vector<int> minAnd2ndMin(int a[], int n) {
    vector<int> ans={-1};
    int smallest=a[0], s_smallest=INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i]<smallest){
            s_smallest=smallest;
            smallest=a[i];
        }else if(a[i]<s_smallest && a[i]>smallest){
            s_smallest=a[i];
        }
    }
    if(s_smallest==INT_MAX){
        return ans;
    }else{
        ans[0]=smallest;
        ans.push_back(s_smallest);
        return ans;
    }
}