#include<stdio.h>
int main()
{
int cases, caseno, first, second;
scanf(" %d",&cases);
for(caseno=1;caseno<=cases;caseno++)
{
scanf(" %d %d",&first,&second);
printf("Case %d: ",caseno);
if(first > second) //Replace the ... with your code
printf("First team wins.\n");
else
printf("Second team wins.\n");
}
return 0;
}
