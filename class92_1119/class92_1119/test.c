#define  _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ģ��ʵ���� isdigit
int isDigit(char c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

char toLower(char c) {
	// �ж� c �ǲ��Ǵ�д��ĸ. ���ǵĻ��Ͷ�����~~
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
		// ��Ҫ���ſ���
		for (size_t i = num - 1; i >= 0; i--) {
			*(pDest + i) = *(pSrc + i);
		}
		return dest;
	} else {
		// ����Ҫ���ſ���
		return myMemcpy(dest, src, num);
	}
}

struct Student {
	char name[1024];
	int age;
};

// C ������Ҫ��, �ṹ���ڲ����ܰ����Լ����ֽṹ�����͵ĳ�Ա. 
// C �����е�Ӳ�Թ涨. 
// ����һ��, ���� sizeof(School)
struct School {
	struct Student students;

	struct School* school;
};

// #pragma once
// ��Ĭ�϶������ĳ��� 1
// ����Ҫ���ǵ������ƽ̨��ʱ��. 
#pragma pack(1)
typedef struct A {
	char one;
	short two;
	int three;
} A;
// ��ԭ��Ĭ��ֵ
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