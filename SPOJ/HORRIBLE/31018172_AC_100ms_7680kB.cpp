#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N=1<<18;
struct bitRange{
    ll m[N],c[N];
    void init()
    {
        memset(m,0,sizeof m);
        memset(c,0,sizeof c);

    }
    void add(int pos,ll mVal,ll cVal)
    {
        for(++pos;pos<=N;pos+=(pos&(-pos)))
        {
            m[pos-1]+=mVal;
            c[pos-1]+=cVal;
        }
    }
    ll get(int pos)
    {
        ll ret=0;
        int x=pos;
        for(pos++;pos;pos-=(pos&(-pos))) {
            ret += m[pos - 1] * x + c[pos - 1];
        }
        return ret;
    }
    void addRange(int l,int r,ll val)
    {
        add(l,val,-val*(l-1));
        add(r+1,-val,val*r);

        /*
          add(m, l, val)
          add(m, r+1, -val)
          add(c, l, -val*(l-1))
          add(c, r+1, val*r)
         */
    }

}bit;
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        bit.init();
        while(c--)
        {
            int typ,l,r,val;
            cin>>typ;
            if(!typ)
            {
                cin>>l>>r>>val;
                if(l>r)
                    swap(l,r);
                bit.addRange(l,r,val);
            }
            else
            {
                cin>>l>>r;
                if(l>r)
                    swap(l,r);
                cout<<bit.get(r)-bit.get(l-1)<<endl;
            }
        }
    }

}
