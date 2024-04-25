#include<bits/stdc++.h>
using namespace std;
// arr[]=[-2, -2, -1, -1, 0, 1, 2] -2+-1+1+2
// for i -> n;

void foursum(vector<int> &arr,int n, int target){
    sort(arr.begin(),arr.end());
   vector<vector<int>> ans;
   for(int i=0; i<n; i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            int k=j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    if(k<l && arr[k] == arr[k-1]) k++;
                    if(k<l && arr[l] == arr[l+1]) l--;
                }else if(sum > target){
                    l--;
                }else{
                    k++;
                }
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
    vector<int> arr ={4,3,3,4,4,2,1,2,1,1} ;
    int n = arr.size();
    int target =9;
    foursum(arr,n,target);
}