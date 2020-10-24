#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int len, int toFind) {
	// 待查找区间就是 [left, right]
	// 初始情况下, left 是 0, right 是最后一个元素的下标. 
	// 最后一个元素的下标, 就是长度 - 1
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < toFind) {
			// 当前要去右侧查找
			left = mid + 1;
		} else if (arr[mid] > toFind) {
			// 当前要去左侧查找
			right = mid - 1;
		} else {
			// 找到了. 
			return mid;
		}
	}
	// 整个区间找完了, 也没找到指定的元素. 
	return -1;
}


// #include "test.h"
// int global = 0;

// #include "test.h"
// int global = 0;

// 求阶乘的普通做法
//int factor(int n) {
//	int result = 1;
//	for (int i = 1; i <= n; i++) {
//		result *= i;
//	}
//	return result;
//}

// 求阶乘的递归做法
// 非常类似于数学上的 "数学归纳法" 
// 初始条件, 1! => 1
// 递推公式, n! => n * (n - 1)!
int factor(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factor(n - 1);
}

void printNum(int n) {
	if (n > 9) {
		printNum(n / 10);
	}
	printf("%d ", n % 10);
}

int main() {
	// 创建一个函数, 针对有序数组进行二分查找
	//int arr[] = { 2, 3, 5, 7, 8, 10 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//// 注意, 这个函数的返回值表示待查找元素在数组中的下标. 
	//// 如果要查找的元素不存在, 直接返回 -1
	//int ret = binarySearch(arr, len, 10);
	//printf("ret = %d\n", ret);

	// 写一个函数, 自增 num 的值
	//int num = 0;
	//func(&num);
	//printf("num = %d\n", num);

	// 写一个函数, 通过递归的方式求 N 的阶乘
	//int n = 5;
	//int ret = factor(n);
	//printf("ret = %d\n", ret);

	int num = 1234;
	printNum(num);

	system("pause");
	return 0;
}

// 针对形参进行修改, 不会影响到实参. 
// 要想影响到实参, 就需要传指针. 
void func(int* num) {
	(*num)++;
}