#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 100000000;
#define LL long long;
struct family{
    int id;
    int areas;
    int sets;
    int number;
    double aveS;
    double aveA;
    family(){
        id = -1;
    }
};

typedef struct family family;

vector<int> father(10000),areas(10000),sets(10000);
vector<family> familyProperty(10000);

bool visited[10000];

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

    if(faA < faB){
        father[faB] = faA;

    }

    else if(faA > faB){
        father[faA] = faB;
    }



}

int cmp(family a,family b){
    if(a.aveA != b.aveA){
        return a.aveA > b.aveA;
    }
    else{
        return a.id < b.id;
    }
}

int main()
{

    int n;
    scanf("%d",&n);

    for(int i=0;i<10000;i++){
        father[i] = i;
    }

    for(int i=0;i<n;i++){


        int id,father,mother;
        scanf("%d%d%d",&id,&father,&mother);
        visited[id] = true;


        if(father!=-1){
            Union(id, father);
            visited[father] = true;
        }
        if(mother!=-1){
            Union(id, mother);
            visited[mother] = true;
        }
        int num;
        scanf("%d",&num);

        for(int j=0;j<num;j++){
            int child;
            scanf("%d",&child);

                Union(id, child);
                visited[child] = true;


        }
        double are,se;
        scanf("%lf%lf",&se,&are);
        areas[id] = are;
        sets[id] = se;

    }

    for(int i=0;i<10000;i++){
        if(visited[i]){
            int id = findFather(i);
            familyProperty[id].id = id;
            familyProperty[id].number++;
            familyProperty[id].areas += areas[i];
            familyProperty[id].sets += sets[i];
        }
    }

    int count=0;
    for(int i=0;i<10000;i++){
        if(familyProperty[i].id!=-1){
            count++;

            familyProperty[i].aveA = (double(familyProperty[i].areas))/familyProperty[i].number;
            familyProperty[i].aveS = (double(familyProperty[i].sets))/familyProperty[i].number;

        }
    }
    sort(familyProperty.begin(),familyProperty.end(),cmp);

    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%04d %d %.3f %.3f\n",familyProperty[i].id,familyProperty[i].number,familyProperty[i].aveS,familyProperty[i].aveA);
    }


    return 0;
}
