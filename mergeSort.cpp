#include <iostream>
using namespace std;

int q[100010];
int n;

//双指针算法合并
void merge(int q[], int l1, int l2, int r1, int r2)
{
    int i = l1, j = l2;
    int *m = new int[r1-l1+r2-l2+2];//使用辅助数组存放合并后的结果
    int m_ptr = 0;
    while( i<= r1 && j<= r2)
    {
        if(q[i]<=q[j])
        {
            m[m_ptr] = q[i];
            i++;
            m_ptr++;
        }
        else
        {
            m[m_ptr] = q[j];
            j++;
            m_ptr++;
        }
    }
    
    if(i>r1) { while(j<=r2){m[m_ptr++] = q[j++];} }
    if(j>r2) { while(i<=r1){m[m_ptr++] = q[i++];} }
    
    
    for(int k=l1;k<r1+r2-l2+2;k++)
    {
        q[k] = m[k-l1];
    }
}

void mergeSort(int q[], int l, int r)//递归调用
{
    int mid = l+r>>1;
    if(l==r) return;
    mergeSort(q, l ,mid);
    mergeSort(q, mid+1, r);
    merge(q, l, mid+1, mid, r);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    mergeSort(q, 0 ,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<q[i]<<" ";
    }
    
}
