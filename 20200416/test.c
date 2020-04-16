#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。
//归并排序做
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int numSize = nums1Size + nums2Size;
	int* num = (int*)malloc(sizeof(int)*numSize);
	int i = 0, j = 0;
	int idx = 0;
	while (i < nums1Size&& j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			num[idx++] = nums1[i];
			i++;
		}
		else {
			num[idx++] = nums2[j];
			j++;
		}
	}
	if (i < nums1Size) {
		memcpy(num + idx, nums1 + i, sizeof(int)*(nums1Size - i));
	}
	if (j < nums2Size) {
		memcpy(num + idx, nums2 + j, sizeof(int)*(nums2Size - j));
	}
	memcpy(nums1, num, sizeof(int)*numSize);
	free(num);
	double r;
	if (numSize % 2 == 0) {
		r = ((double)nums1[numSize / 2] + (double)nums1[numSize / 2 - 1]) / 2;
	}
	else {
		r = (double)nums1[(numSize - 1) / 2];
	}
	return r;
}
int main() {
	int nums1[] = {1,2 };   
	int nums2[] = { 3,4 };
	double ret = findMedianSortedArrays(nums1, 2, nums2, 2);
	printf("%1f\n", ret);
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//利用冒泡排序
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	//先将两个数组合并为一个数组
	int nums3Size = nums1Size + nums2Size;
	int* nums3 = (int*)malloc(sizeof(int)*(nums3Size));
	int idx = 0;
	for (int i = 0; i < nums1Size; i++) {
		nums3[idx++] = nums1[i];
	}
	for (int j = 0; j < nums2Size; j++) {
		nums3[idx++] = nums2[j];
	}
	//接着数组冒泡排序
	for (int i = 0; i < nums3Size; i++) {
		for (int j = nums3Size - 1; j > i; j--) {
			int tmp;
			tmp = nums3[j];
			nums3[j] = nums3[j - 1];
			nums3[j - 1] = tmp;
		}
	}
	//利用二分查找

	if (nums3Size % 2 == 0) {
		return ((double)nums3[nums3Size / 2] + (double)nums3[nums3Size / 2 - 1]) / 2;
	}
	else {
		return (double)nums3[nums3Size - 1] / 2;
	}
	return 0;
}
int main() {
	int nums1[] = { 1,2 };
	int nums2[] = { 3,4 };
	double ret = findMedianSortedArrays(nums1, 2, nums2, 2);
	printf("%1f\n", ret);
	system("pause");
	return 0;
}