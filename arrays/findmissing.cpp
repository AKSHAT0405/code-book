#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums , int n)
    {
        for (int i = 1; i <= n; i++)
        {
            int flag = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return i;
            } 
        }
        return -1;
    }
    int better(vector<int>& nums , int n){
        int N = n+1;
        int hashArr[N+1] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            hashArr[nums[i]] = 1;
        }
        for (int j = 1; j <= N; j++)
        {
            if(hashArr[j] == 0){
                return j;
            }
        }
        return -1;
    }
    int optimal_sum(vector<int>& nums , int n){
        int sum = n*(n+1)/2;
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
        }

        int missing = sum - s;
        return missing;
    }
    int optimal_xor(vector<int>& nums , int n){
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xor1 = xor1^(i+1);
            xor2 = xor2^nums[i];
        }
        xor1 = xor1^(n);
        int missing = xor1^xor2;
        return missing;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    int N = nums.size() + 1;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    // int missing = obj.brute(nums , N);
    // int missing = obj.better(nums , N);
    // int missing = obj.optimal_sum(nums , N);
    int missing = obj.optimal_xor(nums , N);

    cout << "Missing number: " << missing << endl;

    return 0;
}

//  brute : tc = o(n^2) , sc = o(1) , i was confused in size and iterator here 
//  better : tc = o(2n) , sc = o(n) , here too the n usage confused me . 
// optimal_sum : tc = o() , sc = o() , good solution but downfall is integar size and sum value conflict. 
// optimal_xor : tc = o() , sc = o() , new to me , bitwise manipulation introduced , xor of same number ( a^a = 0)
// here the n is the value till which we have numbers like 1,n can have something missing . eg. n = 5 but nums.size = 4