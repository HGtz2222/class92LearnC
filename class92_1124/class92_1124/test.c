#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// һЩ���͵Ĵ�����

// ����������������, ������һ���Ƚϴ���ڴ�ռ�, ��������ʧ��. 
// �������ʧ��, �ͻ᷵�� NULL, Ҳ���޷���������. 
void func1() {
	// 2^31  => 2^10  * 2^10  *  2^10 * 2 ^ 1
	int* p = (int*)malloc(INT_MAX);
	*p = 100;
	printf("%p %d\n", p, *p);
	free(p);
}

void func2() {
	// ��ͨ������ĳ����Ǳ�����̾�ȷ����, ���鳤�Ȳ����Ǳ���. 
	//int a[10] = { 0 };

	// �˴�����Ҳ���԰���� p ������һ�� "��̬������" 
	int size = 10 * sizeof(int);
	int* p = (int*)malloc(size);
	memset(p, 0, size);
	for (int i = 0; i <= 10; i++) {
		printf("%d\n", p[i]);
	}
	free(p);
}

int factor(int n) {
	//if (n == 1) {
	//	return 1;
	//}
	printf("%d\n", n);
	return n * factor(n - 1);
}

int main() {
	char arr[1024 * 900];

	//func1();
	//func2();

	//void* p = malloc(10);
	//free(p);
	//p = NULL;
	//free(p);

	//char* p = (char*)malloc(10);
	//p++;
	//free(p);

	// calloc ������ڴ�, Ҳ��Ҫʹ�� free ���ͷ�. 
	// ������ͷ�, Ч����Ȼ�� �ڴ�й¶. 
	//void* p = calloc(10, 4);

	// malloc ��ʹ�ø��ӳ���һЩ, ������ʹ�� calloc. ��Ҫԭ��
	// ʵ�ʿ����в�һ����Ҫ���ڴ��ʼ����ȫ 0. 
	// �����Ҫ��ʼ����ȫ 0, �ǾͶ��һ�� memset, ��ʱҲ����ɶ��ĳɱ�. 
	//void* p2 = malloc(10 * 4);
	//memset(p2, 0, 10 * 4);

	// realloc ������Ѿ� malloc ��������ڴ�ռ��������
	//// p => 0x100
	//void* p = malloc(10);
	//// p => 0x100??
	//p = realloc(p, 20);


	system("pause");
	return 0;
}