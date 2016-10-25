// Problem::Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,
//
// Consider the following matrix:
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.
//
// Given target = 20, return false.
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r=matrix.size();
        int c=matrix[0].size();

        int i=0,j=c-1;

        while(i<r && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else
            {
                if(matrix[i][j]>target)
                    j--;
                else
                    i++;
            }
        }

        return false;

    }

int main()
{
    int n,m;
    cout<<"Enter no of rows:";
    cin>>n;
    cout<<"Enter no of columns:";
    cin>>m;

    vector<vector<int> > mat(n);

    cout<<"Enter matrix row by row:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            mat[i].push_back(x);
        }

    int target;
    cout<<"Enter target value:";
    cin>>target;

    cout<<"Is target value in matrix? 1-yes 0-No :"<<searchMatrix(mat,target)<<endl;
    return 0;
}
