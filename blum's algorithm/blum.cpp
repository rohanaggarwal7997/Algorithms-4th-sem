#include<bits/stdc++.h>
using namespace std;
int blum(int *a,int c,int d,int k)
{
    int n=(d-c)+1;
    if(n<=3)
    {
    sort(a+c,a+d+1);
    return a[k-1];
    }
    int b[(n/5)+1][5];
    int medians[(n/5)+1];
    for(int i=0;i<n;i++)
    {
        b[i/5][i%5]=a[i+c];
    }
    for(int i=0;i<n;i+=5)
    {
        if(i<n-5)sort(b[i/5],b[i/5]+5);
        else sort(b[i/5],b[i/5]+(n-i));
    }
    for(int i=0;i<n;i++)
    {
        if(i%5==2)medians[i/5]=b[i/5][i%5];
    }
    int m=(n%5>=2)?blum(medians,0,(n/5),((n/5)+1)/2):blum(medians,0,(n/5)-1,((n/5))/2);
    cout<<"median"<<m<<endl;
     int i;
     for(i=c;i<=d;i++)
    {
        if(a[i]==m)break;
    }
    int t=a[c];
    a[c]=a[i];
    a[i]=t;
    for(int i=c;i<=d;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
     i=c+1;
    int j=d;
    while(j>=i)
    {
    while(a[i]<m)i++;
    while(a[j]>=m)j--;
    if(i<j)
    {int t=a[i];
    a[i]=a[j];
    a[j]=t;
    i++;j--;
    }
    }
     t=a[c];
     a[c]=a[j];
     a[j]=t;
    for(int i=c;i<=d;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<j<<endl;
    if(j+1==k){
            cout<<"returning"<<a[j]<<endl;
            return a[j];}
    if(j+1>=k){
        cout<<"calling blum"<<c<<"  "<<j-1<<"  "<<k<<endl;
        int p=blum(a,c,j,k);
        cout<<"returning"<<p<<endl;
        return p;}
    else {
        cout<<"calling blum"<<j+1<<"  "<<d<<"  "<<k<<endl;
        int p=blum(a,j+1,d,k);
        cout<<"returning"<<p<<endl;
        return p;}



}
int main()
    {
    while(1)
    {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<"calling blum"<<0<<"  "<<n-1<<"  "<<4<<endl;
    cout<<blum(a,0,n-1,k);
    }
}
