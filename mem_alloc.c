#include<stdio.h>
int arr[5];
int pr[5];
int n,m;
void input()
{
	printf("Enter the total no of processes and arr blocks \n");
	scanf("%d%d",&n,&m);
	int i;

	printf("Enter the need of the processes\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&pr[i]);
	}
		printf("Enter the arr block spaces \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr[i]);
	}

}

void fcfs()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(pr[i]!=-1)
		{
			for(j=0;j<m;j++)
			{
				if(pr[i]<=arr[j])
				{
					printf("P%d -> M%d\n",i,j);
					arr[j]=-1;
					pr[i]=-1;
					break;
				}
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(pr[i]!=-1)
		{
			printf("P%d not allocated \n",i);
		}
	}
}

int findmin(int a)
{
	int i,pos=-1;
	int min=100000;

	for(i=0;i<m;i++)
	{
		if(pr[a]<=arr[i] && min>arr[i] && arr[i]!=-1)
		{
			min=arr[i];
			pos=i;
		}
	}

	return pos;
}
int findmax(int a)
{
        int i,pos=-1;
        int min=1;

        for(i=0;i<m;i++)
        {
                if(pr[a]<=arr[i] && min<arr[i] && arr[i]!=-1)
                {
                        min=arr[i];
                        pos=i;
                }
        }

        return pos;
}
void best()
{
	int i,j,res;
	for(i=0;i<n;i++)
	{
		res=findmin(i);
		if(res!=-1 && pr[i]!=-1)
		{
			printf("P%d -> M%d\n",i,res);
			arr[res]=-1;
			pr[i]=-1;
		}
	}

	for(i=0;i<n;i++)
	{
		if(pr[i]!=-1)
		{
			printf("P%d not allocated \n",i);
		}
	}
}

void worst()
{
	 int i,j,res;
        for(i=0;i<n;i++)
        {
                res=findmax(i);
                if(res!=-1 && pr[i]!=-1)
                {
                        printf("P%d -> M%d\n",i,res);
                        arr[res]=-1;
                        pr[i]=-1;
                }
        }

        for(i=0;i<n;i++)
        {
                if(pr[i]!=-1)
                {
                        printf("P%d not allocated \n",i);
                }
        }
}
void main()
{
	input();
//	fcfs();
//	best();
	worst();
}
