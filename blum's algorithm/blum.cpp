#include<bits/stdc++.h>
using namespace std;
int main()
    {
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    }
    int b[5][(n/5)+1];
    int medians[(n/5)+1];
    for(int i=0;i<n;i++)
    {
        b[i%5][i/5]=a[i];
        if(i%5==2)medians[i/5]=a[i];
    }
    int m=(n%5>=2)?blum(medians,0,(n/5)+1,((n/5)+1)/2):blum(medians,0,(n/5),((n/5))/2)


}
int blum(int *a,int a,int c,int k)
{
    int b[5][(n/5)+1];
    int medians[(n/5)+1];
    for(int i=a;i<b;i++)
    {
        b[i%5][i/5]=a[i];
        if(i%5==2)medians[i/5]=a[i];
    }
    int m=(n%5>=2)?blum(medians,0,(n/5)+1,((n/5)+1)/2):blum(medians,0,(n/5),((n/5))/2)





}
