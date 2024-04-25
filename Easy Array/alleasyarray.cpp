#include<bits/stdc++.h>
using namespace std;
int largestnum(int arr[], int n){
    int largest=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}
// better aproach
int slargestnum(int arr[], int n){
    int largest = largestnum(arr, n);
    int slargest = -1;
    for(int i=0; i<n; i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i];
        }
    }
    return slargest;
}
// optimal
int sslargestnum(int arr[], int n){
    int largest=arr[0];
    int slargest = INT_MIN;
    for(int i=1; i<n; i++){
        if(arr[i]>largest)
        {
            slargest = largest;
            largest =arr[i];
        }else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    return slargest;
}
bool checksort(int arr[], int n){

    for(int j=1; j<n; j++){
        if(arr[j]>=arr[j-1]){

        }
        else return false;
    }
    return true;
}

int removedup(int arr[], int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}

void leftshift(int arr[], int n){
    int temp = arr[0];
    for(int i=0; i<n; i++){
        arr[i]=arr[i+1];
    }
    arr[n-1] = temp;
}
// bruteforce 
void dshift(int arr[], int n, int k){
    int temp[n];
    for(int i=0; i<k; i++){
        temp[i] = arr[i];
    }
    for(int i=k; i<n; i++){
        arr[i-k] = arr[i];
    }
    int j=0;
    for(int i=n-k; i<n; i++){
        arr[i] = temp[j];
        j++;
    }
}
// optimal
void dshifto(int arr[], int n, int k){
    reverse(arr, arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}
// bruteforce
void movezerotoend(int arr[],int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int noofnz = temp.size();
    for(int i=0; i<temp.size();i++){
        arr[i] = temp[i];
    }
    for(int i=noofnz; i<n; i++){
        arr[i] = 0;
    }
}
// optimal
void movezerotoendo(int arr[], int n){
    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
void unionnums(int arr1[],int arr2[], int n,int m){
    int i=0;
    int j=0;
    vector<int> unionv;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            if( unionv.size()==0 || unionv.back()!=arr1[i]){
                unionv.push_back(arr1[i]);
            }
            i++;
        }else{
            if(unionv.size()==0 || unionv.back()!=arr2[j]){
                unionv.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n){
        if( unionv.size()==0 || unionv.back()!=arr1[i]){
                unionv.push_back(arr1[i]);
            }
            
            i++;
    }
    while (j<m){
        if(unionv.size()==0 || unionv.back()!=arr2[j]){
                unionv.push_back(arr2[j]);
            }
            j++;
    }
    for(auto it : unionv){
        cout << it << " ";
    }
}
vector<int> intersectio(int a[], int b[], int n, int m){
    int i=0;
    int j=0;
    int x=0;
    vector<int> result;
    // int result[max(n,m)];
    while (i < n && j < m) {
    if (a[i] < b[j]) {
        i++;
    } else if (b[j] < a[i]) {
        j++;
    } else {
        cout << a[i] << " ";
        result.push_back(a[i]);
        i++;
        j++;
    }
}
    // for(int y=0; y<max(n,m); y++){
    //     cout << result[y] << " ";
    // }
    return result;
}
// better
void missingnum(int arr[], int n){
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]=1;
    }
    for(int i=1; i<=n; i++){
        if(hash[i]==0){
            cout << i << endl;
        }
    }
}
// optimal
void missingnumo(int arr[], int n){
    int actualsum = (n*(n+1))/2;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    cout << actualsum-sum;
}
void maxconsicutive(int arr[],int n){
    int cnt=0;
    int maxc=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            cnt++;
        }else{
            cnt=0;
        }
        maxc = max(maxc,cnt);
    }
    cout << maxc;
}
// better
void appearone(int arr[], int n){
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(hash[i]==1){
            cout << i << endl;
        }
    }
}
// optimal
void appearones(int arr[], int n){
    int xorr=0;
    for(int i=0; i<n; i++){
        xorr = xorr^arr[i];
    }
    cout << xorr ;
}
int main(){
    int n,m;
    cin >> n;
    int arr[n];
    // int arr2[m];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // for(int i=0; i<m; i++){
    //     cin >> arr2[i];
    // }
    // int index = removedup(arr,n);
    // leftshift(arr, n);
    /* int k ;
    cin >> k;
    dshifto(arr, n, k); */
    // movezerotoendo(arr, n);
    // vector<int> ans = intersectio(arr,arr2,n,m);
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // } 
    // for(auto it : ans){
    //     cout << it << " ";
    // }
    appearones(arr,n);
}