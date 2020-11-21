#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ȴ����ṹ��, ��ʾһ����ϵ��
typedef struct Person {
	char name[1024];
	char tel[1024];
} Person;

#define MAX_PERSON 1024

// ��ʾ����ͨѶ¼, ���������е���ϵ��
typedef struct AddressBook {
	Person persons[MAX_PERSON];
	// ���������������� 1024 ���ռ�. ���ǳ��������, 
	// ͨѶ¼Ӧ���ǿ��ŵ�. ÿ��������ϵ��, ����Ż���һ��Ԫ��
	// size �������Ƶ�ǰͨѶ¼���ж��ٸ���. 
	// [0, size) ������Ч����
	int size;
} AddressBook;

// ʵ�ֺ����Ĵ���
int menu() {
	printf("=====================\n");
	printf(" 1. ������ϵ��\n");
	printf(" 2. ������ϵ��\n");
	printf(" 3. ɾ����ϵ��\n");
	printf(" 4. �޸���ϵ��\n");
	printf(" 5. �鿴������ϵ��\n");
	printf(" 6. ���������ϵ��\n");
	printf(" 0. �˳�\n");
	printf("=====================\n");
	printf(" ����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void init(AddressBook* addressBook) {
	// �������ͨѶ¼���г�ʼ��. 
	// ֻҪ�� size ��� 0 ����. 
	addressBook->size = 0;

	// memset(addressBook, 0, sizeof(AddressBook));
}

void addPerson(AddressBook* addressBook) {
	// ������ϵ��
	printf("������ϵ��\n");
	// ��Ҫ���ж�һ���ǲ����Ѿ�ͨѶ¼����. 
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON) {
		printf("ͨѶ¼�Ѿ�����, ����ʧ��!\n");
		return;
	}

	// ���û������µ���ϵ�˵ĵ绰������
	// ������һ��ר�ŵı�����Ҫ�޸ĵ� Person �ṹ������������. 
	// �˴�����ֱ��ʹ�ýṹ����� Person p ������ʽ, 
	// ����ʹ�ýṹ��ָ��. 
	// ������ϣ���޸�ȫ�ֱ����е� Person �ṹ��. 
	// ��ʹ�ýṹ������Ļ�, �൱�ڴ�����һ���ֲ������Ľṹ��. 
	// ��ʱ���޸�ֻ����Ըþֲ�������Ч, ���ź�������, �ֲ������ͱ��ͷ���. 
	Person* p = &addressBook->persons[currentSize];
	printf("����������ϵ�˵�����: ");
	scanf("%s", p->name);
	printf("����������ϵ�˵ĵ绰: ");
	scanf("%s", p->tel);
	printf("������ϵ�˳ɹ�!\n");
	addressBook->size++;
}

void findPerson(AddressBook* addressBook) {
	// ������ϵ��
	// �����������ҵ绰����
	printf("��������������ϵ��\n");
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		if (strcmp(name, p->name) == 0) {
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
		}
	}
	printf("������ϵ�����!\n");
}

void delPerson(AddressBook* addressBook) {
	// ɾ����ϵ��
	// �û�������ϵ�˵ı��������ɾ��(�����±�). 
	printf("ɾ����ϵ��\n");
	printf("������Ҫɾ������ϵ�˵ı��: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("������ı������!\n");
		return;
	}
	// ɾ���±�Ϊ id ��Ԫ��
	// ��� id ��Ӧ��Ԫ�ؾ������һ��, ֱ�� size--
	if (id == addressBook->size - 1) {
		addressBook->size--;
		printf("ɾ���ɹ�!\n");
		return;
	}
	// ��� id ��Ӧ��Ԫ�����м�Ԫ��, �����һ��Ԫ�ظ�bia����
	addressBook->persons[id]
		= addressBook->persons[addressBook->size - 1];
	// ��ɾ�����һ��Ԫ��
	addressBook->size--;
	printf("ɾ���ɹ�!\n");
}

void updatePerson(AddressBook* addressBook) {

}

void printPerson(AddressBook* addressBook) {
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
	}
	printf("���� [%d] ����¼\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook) {

}


typedef void(*Func)(AddressBook*);

AddressBook addressBook;

int main() {
	// ת�Ʊ�
	Func funcs[] = {
		NULL,
		addPerson,
		findPerson,
		delPerson,
		updatePerson,
		printPerson,
		clearPerson
	};

	// ��ʼ��ͨѶ¼
	init(&addressBook);

	// ������ѭ��
	while (1) {
		int choice = menu();
		if (choice < 0
			|| choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("����������Ч!\n");
			continue;
		}
		if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}