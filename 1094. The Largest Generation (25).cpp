#include<iostream>
#include<cstdio>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
#define INF 100000000;

vector<int> pedigree[100];
int N,M;

int maxLevel;
int maxAns;

void Bfs(int src){
    queue<int> q;
    q.push(src);
    int level = 0;
    int newLastNode = src;
    int lastNode = src;
    int count = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        count++;
        for(int i=0;i<pedigree[temp].size();i++){
            q.push(pedigree[temp][i]);
            newLastNode = pedigree[temp][i];
        }
        if(temp == lastNode){
            level++;
            lastNode = newLastNode;
            if(count > maxAns){
                maxAns = count;
                maxLevel = level;
            }
            count = 0;
        }
    }
}

int main(int agrc,char **argv){

    scanf("%d%d",&N,&M);

    for(int i=0;i<M;i++){
        int parent ;
        scanf("%d",&parent);
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int child ;
            scanf("%d",&child);
            pedigree[parent].push_back(child);
        }
    }
    Bfs(1);

    printf("%d %d",maxAns,maxLevel);

    return 0;
}
