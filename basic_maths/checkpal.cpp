#include <bits/stdc++.h>
using namespace std;
void checkpal(int n)
{
    // palindrom check
    int dup = n; // duplicate
    int rev = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        rev = rev * 10 + lastdigit;
        n = n / 10;
    }
    if (dup == rev)
    {
        cout << "its a palindrom";
    }
    else
        cout << "not";
}
int main()
{
    int n;
    cin >> n;
    checkpal(n);
    return 0;
}