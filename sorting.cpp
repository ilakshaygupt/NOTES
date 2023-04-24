#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include<vector>

//------------------------------------------------------------------------------    
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


//------------------------------------------------------------------------------    



void traverse_arr(int ar[],int n)
{
    int i=0;
    while(i<n)
    {
        cout<<ar[i]<<' ';
        i++;
    }
}


//------------------------------------------------------------------------------    

void selecion_sort(int ar[],int n)
{
	for(int i=0; i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if (ar[min]>ar[j])
			{
				min=j;
			}
		}
		swap(&ar[min],&ar[i]);	
	}
}

//--------------------------------------------------------------------------------------------

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
	{
        for (j = 0; j < n - i - 1; j++)
		{
            if (arr[j] > arr[j + 1])
			{
                swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//-------------------------------------------------------------------------------------------

void insertion_sort(int ar[],int n)
{
	for(int i=1; i<n-1;i++)
	{
		for(int j=i-1;j>=0 and ar[j]>ar[i];j--)
		{
			if (ar[j]>ar[j+1])
			{
				swap(&ar[j],&ar[j+1]);
			}	
		}		
	}
}

//------------------------------------------------------------------------------

void arr()
{
    int n;
    cin >>n;
    int ar[n];
    int i=0;
    while(i<n){
        cin >> ar[i];
        i++;
    } 
}

//------------------------------------------------------------------------------

int main()
{
	int t;
	t=1;
	
	while(t--)
	{
		int n;
		cin>>n;
		int ar[n][n];
		
	for(int i=0;i<n;i++)
	   {
		for(int j=0;j<n;j++)
	   		{
			cin>>ar[i][j];
			}
	   }
	
   }
	return 0;
}