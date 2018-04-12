#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 100000000;
#define LL long long;
vector<int> father,cource,isRoot;

int findFather(int x){
    int a = x;

    while(x!=father[x]){
        x = father[x];
    }

    while(a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void Union(int a,int b){

    int faA = findFather(a);
    int faB = findFather(b);
    father[faA] = faB;

}


int main()
{

    int n;
    scanf("%d",&n);
    father.resize(n+1);
    isRoot.resize(n+1);
    cource.resize(1001);
    for(int i=1;i<=n;i++){
        father[i] = i;
    }
    for(int i=1;i<=n;i++){

        int k;
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            int temp;
            scanf("%d",&temp);
            if(cource[temp] == 0)
                cource[temp] = i;
            else{
                Union(i, findFather(cource[temp]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]++;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(isRoot[i] != 0)
            count++;
    }
    sort(isRoot.begin(),isRoot.end(),greater<int>());
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d",isRoot[i]);
        if(i!=count-1)
            printf(" ");
    }

    return 0;
}
