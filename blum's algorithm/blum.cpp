#include<bits/stdc++.h>
using namespace std;
int blum(int *a,int c,int d,int k)
{
    int n=(d-c);
    if(n<=80)
    {
    sort(a+c,a+d);
    return a[(c+d)/2];
    }
    int b[(n/5)+1][5];
    int medians[(n/5)+1];
    for(int i=c;i<n;i++)
    {
        b[i/5][i%5]=a[i];
    }
    for(int i=0;i<n;i+=5)
    {
        if(i<n-5)sort(b[i/5],b[i/5]+5);
        else sort(b[i/5],b[i/5]+(n-i));
    }
    for(int i=c;i<n;i++)
    {
        if(i%5==2)medians[i/5]=b[i/5][i%5];
    }
    int m=(n%5>=2)?blum(medians,c,(n/5)+1,((n/5)+1)/2):blum(medians,c,(n/5),((n/5))/2);
    int i=c;
    int j=d;
    while(j>=i)
    {
    if(a[i]<m)i++;
    if(a[j]>=m)j--;
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
    }
    if(j==k){return a[j];}
    if(j<k){return blum(a,c,d-j,k);}
    else {return blum(a,j,d,j-k);}



}
int main()
    {

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<blum(a,0,n,(n/2));
}

