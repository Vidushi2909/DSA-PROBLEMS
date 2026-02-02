#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int trap(vector<int> &height)
{
  int n = height.size();
  int ans = 0;
  int leftmax = 0, rightmax = 0;
  int l = 0, r = n - 1;

  while (l <= r)
  {
    leftmax = max(leftmax, height[l]);
    rightmax = max(rightmax, height[r]);

    if (leftmax < rightmax)
    {
      ans += leftmax - height[l];
      l++;
    }
    else
    {
      ans += rightmax - height[r];
      r--;
    }
  }
  return ans;
}

int main()
{
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout<<trap(height)<<"\n";
}