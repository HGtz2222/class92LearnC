#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 求一个字符串的长度
int myStrlen(char* str) {
	//int len = 0;
	//for (int i = 0; str[i] != '\0'; i++) {
	//	len++;
	//}
	//return len;
	char* p = str;
	while (*p != '\0') {
		p++;
	}
	return p - str;
}

// 结构体的名字就相当于用户自己创建的类型的名字. 
// 这个名字随便起. 原则仍然是 "见名知意" 
//struct Student {
//	// 这些内部包含的内容, 称为 "成员" / "属性" / "字段" 
//	int id;         // 学号
//	char name[10];  // 姓名
//	int age;        // 年龄
//	double score;   // 分数
//};
//
//typedef struct Student Student;

// 这个写法就是把 struct 的定义和 typedef 合二为一. 
// 写代码的时候不要太 pia 气
typedef struct Student {
	int id;         // 学号
	char name[1024];  // 姓名
	int age;        // 年龄
	double score;   // 分数
} Student;

int main() {

	// 光有结构体类型还不够. 还需要创建结构体变量
	// C 语言中要求创建结构体变量的时候, 前面必须得有 struct 关键字. 
	// C++ 中就没有这个要求了.
	// C 语言中, 如果不想写 struct , 可以使用 typedef 来简化代码. 

	// 初始化的时候, {} 写的初始值的顺序必须和结构体定义中字段的顺序
	// 保持一致. 
	Student student = { 1, "zhangsan", 20, 95.5 };


	// 结构体的使用
	// 核心操作: 成员访问
	printf("%d\n", student.id);
	printf("%s\n", student.name);
	printf("%d\n", student.age);
	printf("%f\n", student.score);
	// 成员访问不光能读取, 也能修改. 
	student.id = 100;
	
	//student.name = "lisi";
	//student.name[0] = 'l';
	//student.name[1] = 'i';
	//student.name[2] = 's';
	//student.name[3] = 'i';
	//student.name[4] = '\0';

	// C 中提供的字符串拷贝函数. (拷贝就相当于赋值了)
	//strcpy(student.name, "李四");
	//printf("%s\n", student.name);
	printf("%d\n", strlen("李"));





	// 野指针不能解引用. 以下这俩野指针, 并不是用来解引用的
	// 而是随手一写, 只是为了演示指针运算. 
	//int* p1 = (int*)0x100;
	//int* p2 = (int*)0x110;

	//int arr[4] = { 1, 2, 3, 4 };
	//int arr3[100] = {0};
	//int arr2[4] = { 1, 2, 3, 4 };
	//int* p1 = &arr[0];
	//int* p2 = &arr2[2];
	//
	//// 指针相减得到的结果是两个地址之间隔了几个 "元素" 
	//printf("%d\n", p1 - p2);

	//int num = 10;
	//int* p = &num;

	// 判定 p 是否是空指针. 
	//if (p) {
	//	printf("不是空指针\n");
	//} else {
	//	printf("是空指针!\n");
	//}

	//if (!p) {
	//	printf("是空指针\n");
	//} else {
	//	printf("不是空指针!\n");
	//}

	// 数组会隐式转成指针. 
	// 很多场景都会产生这样的转换. 
	// 函数调用传参时会. 
	// 参与运算的时候也会. 
	//int arr[4] = { 0 };
	//printf("%d\n", sizeof(arr));
	//// 这个操作也会触发数组隐式转成指针
	//printf("%d\n", sizeof(arr + 0));

	// 指针进行 [ ] 操作. 
	//int arr[4] = { 1, 2, 3, 4 };
	//int* p = arr;
	//int* p = &arr[0];
	//for (int* p = arr; p < arr + 4; p++) {
	//	printf("%d\n", *p);
	//}
	//int* p = arr;
	//for (int i = 0; i < 4; i++) {
	//	// 最开始 C 语言的设计者, 允许指针 [ ] 的初衷是好的. 
	//	// 万万没想到, 这样写带来了一些困惑, 让指针和数组 ran 了. 
	//	printf("%d\n", p[i]);
	//	printf("%d\n", *(p + i));
	//}

	// 指针进行 [ ] 会有一些奇葩的操作. 
	//int* p = arr + 1;
	// 这个操作是允许的. 数组下标一定是 [0, size-1] 范围
	// 但是指针的下标不一定. 取决于指针初始情况下指向谁. 
	// 整体的原则就是: 保证解引用操作必须针对有效内存进行. 
	//printf("%d\n", p[-1]);
	//printf("%d\n", *(p - 1));

	//int num = 10;
	//int* p = &num;

	// 套娃
	//int** pp = &p;

	// 实际开发中, 程序猿理解不好高级指针的. 
	// 往往会通过一些技巧来化简指针, 保持低阶的状态. 
	//typedef int* IntPtr;
	//IntPtr* pp = &p;

	// 指针数组
	// 数组, 每个元素是一个指针类型的变量
	// 这个东西很常见, 也很有用. 
	//int* arr[4] = { 0 };

	// 数组指针
	// 指针, 指向了一个数组
	// 很不常见, 也没啥用. (最大的用途就是出现在面试中, 难为大家) 
	//int(*p)[4] = &arr;

	// const 和指针之间的关系
	//int num = 0;
	//int num2 = 10;

	// 背下来
	// 这个写法是限制 p 中保存的内存地址对应的变量不能被修改. 
	//const int* p = &num;

	// 这个写法和上面是一样的. 
	//int const* p = &num;

	// 这个写法是限制 p 变量本身保存的地址不能改变
	//int* const p = &num;


	// const 是在限制下方的哪种写法不能编译通过?
	//*p = 100;
	//p = &num2;
	
	system("pause");
	return 0;
}