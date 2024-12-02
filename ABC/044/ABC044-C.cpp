// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//   int N, A;
//   cin >> N >> A;
//   vector<int> x(N);
  
//   // Input the card values and adjust by subtracting A
//   for (int i = 0; i < N; i++)
//     cin >> x[i], x[i] -= A; // Adjusting by subtracting A

//   // DP array, initialized to 0
//   ll dp[51][5000];
//   memset(dp, 0, sizeof(dp));

//   // Base case: There's one way to achieve sum 0 with no cards selected
//   dp[0][2500] = 1;

//   // DP transitions
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < 5000; j++) {
//       if (dp[i][j] > 0) {  // If there's a way to achieve sum j
//         // Do not select the current card
//         dp[i + 1][j] += dp[i][j];

//         // Select the current card
//         dp[i + 1][j + x[i]] += dp[i][j];
//       }
//     }
//   }

//   // The answer is dp[N][2500] (sum 0), subtract 1 to exclude the empty subset
//   cout << dp[N][2500] - 1 << endl;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int N,A;
  cin>>N>>A;
  vector<int>x(N);
  for(int i=0;i<N;i++){
    cin>>x[i];
    x[i]-=A;
  }
  // no basically every element is decreased by A now we just check if the sum is equal to zero
  // there are basicaly 5000 probablities of getting a sum from -2450 to +2450 as it is -49*50 to +49*50 
  // we decalre a dp array to bascilaly no that 
  ll dp[51][5000];
  // now the base condition which is there is only one way to get sum 0 with no cards being selected 
  memset(dp,0,sizeof(dp));
  dp[0][2500]=1;

  for(int i=0;i<N;i++){
    for(int j=0;j<5000;j++){
      if(dp[i][j]>0){
        // there are 2 choices for us either choose the card 
        // or not choose the card 
        // not choosing the card
        dp[i+1][j]+=dp[i][j];
        // choosing the card
        dp[i+1][j+x[i]]+=dp[i][j];
      }
    }
    // the final answer is stored in the N2500-1 we subract one coz there is one possiblity where there is no cards null set we remove that
  }
  cout<<dp[N][2500]-1<<endl;
}
