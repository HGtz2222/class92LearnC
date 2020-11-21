#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A {
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

// 创建的 enum Sex 是一个新的数据类型
enum Sex {
	MALE = 100,
	FEMALE = 200,
	UNKNOWN = 300,
};

typedef enum Sex Sex;

// 创建了一个联合体
union Test {
	char a;
	short b;
	int c;
};

union IP {
	// ip 的数字表示
	int data;

	// ip 的点分十进制表示
	struct Point {
		char a;
		char b;
		char c;
		char d;
	} point;
};

// 判断大小端的问题
int isBigEnd() {
	int a = 0x11223344;
	int* p = &a;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		return 1;
	}
	return 0;
}

// 使用联合体也能实现
int isBigEnd2() {
	union Un {
		char a;
		int b;
	} u;
	u.b = 0x11223344;
	if (u.a == 0x11) {
		return 1;
	}
	return 0;
}

void func() {
	void* p = malloc(20);

	// 中间是一些处理代码

	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}
	if (xx) {
		free(p);
		return;
	}

	free(p);
}

int main() {
	func();

	//union IP ip;
	//ip.data = 0x11223344;
	//printf("%d.%d.%d.%d\n", ip.point.a, ip.point.b,
	//	ip.point.c, ip.point.d);

	//union Test t;
	//t.c = 0x11223344;
	//printf("%x\n", t.c);
	//t.a = 0x55;
	//printf("%x\n", t.c);


	// s 就是一个枚举类型的变量. 
	//Sex s = 1000;

	//// 在 C 语言中, 枚举和 int 是等价的. 
	//// 拿着枚举和 int 进行各种混合运算
	//printf("%d\n", MALE + 100);
	//printf("%d\n", MALE < 200);

	//printf("%d\n", MALE);
	//printf("%d\n", FEMALE);
	//printf("%d\n", UNKNOWN);
	
	system("pause");
	return 0;
}