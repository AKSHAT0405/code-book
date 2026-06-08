#include <bits/stdc++.h>
using namespace std;

void countNo(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        cnt = cnt + 1;
        n = n / 10;
    }
    cout << "no of digits : " << cnt;
}

int main()
{
    int n;
    cin >> n;
    countNo(n);
    return 0;
}