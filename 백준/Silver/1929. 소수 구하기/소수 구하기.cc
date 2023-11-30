#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N;
    cin>> M >> N;
    vector<bool> v(N+1);
    v[0]=true;
    v[1]=true;
    for(int i=2;i*i<=N;i++)
    {
        if(v[i]==false)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                v[j]=true;
            }
        }
    }
    for(int i=M;i<=N;i++)
    {
        if(v[i]==false)
        {
            cout<<i<<"\n";
        }
    }

}