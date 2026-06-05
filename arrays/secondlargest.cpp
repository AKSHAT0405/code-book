#include<bits/stdc++.h>
using namespace std;
pair<int,int> getSecondOrderElements(int n, int a[])
{
    int largest=INT_MIN;
    int slargest=INT_MIN;
    int smallest = INT_MAX;
    int ssmallest=INT_MAX;

    for(int i =0;i<n;i++)
    {
        if(a[i]>largest)
        {
            slargest=largest;
            largest=a[i];
        }
        else if (a[i] < largest && a[i] > slargest)
        {
        slargest = a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<smallest)
        {
            ssmallest=smallest;
            smallest=a[i];
        }
        else if (a[i] > smallest && a[i] < ssmallest)
        {
        ssmallest = a[i];
        }
    }
    return {slargest, ssmallest};
}
int main()
{
    int n ; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    pair<int , int> result = getSecondOrderElements(n,a);
    cout<<"second largest: "<<result.first<<endl<<"second smallest: "<<result.second;

}