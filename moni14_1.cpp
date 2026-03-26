#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }
    vector<int> ans(n,0);
    for(int i = 0; i < n; i++){
        if(i == 0)  ans[i] = (arr[0]+arr[1])/2;
        else if(i == n-1)   ans[i] = (arr[n-2]+arr[n-1])/2;
        else{
            ans[i] = (arr[i-1]+arr[i]+arr[i+1])/3;
        }
    }
    for(int i = 0; i < n; i++){
        if(i != n-1) cout << ans[i] << " ";
        else cout << ans[i];
    }
    return 0;
}