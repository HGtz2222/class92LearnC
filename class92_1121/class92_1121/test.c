#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A {
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

// ������ enum Sex ��һ���µ���������
enum Sex {
	MALE = 100,
	FEMALE = 200,
	UNKNOWN = 300,
};

typedef enum Sex Sex;

// ������һ��������
union Test {
	char a;
	short b;
	int c;
};

union IP {
	// ip �����ֱ�ʾ
	int data;

	// ip �ĵ��ʮ���Ʊ�ʾ
	struct Point {
		char a;
		char b;
		char c;
		char d;
	} point;
};

// �жϴ�С�˵�����
int isBigEnd() {
	int a = 0x11223344;
	int* p = &a;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		return 1;
	}
	return 0;
}

// ʹ��������Ҳ��ʵ��
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

	// �м���һЩ�������

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


	// s ����һ��ö�����͵ı���. 
	//Sex s = 1000;

	//// �� C ������, ö�ٺ� int �ǵȼ۵�. 
	//// ����ö�ٺ� int ���и��ֻ������
	//printf("%d\n", MALE + 100);
	//printf("%d\n", MALE < 200);

	//printf("%d\n", MALE);
	//printf("%d\n", FEMALE);
	//printf("%d\n", UNKNOWN);
	
	system("pause");
	return 0;
}