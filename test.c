#include<stdio.h>
#include<conio.h>
void connectedPair();

void main(){
   int n, edge[50][50], w[50], i,j,move=1;
   int score_Alice,score_Bob,max=0,temp,p1,p2,w1=0,w2=0;
   char c;
   printf("enter the number of nodes in the graph:");
   scanf("%d\n",&n);
   for(i=0;i<n;i++){
       printf("enter wieght of node %d:",i+1);
       scanf("%d\n",&w[i]);
   }
   for(i=0; i<n; i++){
       for(j=0;j<n;j++){
           printf("if there is an edge between node %d and node %d then enter 1 otherwise enter 0:",i+1,j+1);
           scanf("%d\n",&edge[i][j]);
       }
   }
   if(move == 1){
       printf("The edge matrix is:\n");
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               printf("%3d ",a[i][j]);
           }
           printf("\n");
       }
       printf("Alice please enter the node number you want to break:");
       scanf("%d\n",&temp);
       score_Alice = w[temp];
       for(j=0;j<n;j++){
           edge[temp][j] = 0;
           edge[j][temp] = 0;
       }
       move++;
   }
   else if(move == 2){
       printf("The edge matrix is:\n");
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               printf("%3d ",a[i][j]);
           }
           printf("\n");
       }
       printf("Bob please enter the pair of connected nodes you want to pick\n");
       connectedPair();  
       score_Bob = w1+w2;
       move++;
   }
   else if(move == 3){
       printf("The edge matrix is:\n");
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               printf("%3d ",a[i][j]);
           }
           printf("\n");
       }
       printf("Bob please enter the pair of connected nodes you want to pick\n");
       connectedPair();  
       score_Alice = score_Alice+w1+w2;
       move++;
   }
   else{
       if(score_Alice > score_Bob)
           printf("Alice wins:- Alice score is:%d, Bob score is:%d",score_Alice,score_Bob);
       else if(score_Alice < score_Bob)
           printf("Bob wins:- Alice score is:%d, Bob score is:%d",score_Alice,score_Bob");
       else
           printf("Game tied");
   }
   getch();
}
void connectedPair(){
   printf("If you have a pair of connected node enter y, else press any character");
   scanf("%c\n",&c);
   if((c=='y') || (c=='Y')){
       printf("Please enter the first node of the pair:");
       scanf("%d\n",&p1);
       printf("Please enter the second node of the pair:");
       scanf("%d\n",&p2);
       if((edge[p1-1][p2-1] == 1) && (edge[p2-1][p1-1] == 1)){
           edge[p1-1][p2-1] = 0;
           edge[p2-1][p1-1] = 0;
           w1 = p1;
           w2 = p2;
       }else{
           printf("invalid pair, enter another");
           connectedPair();
       }
   }
}