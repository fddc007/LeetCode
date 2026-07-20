/*
https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
*/


#include<iostream>

using namespace std;

int tmp[6] = {0};
int arr[6] = {1,3,5,2,4,6};
int len = 6;

long long merge(int l,int r,int m)
{
    int left = l;
    int right = m+1;
    int i = l;
    long long x = 0;
    long long  sum = 0;
    while(left<=m && right <= r)
    {
        // tmp[i++] = arr[left] <= arr[right]?arr[left++]:arr[right++];
        if(arr[left]<=arr[right])
        {
            x += arr[left];
            tmp[i++] = arr[left++];
        }
        else
        {
            sum += x;
            tmp[i++] = arr[right++];
        }
    }
    while (left <= m)
    {
        tmp[i++] = arr[left++];
    }
    while(right <= r)
    {
        sum += x;
        tmp[i++] = arr[right++];
    }
    for(int i = l;i<=r;i++)
    {
        arr[i] = tmp[i];
    }

    return sum;
    
}


long long solve(int l,int r)
{
    if(l == r)
    {
        return 0;
    }
    int sum = 0;
    int m = l + ((r-l)>>1);
    sum = solve(l,m) + solve(m+1,r) + merge(l,r,m);
    return sum;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // while(cin >> len)
    // {
    //     for(int i = 0;i<len;i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     cout << solve(0,len-1)<<'\n';
    // }
    cout<<solve(0,len-1);

    return 0;
}