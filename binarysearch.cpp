#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include<vector>
---------------------------------------------------------------------------------
----------------------
NORMAL BINARY SEARCH |
----------------------

int binarysearch(int ar[],int n)
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
            return ans;
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
    return -1;
}
---------------------------------------------------------------------------------
---------------------------
FIRST OCCURENCE OF ELEMENT|
---------------------------

int firstoccurance(int ar[],int n,int key)
{
	int first=0;
    int last=n-1;

    int mid=first+(last-first)/2;
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
    return ans;
}
---------------------------------------------------------------------------------
--------------------------
LAST OCCURENCE OF ELEMENT|
--------------------------

int lastoccurance(int ar[],int n,int key)
{
	int first=0;
    int last=n-1;
    int mid=first+(last-first)/2;
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
     return ans;
}
-------------------------------------------------------------------------------

-------------------------------
MISSING NUMBER IN RANGE O TO N|
-------------------------------

int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=n-1,mid,ans=n;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]>mid)//peeche jaye
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
-------------------------------------------------------------------------------
--------------------------------------
LOWEST ELEMENT IN SORTED ROTATED ARRAY|
---------------------------------------
-------------
NO DUPLICATES|
-------------

int findMin(vector<int>& num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            int mid = (start+end)/2;
            if (num[mid]<num[end]) {
                end = mid;  
            } 
            else{
                start = mid+1;
            }
        }
        
        return num[start];
    }
----------
DUPLICATES|
----------
 int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                r--;
            }
        }
        return nums[l];
    }
---------------------------------------------------------------------------------

-----------------------
PEAK ELEMENT IN A ARRAY|
-----------------------
int findPeakElement(const vector<int> &nums) 
    {
	if(nums.size() == 1) return 0; // single element
        
        int n = nums.size();
        
		// check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
		
		// search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid-1]) end = mid - 1;
            else if(nums[mid] < nums[mid+1]) start = mid + 1;
        }
        return -1; // dummy return statement
    }

---------------------------------------------------------------------------------
------------------------
SQUARE ROOT INTEGER PART|
------------------------

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
		else if (sqrt<n)
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

---------------------------------------------------------------------------------

----------------------
SQUARE ROOT FLOAT PART|
----------------------

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
---------------------------------------------------------------------------------

----------------------------
SQUARE ROOT IN SINGLE SEARCH|
----------------------------

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void nRoot(int n/*number*/   , int m/*power*/) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    return low;
}

---------------------------------------------------------------------------------
-----------------------------------
CHECK IF NUMBER IS A PERFECT SQUARE|
-----------------------------------

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
    return -1;
}

---------------------------------------------------------------------------------

------------------
PYTHAGORAN TRIPLET|
------------------

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


---------------------------------------------------------------------------------

--------------------------------
MEDIAN OF ROW WISE SORTED MATRIX|
--------------------------------

#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

---------------------------------------------------------------------------------
---------------------------------------------------
FIND SINGLE ELEMENT IN ARRAY IN ARRAY OF DUPLICATES|
---------------------------------------------------

int findSingleElement(vector < int > & nums) 
{
    int low = 0;
    int high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (mid % 2 == 0) {
            if (nums[mid] != nums[mid + 1]) 
            //Checking whether we are in right half

                high = mid - 1; //Shrinking the right half
            else
                low = mid + 1; //Shrinking the left half
        } else {

            //Checking whether we are in right half
            if (nums[mid] == nums[mid + 1]) 
                high = mid - 1; //Shrinking the right half
            else
                low = mid + 1; //Shrinking the left half
        }
    }

    return nums[low];
}



-----------------------------------------------------------------------------

