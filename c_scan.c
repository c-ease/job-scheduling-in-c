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

int displayList(int head, int n, int string[n], int dir, int total, int max)
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

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void asc(int n, int array[n])
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
		{
			if(array[j] > array[j+1])
				swap(&array[j],&array[j+1]);
		}
}

void desc(int n, int array[n])
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
		{
			if(array[j] < array[j+1])
				swap(&array[j],&array[j+1]);
		}
}

void display(int n, int array[n])
{
	int i;
	printf("\n");
	for(i=0; i<n; i++)
		printf("\t%d",array[i]);
}

void merge(int n, int dir, int first[n], int second[n], int sorted[n])
{
	int i, c = 0;
	for(i=0; i<n; i++)
	{
		if(first[i] != -1)
		{
			sorted[c] = first[i];
			c++;
		}
	}
	for(i=0; i<n; i++)
	{
		if(second[i] != -1)
		{
			sorted[c] = second[i];
			c++;
		}
	}	
}

int sort(int n, int head, int dir, int max, int string[n], int left[n], int right[n], int sorted[n])
{
	int i, a = 0, b = 0;
	for(i=0; i<n; i++)
	{
		if(string[i] <= head)
		{
			left[a] = string[i];
			a++;
		}
		else
		{
			right[b] = string[i];
			b++;
		}
	}
	
	switch(dir)
	{
		case 0: desc(n,left); desc(n,right); //display(n,left); display(n,right);
                merge(n,dir,left,right,sorted); break;
		case 1: asc(n,left); asc(n,right); //display(n,left); display(n,right);
                merge(n,dir,right,left,sorted); break;
	}
	return a;

}

void setdefault(int n, int array[n])
{
	int i;
	for(i=0; i<n; i++)
		array[i] = -1;
}

int main()
{
	int n, i, max, dir, head, total = 0;
	printf("\n\n\t\t\t\t\t\t\tC-SCAN\n\n");

	printf("\n Enter the total number of disk blocks: ");
	scanf("%d",&max); 
	printf("\n Enter the total number of requests: ");
	scanf("%d",&n);
	int string[n], left[n], right[n], sorted[n];

	printf("\n Enter the disk request string (%d values)(range 0 - %d): ",n,max);
	for(i=0; i<n; i++)
	{
		scanf("%d",&string[i]);
		if(string[i] < 0)
		{
			printf("\n !-- Request cannot be negative --!\n");
			return -1;
		}
	}
	printf("\n Enter the direction of head [left - 0 / right - 1]: "); scanf("%d",&dir);
	printf("\n Enter the current head position: ");
	scanf("%d",&head);

	setdefault(n,left);
	setdefault(n,right);

	int len = sort(n,head,dir,max,string,left,right,sorted);
	printf("\n\n\t %d\t-\t%d",len,n-len);

	printf("\n\n\t\t\t\t\t\tList of requests\n\n");
	displayHeader(max);
	
	total = displayList(head,n,sorted,dir,total,max);
	printf("\n\n The total Head moment:- %d units\n\n",total);


	return 0;
}



