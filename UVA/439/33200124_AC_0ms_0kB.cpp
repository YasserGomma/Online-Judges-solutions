#include <bits/stdc++.h>
#include <ext/numeric>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
int vis[8][8],vid;
bool valid(int i,int j)
{
    return (i>=0 and i<8 and j>=0 and j<8);
}
int bfs(int si,int sj,int ti,int tj)
{
    ++vid;
    if(tie(si,sj)==tie(ti,tj))return 0;
    queue<pair<int,int>>q;
    q.emplace(si,sj);
    int no_steps=0;
    while(q.size())
    {
        no_steps++;
        int s=q.size();
        while (s--) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            for(int di=-1;di<2;di+=2)
                for(int dj=-1;dj<2;dj+=2)
                    for(int ii=1,jj=2,k=2;k--; swap(ii,jj))
                    {
                        int ni=i+(di*ii);
                        int nj=j+(dj*jj);
                        if(!valid(ni,nj) or vis[ni][nj]==vid)
                            continue;
                        if(tie(ni,nj)==tie(ti,tj))return no_steps;
                        vis[ni][nj]=vid;
                        q.emplace(ni,nj);

                    }

        }
    }
    return -1;
}
int main() {

    int  sj, tj;
    char si, ti;
    while (~scanf(" %c%d %c%d", &si, &sj, &ti, &tj)) {
        printf("To get from %c%d to %c%d takes %d knight moves.\n", si, sj, ti, tj,
               bfs(si - 'a', sj - 1, ti - 'a', tj - 1));
    }

}
