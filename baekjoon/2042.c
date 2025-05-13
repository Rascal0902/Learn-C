#include<stdio.h>
typedef long long ll;
int N,M,K;
ll a[1000005],tree[10000000]={0};
ll init(int node,int start, int last){
     if(start == last){
        return tree[node]= a[start];
     }
     else{
        int mid = (start+last)/2;
        return tree[node] = init(2*node,start,mid)+init(2*node+1,mid+1,last);
     }
}
void update(int node, int start, int last, int loc, ll diff){
    if(loc < start || loc > last){return;}
    tree[node]+=diff;
    if(start == last){return;}
    int mid = (start+last)/2;
    update(node*2,start,mid,loc,diff);
    update(node*2+1,mid+1,last,loc,diff);
}
ll sum(int node, int start, int last, int left, int right){
    if(left > last || right < start){return 0;}
    if(left <= start && last <= right){return tree[node];}
    int mid = (start+last)/2;
    return sum(node*2,start,mid,left,right)+sum(node*2+1,mid+1,last,left,right);
}
int main(){
   scanf("%d %d %d",&N,&M,&K);

   for(int i=0;i<N;i++){
     scanf("%lld",&a[i]);
   }
   init(1,0,N-1);

   int x,y;
   ll z;
   for(int i=0;i<M+K;i++){
      scanf("%d %d %lld",&x,&y,&z);
      if(x==1){
        ll diff =z-a[y-1];
        a[y-1] = z;
        update(1,0,N-1,y-1,diff);
      }
      if(x==2){
        printf("%lld\n",sum(1,0,N-1,y-1,z-1));
      }
   }
}