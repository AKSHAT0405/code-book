#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double multiply(double number , int n){
        double ans = 1.0;
        for(int i = 0; i < n; i++){
            ans = ans*number;
        } 
        return ans;
    }

    double optimal(int n, int m)
    {
        double low = 1;
        double high = m;
        double eps = 1e-6;
        while ((high - low )> eps)
        {
            double mid = low + (high - low)/2.0;
            // long long prod = 1;
            // for(int i = 0; i < n; i++){
            //     prod = mid*prod;
            // } -- or multiply function
            if(multiply(mid,n) < m){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};

int main()
{
    int n, m;

    cout << "Enter n (root): ";
    cin >> n;

    cout << "Enter m (number): ";
    cin >> m;

    Solution obj;

    double result = obj.optimal(n, m);


    cout << "Nth root: " << result << endl;

    return 0;
}

// optimal : tc - O(N * log2(M*10^T)) , sc - O(1) 
// here M is the number whose root we have to find , N is the Nth number 
// T is the eps limit upto which we precisely find the number in double
// example the 1 and 2 have 10 number from 1.0 , 1.1 to 2.0 so 
// total of 10 between these 2 also counted in binary search 