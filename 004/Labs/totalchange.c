#include<stdio.h>

void ExactChange(int UserValue , int coinVals[]){
   int deno[] = {100,25,10,5,1};
   int i;
   for (i = 0; i <5; i++) {
        while (UserValue >= deno[i]) {
            UserValue -= deno[i];
            coinVals[i]++;
        }
    }
}

int main(){
   int n;
   int coinVals[5];
   int i;
   for(i=0;i<5;i++)coinVals[i]=0;
  
   //printf("Enter value : ");
   scanf("%d",&n);
  
   ExactChange(n,coinVals);
  
   if(coinVals[0]==0&&coinVals[1]==0&&coinVals[2]==0&&coinVals[3]==0&&coinVals[4]==0)
   printf("no change\n");
  
   else{
      
       if(coinVals[0]>0)printf("%d %s\n",coinVals[0],coinVals[0]>1?"dollars":"dollar");
       if(coinVals[1]>0)printf("%d %s\n",coinVals[1],coinVals[1]>1?"quarters":"quarter");
       if(coinVals[2]>0)printf("%d %s\n",coinVals[2],coinVals[2]>1?"dimes":"dime");
       if(coinVals[3]>0)printf("%d %s\n",coinVals[3],coinVals[3]>1?"nickels":"nickel");
       if(coinVals[4]>0)printf("%d %s\n",coinVals[4],coinVals[4]>1?"pennies":"penny");
      
   }
   return 0;
}