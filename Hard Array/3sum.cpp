#include<bits/stdc++.h>
using namespace std;
void threesum(vector<int>& arr, int n)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                if(j<k && arr[j]==arr[j-1]) j++;
                if(j<k && arr[k]==arr[k+1]) k--;
            }
        } 
    }
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}
int main(){
    vector<int> arr = {-1,0,1,2,-1,4};
    int n = arr.size();
    threesum(arr,n);
}