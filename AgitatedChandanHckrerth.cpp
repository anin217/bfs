#include <bits/stdc++.h>

using namespace std;

int vis[100050];
int arr[100050];
int dist[100005];
vector<pair<int,int> > v[100005];


int sum=0;
int n;
int bfs(int st)
{
    vector<pair<int,int> > :: iterator it;
    queue <int> q;
    q.push(st);
  //  cout<<"pushing "<<st<<endl;

        vis[st]=1;
    int x=st;
    while(!q.empty())
    {

        x=q.front();
       q.pop();
       //cout<<"popping "<<x<<endl;
       for(it=v[x].begin();it!=v[x].end();it++)
       {
           if(!vis[it->first])
           {
               vis[it->first]=1;

               int ff=it->first;
               int ss=it->second;
               dist[ff]+=dist[x]+ss;
               //cout<<"dist at "<<it->first<<" is "<<dist[it->first]<<endl;
               q.push(it->first);
               //cout<<"pushing "<<it->first<<endl;
           }
       }
    }
    return int(max_element(dist+1,dist+n+1)-dist);
}

int main()
{
    int t,i,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;


        for(i=0;i<n-1;i++)
        {cin>>a>>b>>c;

        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));}

        int x=bfs(1);
        //cout<<x<<endl<<endl;

        for(i=0;i<=n;i++)
        {
            vis[i]=0;
            dist[i]=0;
        }
        //q.clear();

        int res=bfs(x);
        int ans=dist[res];
        int mn=0;
        if(ans>100)
            mn=100;
        if(ans>1000)
            mn=1000;
        if(ans>10000)
            mn=10000;

        cout<<mn<<" "<<ans<<endl;

        for(i=0;i<=n;i++)
            v[i].clear();


    }

}
