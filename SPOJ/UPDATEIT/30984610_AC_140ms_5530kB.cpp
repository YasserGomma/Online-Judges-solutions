#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N=1<<14;
struct BIT{
    int tree[N];
    void init()
    {
        memset(tree,0,sizeof tree);
    }
    void add(int pos,int val)
    {
        for(++pos;pos<=N;pos+=(pos&(-pos)))
            tree[pos-1]+=val;
    }
    int get(int pos)
    {
        int ret=0;
        for(++pos;pos;pos-=(pos&(-pos)))
            ret+=tree[pos-1];
        return ret;

    }
}bit;

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,u;
        cin>>n>>u;
        bit.init();
        while(u--)
        {
            int l,r,val;
            cin>>l>>r>>val;
            if(l>r)
                swap(l,r);
            l++,r++;
            bit.add(l,val);
            bit.add(r+1,-val);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int i;
            cin>>i;
            i++;
            cout<<bit.get(i)<<endl;
        }
    }


}
