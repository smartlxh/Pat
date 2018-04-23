#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<set>
#define ll long long
using namespace std;

vector<int> tempPath;
vector<int> ansPath;
vector<int> data;
int N,P,K;
int maxSum;

void init(){
    int temp = 0;
    int index = 1;
    while(temp<=N){
        data.push_back(temp);
        temp = pow(index,P);
        index++;
    }
}

void Dfs(int index,int curSum,int num,int indexSum){

    if(num == K && curSum ==N && indexSum > maxSum){
        ansPath = tempPath;

        maxSum = indexSum;
        return ;
    }

    if(curSum > N || num > K)
        return ;

    if(index>=1){
        tempPath.push_back(index);
        Dfs(index,curSum+data[index],num+1,indexSum+index);
        tempPath.pop_back();
        if(index>1)
        Dfs(index-1,curSum,num,indexSum);

    }
}

int main()
{
    maxSum = -1;
    scanf("%d%d%d",&N,&K,&P);
    init();
    Dfs(data.size()-1,0,0,0);
    if(maxSum == -1){
        printf("Impossible");
        return 0;
    }
    else{
        printf("%d = ",N);
        for(int i = 0;i<ansPath.size();i++){
            printf("%d^%d",ansPath[i],P);
            if(i!=ansPath.size()-1)
                printf(" + ");
        }
    }
    return 0;
}
