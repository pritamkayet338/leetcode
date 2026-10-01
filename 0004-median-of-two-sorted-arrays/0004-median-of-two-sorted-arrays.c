#include <limits.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    
    // Make nums1 the smaller array
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);

    int low = 0, high = m;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {

            // Odd number of elements
            if ((m + n) % 2 == 1)
                return (double)(left1 > left2 ? left1 : left2);

            // Even number of elements
            int maxLeft = left1 > left2 ? left1 : left2;
            int minRight = right1 < right2 ? right1 : right2;

            return (maxLeft + minRight) / 2.0;
        }

        if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0;
}