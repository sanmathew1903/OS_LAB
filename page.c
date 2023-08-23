#include<stdio.h>
int page[100],frames[5];
int n,m;
void input()
{
	printf("Enter the no of page and frames \n");
	scanf("%d%d",&n,&m);
	int i,j;
	printf("Enter the page order \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&page[i]);
	}
	for(i=0;i<m;i++)
	{
		frames[i]=-1;
	}

}
void printframe()
{
	int i;
	for(i=0;i<m;i++)
	{
		printf(" |%d|\n",frames[i]);
	}
	printf("\n\n");

}

void fcfs()
{
	int i,j,fault=0,k=0;
	for(i=0;i<n;i++)
	{
		int flag=1;
		for(j=0;j<m;j++)
		{
			if(page[i]==frames[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			fault++;
			frames[k]=page[i];
			k=(k+1)%m;
			printframe();
		}
	}

	printf("total page fault is : %d \n",fault);
}

void lfu()
{
	int min,j,i,flag,p;
	int freq[m],fault=0;
	for(j=0;j<m;j++)
	{
		freq[j]=0;
	}

	printf("\tLFU page replacement\n");
	fault=0;
	for(i=0;i<n;i++)
	{
		p=page[i];
		flag=1;
		for(j=0;j<m;j++)
		{
			if (p==frames[j])
			{
				flag=0;
				freq[j]++;
				break;
			}
		}
		if (flag==1)
		{
			fault++;
			min=0;
			for(j=1;j<m;j++)
			{
				if (freq[j] < freq[min])
				{
					min=j;
				}
			}
			frames[min]=p;
			freq[min]=1;
			printframe();
		}
		else
		{
			printframe();
		}
	}
	printf("Total no of page fault is: %d",fault);
}

void lru()
{
	int min,p,flag,i,j,k;
	int recent[m],fault;
	for(j=0;j<m;j++)
	{
		recent[j]=0;
	}
	fault=0;
	k=1;
	for(i=0;i<n;i++)
	{
		p=page[i];
		flag=1;
		for(j=0;j<m;j++)
		{
			if (p==frames[j])
			{
				flag=0;
				recent[j]=k;
				k++;
				break;
			}
		}
		if (flag==1)
		{
			fault++;
			min=0;
			for(j=1;j<m;j++)
			{
				if (recent[j] < recent[min])
				{
					min=j;
				}
			}
			frames[min]=p;
			recent[min]=k;
			k++;
			printframe();
		}
		else
		{
			printframe();
		}
	}
	printf("Total page fault :%d\n",fault);
}
void main()
{
	input();
//	fcfs();
	lru();
}
