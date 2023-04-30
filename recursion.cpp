    1. sort a stack using recursion

  void add(stack<int> &s, int temp){
    if(s.size() == 0 || s.top() <= temp){
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    add(s, temp);
    s.push(x);
    return;
}

void helper(stack<int>&s){
    if(s.size() == 1){
        return;
    }
    int temp = s.top();
    s.pop();
    helper(s);
    
    add(s, temp);
    return;
}
int main(){
    stack<int> st;
    int n;
    cin>>n;
    while (n--){
        int x;
        cin>>x;
        st.push(x);
    }
    helper(st);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout<<top<<endl;
    }
    return 0;
}
Time Complexity: O(n^2)  Space Complexity: O(n) for the auxiliary space stack

-------------------------------------------------------------------------------------

2.reverse a stack using recursion


 void insertAtBottom(stack<int> &s, int item)
{
    // base case: if the stack is empty, insert the given item at the bottom
    if (s.empty())
    {
        s.push(item);
        return;
    }
    // Pop all items from the stack and hold them in the call stack
    int top = s.top();
    s.pop();
    insertAtBottom(s, item);
    // After the recursion unfolds, push each item in the call stack
    // at the top of the stack
    s.push(top);
}
    
    void Reverse(stack<int> &st)
    {
        if(!st.empty()){
        int top_element = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st,top_element);
        }
        return;
        
    }
    



-------------------------------------------------------------------------------------

3.sebsequences using recursion   

    all subsequences must be in order 


void f(int index,vector <int> &ds,int arr[],int n)
{
    if(index>=n)
    {
        for(auto it:ds)
        {
            cout<<it<<" ";
        }

    
    if(ds.size()==0)
    {
        cout<<"{}";
    }
    cout<<endl;
    return;
    }
    ds.push_back(arr[index]);
    f(index+1,ds,arr,n);
    ds.pop_back();
    f(index+1,ds,arr,n);
}

int main()
{   
   int arr[]={3,1,2};
   int n=3;
   vector<int> ds;
    f(0,ds,arr,n);
    return 0;
}
input {3,1,2}    
output

3 1 2 
3 1 
3 2 
3 
1 2 
1 
2 
{}
no of permutations =2^n
// to print in reverse order just take not pick condition first
    f(index+1,ds,arr,n);
    ds.push_back(arr[index]);
    f(index+1,ds,arr,n);
    ds.pop_back();
    output 
    {}
    2
    1
    1 2
    3
    3 2
    3 1
    3 1 2

   
    
-------------------------------------------------------------------------------------
4. All subsequences with sum equals k

void f(int index,vector <int> &ds,int arr[],int n,int sum)
{
    if(index>=n)
    {   if(sum==3)
    {
        for(auto it:ds)
        {
            cout<<it<<" ";
        }
         cout<<endl;
    }
   
    return;
    }
    ds.push_back(arr[index]);
   sum+=arr[index];
    f(index+1,ds,arr,n,sum);//f(index+1,ds,arr,n,sum+arr[index]);
    ds.pop_back();
    sum-=arr[index];
    f(index+1,ds,arr,n,sum);
}



int main()
{   
   int arr[]={3,1,2};
   int n=3;
   vector<int> ds;
   
    f(0,ds,arr,n,0);
    return 0;
}


    
-------------------------------------------------------------------------------------



5. single subsequence with sum k
bool f(int index,vector <int> &ds,int arr[],int n,int sum)
{
    if(index>=n)
    {   if(sum==3)
    {
        for(auto it:ds) cout<<it<<" ";
         cout<<endl;
         return true;
    }
   
    else return false;
    }
    ds.push_back(arr[index]);
   sum+=arr[index];
    if(f(index+1,ds,arr,n,sum))
        return true;
    ds.pop_back();
    sum-=arr[index];
    if(f(index+1,ds,arr,n,sum))return true;

    return false;
}



int main()
{   
   int arr[]={3,1,2};
   int n=3;
   vector<int> ds;
   
   cout<< f(0,ds,arr,n,0);
    return 0;
}


    
-------------------------------------------------------------------------------------
6.count the number of subsequence with sum k

int f(int index,int arr[],int n,int sum)
{   if(sum>3) return 0;//only true for postitive number
    if(index>=n)
    {   if(sum==3) return 1;
    else return 0;
    }
    
    int l=f(index+1,arr,n,sum+arr[index]);
        
   
    int r=f(index+1,arr,n,sum);

    return l+r;
}


int main()
{   
   int arr[]={3,1,2};
   int n=3;
  
   int count=0;
   cout<<f(0,arr,n,0);
   
    return 0;
}


    
-------------------------------------------------------------------------------------
7. subsequences with sum equal target and a element can be use any number of time
combinations must be unique-->> Two combinations are unique if the frequency of at least one of the chosen numbers is different.



 void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the same element n times until condition is not met 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }


