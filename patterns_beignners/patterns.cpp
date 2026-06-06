#include<iostream>
using namespace std;
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n)

{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    int x = 0;
    int y = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                cout << x;
                x = 1 - x;
            }
            else
            {
                cout << y;
                y = 1 - y;
            }
        }
        cout << endl;
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // normal iteration till 4
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        // spaces by relation between iteration and spaces
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  "; // two spaces here
        }
        // reverse loop form 1
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}
void print14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char x = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << x;
            x++;
        }
        cout << endl;
    }
}
void print16(int n)
{
    char x = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << x;
        }
        x++;

        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        int breakpoint = (2 * i + 1) / 2;
        char c = 'A';
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << c;
            if (j <= breakpoint)
                c++;
            else
                c--;
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print18(int n)
{
    char ch = 'A' + n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (ch = 'A' + n - i; ch <= 'A' + n - 1; ch++)
        {
            cout << ch << " ";
        }
        ch--;
        cout << endl;
    }
}
void print19(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j < 2 * i + 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j < 2 * n - 2 * i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print20(int n)
{
    int space = 2 * n - 2;
    int nspace = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        space -= 2;
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            cout << "*";
        }
        for (int j = nspace; j >= 1; j--)
        {
            cout << " ";
        }
        for (int j = n - i; j >= 1; j--)
        {
            cout << "*";
        }
        nspace += 2;
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n - 1 || i == 0 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min(min(top, down), min(left, right))) << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    print22(n);
    print21(n);
    print20(n);
    print19(n);
    print18(n);
    print17(n);
    print16(n);
    print14(n);
    print13(n);
    print12(n);
    print11(n);
    print10(n);
    print9(n);
    print7(n);
    return 0;
}