#include <bits/stdc++.h>
using namespace std;

void checkarm(int n)
{
    // check armstrong number --- a^3+b^3+c^3+....n^3 = abc...n
    int dup = n; // duplicate
    int sum = 0;
    while (n > 0)
    {
        int ld = n % 10;
        int x = 1;
        for (int i = 0; i < (int)(log10(dup) + 1); i++) // dp multiplication based on no of digit in duplicate
        {
            x = x * ld;
        }
        sum = sum + x;
        n = n / 10;
    }
    if (sum == dup)
    {
        cout << "its armstrong";
    }
    else
    {
        cout << "not an armstrong";
    }
}

int main()
{
    int n;
    cin >> n;
    checkarm(n);
    return 0;
}