tabulation  -->> bottom up
memoization -->> up bottom

-------------------------------------------------------------------------------------------
fibonacci
  memoization


int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}


int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<f(n,dp);
  return 0;
}

T.C O(N)
S.C O(N) + recursion complex


tabulation
int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

T.C O(N)
S.C O(N)



space optimization


int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
T.C O(N)
S.C O(1)
-------------------------------------------------------------------------------------------

climbing stairs

int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}



int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}


---------------------------------------------------------------------------------------------------------
frog jump


int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}



int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp);
}

memoization

int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){//small to big index
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}

-------------------------------------------------------------------------------
 k jumps



int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}


tabulation

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);//sare jump me se kaunsi minimal hai
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}


---------------------------------------------------------------------

 max sum of non adjacent elements
 int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(ind==0) return arr[ind];
    if(ind<0)  return 0;
    
    int pick= arr[ind]+ solveUtil(ind-2, arr,dp);
    int nonPick = 0 + solveUtil(ind-1, arr, dp);
    
    return dp[ind]=max(pick, nonPick);
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n-1, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}

MEMEOZITAION

int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}
SPACE optimization

nt solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}

-----------------------------------------------------------------------
HOUSE ROBBERY

A thief needs to rob money in a street. The houses in the street are arranged in a circular manner.
 Therefore the first and the last house are adjacent to each other.

long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;
    
    if(n==1)
       return arr[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}


int main() {

  vector<int> arr{1,5,1,2,6};
  int n=arr.size();
  cout<<robStreet(n,arr);
}

------------------------------------------------------------------

NINJA TRAINING


MEMEOZITAION
int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return f(n - 1, 3, points, dp);
}

int main() {

  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}

tabulation

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}

int main() {

  vector<vector<int> > points = {{10,40,70},
                                 {20,50,80},
                                 {30,60,90}};
  int n = points.size();
  cout << ninjaTraining(n, points);
}


space optimization

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}

int main() {

  
  vector<vector<int> > points = {{10,40,70},
                                 {20,50,80},
                                 {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}

--------------------------------------------------------------------
UNIQUE PATHS
recursion
int solve(int i , int j)
    {
        // base cases; 
        if(i < 0 || j < 0) return 0; //boundary cases ;
        if(i == 0 && j==0) 
            return 1;
        int left = solve(i , j-1) ;
        int up = solve(i-1 , j) ;
        return left + up ;
        
    }


MEMOIZATION
int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp);
  int left = countWaysUtil(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}


int main() {

  int m=3;
  int n=2;
  vector<vector<int> > dp(m,vector<int>(n,-1));
  cout<<countWaysUtil(m-1,n-1,dp);
}

tabulation
int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
  for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  return dp[m-1][n-1];
}


int main() {

  int m=3;
  int n=2;
  vector<vector<int> > dp(m,vector<int>(n,-1));
  cout<<countWays(m,n,dp);
}



space optimization
 int uniquePaths(int m, int n) {//dp[i]=curr row  dp[i-1]=prev row
        vector<int> prev(n,0);
        for(int i=0; i<m; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(mat[i][j]==-1) cur[j]=0;
                else if(i==0 and j==0) cur[j]=1;
                else 
                {
                  int up=0,left=0;
                  if(i>0)up=prev[j];
                  if(j>0) left=curr[j-1];
                  cur[j]=left+up;
                }
            }
            prev = curr
          }
        return prev[n - 1];
    }





math total ways =(m+n)!/m!n!


int uniquePaths(int m, int n) {
  if(m == 1 || n == 1)
      return 1;
  m--;
  n--;
  if(m < n) {              // Swap, so that m is the bigger number
      m = m + n;
      n = m - n;
      m = m - n;
  }
  long res = 1;
  int j = 1;
  for(int i = m+1; i <= m+n; i++, j++){       // Instead of taking factorial, keep on multiply & divide
      res *= i;
      res /= j;
  }
      
  return (int)res;
}



int uniquePaths(int m, int n) {
         vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
-----------------------------------------------------------
MINIMUM PATH SUM IN GRID

recursion
int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
  int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);
  
  return dp[i][j] = min(up,left);
  
}

int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return minSumPathUtil(n-1,m-1,matrix,dp);
    
}

int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix);
}


tabulation
int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;//value becomes zero due to integer overflow
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
}

int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix);
}

space optimization
int minSumPath(int n, int m, vector<vector<int> > &matrix){
      vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
    
}



int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix);
}
-------------------------------------------------------------------------------------

triangular path having fixed starting point and variable ending point

recursion
int solve(int i, int j, int n, vector<vector<int>>&triangle) {
		if(i == n - 1)
			return triangle[i][j];
		int down = triangle[i][j] + solve(i+1, j, n, triangle);
		int down_right = triangle[i][j] + solve(i+1, j+1, n, triangle);
		return min(down,down_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		return solve(0, 0, n, triangle);
	}

  memoization

  int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		if(dp[i][j] != -1)
			return dp[i][j];
		int down = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  down_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		return dp[i][j] = min(down, down_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return solve(0, 0, n, triangle, dp);
	}

  tabulation
  int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) 
			dp[n-1][i] = triangle[n-1][i];
		for(int i = n-2; i >= 0; i--) {
			for(int j = i; j >= 0; j--) {
				int up = triangle[i][j] + dp[i+1][j];
				int up_left = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(up, up_left);
			}
		}
		return dp[0][0];
	}
	

  space optimization
  int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int>next(n);
		for(int i = n-1; i >= 0; i--) {
			vector<int>curr(n);
			for(int j = i; j >= 0; j--) {
				if(i == n-1)
					curr[j] = triangle[i][j];
				else {
					int up = triangle[i][j] + next[j];
					int up_left = triangle[i][j] + next[j+1];
					curr[j] = min(up, up_left);
				}
			}
			next = curr;
		}
		return next[0];
	}

 int minimumTotal(vector<vector<int>>& arr) {
    int row = arr.size();
    vector<int> front = arr[row-1];

    for(int i = row-2 ; i>=0 ; i--)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            front[j] = arr[i][j] +  min(front[j] , front[j+1]);
        }
    }
    return front[0];

    }

-----------------------------------------------------------------------------------------------
    min/max falling path SUM



int dfs(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(j < 0 || j == n) return INT_MAX;
        if(i == n - 1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int l = dfs(i + 1, j - 1, n, matrix, dp);
        int b = dfs(i + 1, j, n, matrix, dp);
        int r = dfs(i + 1, j + 1, n, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(l, min(b, r));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX, n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++) {
            ans = min(ans, dfs(0, i, n, matrix, dp));
        }
        return ans;
    }

tabulation

int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX, n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        dp[0] = matrix[0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int l = 1e9, a = 1e9, r = 1e9;
                if(j > 0) l = dp[i - 1][j - 1];
                a = dp[i - 1][j];
                if(j + 1 < n) r = dp[i - 1][j + 1];
                dp[i][j] = matrix[i][j] + min(l, min(a, r));
            }
        }

        for(int i=0; i<n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }


    space optimization

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX, n = matrix.size();
        vector<int> dp = matrix[0];
        
        for(int i=1; i<n; i++) {
            vector<int> temp(n);
            for(int j=0; j<n; j++) {
                int l = 1e9, a = 1e9, r = 1e9;
                if(j > 0) l = dp[j - 1];
                a = dp[j];
                if(j + 1 < n) r = dp[j + 1];
                temp[j] = matrix[i][j] + min(l, min(a, r));
            }
            dp = temp;
        }

        for(int i=0; i<n; i++) ans = min(ans, dp[i]);
        return ans;
    }








