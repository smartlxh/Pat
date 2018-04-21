#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<set>
using namespace std;


set<char> stuck;
int hashTable['z'+'Z'+'_'];
int sureNobroken['z'+'Z'+'_'];
string str;

int main()
{
    int k;
    scanf("%d",&k);

    cin>>str;
    for(int i=0;i<str.length();i++){

        int count = 0;
        for(int j=i;j<i+k && j<str.length();j++){
            if(str[j] == str[i]) count++;
            else break;
        }

        if(count==k){

            hashTable[str[i]] = 1;
            i+=k-1;

        }
        else {
            sureNobroken[str[i]] = 1;
        }
    }

    for(int i=0;i<str.length();i++){
        if(sureNobroken[str[i]] > 0){
            hashTable[str[i]] = 0;
        }
    }

    for(int i=0;i<str.length();i++){
        if(hashTable[str[i]] > 0 && stuck.find(str[i]) == stuck.end()){

            printf("%c",str[i]);
            stuck.insert(str[i]);
        }
    }
    printf("\n");
    for(int i=0;i<str.length();i++){
        if(hashTable[str[i]] > 0){

            printf("%c",str[i]);
            i+=k-1;
        }
        else {
            printf("%c",str[i]);
        }
    }


}
