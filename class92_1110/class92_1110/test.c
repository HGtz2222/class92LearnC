#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	char name[1024];
} Student;

// ����� ��� ���� 1, ����� С�� ���� 0
// ����˼·����ȥ��һ�� int ����͵�ַ��Ӧ���ֽ�, �����Ǹ�λ���ǵ�λ
int isBigEnd() {
	int num = 0x11223344;
	int* p = &num;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		return 1;
	}
	return 0;

	// ��������д������һ�еİ汾. ���������. 
	// return *((char*)(&num)) == 0x11;
}

//void print(int arr[3][5]) {
//
//}

//void print(int(*p)[5]) { //
//}

void print(int** p) {

}

int main() {

	//Student s = { 10, "zhangsan" };
	//printf("%d\n", s.id);

	// ̸��ָ���漰�����������Ϣ:
	// 1. ������Ǽ�, p �����ڲ��洢�ľ��Ƿ����
	// 2. �����С�Ǽ�. sizeof(Student) ���Ƿ����С. 
	//Student* p = &s;
	//printf("%d\n", p->id);
	//printf("%d\n", (*p).id);

	////int a = 0x11223344;
	//char name[] = "hello";

	//printf("%d\n", isBigEnd());

	//float a = 19.0;
	//float b = a / 7.0;
	//if (b * 7.0 == a) {
	//	printf("���!\n");
	//} else {
	//	printf("�����\n");
	//}
	
	// 1e-4 => 1 * 10 ^ -4 => 0.0001
 //   #define N 1e-4
	//if (b * 7.0 - a < N && b * 7.0 - a > -N) {
	//	printf("���, �˴������ϸ����, �����������\n");
	//} else {
	//	printf("�����\n");
	//}



	//float a = 1.0;
	//float b = 2.0;
	//float c = a + b;
	//if (a + b == 3.0) {
	//	printf("���\n");
	//} else {
	//	printf("�����\n");
	//}

	//char a = 'a';
	//char* p = &a;

	//char name[1024] = "zhangsan";
	//char* p2 = name;

	//char str1[] = "hehe";
	//char str2[] = "hehe";
	//char* str3 = "hehe";
	//char* str4 = "hehe";

	//// �˴����鱾���ǲ���ֱ�ӱȽϵ�. 
	//// ����ָ�����. �˴�����������ʽת��ָ����. 
	//if (str1 == str2) {
	//	printf("���\n");
	//} else {
	//	printf("�����\n");
	//}

	//if (str3 == str4) {
	//	printf("���\n");
	//} else {
	//	printf("�����\n");
	//}

	//int* arr[4] = { 0 };

	//int arr2[4] = { 0 };
	//int(*p)[4] = &arr2;

	//printf("%p\n", arr2);
	//// arr2 ����������� int* (��Ԫ�ص�ָ��)
	//printf("%p\n", arr2 + 1);
	//// &arr2 ��������� �� int(*)[4] (ָ�������ָ��)
	//printf("%p\n", &arr2 + 1);

	// ����Ϊ 3 ��һά����, �����ÿ��Ԫ�����ǳ���Ϊ 5 ��һά����. 
	int arr[3][5] = { 0 };
	print(arr);
	
	system("pause");
	return 0;
}