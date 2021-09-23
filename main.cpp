#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {
        int totalsize = nums1.size() + nums2.size();
        int oddSize = totalsize % 2;
        size_t it1 = 0;
        size_t it2 = 0;
        int val1 = 0, val2 = 0;

        for (size_t counter = 0; counter <= totalsize / 2; counter++)
        {
            if(!oddSize)
            {
                val2 = val1;
            }
            if (it1 < nums1.size() && it2 < nums2.size())
            {
                if(nums1[it1] > nums2[it2]){
                    val1 = nums2[it2];
                    it2++;
                }else{
                    val1 = nums1[it1];
                    it1++;
                }
            }else if(it1 < nums1.size()){
                val1 = nums1[it1];
                it1++;
            }else{
                val1 = nums2[it2];
                it2++;
            }
        }
        return (oddSize) ? val1 : ((val1 + val2) / 2.0);
    }
};