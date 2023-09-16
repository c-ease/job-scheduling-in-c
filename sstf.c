#include <stdio.h>
#include <math.h>


void displayHeader(int max)
{
	int i, count = 0;
	printf("\n ");
	for(i=0; i<=max; i++)
	{
			if(i == 0 || i%10 == 0 || i == max)
			{
			    printf("%d",i);
			    if(i > 99)
			        count = 2;
			    else if(i > 9)
			        count = 1;
			    else
			        count = 0;
			}
			else
			{
			    if(count == 2)
			        count--;
			    else if(count == 1)
			        count--;
			    else
				    printf(" ");
			}
	}
	printf("\n<");
	for(i=0; i<=max; i++)
	{
			printf("-");
	}
	printf(">\n");

}

void point(int p)
{
	int i;
	printf("\n ");
	for(i=0; i<p; i++)
		printf(" ");
	printf("+ [%d]",p);
	printf("\n\n");
}


void line(int max)
{
	int i; 
	printf("|");
	for(i=0; i<=max; i++)
		printf("-");
	printf("|\n");
}

int displayList(int head, int n, int string[n], int total, int max)
{
	int i;
	point(head);
	line(max);
	for(i=0; i<n; i++)
	{
		total = total + fabs(head - string[i]);
		head = string[i];
		point(string[i]);
		line(max);
	}
	return total;
}

int closest(int head, int n, int string[n])
{
	int i, j, min, index = -1, count = 0;
	for(i=0; i<n; i++)
	{
		if(string[i] != -1)
		{
			if(count==0)
			{
				min = fabs(head-string[i]);
				index = i;
				count++;
			}
			if(fabs(head-string[i]) < min)
			{
				index = i;
				min = fabs(head-string[i]);
			}
		}
	}
	return index;
}

void sort(int head, int n, int string[n], int sorted[n])
{
	int i, index;
	for(i=0; i<n; i++)
	{
		index = closest(head,n,string);
		sorted[i] = string[index];
		head = string[index];
		string[index] = -1;
	}
	
}

int main()
{

	int n, i, max, head, total = 0;
	printf("\n\n\t\t\t\t\t\t\tSSTF\n\n");

    printf("\n Enter the total number of disk blocks: "); scanf("%d",&max);
	printf("\n Enter the total number of requests: "); scanf("%d",&n);
	int string[n], sorted[n];

	printf("\n Enter the disk request string (%d values)(range 0 - 60): ",n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&string[i]);
		if(string[i] < 0)
		{
			printf("\n !-- Request cannot be negative --!\n");
			return -1;
		}
		sorted[i] = -1;
	}

	printf("\n Enter the current head position: ");
	scanf("%d",&head);

	sort(head,n,string,sorted);

	printf("\n\n\t\t\t\t\t\tList of requests\n\n");
	displayHeader(max);
	total = displayList(head,n,sorted,total,max);
	printf("\n\n The total Head moment:- %d units\n\n",total);


	return 0;
}



