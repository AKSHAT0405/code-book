#include <bits/stdc++.h>
using namespace std;

void revNo(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        rev = rev * 10 + lastdigit;
        n = n / 10;
    }
    cout << "no of digits : " << rev;
}
int main()
{
    int n;
    cin >> n;
    revNo(n);
    return 0;
}