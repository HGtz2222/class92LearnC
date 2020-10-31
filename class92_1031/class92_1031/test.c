#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
	// 进行相邻元素的比较和交换
	// 此处按照升序排序. 
	// 按照从后往前遍历的方式进行比较和交换. 
	// 注意排序过程中 待排序区间 和 已排序区间 的变换
	// 此处 bound 就是划分了已排序区间和待排序区间的边界
	// [0, bound) 已排序区间
	// [bound, size) 待排序区间
	for (int bound = 0; bound < size; bound++) {
		// 里层循环进行一趟遍历的实现. 此时需要从后往前
		for (int cur = size - 1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				// 交换的前提是不符合排序规则. 
				// 此处是升序排序
				// 前一个元素比后一个元素大, 就是 "不符合规则"
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

int main() {
	//int arr[3][4] = {
	//	{1, 2, 3, 4},
	//	{5, 6, 7, 8},
	//	{9, 10, 11, 12 },
	//};
	//// 二维数组在访问下标的时候呢需要两个下标. 分别表示行的下标和列的下标
	//// i 这个变量在循环中出场频率太高, 容易手滑. 
	//// i 和 j 这俩变量长的很像, 找 bug 的时候也不容易看到. 
	//for (int row = 0; row < 3; row++) {
	//	for (int col = 0; col < 4; col++) {
	//		printf("%d ", arr[row][col]);
	//	}
	//	printf("\n");
	//}

	// 冒泡排序
	int arr[] = { 9, 5, 2, 7 };
	// 按照升序排序
	bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	
	system("pause");
	return 0;
}