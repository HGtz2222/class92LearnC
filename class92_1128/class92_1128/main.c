

int add(int x, int y);

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



// 1. 使用宏定义常量
#define SIZE 10

// 2. 使用宏给运算符重命名
#define and &&
#define or ||

// 3. 使用宏重新定义类型的别名. 
// typedef unsigned int uint;
#define uint unsigned int

// 4. 宏还可以用来给关键字定义别名
// register 表示 "寄存器" 
// 这个关键字已经废弃了. 
#define reg register

// 5. 宏还能定义一段代码片段
//    这种用法和函数很像
#define CHECK(ret) if (ret == 0) { \
	printf("执行失败\n"); \
	return 1; \
}

// 6. 宏还可以作为 "编译开关" 
//    可以根据条件让一些代码能编译或者不编译. 
//    结合条件编译来使用(一会介绍)
// _CRT_SECURE_NO_WARNINGS 就是一个编译开关
// 没有这个宏的定义的时候, VS 就会多编译一些对于 scanf 等函数安全检查的逻辑
// 有这个宏定义, 相关的检查代码就不被编译了. 
// 这段检查的代码在 stdio.h 里头. 所以必须把这个宏定义到 stdio.h 的上方

int login() { return 1; }
int enterRoom() { return 1; }
int startMatch() { return 1; }
int acceptGame() { return 1; }

#define ADD(x, y) ((x) + (y))
#define MUL(x, y) ((x) * (y))

#define PRINT(FORMAT, VALUE)\
	printf("the value of " #VALUE " is "FORMAT "\n", VALUE);

#define ADD_TO_SUM(num, value) \
	sum##num += value;

int main() {
	int sum1 = 0;
	int sum2 = 0;

	ADD_TO_SUM(1, 10);
	ADD_TO_SUM(2, 20);


	//int i = 10;
	//PRINT("%d", (i + 2));

	// 宏实际开发中是弊大于利的. 会引入一些非常难以定位的问题
	// 此处的代码展开就相当于 printf("%d\n", 10 + 20);
	// (10 + 20) * (10 + 20)
	// printf("%d\n", ADD(10, 20) * ADD(10, 20));
	// (10 + 20 * 10 + 20)
	//printf("%d\n", MUL(10 + 20, 10 + 20));

	//int* p = NULL;
	//ADD(p, 10);

	// 实际开发中经常有这种需求: 
	// 如果程序执行成功, 就继续往下走
	// 如果程序执行失败, 就结束程序
	//int ret = 0;
	//ret = login();
	//CHECK(ret);
	//ret = enterRoom();
	//CHECK(ret);
	//ret = startMatch();
	//CHECK(ret);
	//ret = acceptGame();
	//CHECK(ret);


	//int ret = add(10, 20);
	//printf("ret = %d\n", ret);
	//// printf("%d\n", __STDC__);

	// int num = 10;;
	// int num = SIZE;

	// int arr[10;] = {0};
	// int arr[SIZE] = { 0 };

	system("pause");
	return 0;
}