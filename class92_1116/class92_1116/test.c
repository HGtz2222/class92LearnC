#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// �����޷���֤�����ߴ���һ��ɶ���Ĳ���. ���缫������´���һ���Ƿ���ַ. 
// ����Ҫ�����ô����ܱȽϽ�׳. 
// Ӧ���ں�������ڴ����϶��ڲ����Ϸ��Ե�У��
// �� C ������, �������, û�취, �޽�~~~ . 
// ��ν�� �п� ֻ�� "��ʤ����" �Ĳ���. �����ܴӸ����Ͻ������Ƿ�����������. 

// ������Բ����ĺϷ��Լ�������ַ��: 
// 1. if
// 2. assert ����: ( ) дһ�����ʽ, ������ʽΪ��, ����û���κ�Ч��,
//    �������ִ��. ������ʽΪ��, ����ͻ�ֱ�ӱ���
size_t myStrlen(const char* str) {
	// �ڵ��ú������ڲ������ж�
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
	// ǧ��Ҫ���ǺϷ���У��. ��Ȼûɶʵ������, ���������������ʶ. 
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	// ��������ֵ������ԭʼ�Ĳ��� dest
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
	// strcat �� strcpy �Ƿǳ����Ƶ�. 
	// strcpy �ǰ� src �����ݿ����� dest �Ŀ�ʼλ��. 
	// strcat �ǰ� src �����ݿ����� dest �Ľ���λ��. 

	// ��Ҫ���ҵ� dest �Ľ���λ��. 
	char* p = dest;
	while (*p != '\0') {
		p++;
	}
	// ��ѭ��������, p ָ���λ��, ���� dest ��ĩβ. 
	while (*src != '\0') {
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return dest;
}

int myStrcmp(const char* str1, const char* str2) {
	// һ��Ҫ�ǵ�, ��У������ĺϷ���. 
	// �˴����ֲ����Ƿ���ʱ��, ���������ҵ�һ������ֵ��Ϊ�Ƿ����. 
	// �� C ��ûɶ̫�õİ취. δ�� C++ �� Java ����һ�ֲ��� �׳��쳣
	assert(str1 != NULL && str2 != NULL);

	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			// ��ʱ���ƽ����, ��Ҫ�Ƚ���һ���ַ�
			str1++;
			str2++;
		}
	}
	// ��������ѭ���Ѿ�������, ��û�д��� return , ���ܾ����������:
	// hehe  ��  hehehe �ıȽ�
	// ����������Ҫ��˭��˭��С. ֱ�ӿ���ǰλ�õ� str1 �� str2 ָ������ݴ�С������. 
	// ����ָ��������һ���� \0 , ��һ���͸���. 
	// ����������� \0, �������
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

	// blackPtr ȷ���˵�ǰ���˱Ƚϵ���ʼλ��. 
	const char* blackPtr = str1;

	while (*blackPtr != '\0') {
		// ��Ҫ���ݵ�ǰ����ʼλ��, ��һ���ıȽ� str1 �����ݺ� str2 ������
		// ���������Ҫ����������ָ��, һ���� redPtr, һ���� subPtr
		const char* redPtr = blackPtr;
		const char* subPtr = str2;

		// ���ѭ�������Ե�ǰ�� blackPtr Ϊ���, ����һ�˱Ƚ�
		while (*redPtr != '\0' && *subPtr != '\0'
			&& *redPtr == *subPtr) {
			redPtr++;
			subPtr++;
		}
		// ��ѭ������֮��, �������ֿ���: 
		// 1) ����� *redPtr != '\0' ����������, ��ʱ, ���ǲ�ƥ��
		//    ���ʱ���Ӧ�� blackPtr++ �����¸���ʼλ��. 
		// 2) ����� *subPtr != '\0' ����������, ��ʱ���ҵ�ƥ��Ľ����
		//    ��Ӧ�÷��� blackPtr
		// 3) ����� *redPtr == *subPtr ������, ��ʱҲӦ���� blackPtr++
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
	//// %u ��ӡ���� �޷��� ������. 
	//printf("%u\n", c);

	//char* str = NULL;
	//// ���ú������ⲿ�����ж�. 
	//if (str != NULL) {
	//    printf("%d\n", myStrlen(str));
	//}
	
	//char name[5] = "hehe";
	//// name = "lisi";
	//strcpy(name, "lisisi");
	//printf("%s\n", name);

	// strcpy ����ֵ�����Ǹ� char*, Ŀ����Ϊ��ʵ�� ��ʽ����
	//char name1[1024] = "";
	//char name2[1024] = "";
	//strcpy(name1, "zhangsan");
	//strcpy(name2, "zhangsan");

	//strcpy(name1, strcpy(name2, "zhangsan"));

	//char name[1024] = "zhang ";
	//// ����������Ե��ַ���ƴ��, һ���� +=
	//// name += "san"
	//strcat(name, "san");
	//printf("%s\n", name);

	//char name1[1024] = "hehe";
	//char name2[1024] = "hehehe";

	//int ret = strcmp(name1, name2);
	//if (ret == 0) {
	//	// �ַ�����ȵ����
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