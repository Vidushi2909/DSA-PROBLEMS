#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool valid(vector<int> &stalls, int k, int mid)
{
  int cows = 1;
  int n = stalls.size();
  int last = stalls[0];
  for (int i = 1; i < n; i++)
  {
    if (stalls[i] - last >= mid)
    {
      cows++;
      last = stalls[i];
    }
    if (cows == k)
      return true;
  }
  return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
  // code here
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  int high = stalls[n - 1];
  int ans = 0;
  int low = 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (!valid(stalls, k, mid))
    {

      high = mid - 1;
    }
    else
    {
      ans = mid;
      low = mid + 1;
    }
  }
  return ans;
}

int main(){
  vector<int> stalls = {1, 2, 4, 8, 9};
  int  k = 3;
  cout<<aggressiveCows(stalls,k)<<"\n";
}