int main()
{   vector < int > v {2,3,6,7};
    int target = 7;
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, v, ans, ds);
    
   cout << "Combinations are: " << endl;
   for (int i = 0; i < ans.size(); i++) {
   for (int j = 0; j < ans[i].size(); j++)
   {
      cout << ans[i][j] << " ";
   }
    cout << endl;
  }
   
    return 0;
}


input = {2,3,6,7}

output

2 2 3 
7


-------------------------------------------------------------------------------------
8.
subsequences with sum equal target and a element can be used ponly once
combinations must be unique-->> Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// arrayh fitst must be sorted

void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}


int main()
{   vector < int > v {1,1,1,2,2};
    int target = 4;
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, v, ans, ds);
    
   cout << "Combinations are: " << endl;
   for (int i = 0; i < ans.size(); i++) {
   for (int j = 0; j < ans[i].size(); j++)
   {
      cout << ans[i][j] << " ";
   }
    cout << endl;
  }
   
    return 0;
}
input={1,1,1,2,2}
ouyput
1 1 2 
2 2



-------------------------------------------------------------------------------------
9. return sum of all posssible subsets of array in increasng order

 void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  


int main()
{   vector < int > v= {3,1,2};
int n=3;
    vector < int > ans;
    sort(v.begin(), v.end());
    subsetSumsHelper(0, v, n, ans, 0);
    sort(ans.begin(), ans.end());
    
  
   for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;
  
   
    return 0;
}
a={3,1,2}
output
0 1 2 3 3 4 5 6
---------------------------------------------------------------------------------------
10.return all unique subsets






 void fin(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            fin(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }

int main()
{  vector < int > v= {1,2,2};
    int n=3;
    vector < vector < int >> ans;
   
    vector < int > ds;
    fin(0, v, ds, ans);
    cout << "The unique subsets are " << endl;
  cout << "[ "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
    cout<<endl;
  }
  cout << " ]";
   
    return 0;

}

a={1,2,2}
output
[ 
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 2 ]
[ 2 ]
[ 2 2 ]
]


--------------------------------------------------------------------------------------------------

11.all permutations of string given that all elelmebts are distinct

ap-1  RECURSIVWE

 void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }

int main()
{  vector < int > v= {1,2,3};
    int n=3;
     
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[v.size()];
      for (int i = 0; i < v.size(); i++) freq[i] = 0;
      recurPermute(ds, v, ans, freq);

for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;}

     
    return 0;

}

input ={1,2,3}
output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2

a-2 swapping

void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }

int main()
{  vector < int > v= {1,2,3};
    int n=3;
     
      vector < vector < int >> ans;
      recurPermute(0, v, ans);

for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;}

     
    return 0;

}

input ={1,2,3}
output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2


-------------------------------------------------------------------------------------------------

12. N-Queens Arrangement


bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }


void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';//backttracking and removing placed q for futher combiantion
        }
      }
    }

int main()
{  
    int n=4;
    vector < vector < string >> ans;
    vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);



      for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }

     
    return 0;

}


ap-2 with different checking condition

void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

int main()
{  



    int n=4;
    vector < vector < string >> ans;
    vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);



      for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }

     
    return 0;

}


input n=4

output
Arrangement 1
..Q.
Q...
...Q
.Q..

Arrangement 2
.Q..
...Q
Q...
..Q.






-------------------------------------------------------------------------------------------------
13. sudoku solver


bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector < vector < char >> & board) 
{
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.') 
        {
            for (char c = '1'; c <= '9'; c++) 
        {
            if (isValid(board, i, j, c)) 
            {
                board[i][j] = c;
                if (solveSudoku(board)) 
                    return true;
                else   
                    board[i][j] = '.';
            }
        }
        return false;//nfor previous number placed at rpevious cell no number can be placed at next empty index
      }
    }
  }
  return true;
}

int main() {
    
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solveSudoku(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}

output
9 5 7 6 1 3 2 8 4 
4 8 3 2 5 7 1 9 6 
6 1 2 8 4 9 5 3 7 
1 7 8 3 6 4 9 5 2 
5 2 4 9 7 1 3 6 8 
3 6 9 5 2 8 7 4 1 
8 4 5 7 9 2 6 1 3 
2 9 1 4 3 6 8 7 5 
7 3 6 1 8 5 4 2 9


-------------------------------------------------------------------------------------------------

14.palindrome partitionng

 partition it in such a way that every substring is a palindrome.

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
  
 void partitionHelper(int index, string s, vector < string > & path,vector < vector < string > > & res) 
 {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  
  int main() {
  string s = "aabb";

   vector < vector < string > > ans;
      vector < string > path;
    partitionHelper(0, s, path, ans);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}




The Palindromic partitions are :-
 [ [ a a b b ] [ a a bb ] [ aa b b ] [ aa bb ] ]

-------------------------------------------------------------------------------------------------------
15.

rat in a maze

void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,vector < vector < int >> & vis) 
    {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }
  }


  
  int main() {

    int n = 4;
    vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector < string > ans;
    vector < vector < int >> vis(n, vector < int > (n, 0));
    vector < string > result;
      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);

  if (ans.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
   
  return 0;
}

output 

DDRDRR DRDDRR







