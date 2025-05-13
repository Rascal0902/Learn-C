#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int count=0;
struct parse{
     int x;
     int y;

     parse(int a,int b){
          x=a;
          y=b;
     }
};
int test;
int main(){
   scanf("%d",&test);
   
   int n,m,ipt;
   for(int i=0 ; i<test ; i++){
        scanf("%d %d",&n,&m);
        count = 0;
        priority_queue<int> p;
        queue<parse> q;
        for(int j=0;j<n;j++){
           scanf("%d",&ipt);
           q.push(parse(j,ipt));
           p.push(ipt);
        }

        while(!q.empty()){
            int index = q.front().x;
            int value = q.front().y;
            q.pop();

            if(p.top() == value){
                p.pop();
                ++count;
                if(index == m){
                    printf("%d\n",count);
                    break;
                }
            }
            else{q.push(parse(index,value));}
        }
   }
}