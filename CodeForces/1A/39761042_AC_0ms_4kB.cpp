    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long n,m,a;
        cin>>n>>m>>a;

        long long w=n/a;
        long long h=m/a;

        if(n%a!=0)
            w++;
        if(m%a!=0)
            h++;

        cout<<w*h;

    }

