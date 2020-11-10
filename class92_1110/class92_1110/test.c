#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	char name[1024];
} Student;

// 如果是 大端 返回 1, 如果是 小端 返回 0
// 核心思路就是去除一个 int 的最低地址对应的字节, 看看是高位还是低位
int isBigEnd() {
	int num = 0x11223344;
	int* p = &num;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		return 1;
	}
	return 0;

	// 不建议大家写成缩成一行的版本. 不利于理解. 
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

	// 谈到指针涉及到两方面的信息:
	// 1. 房间号是几, p 变量内部存储的就是房间号
	// 2. 房间大小是几. sizeof(Student) 就是房间大小. 
	//Student* p = &s;
	//printf("%d\n", p->id);
	//printf("%d\n", (*p).id);

	////int a = 0x11223344;
	//char name[] = "hello";

	//printf("%d\n", isBigEnd());

	//float a = 19.0;
	//float b = a / 7.0;
	//if (b * 7.0 == a) {
	//	printf("相等!\n");
	//} else {
	//	printf("不相等\n");
	//}
	
	// 1e-4 => 1 * 10 ^ -4 => 0.0001
 //   #define N 1e-4
	//if (b * 7.0 - a < N && b * 7.0 - a > -N) {
	//	printf("相等, 此处不是严格相等, 而是允许误差\n");
	//} else {
	//	printf("不相等\n");
	//}



	//float a = 1.0;
	//float b = 2.0;
	//float c = a + b;
	//if (a + b == 3.0) {
	//	printf("相等\n");
	//} else {
	//	printf("不相等\n");
	//}

	//char a = 'a';
	//char* p = &a;

	//char name[1024] = "zhangsan";
	//char* p2 = name;

	//char str1[] = "hehe";
	//char str2[] = "hehe";
	//char* str3 = "hehe";
	//char* str4 = "hehe";

	//// 此处数组本来是不能直接比较的. 
	//// 但是指针可以. 此处数组名又隐式转成指针了. 
	//if (str1 == str2) {
	//	printf("相等\n");
	//} else {
	//	printf("不相等\n");
	//}

	//if (str3 == str4) {
	//	printf("相等\n");
	//} else {
	//	printf("不相等\n");
	//}

	//int* arr[4] = { 0 };

	//int arr2[4] = { 0 };
	//int(*p)[4] = &arr2;

	//printf("%p\n", arr2);
	//// arr2 单独拎出来是 int* (首元素的指针)
	//printf("%p\n", arr2 + 1);
	//// &arr2 单独拎出来 是 int(*)[4] (指向数组的指针)
	//printf("%p\n", &arr2 + 1);

	// 长度为 3 的一维数组, 里面的每个元素又是长度为 5 的一维数组. 
	int arr[3][5] = { 0 };
	print(arr);
	
	system("pause");
	return 0;
}