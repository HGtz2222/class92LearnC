

int add(int x, int y);

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



// 1. ʹ�ú궨�峣��
#define SIZE 10

// 2. ʹ�ú�������������
#define and &&
#define or ||

// 3. ʹ�ú����¶������͵ı���. 
// typedef unsigned int uint;
#define uint unsigned int

// 4. �껹�����������ؼ��ֶ������
// register ��ʾ "�Ĵ���" 
// ����ؼ����Ѿ�������. 
#define reg register

// 5. �껹�ܶ���һ�δ���Ƭ��
//    �����÷��ͺ�������
#define CHECK(ret) if (ret == 0) { \
	printf("ִ��ʧ��\n"); \
	return 1; \
}

// 6. �껹������Ϊ "���뿪��" 
//    ���Ը���������һЩ�����ܱ�����߲�����. 
//    �������������ʹ��(һ�����)
// _CRT_SECURE_NO_WARNINGS ����һ�����뿪��
// û�������Ķ����ʱ��, VS �ͻ�����һЩ���� scanf �Ⱥ�����ȫ�����߼�
// ������궨��, ��صļ�����Ͳ���������. 
// ��μ��Ĵ����� stdio.h ��ͷ. ���Ա��������궨�嵽 stdio.h ���Ϸ�

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

	// ��ʵ�ʿ������Ǳ״�������. ������һЩ�ǳ����Զ�λ������
	// �˴��Ĵ���չ�����൱�� printf("%d\n", 10 + 20);
	// (10 + 20) * (10 + 20)
	// printf("%d\n", ADD(10, 20) * ADD(10, 20));
	// (10 + 20 * 10 + 20)
	//printf("%d\n", MUL(10 + 20, 10 + 20));

	//int* p = NULL;
	//ADD(p, 10);

	// ʵ�ʿ����о�������������: 
	// �������ִ�гɹ�, �ͼ���������
	// �������ִ��ʧ��, �ͽ�������
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