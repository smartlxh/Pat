## 并查集
```

void init(){
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
}

int findFather(int x){
    int a = x;
    while(x!=parent[x]){
        x = parent[x];
    }
    while(a!=parent[a]){
        int temp = a;
        a = parent[a];
        parent[temp]=x;
    }
    return x;
}
void Unionf(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) parent[faA] = faB;
}


int main(){
    
    for(int i=0;i<N;i++){
        isRoot[findFather(i)]++;// 统计 并查集元素的个数    
    }

    for(int i=0;i<N;i++){
      if(isRoot[i]!=0) num++; 统计并查集的个数
    }
}

```
