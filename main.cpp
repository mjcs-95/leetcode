#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    //v2  binary search based solution
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if(nums2.size() < nums1.size()) 
            nums1.swap(nums2);
        size_t half = (nums1.size() + nums2.size() + 1)/2; // +1 deals with a odd number of elements        
        size_t pivotL = 0; 
        size_t pivotR = nums1.size();
        while(pivotL <= pivotR){
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

    //Naive implementation of power algorithm
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1.0;        
        double sol = 1;
        for(auto i=0; i < abs(n); ++i)           
            sol = sol * x;        
        return (n > 0.0) ? sol : 1.0/sol;
    }
};