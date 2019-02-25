##图

Dijstra

```
void Dijstra(int src){
    //init
    for(int i=0;i<N;i++){
        if(Graph[src][i]>0){
            dist[i]=Graph[src][i];
        }
        else{
            dist[i]=INF;
        }
    }
    visited[src]=true;
    dist[src]=0;

    // n次循环
    for(int i=0;i<N;i++){

        // find the min dist
        int index=0;
        int minValue=INF;
        for(int j=0;j<N;j++){
            if(!visited[j]&&dist[j]<minValue){
                minValue = dist[j];
                index = j;
            }
        }
        // update
        visited[index]=true;
        for(int k=0;k<N;k++){
            if(!visited[k]&&Graph[index][k]>0&&dist[k]>dist[index]+Graph[index][k]){
                dist[k] = dist[index]+Graph[index][k];
            }
        }
    }
}


```

Floyed
```
void Floyd(){

    for(int k=0;k<N;k++){
        for(int i=0;k<N;k++){
            for(int j=0;j<N;j++){
                if(Graph[i][k]!=INF && Graph[k][j]!=INF){
                    if(Graph[i][k]+Graph[k][j] < Graph[i][j]){
                        Graph[i][j]=Graph[i][k]+Graph[k][j];
                    }
                }

            }
        }
    }
}


```


DFS
dfs 求连通分量
```

void dfs(int src){
    visited[src]=true;
    for(int i=0;i<N;i++){
        if(!visited[i] && Graph[src][i]>0){
            dfs(src);
        }
    }
}

int main(){

    int num=0;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i);
            num++;
        }
    }
}

```

dfs 搜索并保存路径

```
vector<int> path,result;
//path 保存临时路径，result 最终路径
void dfs1(int src,int dest,int curValue){

    visited[src]=true;
    if(src==dest){
        if(curValue==dist[dest]){
            result = path;
        }
    }
    else if(curValue > dist[dest]) return ;
    else{
        for(int i=0;i<N;i++){
            if(!visited[i] && Graph[src][i]>0){
                path.push_back(Graph[src][i]);
                dfs1(i,dest,curValue+weight[src][i]);
                path.pop_back();// 一定要pop 出来，这样才能遍历所有的可能路径
                visited[i]=false;
            }
        }
    }
}


```
BFS

```
void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src]=true;
    int lastNode = src;
    int newLastNode = src;
    int level=0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        visited[temp]=true;
        for(int i=0;i<N;i++){
            if(!visited[i]&&Graph[temp][i]>0){
                q.push(i);
                newLastNode = i;
            }

        }
        if(temp==lastNode){
            lastNode = newLastNode;
            level++;
        }
    }
}


```
