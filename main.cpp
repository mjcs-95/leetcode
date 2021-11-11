#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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

    string longestPalindrome(string s)
    {
        if (s.length() < 2)
            return s;
        string palindrome = s.substr(s.length() / 2, 1);

        return palindrome;
    }

    bool isPalindrome(int x)
    {
        if (x < 0) 
            return false;
        else if(x < 10) 
            return true;
        else{
            int divideby = 1;
            while( (long) divideby * 10 < x){
                divideby = divideby * 10;
            }
            while (x > 0 )
            {
                if ((x % 10) != (x / divideby))
                    return false;
                x = (x % divideby) / 10;
                divideby = divideby / 100;
                
            }            
            return true;            
        }
    }
};