---------------------------------------
SEARCH IN ROTATED ARRAY DISTINCT VALUES|
---------------------------------------
int search(vector < int > & nums, int target) {
  int low = 0, high = nums.size() - 1; 

  while (low <= high) { 
    int mid = (low + high) >> 1; 
    if (nums[mid] == target)
      return mid; 

    if (nums[low] <= nums[mid]) {      
        if (nums[low] <= target && nums[mid] >= target)
            high = mid - 1; 
        else
            low = mid + 1;     
        } 
        else {       
        if (nums[mid] <= target && target <= nums[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
  }
  return -1;
}

-------------------
NON DISTINCT VALUES|
-------------------
bool search(vector<int>& nums, int target)
    {
        int l = 0, h = nums.size() - 1, mid;
        while(l <= h)
        {
            mid = (l + h)/2;
            if(target == nums[mid])
                return true;
            
            if(nums[l] == nums[mid] and nums[mid] == nums[h])
            {
                l++; h--;
                continue;
            }
            
            if(nums[l] <= nums[mid])               // left is sorted
            {
                if(nums[l] <= target and target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else                                   // right is sorted
            {
                if(nums[mid] < target and target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }

---------------------------------------------------------------------------------
---------------------------------------------
MEDIAN OF TWO SORTED ARRAY OF DIFFERENT SIZES|
---------------------------------------------
-----
BRUTE|
-----
float median(int nums1[],int nums2[],int m,int n) {
    int finalArray[n+m];
    int i=0,j=0,k=0;
    while(i<m && j<n) {
        if(nums1[i]<nums2[j]) {
            finalArray[k++] = nums1[i++];
        }
        else {
            finalArray[k++] = nums2[j++];
        }
    }
    if(i<m) {
        while(i<m) 
            finalArray[k++] = nums1[i++];
    }
    if(j<n) {
        while(j<n)
            finalArray[k++] = nums2[j++];
    }
    n = n+m;
    if(n%2==1) 
        return finalArray[((n+1)/2)-1];
    else return ((float)finalArray[(n/2)-1]+(float)finalArray[(n/2)])/2;
}

int main() {
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}

-------------
BINARY SEARCH|
-------------
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n)
        return findMedianSortedArrays(nums2,nums1);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {

        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}
---------------------------------------------------------------------------------
--------------------------------
K TH ELEMENT OF TWO SORTED ARRAY|
--------------------------------
int kthelement(vector<int> vec1 , vector<int>vec2 ,int k) {
    int m=vec1.size()-1,n=arr2.size()-1;
    int p1=0,p2=0,counter=0,answer=0;
    
    while(p1<m && p2<n) {
        if(counter == k) break;
        else if(vec1[p1]<vec2[p2]) {
            answer = vec1[p1];
            ++p1;
        }
        else {
            answer = vec2[p2];
            ++p2;
        }
        ++counter;
    }
    if(counter != k) {
        if(p1 != m-1) 
            answer = vec1[k-counter];
        else 
            answer = vec2[k-counter];
    }
    return answer;
}



BINARY SEARCH LOG O(MIN(M,N))
int kthElement(vector<int> arr1,vector<int> arr2,int m,int n, int k) {
  
    if(m > n) {
        return kthElement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}


---------------------------------------------------------------------------------



--------------------------------
ALLOCATE MINIMUM NUMBER OF PAGES|
--------------------------------


//to check if allocation of books among given students is possible.
int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) 
    {//greater than mid
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
int findPages(vector < int > & A,int n, int B) {
  if (B > A.size()) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < A.size(); i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

---------------------------------------------------------------------------------
--------------
AGGRESIVE COWS|
--------------
-----
BRUTE|
-----
bool isCompatible(vector < int > inp, int dist, int cows) {
  int n = inp.size();
  int k = inp[0];
  cows--;
  for (int i = 1; i < n; i++) {
    if (inp[i] - k >= dist) {
      cows--;
      if (!cows) {
        return true;
      }
      k = inp[i];
    }
  }
  return false;
}
int main() {
  int n = 5, m = 3;
  vector<int> inp {1,2,8,4,9};
  sort(inp.begin(), inp.end());
  int maxD = inp[n - 1] - inp[0];
  int ans = INT_MIN;
  for (int d = 1; d <= maxD; d++) {
    bool possible = isCompatible(inp, d, m);
    if (possible) {
      ans = max(ans, d);
    }
  }
  cout << "The largest minimum distance is " << ans << '\n';
}


-------------
BINARY SEARCH|
-------------

bool possible(int mid, vector<int>&stalls,int k)
      {
          int i,j,temp=stalls[0],count=1;
          for(i=1;i<stalls.size();i++)
          {
              if(stalls[i]-temp>=mid)
              {
                temp=stalls[i];
                count++;
              }
              if(count==k)
              return true;
          }
          return false;
      }

int aggressiveCows(vector<int> &stalls, int k)
{
    
            int n=stalls.size();
        int  i,j;
        sort(stalls.begin(), stalls.end()) ;// nlog(n)
        // to get the order of placement of the  cows.
       int high=stalls[n-1]-stalls[0],ans=1;
       int low=1,mid;
        while(low<=high)
        {
            // cout<<low<<high<<" ";
            mid=(low+high)/2;
            //   cout<< mid<<" ";
            if(possible(mid,stalls,k))
            {
                // cout<< mid<<" ";
                low=mid+1;
                ans=max(ans,mid);
            }
            else
            {
                high=mid-1;
                
            }
            
        }
        return ans;
}

---------------------------------------------------------------------------------
-------------------------
MINIMUM SIZE SUBARRAY SUM|
-------------------------  
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

  bool isPossible(vector<int> &nums , int k , int target){
		int sum = 0 , i = 0;
			for(i = 0 ; i < k ; i++){
				sum+=nums[i];
			}
			int maxi = sum;
			for(i = k ; i < nums.size() ; i++){
				sum+=nums[i] - nums[i-k];
				maxi = max(maxi , sum);
			}
			return maxi>=target;
	}

    int minSubArrayLen(int target, vector<int>& nums) {
    	int low = 1 , high = nums.size() , n = nums.size();
        bool ansPossible = false;
    	while(low <= high){
    		int mid = low + (high-low)/2;
    		if(isPossible(nums,mid,target)){
    			ansPossible = true;
    			high = mid-1;//usse uppar wale hata do kyoki wo minimum nahi hn
    		}else low = mid + 1;         
    	}
        if(ansPossible)
			return low;
		else
			return 0;
    }
---------------------------------------------------------------------------------
---------------------------------------------
find the smallest divisor given a threshhold|
--------------------------------------------

bool check(int mid , vector<int>& nums , int threshold){
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int val = 0;
            // if(mid >= nums[i]){
            //     val = 1;
            // }
            // else{
                // val = ceil((double)nums[i]/(double)mid);
            // }
            val = ceil((double)nums[i]/(double)mid);
            
            sum += val;
        }
        
        return sum <= threshold;
    }


int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, // bad
        hi = 1e9 , // good
        ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(mid , nums , threshold)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
---------------------------------------------------------------------------------

-----------------------------------------------
minimum capacity to ship packages within d days|
-----------------------------------------------

int shipWithinDays(vector<int>& weights, int days) {
    int left = -1, right = 0;
    for (int weight : weights) {
        left = max(left, weight);
        right = right + weight;
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        int daysNeeded = 1, currWeight = 0;
        for (int weight : weights) {
            if (currWeight + weight > mid) {
                daysNeeded++;
                currWeight = 0;
            }
            currWeight = currWeight + weight;
        }
        if (daysNeeded > days) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

---------------------------------------------------------------------------------
-----------------------
split array largest sum|
-----------------------

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.


int check(vector<int> nums,int mid)
{
    int nosubarray=1;
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {   if(sum+nums[i]>mid)
        {
        nosubarray++;
        sum=nums[i];
        }
        else
        {
        sum+=nums[i];
        }
    }
    return nosubarray;
}

int splitArray(vector<int>& nums, int k) {
    int low=*max_element(nums.begin(),nums.end());
    int high=0;
    for(int i=0;i<nums.size();i++)high+=nums[i];
    int ans=high;//ans to be minimized
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(nums,mid)>k)
        {
            low=mid+1;   
        }
        else
        {
            ans=mid;
            high=mid-1;

        }
    }
    return ans;
}


---------------------------------------------------------------------------------

----------------
DIVIDE CHOCOLATE|
----------------

#include <bits/stdc++.h> 



int check(vector<int> &arr,int mid,int k)
{
    int sum=0,count=0;
    for(int i=0;i<arr.size();i++)
    {sum+=arr[i];
        if(sum>=mid)
        {
            count++;
           sum=0;
            
        }

    }
    return count>=k;
}
int getMaximumSweetness(vector<int> &arr, int k)
{
    int low=1;
    int high=0;
    for(int i=0;i<arr.size();i++)high+=arr[i];
    int ans=0;
    while(low<=high)
    {int mid=(low+high)/2;
        if(check(arr,mid,k+1))
        {
            ans=mid;
            low=mid+1;

        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

---------------------------------------------------------------------------------
--------------------
koko eating bananas|
--------------------
bool check(vector<int>&piles,int h,long long speed)
    {
        long long countHours=0;
        for(auto i:piles)
        {
            countHours+=(i+speed-1)/speed;//equivalent to ceil(i/speed)
        }
        if(countHours<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=1e9;
        int ans=-1;
        while(low<=high)
        {
            long long mid=(low+high>>1);//equivalent to (mid+high)/2
            if(check(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
---------------------------------------------------------------------------------

                                  ------
                                  |TODO|
                                  ------

 ARRAY INTERSECTION BY BINARYS SEARCH