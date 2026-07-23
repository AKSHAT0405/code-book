#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a,b,k;
    vector<vector<int>> arr;
    for (int m = 0; m < n; m++)
    {
        cin>>a>>b;
        arr.push_back({a,b});
    }

    cin>>k;
    for (int i = 0; i < arr.size(); i++)
    {
        if( k >= arr[i][0] && k <= arr[i][1]){
            cout<<(n-i)<<endl;
            return 0;
        }
    }
}

// codeforces problem - 1136A
