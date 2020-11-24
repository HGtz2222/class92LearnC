#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一些典型的错误案例

// 这个代码的问题在于, 申请了一个比较大的内存空间, 可能申请失败. 
// 如果申请失败, 就会返回 NULL, 也就无法解引用了. 
void func1() {
	// 2^31  => 2^10  * 2^10  *  2^10 * 2 ^ 1
	int* p = (int*)malloc(INT_MAX);
	*p = 100;
	printf("%p %d\n", p, *p);
	free(p);
}

void func2() {
	// 普通的数组的长度是编译过程就确定的, 数组长度不能是变量. 
	//int a[10] = { 0 };

	// 此处我们也可以把这个 p 理解成是一个 "动态的数组" 
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

	// calloc 申请的内存, 也需要使用 free 来释放. 
	// 如果不释放, 效果仍然是 内存泄露. 
	//void* p = calloc(10, 4);

	// malloc 的使用更加常见一些, 而很少使用 calloc. 主要原因
	// 实际开发中不一定是要把内存初始化成全 0. 
	// 如果需要初始化成全 0, 那就多加一句 memset, 此时也不是啥大的成本. 
	//void* p2 = malloc(10 * 4);
	//memset(p2, 0, 10 * 4);

	// realloc 负责对已经 malloc 申请出的内存空间进行扩容
	//// p => 0x100
	//void* p = malloc(10);
	//// p => 0x100??
	//p = realloc(p, 20);


	system("pause");
	return 0;
}