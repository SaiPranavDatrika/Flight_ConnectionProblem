/*Flight Connection Solution:

Link to the problem statement:
https://www.codingninjas.com/codestudio/problem-details/flight-connections_625702

n number of cities (numbered from 1 to n) are connected by m number of 2-way flights. Connectivity factor of a city is calculated as, the number of cities which are reachable from that city. Two cities i and j are reachable, if you can reach from city i to j via direct or sequence of any number of flights.
Overall connectivity factor is sum of connectivity factors of all cities.
After few years, due to some financial crisis, 2 flights needs to shut down. We need to shut down the flights such that overall connectivity factor is maximized.
Given the details of flights (without any shut down), you need to find and print the updated overall connectivity factor after 2 shut downs, which is maximum.
Note : All Pairs Of Cities Don't Have To Be Reachable After Shut Down Of Flights.*/



Solution:

#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
    long int V;
    long int oc=0;
    long int *color;
    long int *par;  
    long int cyclenumber=0;
    list<long int> *adj;
    long int count=0;
    long int f_count=2;
    map<long int,long int> mp;
    Graph(long int x);
    void addedge(long int u,long int v);
    void dfs_cycles(long int u,long int p);
    void dfs_oc_aftershutdown(long int u,long int p);
};
Graph::Graph(long int x){
    this->V=x+1;
    adj=new list<long int>[500001];
    color=new long int[500001];
    par=new long int[500001];
}
void Graph::dfs_cycles(long int u,long int p){
    if(color[u]==2)
    {return;}      
    if(color[u]==1){
        cyclenumber++;      
        return;
    }
    count++;
    par[u]=p;
    color[u]=1;
    list<long int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i){
       if(*i==par[u]){
          continue;}
          dfs_cycles(*i,u);
    }
    color[u]=2; 
}

void Graph::addedge(long int u,long int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::dfs_oc_aftershutdown(long int u,long int p){
 
    list<long int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++){
        if(*i==p)
          {continue;}
         if(mp[*i]>0 && adj[u].empty()==false)
            { oc=oc-1;mp[*i]=mp[*i]-1;}
            dfs_oc_aftershutdown(*i,u);
    }
}
bool cmp(pair<long int,long int>& a,
         pair<long int,long int>& b)
{
    return a.second<b.second;
}
vector<pair<long int,long int>> sort(map<long int,long int>& M)
{
    vector<pair<long int,long int>> A;
      for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    return A;
}
  
int main() {
	long int n;
	cin>>n;
	long int m;
	cin>>m;
	long int a;
	long int b;
	Graph g1(n);
	for(long int i=0;i<m;i++){
	    cin>>a;
	    cin>>b;
	    g1.addedge(a,b);
	}
	
	for(long int i=1;i<=n;i++){
	    if(g1.color[i]!=2 && g1.adj[i].empty()==false)
	    { g1.dfs_cycles(i,0);
	        for(long int i=1;i<=n;i++){
	         if(g1.color[i]==2)
             { g1.mp.insert({i,g1.count-1});}
	     }
	    g1.oc+=(g1.count-1)*(g1.count);
	     g1.count=0;}	    
	}

   g1.f_count-=g1.cyclenumber;
vector<pair<long int,long int>> vc;
    vc=sort(g1.mp);
    if(g1.f_count>0){
       for (auto& it : vc) {
           if(g1.f_count>0){
            g1.oc=g1.oc-it.second;it.second=0;
            long int u=it.first;
            g1.dfs_oc_aftershutdown(u,0);
            g1.f_count--;
        }
        else
          break;
    }
    }
	cout<<g1.oc;
	return 0;
}

