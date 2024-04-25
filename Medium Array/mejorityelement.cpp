#include<bits/stdc++.h>
using namespace std;
// basic idea of this problem 
// we have an array arr[] = {2,2,3,1,2,2} output will be = 4 the length of array is 6 and 6/2 mejority 
// element should be > 3 so the 2 is more then 3 then mejority element output will be 4
// bruteforce
int mejorityelementbr(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        int cnt =0;
        for(int j=0; j<arr.size(); j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(cnt > (arr.size()/2)){
            return arr[i];
        }
    }
    return-1;
}
// better
int mejorityelementb(vector<int>& arr){
    map<int,int> mpp;
    int n = arr.size();
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second > n/2) return it.first;
    }
    return -1;
}
// optimal with moore's algoritham
int mejorityelement(vector<int>& arr){
    int n = arr.size();
    int cnt=0;
    int el;
    for(int i=0; i<n; i++){
        if(cnt==0){
            el = arr[i];
            cnt=1;
        }else if(el==arr[i]){
                cnt++;
        }else{
            cnt--;
        }
    }
    // test
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(el==arr[i]) cnt1++;
    }
    if(cnt1 > n/2){ return el; }
    
    return -1;
}
int main(){
    vector<int> arr = {2,3,3,3,3,2,2};
    int ans = mejorityelementb(arr);
    cout << ans;
}