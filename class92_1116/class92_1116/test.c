#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// 由于无法保证调用者传入一个啥样的参数. 比如极端情况下传入一个非法地址. 
// 就需要尽量让代码能比较健壮. 
// 应该在函数的入口处加上对于参数合法性的校验
// 在 C 语言中, 这种情况, 没办法, 无解~~~ . 
// 所谓的 判空 只是 "聊胜于无" 的操作. 并不能从根本上解决传入非法参数的问题. 

// 这里针对参数的合法性检查有两种风格: 
// 1. if
// 2. assert 断言: ( ) 写一个表达式, 如果表达式为真, 断言没有任何效果,
//    代码继续执行. 如果表达式为假, 程序就会直接崩溃
size_t myStrlen(const char* str) {
	// 在调用函数的内部进行判定
	if (str == NULL) {
		return 0;
	}

	size_t len = 0;
	// str[len] => *(str + len)
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

char* myStrcpy(char* dest, const char* src) {
	// 千万不要忘记合法性校验. 虽然没啥实际卵用, 但是体现了你的意识. 
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	// 函数返回值就是最原始的参数 dest
	char* ret = dest;
	while (*src != '\0') {
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return ret;
}

char* myStrcat(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return dest;
	}
	// strcat 和 strcpy 是非常类似的. 
	// strcpy 是把 src 的内容拷贝到 dest 的开始位置. 
	// strcat 是吧 src 的内容拷贝到 dest 的结束位置. 

	// 需要先找到 dest 的结束位置. 
	char* p = dest;
	while (*p != '\0') {
		p++;
	}
	// 当循环结束后, p 指向的位置, 就是 dest 的末尾. 
	while (*src != '\0') {
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return dest;
}

int myStrcmp(const char* str1, const char* str2) {
	// 一定要记得, 先校验参数的合法性. 
	// 此处发现参数非法的时候, 并不容易找到一个返回值作为非法结果. 
	// 在 C 中没啥太好的办法. 未来 C++ 和 Java 里有一手操作 抛出异常
	assert(str1 != NULL && str2 != NULL);

	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			// 此时打成平手了, 需要比较下一个字符
			str1++;
			str2++;
		}
	}
	// 如果上面的循环已经结束了, 还没有触发 return , 可能就是这种情况:
	// hehe  和  hehehe 的比较
	// 接下来就需要看谁短谁就小. 直接看当前位置的 str1 和 str2 指向的内容大小就行了. 
	// 这俩指针中至少一个是 \0 , 另一个就更大. 
	// 如果两个都是 \0, 就是相等
	if (*str1 < *str2) {
		return -1;
	} else if (*str1 > *str2) {
		return 1;
	} else {
		return 0;
	}
	//return *str1 - *str2;
}

const char* myStrstr(const char* str1, const char* str2) {
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}

	// blackPtr 确定了当前这趟比较的起始位置. 
	const char* blackPtr = str1;

	while (*blackPtr != '\0') {
		// 就要根据当前的起始位置, 进一步的比较 str1 的内容和 str2 的内容
		// 这里面就需要两个辅助的指针, 一个是 redPtr, 一个是 subPtr
		const char* redPtr = blackPtr;
		const char* subPtr = str2;

		// 这个循环就是以当前的 blackPtr 为起点, 进行一趟比较
		while (*redPtr != '\0' && *subPtr != '\0'
			&& *redPtr == *subPtr) {
			redPtr++;
			subPtr++;
		}
		// 当循环结束之后, 就有三种可能: 
		// 1) 如果是 *redPtr != '\0' 条件不成立, 此时, 就是不匹配
		//    这个时候就应该 blackPtr++ 再找下个起始位置. 
		// 2) 如果是 *subPtr != '\0' 条件不成立, 此时是找到匹配的结果了
		//    就应该返回 blackPtr
		// 3) 如果是 *redPtr == *subPtr 不成立, 此时也应该是 blackPtr++
		if (*subPtr == '\0') {
			return blackPtr;
		}
		blackPtr++;
	}
	return NULL;
}

int main() {
	//unsigned int a = 10;
	//unsigned int b = 20;
	//unsigned int c = a - b;
	//// %u 打印的是 无符号 的整数. 
	//printf("%u\n", c);

	//char* str = NULL;
	//// 调用函数的外部进行判定. 
	//if (str != NULL) {
	//    printf("%d\n", myStrlen(str));
	//}
	
	//char name[5] = "hehe";
	//// name = "lisi";
	//strcpy(name, "lisisi");
	//printf("%s\n", name);

	// strcpy 返回值类型是个 char*, 目的是为了实现 链式调用
	//char name1[1024] = "";
	//char name2[1024] = "";
	//strcpy(name1, "zhangsan");
	//strcpy(name2, "zhangsan");

	//strcpy(name1, strcpy(name2, "zhangsan"));

	//char name[1024] = "zhang ";
	//// 其他编程语言的字符串拼接, 一般是 +=
	//// name += "san"
	//strcat(name, "san");
	//printf("%s\n", name);

	//char name1[1024] = "hehe";
	//char name2[1024] = "hehehe";

	//int ret = strcmp(name1, name2);
	//if (ret == 0) {
	//	// 字符串相等的情况
	//}

	char str[] = "aaa,bbb,ccc,ddd";
	char* p = strtok(str, ",");
	while (p != NULL) {
		printf("%s\n", p);
		p = strtok(NULL, ",");
	}

	system("pause");
	return 0;
}