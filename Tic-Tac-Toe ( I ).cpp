/**
*Author:Ahmed Elafifi / getting help from video made by Ayman Salah
*date : 3/9/2018
*category : BFS
*/
#include <bits/stdc++.h>

using namespace std;
int t;
string bord;
///012
///345
///678
bool is_win(string b)
{
    bool row = (b[0] != '.'&&b[0] == b[1]&&b[1] == b[2])||
                (b[3] != '.' && b[3] == b[4] && b[4] == b[5])||
                (b[6] != '.' && b[6] == b[7] && b[7] == b[8]);

    bool col =  (b[0] != '.'&&b[0] == b[3]&&b[3] == b[6])||
                (b[1] != '.' && b[1] == b[4] && b[4] == b[7])||
                (b[2] != '.' && b[2] == b[5] && b[5] == b[8]);

    bool diag = (b[0] != '.'&&b[0] == b[4]&&b[4] == b[8])||
                (b[2] != '.' && b[2] == b[4] && b[4] == b[6]);

    return row||col||diag;
}

bool BFS()
{
    string start = ".........";
    queue< pair<string,bool> >q;
    q.push({start,1});
    while(!q.empty())
    {
        string cur = q.front().first;
        bool cur_player = q.front().second;
        q.pop();
        if(cur == bord)return true;
        if(is_win(cur))continue;
        for(int i= 0;i<9;i++)
        {
            if(cur[i]=='.')
            {
                cur[i] = (cur_player?'X':'O');
                if(cur[i] == bord[i])
                    q.push({cur,1^cur_player});
                cur[i] = '.';
            }
        }
    }
    return false;

}
int main()
{
scanf("%d",&t);
while(t--)
{
    bord = "";
    for(int i = 0;i<3;i++) {
    string s;
    cin>>s;
    bord += s;
    }
    bool good = BFS();
    cout<<(good?"yes":"no")<<endl;
}
    return 0;
}
