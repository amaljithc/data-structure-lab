# include <stdio.h>
# include <stdlib.h>

int s[20],a[20],b[20],bita[20],bitb[20],bitu[20],biti[20],bitd[20];
int supersize=0,asize=0,bsize=0;

void setUnion(int arr1[],int arr2[]){
    for(int i=0;i<supersize;i++){        
        bitu[i]=arr1[i]|arr2[i];
    }
}
void setIntersection(int arr1[],int arr2[]){
    for(int i=0;i<supersize;i++){        
        biti[i]=arr1[i]&arr2[i];
    }
}
void setDifference(int arr1[],int arr2[]){
    for(int i=0;i<supersize;i++){  
        bitd[i]=arr1[i]&(!arr2[i]);
    }
}


void setresult(int a[])
{
printf("{");
for(int i=0;i<supersize;i++)
{
    if(a[i]==1)
    {
        printf("%d",s[i]);
        if(i!=supersize-1)
        {
            printf(",");
        }
    }
}
printf("}\n");

}

void getSet(int arr[],int setSize){
    printf("\nEnter set\n");
    for(int i=0;i<setSize;i++){
        scanf("%d",&arr[i]);
    }
}
void printSet(int arr[],int size){
    printf("{");
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
        if(i!=size-1){
            printf(",");
        }
    }
    printf("}\n");
}

void printbitstring()
{
printf("\nSuper Set:");
    printSet(s,supersize);
    printf("Set A:");
    printSet(a,asize);
    printf("Set B:");
    printSet(b,bsize);
    printf("Set A bit string :");
    printSet(bita,supersize);
    printf("Set B bit string :");
    printSet(bitb,supersize);

}
void createbitstring(int set[],int size,int bit[])
{
int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<supersize;j++)
        {
            if(set[i]==s[j])
            {
                bit[j]=1;
            }
        }

    }

}
void newset()
{
    printf("\n============================\n");
        printf("**********Enter Universal Set\n");
          printf("Enter Super Set Size:");
            scanf("%d",&supersize);
            getSet(s,supersize);
        printf("*****************Enter Set A\n");
         printf("Enter Set A Size:");
            scanf("%d",&asize);
            getSet(a,asize);
        printf("************Enter Set B\n");
         printf("Enter Set B Size:");
            scanf("%d",&bsize);
            getSet(b,bsize);


            for(int i=0;i<supersize;i++){
        bita[i]=0;
        bitb[i]=0;
        bitu[i]=0;
        biti[i]=0;
        bitd[i]=0;
    }
    createbitstring(a,asize,bita);
    createbitstring(b,bsize,bitb);

}

void main()
{
    int choice;



      do
      {  
        printf("1.creating new sets\n");
        printf("2.Union\n");
        printf("3.Intersection\n");
        printf("4.Difference\n");
        printf("5.Print Sets and its bit string representation\n");
        printf("6.Exit\n");
        printf("============================\n");
        printf("Enter Choice:");
        scanf("%d",&choice);
        printf("============================\n");

    switch(choice){
        case 1:newset();

            break;
        case 2:setUnion(bita,bitb);
                setresult(bitu);

            break;
        case 3:setIntersection(bita,bitb);
                setresult(biti);

             break;
             case 4:setDifference(bita,bitb);
                setresult(bitd);


             break;
        case 5:printbitstring();

             break;

    }
     }while(choice!=6);

    }