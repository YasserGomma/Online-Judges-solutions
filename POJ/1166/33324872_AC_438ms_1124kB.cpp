/*
 TASK: clocks
 LANG: C++11
 */
#include<cstdio>
using namespace std;
typedef long long ll;
char *moves[]=  { "ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int vis[1<<18],sol[1<<5],vid;
bool dfs(int u,int st,int mx)
{
    if(vis[u]==vid )return 0;
    if(!u)return 1; //mask becomes 000000000000000000
    if(!mx)return 0;
    vis[u] = vid;
    for(int i=st;i<9;i++)
    {
        int v=u;
        for (char *curCap = moves[i]; *curCap;curCap++)
        {
            int id=*curCap-'A'; // current clock (we will change its state)
            int curState=(v>>(2*id))&3; // curent state of current clock
            v&=~(3<<(2*id)); // delete current state of current clock
            curState=++curState&3; // move curent state to the next state
            v|=(curState<<(2*id)); // set curent clock with the new state

        }
        sol[mx-1]=i+1; // save solution
        if (dfs(v, i ,mx - 1)) return 1;
    }
    return 0;
}
int main() {
    int u=0,curClock;
    for(int i=0;i<9;i++)
    {
        scanf("%d",&curClock);
        u|=curClock<<(2*i);
    }

    int mx;
    for(mx=0,++vid;!dfs(u,0, mx);++vid,++mx);

    while(mx--)
        printf("%d%c",sol[mx]," \n"[!mx]);



}
