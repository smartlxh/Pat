#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 100000000;
#define LL long long;
vector<vector<int>> Graph(100000);
bool visited[100000];
int N;
double P;
double R;

int level;
int ans;

void Bfs(){

    queue<int> q;
    q.push(0);
    int newLastNode=0,lastNode=0;
    bool flag = false;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        if(Graph[temp].size() == 0){

            ans++;
            flag = true;

        }
        else{

            for(int i=0;i<Graph[temp].size();i++){
                q.push(Graph[temp][i]);
                newLastNode = Graph[temp][i];
            }
        }

        if(temp == lastNode){
            lastNode = newLastNode;

            level++;
            if(flag == true) {return;}

        }
    }
}
int main()
{

    scanf("%d%lf%lf",&N,&P,&R);

    for(int i=0;i<N;i++){
        int k;
        scanf("%d",&k);
        for(int j = 0;j<k;j++){
            int temp;
            scanf("%d",&temp);
            Graph[i].push_back(temp);
        }
    }

    Bfs();
    printf("%.4f %d",pow(1+R/100,level-1)*P,ans);

    return 0;
}
