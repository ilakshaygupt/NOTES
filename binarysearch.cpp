#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include<vector>



void binarysearch(int ar[],int n)
{
    int first=0;
    int last=n-1;
    int key;
    int mid=(first+last)/2;
    cin >> key;
    int ans=-1;
    while(first<=last)
    {
        if (ar[mid]==key)
        { ans=mid;
            cout<<ans;
            break;
        }
        else if (key>ar[mid])
        {
            first=mid+1;
        }
        else
        {
            last=mid-1;
        }
    mid=(first+last)/2;
    }
}

void firstoccurance(int ar[],int n)
{
	int first=0;
    int last=n-1;
    int key;
    int mid=first+(last-first)/2;
    cin >> key;
    int ans=-1;
    while(first<=last)
    {
        if (ar[mid]==key)
        {
            ans=mid;
            last=mid-1;
        }
        else if (key>ar[mid])
        { 
            first=mid+1;
            
        }
        else
        {
            last=mid-1;
        }
       mid=(last+first)/2;
       }
        cout << ans;
}


void lastoccurance(int ar[],int n)
{
	int first=0;
    int last=n-1;
    int key;
    int mid=first+(last-first)/2;
    cin >> key;
    int ans=-1;
    while(first<=last)
    {
        if (ar[mid]==key)
        {
            ans=mid;
            first=mid+1;
        }
        else if (key>ar[mid])
        { 
            first=mid+1;
            
        }
        else
        {
            last=mid-1;
        }
       mid=(last+first)/2;
       }
        cout << ans;
}


void peakelement(int arr[],int n)
{
    int l = 0;
    int r = n-1;
    int mid;
   
    while (l <= r) {
       
        
        mid = (l + r) / 2;
        // first case if mid is the answer in extreme cases
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) and (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            
            break;
       
        // move the right pointer
        else if (mid > 0 and arr[mid - 1] > arr[mid])
            r = mid - 1;
       
        // move the left pointer
        else if (arr[mid+1]>arr[mid] and mid<n-1)
            l = mid + 1;
    }
   
    cout<< mid;
}

int  break_in_ascending_order_in_rotated_array(int ar[],int n)// ar={2,3,4,6,1}
{
	int first=0;
    int last=n-1;//arr={3,4,5,1,2}
    int mid=(first+last)/2;
 
    while(first<last)
    {
    	if (ar[mid]>=ar[0])
    	{
    		first=mid+1; 
    	}
    	else //then. mid becomes of other monotonic fucntion 
    	{
    		last=mid;
    	}
    	
 		mid=(first+last)/2;
    }
    return last; 
}


int seachinsortedrotatedarray(int ar[],int n)
{
	int first=0;
    int last=n-1;
    int key;
    cin>> key;
    int mid;
 	int pivot=break_in_ascending_order_in_rotated_array(ar,n);
 	int ans=-1;
 	if (key==ar[pivot])
    	{
    		return pivot; 
    	}
    else if(key>ar[0])
    	{
    		last=pivot-1;
    	}
    else if(key<ar[0])
    	{
    		first=pivot+1;
    	}
    mid=(first+last)/2;	
    
    while(first<=last)
    {
    	if (key==ar[mid])
    	{
    		ans=mid;
    		return ans; 
    	}
    	else if(key>ar[mid])
    	{
    		first=mid+1;
    	}
    	else
    	{
    		last=mid-1;
    	}
 		mid=(first+last)/2;
    }
    return ans; 
}


int binary_sqrt_integerpart(int n)//brute force
{
	int start=0;
	int last=n;
	long long int mid=(start+last)/2;
	long long int sqrt=mid*mid;
	long long int ans=-1;
	while(start<=last)
	{ 	long long int sqrt=mid*mid;
		if (sqrt==n)
		{
			return mid;
		}
		if (sqrt<n)
		{
			ans=mid;//for lowest intger whose square<n
			start=mid+1;

		}
		else
		{
			last=mid-1;
		}
        mid=(start+last)/2;
	}
	return ans;
}



double binary_sqrt_floatpart(int n, int precesion, int c)
{
	double ans=c;
	double factor=1;
	for(int i=0;i<precesion;i++)
	{
		factor= factor/10;
		for(double j=ans;j*j<n;j=j+factor)
		{
			ans=j;
		}
	}
	return ans;
}





bool isPerfectSquare(int n) {
int start=0;
int last=n;
long long int mid=(start+last)/2;
long long int sqrt=mid*mid;
long long int ans=-1;
while(start<=last)
{ 	long long int sqrt=mid*mid;
	if (sqrt==n)
	{
		return 1;
	}
	if (sqrt<n)
	{
		ans=mid;//for lowest intger whose square<n
		start=mid+1;

	}
	else
	{
		last=mid-1;
	}
    mid=(start+last)/2;
}
return 0;
}



bool issumofsquare() {//bruteforce. double pointer
	int c;
	cin>>c;
    long long int i=0,j=sqrt(c);//as sqrt(c)>j*j
while(i<=j)
{   long long int sqr=i*i+j*j;
    
    if (sqr>c)
    {
        j--;
    }
    else if (sqr<c)
    {
        i++;    
    }
    else 
    {
        return 1;
    }
}
return 0;
}


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
 	
   cout<< break_in_ascending_order_in_rotated_array(ar,n);
    
}




int main()
{
    int t;
    t=1;
    while(t--)
    {   
    	arr();
    //int n;
	//cin >> n;
    // cout<<binary_sqrt_floatpart(n,3,binary_sqrt_integerpart(n));  
    }
    return 0;
}