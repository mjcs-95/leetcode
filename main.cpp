#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    //v2  binary search based solution
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
            nums1.swap(nums2);
        size_t half = (nums1.size() + nums2.size() + 1) / 2; // +1 deals with a odd number of elements
        size_t pivotL = 0;
        size_t pivotR = nums1.size();
        while (pivotL <= pivotR)
        {
            size_t it1 = (pivotL + pivotR) / 2;
            size_t it2 = half - it1;
            int leftElementNums1 = (it1 > 0) ? nums1[it1 - 1] : INT_MIN;
            int rightElementNums1 = (it1 < nums1.size()) ? nums1[it1] : INT_MAX;
            int leftElementNums2 = (it2 > 0) ? nums2[it2 - 1] : INT_MIN;
            int rightElementNums2 = (it2 < nums2.size()) ? nums2[it2] : INT_MAX;
            if (leftElementNums1 <= rightElementNums2 && leftElementNums2 <= rightElementNums1)
            {
                if ((nums1.size() + nums2.size()) % 2 == 0)
                {
                    return (max(leftElementNums1, leftElementNums2) + min(rightElementNums1, rightElementNums2)) / 2.0;
                }
                return max(leftElementNums1, leftElementNums2);
            }
            else if (leftElementNums1 > rightElementNums2)
            {
                pivotR = it1 - 1;
            }
            else
            {
                pivotL = it1 + 1;
            }
        }
        return 0;
    }

    //improved solution of mypow
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1.0)
            return 1.0;
        if (x == -1.0)
            return (n % 2 == 0) ? 1.0 : -1.0;
        long target = n;
        if (target < 0)
            target = -target;
        double sol = 1.0;
        while (target > 0)
        {
            if (target % 2 == 0)
            {
                x = x * x;
                target = target / 2;
            }
            else
            {
                --target;
                sol = sol * x;
            }
        }
        return (n > 0.0) ? sol : 1.0 / sol;
    }

    void rotate(vector<vector<int>> &matrix)
    {
        auto N = matrix[0].size();
        for (auto depth = 0; depth < N / 2; ++depth)
        {
            for (auto rowPosition = depth; rowPosition < N - depth - 1; ++rowPosition)
            {
                //backup of first deleted position
                int temp = matrix[depth][rowPosition];
                //We rotate 4 pixels in each loop
                long coord1 = N - 1 - rowPosition;
                long coord2 = N - 1 - depth;
                matrix[depth][rowPosition] = matrix[coord1][depth];
                matrix[coord1][depth] = matrix[coord2][coord1];
                matrix[coord2][coord1] = matrix[rowPosition][coord2];
                matrix[rowPosition][coord2] = temp;
            }
        }
    }

    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1;)
            if (nums[i] == nums[++i])
                return true;
        return false;
    }

    int reverse(int x)
    {
        int negative = x < 0;
        x = abs(x);
        int sol = 0;
        for (int i = 0; 0 < x; ++i)
        {
            if (sol > INT_MAX / 10)
                return 0;
            sol = sol * 10 + x % 10;
            x = x / 10;
        }
        return (negative) ? -sol : sol;
    }

    int romanToInt(string s)
    {
        unordered_map<char, int> hash{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int sol = 0;
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (hash[s[i]] < hash[s[i + 1]])
            {
                sol += hash[s[i + 1]] - hash[s[i++]];
            }
            else
            {
                sol += hash[s[i]];
            }
        }
        return sol;
    }
};
