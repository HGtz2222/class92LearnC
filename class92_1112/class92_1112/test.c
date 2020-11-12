#include <stdio.h>
#include <stdlib.h>

void func1(int arr[10]) {

}

void func2(int arr[]) {

}

void func3(int* arr) {

}

void func4(int* arr[]) {

}

void func5(int** arr) {

}

void func6(int arr[3][4]) {

}

void func7(int arr[][4]) {

}

//void func8(int arr[][]) {
//
//}

void func9(int arr[3][5]) {

}

void func10(int arr[4][4]) {

}

void func11(int** arr) {

}

int test(int num) {
	printf("num = %d\n", num);
	return 0;
}

void test2(int a, int b) {

}

double test3() {
	return 0.0;
}

int* test4(int* a, int* b) {
	// 闹, 不是 扭
	return NULL;
}

//int add(int a, int b) {
//	return a + b;
//}
//
//int sub(int a, int b) {
//	return a - b;
//}
//
//int mul(int a, int b) {
//	return a * b;
//}

//int div(int a, int b) {
//	return a / b;
//}

// 按升序来写
// asc 为 1 认为是升序
// asc 为 0 认为是降序
// 这个方案虽然可行, 但是局限性较大. 
// 主要就是现实中的 "比较大小" 可能是一系列复杂的规则. 
// 光用一个参数作为标记就不太够用了. 
// 更通用的做法, 是使用一个回调函数. 回调函数的内容由
// 函数的调用者来决定, 这个回调函数里面写的逻辑, 就是制定了比较规则. 
void bubbleSort(int arr[], int size, int asc) {
	// [0, bound) 作为已排序区间
	// [bound, size) 作为待排序区间. 
	// 每次比较交换一趟之后, 就会把当前待排序区间的最小值, 放到
	// 已排序区间的末尾
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (asc == 1) {
				if (arr[cur - 1] > arr[cur]) {
					// 不符合升序规则, 于是就交换
					int tmp = arr[cur - 1];
					arr[cur - 1] = arr[cur];
					arr[cur] = tmp;
				}
			} else if (asc == 0) {
				if (arr[cur - 1] < arr[cur]) {
					// 不符合升序规则, 于是就交换
					int tmp = arr[cur - 1];
					arr[cur - 1] = arr[cur];
					arr[cur] = tmp;
				}
			}
		}
	}
}

// Cmp 指向一个函数, 指向的函数的参数是两个 int, 返回值也是 int
// 这个指向的函数就表示比较规则. 
// 约定:
// a 应该在 b 之前, 就让函数返回 -1
// a 应该在 b 之后, 就让函数返回 1
// a 和 b 一样大, 就返回 0
typedef int(*Cmp)(int a, int b);

void bubbleSort2(int arr[], int size, Cmp cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			// cur - 1 的位置在前
			// cur 的位置在后
			// 如果发现 cmp 的函数返回值 为 1
			if (cmp(arr[cur - 1], arr[cur]) == 1 ) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

// 如果按照升序排序
// a 应该在 b 之前, 就让函数返回 -1
// a 应该在 b 之后, 就让函数返回 1
// a 和 b 一样大, 就返回 0
int less(int a, int b) {
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1;
	}
	return 1;
}

int main() {

	int arr[] = { 9, 5, 2, 7 };
	bubbleSort2(arr, 4, less);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}

	//typedef int(*Func)(int, int);
	//Func arr[] = {
	//	NULL,
	//	add,
	//	sub,
	//	mul,
	//	div,
	//};

	//while (1) {
	//	int choice = 0;
	//	int a = 0;
	//	int b = 0;
	//	int ret = 0;
	//	printf("请输入您的选择: ", &choice);
	//	scanf("%d", &choice);
	//	printf("请输入两个操作数: ");
	//	scanf("%d %d", &a, &b);
	//	//if (choice == 1) {
	//	//	ret = add(a, b);
	//	//} else if (choice == 2) {
	//	//	ret = sub(a, b);
	//	//} else if (choice == 3) {
	//	//	ret = mul(a, b);
	//	//} else if (choice == 4) {
	//	//	ret = div(a, b);
	//	//}
	//	int ret = arr[choice](a, b);
	//	printf("ret = %d\n", ret);
	//}

	// 这个函数指针的 "准确的类型" 是啥?
	//printf("%p\n", test);

	// 这个代码就是创建了一个变量 p, 用来保存 test 的函数指针. 
	// 类型就是 int(*)(int)   
	// 此处的形参的变量名可以省略. 

	// 这都是针对函数指针进行了规则上的特殊处理. 需要大家记住. 
	//int(*p)(int) = test;
	//int(*p)(int) = &test;  // 这种写法和上面是等价的. 

	//p(1);
	//(*p)(1);  // 这种写法和上面也是等价

	// 这个操作等价于 test(1);

	//void(*p2)(int, int) = test2;

	//double(*p3)() = test3;

	//int*(*p4)(int*, int*) = test4;

	//// 定义出来的类型的别名就是 FuncPtr , 类型就是 int*(*)(int*, int*)
	//typedef int*(*FuncPtr)(int*, int*);
	//FuncPtr p5 = test4;

	//int arr[3][4] = { 0 };
	//func7(arr);
	//func8(arr);
	//func9(arr);
	//func10(arr);
	//func11(arr);

	//int arr[10] = { 0 };
	//int* arr2[10] = { 0 };

	//func1(arr);
	//func2(arr);
	//func3(arr);
	//func4(arr);
	//func5(arr);

	//func1(arr2);
	//func4(arr2);


	system("pause");
	return 0;
}