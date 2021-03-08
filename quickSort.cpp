#include <iostream>
#include <string>
using namespace std;
void quickSort(int p[], int l, int r)
{
    if(l>=r)
    {
        return;
    }

    int mid = p[l+r>>1];
    int i=l-1,j=r+1;
    while(i<j)
    {
        do{i++;} while(p[i]<mid);
        do{j--;} while(p[j]>mid);
        
        if(i<j)
        {
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
        }
        
    }
    quickSort(p,l,j);
    quickSort(p,j+1,r);
    
}

int main()
{
    int n;
    cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    quickSort(p,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}
