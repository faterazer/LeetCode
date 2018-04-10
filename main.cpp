#include "median_of_two_sorted_arrays.h"

#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[])
{
	vector<int> nums1{ 1, 3 }, nums2{ 2 };
	printf("%lf\n", findMedianSortedArrays(nums1, nums2));

	system("pause");
	return 0;
}