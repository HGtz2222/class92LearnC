#include <stdio.h>
#include <stdlib.h>

int* func() {
	int a = 10;
	return &a;
}

// 写一个函数递归求字符串的长度
int myStrlen(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

int main() {
	// int num = 10;

	// 此处的 & 不是逻辑与了, 而是取地址操作. 
	// printf("%p\n", &num);

	// 创建指针变量
	// 此处的 int* 是一个整体, 表示一种数据类型. 
	// int* 和 int, double, float 这些类型是并列的关系. 
	//int* p = &num;
	//int* p = NULL;
	//printf("%d\n", *p);
	// 上面的代码是一个典型的错误. "未定义行为" 
	// 内存访问越界. (访问了非法的内存). 因为 100 地址对应的内存
	// 之前不曾申请到, 拿来直接就用, 就会产生未定义行为. 
	// 最终的效果, 可能会读取一个看起来靠谱的数据, 也可能是个随机值, 
	// 还可能是程序直接崩溃. 

	// 指针变量的类型有很多种. 
	// 这些类型都是不同类型. (严谨的说, 指针类型是一个 "统称" )
	//char a = 'a';
	//char* pa = &a;

	//short b = 10;
	//short* pb = &b;

	//int c = 20;
	//int* pc = &c;

	//printf("%d\n", sizeof(pa));
	//printf("%d\n", sizeof(pb));
	//printf("%d\n", sizeof(pc));

	//int* p = func();
	//printf("%d\n", *p);

	//int num = 10;
	//int* p = &num;
	//void* p2 = p;
	//printf("%d\n", *p2);

	//double* p = 0x100;
	//printf("%p\n", p - 1);

	//short* p2 = NULL;
	//printf("%p\n", p2 + 2);

	//int* p3 = NULL;
	//printf("%p\n", p3 + 2);

	//double* p4 = NULL;
	//printf("%p\n", p4 + 2);

	//void* p5 = NULL;
	//printf("%p\n", p5 + 1);

	system("pause");
	return 0;
}