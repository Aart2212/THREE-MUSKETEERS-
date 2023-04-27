// AUTHOR :: AART DESAI , SHARAD PATEL, VEDANT PATEL
// DATE   :: 26 / 04 / 2023

#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b)*b)
#define to_upper(a) transform((a).begin(), (a).end(), (a).begin(), ::toupper)
#define to_lower(a) transform((a).begin(), (a).end(), (a).begin(), ::tolower)
#define is_prime(a) ((a)==2||(a)>1&&((a)&1)&&__builtin_probabiliyll((a),2))
#define yes() cout<<"YES\n"
#define no() cout<<"NO\n"
#define N 9



int grid[N][N];

bool isPresentInCol(int col, int num){//check whether num is present in col or not
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInRow(int row, int num){//check whether num is present in row or not
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
//check whether num is present in 3x3 box or no
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}

void sudokuGrid(){//print the sudoku grid after solve
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}

bool findEmptyPlace(int &row, int &col){//get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0)//marked with 0 is empty
            return true;
   return false;
}

bool isValidPlace(int row, int col, int num){
    //when item not found in col, row and current 3x3 box
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}

bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true;//when all places are filled
   for (int num = 1; num <= 9; num++){//valid numbers are 1 - 9
      if (isValidPlace(row, col, num)){//check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku())//recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0;//turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}

int main(){
   cout << "Enter the Sudoku grid:\n";
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           cin >> grid[i][j];
       }
   }
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}
