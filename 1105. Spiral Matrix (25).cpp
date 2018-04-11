#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 100000000;
vector<int> data;
bool visited[1000][1000];
int matrix[1000][1000];

int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int turn = 0;
int main()
{
    int input = 0;
    scanf("%d",&input);
    int m=0,n=0;

    for(int i = (int)sqrt(input);i<=input;i++){
        if((input % i) == 0){
            m = i;
            n = input/i;
            if(m < n){
                m = input/i;
                n = i;
            }
            break;
        }
    }

    for(int i=0;i<input;i++){
        int temp;
        scanf("%d",&temp);
        data.push_back(temp);
    }

    sort(data.begin(),data.end(),greater<int>());

    int row=0,column=0;
    int count = 1;
    turn = 0;
    matrix[row][column] = data[0];
    visited[row][column]=true;
    while(count!=input){

        if(turn == 0){
            if(column < n-1 && !visited[row][column+1]){
                column++;
                matrix[row][column] = data[count];
                count++;
            }
            else {
                turn = (turn+1) % 4;
                continue;
            }

        }
        else if(turn==1){
            if(row < m-1 && !visited[row+1][column]){
                row++;
                matrix[row][column] = data[count];
                count++;
            }
            else {
                turn = (turn+1) % 4;
                continue;
            }

        }
        else if(turn == 2){

            if(column > 0 && !visited[row][column-1]){
                column--;
                matrix[row][column] = data[count];
                count++;
            }
            else {
                turn = (turn+1) % 4;
                continue;
            }

        }

        else {

            if(row > 0 && !visited[row-1][column]){
                row--;
                matrix[row][column] = data[count];
                count++;
            }
            else {
                turn = (turn+1) % 4;
                continue;

            }

        }

       // cout<<count<<endl;
        visited[row][column] = true;

    }

    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            printf("%d",matrix[i][j]);
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
