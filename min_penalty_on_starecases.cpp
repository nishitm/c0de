// Problem::In this problem we consider two stairways, A and B, which are parallel to each other.
          // Both stairways, A and B, have N steps each where A[i], B[i] represent i-th step of A and B respectively.
          // Each step has some amount of penalty associated and if you use that step you will be penalized by the same amount.
          // After taking few steps you will accumulate penalty of all of the steps you visited.
          // You have a maximum jump length of K i.e., from A[i] you can jump forward to A[i+1] or A[i+2] … or A[i+K] without using any steps in between.
          // You can also jump across the stairways with an extra penalty P for changing stairways.
          // For example from A[i] you can jump to B[i+1] or B[i+2] … or B[i+K] with an additional penalty P along with the penalty of the step you visit.
          // You can also jump from stairway B to stairway A and that too incurs an additional penalty P along with the penalty of the step you visit.
          // Observe that from each step you can jump forward only.
          // Your final penalty will be penalty of all the steps you visited plus P times the number of times you crossed the stairways.
          // You can start from A[1] or B[1] and should reach A[N] or B[N] minimizing the penalty accumulated on the way. Find the minimum penalty you will accumulate.

#include<bits/stdc++.h>
using namespace std;
int dp[3000][2];

int min_penalty(vector<int> A, vector<int> B, int i, int n, int k, int p, char stair) {

    if(n == 1)
      return min(A[0], B[0]);

    if(i == n-1)
    {
      if(stair=='a')
        return A[i];
      else
        return B[i];
    }
    if(i >= n)
      return 0;

    if(dp[i][stair-'a'] != INT_MAX)
      return dp[i][stair-'a'];

    int incl = INT_MAX;
    int excl = INT_MAX;

    if(stair == 'a') {

        for(int j=1;j<=k;j++)
          if(i+j < n)
            excl = min(excl, A[i] + min_penalty(A, B, i+j, n, k, p, 'a'));

        for(int j=1;j<=k;j++)
          if(i+j < n)
            incl = min(incl, A[i] + p + min_penalty(A, B, i+j, n, k, p, 'b'));

        return dp[i][stair-'a'] = min(incl, excl);
    }
    else {
        for(int j=1;j<=k;j++)
          if(i+j < n)
            excl = min(excl, B[i] + min_penalty(A, B, i+j, n, k, p, 'b'));
        for(int j=1;j<=k;j++)
          if(i+j < n)
            incl = min(incl, B[i] + p + min_penalty(A, B, i+j, n, k, p, 'a'));

        return dp[i][stair-'a'] = min(incl, excl);
    }

}



int main() {

  int n, k, p;

  cout<<"Enter no of stairs in A&B:";
  cin >> n;
  cout<<"Enter the value of k:";
  cin>> k;
  cout<<"Enter the value of P:";
  cin>> p;
  vector<int>A,B;
  cout<<"Now enter A:\n";
  for(int i=0; i<n; i++)
  {
    int x;
    cin>>x;
    A.push_back(x);
  }
  cout<<"Now enter B:\n";
  for(int i=0; i<n; i++)
  {
    int x;
    cin>>x;
    B.push_back(x);
  }
  for(int i=0;i<=n;i++)
    for(int j=0;j<2;j++)
      dp[i][j]=INT_MAX;

  cout << "Min penalty is:"<<min(min_penalty(A, B, 0, n, k, p, 'a'), min_penalty(A, B, 0, n, k, p, 'b')) << endl;

  return 0;
}
