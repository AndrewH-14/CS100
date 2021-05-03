#include<stdio.h>
#include <string.h>
int main() {
    
char str[100];
printf("Enter a string : ");
//gets(str);
scanf("%s", str);
int i,j,count,flag=0;
printf("Unique characters include: ");
for(i=0;i<strlen(str);i++) {
    count=0;
    for(j=0;j<strlen(str);j++) {
        if((int)str[i]==(int)str[j] && i!=j) {
            count++;
            break;
        }
    }
    if(count==0) {
        printf("%c ",str[i]);
        flag++;
    }
}
if(flag==0)
printf("NONE");

return 0;
}