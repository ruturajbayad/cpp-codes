#include<bits/stdc++.h>
using namespace std;
// same as >n/2 but diffrence is >n/3 simple 🤙🏻
void mejorityel(int arr[], int n){
    vector<int> ans;
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for(int i=0; i<n; i++){
        if(cnt1==0 && el2 != arr[i]){
            cnt1=1;
            el1 = arr[i];
        }else if(cnt2==0 && el1!=arr[i]){
            cnt2=1;
            el2 = arr[i];
        }else if(el1 == arr[i]){
            cnt1++;
        }else if(el2 ==arr[i]){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    int cont1=0,cont2=0;
    for(int i=0; i<n; i++){
        if(arr[i] == el1) cont1++;
        if(arr[i] == el2) cont2++;
    }
    int mid = (n/3)+1;
    if(cont1 > mid) ans.push_back(el1);
    if(cont2 > mid) ans.push_back(el2);
    for(auto it : ans){
        cout << it << " ";
    } 
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    mejorityel(arr,n);   
}