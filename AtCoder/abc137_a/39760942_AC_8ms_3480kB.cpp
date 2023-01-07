    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int a,b;
        cin>>a>>b;
        int mul=a*b;
        int sum=a+b;
        int sub=a-b;
        int mx=0;
        if(mul>=sum and mul>=sub)
            mx=mul;
        else if(sum>=mul and sum>=sub)
            mx=sum;
        else
            mx=sub;
        cout<<mx;
    }
