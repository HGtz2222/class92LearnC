#include <stdio.h>
#include <stdlib.h>

// 由于 C 语言中数组作为参数会自动转成指针. 
// 所以此处的形参写作 char str[] 和 char* str 完全等价. 
//int strLen(char str[]) {
//	// 求字符串长度的思路就是, 从前往后遍历字符数组. 
//	// 每次读取到一个 字符 就 count++, 遇到 \0 就循环结束. 
//	int count = 0;
//	for (int i = 0; str[i] != '\0'; i++) {
//		count++;
//	}
//	return count;
//}

// 递归版本求字符串长度(没有临时变量)
// 思路就是把问题进行拆分
// 例如 str 如果是 "abcd" 
// 求 strLen("abcd") => 1 + strLen("bcd");
// 求 strLen("bcd") => 1 + strLen("cd");
// 求 strLen("cd") => 1 + strLen("d");
int strLen(char str[]) {
	if (str[0] == '\0') {
		// str 是一个空字符串 ""
		return 0;
	}
	return 1 + strLen(str + 1);
}

// 求第 N 个斐波那契数
// 两路递归. 
//int fib(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 1;
//	}
//	return fib(n - 1) + fib(n - 2);
//}

// 求第 N 个斐波那契数, 采用非递归(循环), 避免重复计算. 
int fib(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	// 接下来就直接使用循环来计算
	// 这俩变量分别表示第 i - 1 项和第 i - 2 项
	int last1 = 1;
	int last2 = 1;
	// 此处 cur 表示当前这个第 i 项
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}

//enum {
//	SIZE = 10
//};
//#define SIZE 10

int main() {
	// str 这个字符串, 里面包含的字符其实是 5 个. 
	// 最后一个位置是 '\0'
	//char str[] = "hehe";
	//int ret = strLen(str);
	//printf("ret = %d\n", ret);

	//int result = fib(50);
	//printf("result = %d\n", result);

	// 创建一个数组
	//int arr[10];
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\n", arr[i]);
	//}
	// 被初始化的数组. 
	// int arr2[4] = { 9, 5, 2, 7 };

	// 在 C89 标准中, 创建数组时, [ ] 中写的数字, 必须是 "常量" 
	// 在 C99 标准中, 是允许 [] 使用变量的. 
	// 只不过 VS 系列对于 C99 支持的很差. 

	// 如果去网上搜, 有种说法, const int 这种叫做 "常变量" (一派胡言)
	// 真实情况是, 这就是一个 C 语言的 BUG
	//const int SIZE = 10;
	//int arr[SIZE] = { 0 };

	//int arr[10] = { 1, 2, 3 };
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\n", arr[i]);
	//}

	//int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };

	// arr1 是字符数组, 但是不是字符串. (没有 \0)
	// char arr1[] = { 'a', 'b', 'c' };
	// arr2 才是字符串. 字符串是特殊的字符数组. 必须以 \0 结尾
	// char arr2[] = "abc";

	//int arr[10] = { 0 };
	//// 注意, 对于该数组来说, 下标不能是 10
	//for (int i = 0; i < 10; i++) {
	//	arr[i] = i;
	//}
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\n", arr[i]);
	//}

	//double arr[10] = { 0 };
	//for (int i = 0; i < 10; i++) {
	//	// 打印每个元素的地址. 
	//	// %p 的功能就是打印地址/指针变量
	//	// 此处使用 %d 来打印地址, 也是完全 ok 的. 
	//	// 但是咱们习惯上还是要用 %p
	//	printf("%p\n", &arr[i]);
	//}

	// 二维数组
	// [正确] 这个数组是一个 长度为 3 的一维数组, 每个元素又是一个长度为 4 的一维数组
	// [错误] 这个数组是一个 长度为 4 的一维数组, 每个元素又是一个长度为 3 的一维数组
	// 也习惯上把这个数组叫做 "3行4列"
	// int arr[3][4] = { 1, 2, 3, 4, 5 };
	int arr[][] = {
		{ 1, 2 },
		{ 3, 4 },
	};

	system("pause");
	return 0;
}