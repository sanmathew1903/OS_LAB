#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
typedef struct mem
{
        int n,m;
        int num[3][3];
        int trans[3][3];
}node ;

void main()
{
        node * com;
        int key =98765;
        int shmid=shmget(key,sizeof(node),IPC_CREAT| 0666);
        com=(node * )shmat(shmid,NULL,0);
///////size of the matrix
        printf("Enter the size of the matrix");
        scanf("%d%d",&com->n,&com->m);
        int n=com->n;
        int m=com->m;
        int i,j;
        printf("Enter the matrix \n");
///////input matrix
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        printf("Enter the digit \n: ");
                        scanf("%d",&com->num[i][j]);
                }
        }
///////print matrix
        for(i=0;i<n;i++)
        {
                printf("\n");
                for(j=0;j<m;j++)
                {
                        printf(" %d ",com->num[i][j]);
                }
        }
        printf("\n");
}
