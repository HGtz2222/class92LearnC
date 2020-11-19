#define  _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 模拟实现下 isdigit
int isDigit(char c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

char toLower(char c) {
	// 判定 c 是不是大写字母. 不是的话就都不改~~
	if (c <= 'Z' && c >= 'A') {
		c += ('a' - 'A');
	}
	return c;
}

void* myMemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pDest = (char*)dest;
	char* pSrc = (char*)src;
	for (size_t i = 0; i < num; i++) {
		//*(dest + i) = *(src + i);
		*(pDest + i) = *(pSrc + i);
	}
	return dest;
}

void* myMemmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pDest = (char*)dest;
	char* pSrc = (char*)src;
	if (pSrc <= pDest && pDest <= pSrc + num) {
		// 需要反着拷贝
		for (size_t i = num - 1; i >= 0; i--) {
			*(pDest + i) = *(pSrc + i);
		}
		return dest;
	} else {
		// 不需要反着拷贝
		return myMemcpy(dest, src, num);
	}
}

struct Student {
	char name[1024];
	int age;
};

// C 语言中要求, 结构体内部不能包含自己这种结构体类型的成员. 
// C 语言中的硬性规定. 
// 想象一下, 计算 sizeof(School)
struct School {
	struct Student students;

	struct School* school;
};

// #pragma once
// 把默认对齐数改成了 1
// 当需要考虑到代码跨平台的时候. 
#pragma pack(1)
typedef struct A {
	char one;
	short two;
	int three;
} A;
// 还原成默认值
#pragma pack()

int main() {
	A a;
	printf("%d\n", sizeof(a));
	printf("%p\n", &a);
	printf("%p\n", &a.one);
	printf("%p\n", &a.two);
	printf("%p\n", &a.three);


	//char str[] = "I am a student";
	//char* p = strtok(str, " ");
	//while (p != NULL) {
	//	printf("%s\n", p);
	//	p = strtok(NULL, " ");
	//}

	// memcpy
	//int arr[4] = { 1, 2, 3, 4 };
	//int arr2[4] = { 0 };
	//memcpy(arr2, arr, sizeof(arr));
	//for (int i = 0; i < 4; i++) {
	//	printf("%d\n", arr2[i]);
	//}

	system("pause");
	return 0;
}