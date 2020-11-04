#include <stdio.h>
#include <stdlib.h>

void print() {
	printf("hehe\n");
}

int countOneBit(int num) {
	// 依次取 1, 10, 100... 这些数字和 num 进行按位与. 
	// 取1运算时, 相当于把 num 的最后一位取出来了. 
	// 取10运算时, 相当于把 num 的倒数第二位取出来了....
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (num & (1 << i)) {
			count++;
		}
	}
	return count;
}

#define and &&
#define or ||

#define 整型 int
#define 如果 if
#define 否则 else

// 写一个函数, 求出两个数字较大的值再+100 的结果. 
int maxNum(int x, int y) {
	//if (x > y) {
	//	return x;
	//}
	//return y;
	return x > y ? x : y + 100;
}

int main() {
	//int num = 11;
	//
	//int ret = countOneBit(num);
	//printf("%d\n", ret);

	//const int a = 10;
	//a = 20;

	// 非常不建议这么写. 
	//int a;
	//a = 10;
	//int a = 10;

	// 例如代码中有三个变量
	// 第一种写法(旧版本 C 编译器强制要求这么写)
	//int a = 10;
	//int b = 20;
	//int c = 30;

	//// 这里有一段很长的代码. 

	//printf("%d\n", a);
	//printf("%d\n", b);
	//printf("%d\n", c);

	// 第二种写法(更推荐)
	// 一个变量最好在使用之前去创建. 
	// 而不要创建了之后, 隔了很久再去使用. 
	//int a = 10;
	//printf("%d\n", a);

	//int b = 20;
	//printf("%d\n", b);

	//int c = 30;
	//printf("%d\n", c);

	//int a = 10;
	//int b = 20;

	// 不要写作
	//int a = 10, b = 20;

	//int num = 10;
	//num += 1;
	//// 在 C 语言中, 两者是等价的
	//num = num + 1;
	
	//int num = 10;
	//printf("%d\n", --num);

	//printf("%d\n", sizeof(int));

	//int arr[10] = { 0 };
	// A. 4
	// B. 40
	// C. 未定义行为
	// 注意, 此处的结果 4 , 并不是未定义行为. 
	// sizeof 是一个特殊的运算符, 一个重要的特性是: 编译期求值. 
	//printf("%d\n", sizeof(arr[10]));

	//int num = 0;
	// ! 逻辑取反, 是把操作数, 当成 "真, 假" 来看待. 
	// C 语言中, 非0 都表示真, 0 表示假. 
	// 此时  ! 就是在真假值的基础上进行取反. 
	//printf("%x\n", !num);
	//printf("%x\n", ~num);

	//printf("%d\n", 1 > 2);

	//int a = 1;	// 01
	//int b = 2;	// 10
	//printf("%d\n", a & b);
	//printf("%d\n", a and b);

	//整型 i = 10;
	//如果(i < 10) {
	//	printf("wocao\n");
	//} 否则{
	//	printf("hehe\n");
	//}

	//int i = 0, a = 0, b = 2, c = 3, d = 4;
	// a++ 返回值是 0, 按照短路求值的规则, 此时, b, c, d 的表达式都不进行求值了. 
	//i = a++ && ++b && c++ && d++;
	//i = a++||++b||c++ || d++;
	//printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);

	//int arr[3][4] = {
	//	(1, 2), 
	//	(3, 4)
	//};

	// 这是函数调用
	//print(); 

	// 这个操作其实是取到了函数指针
	//print;

	//int a = 10;
	//float b = 1.5;
	////b = a;
	//a = b;
	//printf("%d\n", a);

	// 2 个字节, -32768 -> +32767 (要记住)    无符号 0->65535
	//short a = 10;
	// 4 个字节, -21亿 -> +21亿  无符号 0-> 42亿9千万
	//int b = 100000;
	
	//a = b;
	//printf("%d\n", a);

	int i = 1;
	int ret = ++i + ++i + ++i;
	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}