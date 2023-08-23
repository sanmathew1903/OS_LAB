#include<stdio.h>
int max[5][5],need[5][5],alloc[5][5],n,m,seq[5],avail[5],end[5];
void input()
{
	int i,j;
	printf("Enter the no of processses and mem blocks \n");;
	scanf("%d%d",&n,&m);
	printf("Enter the max matrix\n");
	for(i=0;i<n;i++)
	{
		seq[i]=-1;
		end[i]=-1;
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the alloc matrix\n");
	for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        scanf("%d",&alloc[i][j]);
                }
        }


	for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
			need[i][j]=max[i][j]-alloc[i][j];
                }
        }

	printf("Enter the availabe resources \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}

}

void banker()
{
	int k,i,j,p=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			int flag=1;
			if(end[i]==-1)
			{
					for(j=0;j<m;j++)
					{
						if(need[i][j]>avail[j])
						{
							flag=0;
							break;
						}
					}
				if(flag==1)
				{
					end[i]=1;
					seq[p]=i;
					p++;
					int temp;
					for(temp=0;temp<m;temp++)
					{
						avail[temp]+=alloc[i][temp];
					}
				}
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(end[i]==-1)
		{
			printf("deadlock");
//			return;
		}
	}

	for(i=0;i<n;i++)
	{
		printf(" P%d ",seq[i]);
	}
}

void main()
{
	input();
	banker();
}
