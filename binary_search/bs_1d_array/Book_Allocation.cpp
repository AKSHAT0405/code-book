#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canAllocate(vector<int>& nums,long long limit, int m ) {
        long sum = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= limit){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];  
            }
        }
        if(count <= m){
            return true;
        }
        return false;
    }

public:
    int brute(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = *min_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end(),0);
        for(int i = low; i < high; i++){
            if(canAllocate(nums , i , m)){
                return i;
            }
        }
        return -1;
    }
    int optimal(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = *min_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end(),0);
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canAllocate(nums, mid , m)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    int n, m;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> pages(n);

    cout << "Enter pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    Solution obj;

    cout << "Brute: " << obj.brute(pages, m) << endl;
    cout << "Optimal: " << obj.optimal(pages, m) << endl;

    return 0;
}
// let Z = high - low
// brute : tc - O(n * Z) m sc - O(1)
// brute : tc - O(n*log2Z) m sc - O(1)