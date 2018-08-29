/**
*Algorithim: BFS
*make solution by getting help from this video :https://www.youtube.com/watch?v=dMacXPeTyak
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
set<pii>vis;
queue<pii>q;
int t,a,b,c,newA,newB,res;
void markVisited(int a,int b) {
pii state = {a,b};
if(vis.find(state) == vis.end()) {
    vis.insert(state);
    q.push(state);
}
}
int BFS() {
while(q.size())q.pop();
vis.clear();
int res = 0;
pii state = {0,0};
q.push(state);
vis.insert(state);
while(!q.empty()) {
    int sz = q.size();
    while(sz--) {
        state = q.front(),q.pop();
        if(state.first == c || state.second == c)
        {
            return res;
        }
        //fill a
        markVisited(a,state.second);
        //fill b
        markVisited(state.first,b);
        //empty a
        markVisited(0,state.second);
        //empty b
        markVisited(state.first,0);
        //from a to b
        newB = min(b,state.first + state.second);
        newA = state.first - (newB - state.second);
        markVisited(newA,newB);
        //from b to a
        newA = min(a,state.first + state.second);
        newB = state.second - (newA - state.first);
        markVisited(newA,newB);

    }
    res++;
}
return -1;
}
int main()
{
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        if(c>a&&c>b)
        {
            puts("-1");
            continue;
        }
        int ans = BFS();
        cout<<ans<<endl;
    }
    return 0;
}
