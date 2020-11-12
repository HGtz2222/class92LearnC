#include <stdio.h>
#include <stdlib.h>

void func1(int arr[10]) {

}

void func2(int arr[]) {

}

void func3(int* arr) {

}

void func4(int* arr[]) {

}

void func5(int** arr) {

}

void func6(int arr[3][4]) {

}

void func7(int arr[][4]) {

}

//void func8(int arr[][]) {
//
//}

void func9(int arr[3][5]) {

}

void func10(int arr[4][4]) {

}

void func11(int** arr) {

}

int test(int num) {
	printf("num = %d\n", num);
	return 0;
}

void test2(int a, int b) {

}

double test3() {
	return 0.0;
}

int* test4(int* a, int* b) {
	// ��, ���� Ť
	return NULL;
}

//int add(int a, int b) {
//	return a + b;
//}
//
//int sub(int a, int b) {
//	return a - b;
//}
//
//int mul(int a, int b) {
//	return a * b;
//}

//int div(int a, int b) {
//	return a / b;
//}

// ��������д
// asc Ϊ 1 ��Ϊ������
// asc Ϊ 0 ��Ϊ�ǽ���
// ���������Ȼ����, ���Ǿ����Խϴ�. 
// ��Ҫ������ʵ�е� "�Ƚϴ�С" ������һϵ�и��ӵĹ���. 
// ����һ��������Ϊ��ǾͲ�̫������. 
// ��ͨ�õ�����, ��ʹ��һ���ص�����. �ص�������������
// �����ĵ�����������, ����ص���������д���߼�, �����ƶ��˱ȽϹ���. 
void bubbleSort(int arr[], int size, int asc) {
	// [0, bound) ��Ϊ����������
	// [bound, size) ��Ϊ����������. 
	// ÿ�αȽϽ���һ��֮��, �ͻ�ѵ�ǰ�������������Сֵ, �ŵ�
	// �����������ĩβ
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (asc == 1) {
				if (arr[cur - 1] > arr[cur]) {
					// �������������, ���Ǿͽ���
					int tmp = arr[cur - 1];
					arr[cur - 1] = arr[cur];
					arr[cur] = tmp;
				}
			} else if (asc == 0) {
				if (arr[cur - 1] < arr[cur]) {
					// �������������, ���Ǿͽ���
					int tmp = arr[cur - 1];
					arr[cur - 1] = arr[cur];
					arr[cur] = tmp;
				}
			}
		}
	}
}

// Cmp ָ��һ������, ָ��ĺ����Ĳ��������� int, ����ֵҲ�� int
// ���ָ��ĺ����ͱ�ʾ�ȽϹ���. 
// Լ��:
// a Ӧ���� b ֮ǰ, ���ú������� -1
// a Ӧ���� b ֮��, ���ú������� 1
// a �� b һ����, �ͷ��� 0
typedef int(*Cmp)(int a, int b);

void bubbleSort2(int arr[], int size, Cmp cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			// cur - 1 ��λ����ǰ
			// cur ��λ���ں�
			// ������� cmp �ĺ�������ֵ Ϊ 1
			if (cmp(arr[cur - 1], arr[cur]) == 1 ) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

// ���������������
// a Ӧ���� b ֮ǰ, ���ú������� -1
// a Ӧ���� b ֮��, ���ú������� 1
// a �� b һ����, �ͷ��� 0
int less(int a, int b) {
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1;
	}
	return 1;
}

int main() {

	int arr[] = { 9, 5, 2, 7 };
	bubbleSort2(arr, 4, less);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}

	//typedef int(*Func)(int, int);
	//Func arr[] = {
	//	NULL,
	//	add,
	//	sub,
	//	mul,
	//	div,
	//};

	//while (1) {
	//	int choice = 0;
	//	int a = 0;
	//	int b = 0;
	//	int ret = 0;
	//	printf("����������ѡ��: ", &choice);
	//	scanf("%d", &choice);
	//	printf("����������������: ");
	//	scanf("%d %d", &a, &b);
	//	//if (choice == 1) {
	//	//	ret = add(a, b);
	//	//} else if (choice == 2) {
	//	//	ret = sub(a, b);
	//	//} else if (choice == 3) {
	//	//	ret = mul(a, b);
	//	//} else if (choice == 4) {
	//	//	ret = div(a, b);
	//	//}
	//	int ret = arr[choice](a, b);
	//	printf("ret = %d\n", ret);
	//}

	// �������ָ��� "׼ȷ������" ��ɶ?
	//printf("%p\n", test);

	// ���������Ǵ�����һ������ p, �������� test �ĺ���ָ��. 
	// ���;��� int(*)(int)   
	// �˴����βεı���������ʡ��. 

	// �ⶼ����Ժ���ָ������˹����ϵ����⴦��. ��Ҫ��Ҽ�ס. 
	//int(*p)(int) = test;
	//int(*p)(int) = &test;  // ����д���������ǵȼ۵�. 

	//p(1);
	//(*p)(1);  // ����д��������Ҳ�ǵȼ�

	// ��������ȼ��� test(1);

	//void(*p2)(int, int) = test2;

	//double(*p3)() = test3;

	//int*(*p4)(int*, int*) = test4;

	//// ������������͵ı������� FuncPtr , ���;��� int*(*)(int*, int*)
	//typedef int*(*FuncPtr)(int*, int*);
	//FuncPtr p5 = test4;

	//int arr[3][4] = { 0 };
	//func7(arr);
	//func8(arr);
	//func9(arr);
	//func10(arr);
	//func11(arr);

	//int arr[10] = { 0 };
	//int* arr2[10] = { 0 };

	//func1(arr);
	//func2(arr);
	//func3(arr);
	//func4(arr);
	//func5(arr);

	//func1(arr2);
	//func4(arr2);


	system("pause");
	return 0;
}