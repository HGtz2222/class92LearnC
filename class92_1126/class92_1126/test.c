#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
	// ���ļ�
	// �˴��� FILE ��һ���ṹ��. (C ��׼�����Ѿ�������˵�)
	// ���ؽ������ "�ļ�ָ��", �е�ʱ��Ҳ���Խ��� "���"(handler) 
	// �ļ��򿪿��ܻ�ʧ��. ���� NULL
	FILE* f = fopen("d:/test.txt", "w");
	if (f == NULL) {
		// printf("�ļ���ʧ��! errno = %d, %s\n", errno, strerror(errno));
		perror("�ļ���ʧ��!");
		system("pause");
		return 1;
	}
	printf("�ļ��򿪳ɹ�!\n");

	// fread ����Ѵ����ϵ�����, ��ȡ���ڴ���. 
	// char buf[1024] = { 0 };
	// ���еڶ��������͵������������, �͵õ���Ҫ��ȡ��������ֽ���. 
	// ����ֵ��ʾʵ�ʶ�ȡ����Ԫ�ظ���. 
	// ���ʵ�ʶ�����Ԫ�ظ���С��Ԥ�ڵ�Ҫ����Ԫ�ظ���, �Ϳ�����Ϊ
	// �ļ�������
	//int n = fread(buf, 1, 1024, f);
	//printf("%s\n", buf);

	// fwrite ������ڴ������, д��������
	// ��� fwrite д�ɹ���, ��ô�ͻ᷵��ʵ��д���Ԫ�ظ���. 
	// ���ʧ���˾ͻ᷵�� < 0 �Ľ��. 
	//char buf[1024] = "hahaha";
	//int n = fwrite(buf, 1, strlen(buf), f);
	//if (n < strlen(buf)) {
	//	perror("fwrite");
	//}

	// ʹ�� fprintf ���и�ʽ��д��
	//int num = 10;
	//fprintf(f, "num = %d", num);

	// ��������ͺ� printf �ǵȼ۵�. 
	// ʹ�� fscanf(stdin, ""); �ͺ� scanf �ǵȼ۵�.
	// fprintf(stdout, "num = %d", num);

	// sprintf / sscanf ����һ���ǳ���Ҫ�ĺ���
	// sprintf �Ѹ�ʽ���Ľ��д���ַ�����
	// sscanf �ǴӸ�ʽ���ַ����н������. 

	//char buf[1024] = { 0 };
	//sprintf(buf, "num = %d", num);
	//printf("%s\n", buf);

	// sprintf �� sscanf ��һ�������÷�: 
	// ������ת���ַ���, ���ַ���ת������. 

	int num = 10;
	// buf �е�������һ�� "10"
	char buf[1024] = { 0 };
	// ����������� "���", ���ǰ� int �������, ���ŵ� char buf[] ��������
	sprintf(buf, "%d", num);

	printf("%c\n", buf[0]);
	printf("%c\n", buf[1]);
	printf("%c\n", buf[2]);

	printf("%s\n", buf);

	// �� C ������, ����һ�麯��Ҳ��ʵ���ַ�����������ת��
	// atoi ���ַ���, ת������
	// itoa ������, ת���ַ���


	// �ر��ļ�
	// ������, ����ļ�ʹ�����֮��, һ��Ҫ�ǵùر��ļ�. 
	// �ļ���Դй¶/���й¶
	// ���Ծ�����
	fclose(f);

	// \ Ҳ��ʾ ת���ַ� 
	// char name[] = "D:\\program2\\qq\\Bin";
	//char name[] = "D:/program2/qq/Bin";
	//printf("%s\n", name);
	system("pause");
	return 0;
}