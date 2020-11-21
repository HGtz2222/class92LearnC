#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 先创建结构体, 表示一个联系人
typedef struct Person {
	char name[1024];
	char tel[1024];
} Person;

#define MAX_PERSON 1024

// 表示整个通讯录, 管理着所有的联系人
typedef struct AddressBook {
	Person persons[MAX_PERSON];
	// 创建出的数组里有 1024 个空间. 但是出事情况下, 
	// 通讯录应该是空着的. 每次新增联系人, 里面才会多出一个元素
	// size 用来控制当前通讯录中有多少个人. 
	// [0, size) 就是有效区间
	int size;
} AddressBook;

// 实现后续的代码
int menu() {
	printf("=====================\n");
	printf(" 1. 新增联系人\n");
	printf(" 2. 查找联系人\n");
	printf(" 3. 删除联系人\n");
	printf(" 4. 修改联系人\n");
	printf(" 5. 查看所有联系人\n");
	printf(" 6. 清空所有联系人\n");
	printf(" 0. 退出\n");
	printf("=====================\n");
	printf(" 请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void init(AddressBook* addressBook) {
	// 针对整个通讯录进行初始化. 
	// 只要把 size 设成 0 即可. 
	addressBook->size = 0;

	// memset(addressBook, 0, sizeof(AddressBook));
}

void addPerson(AddressBook* addressBook) {
	// 新增联系人
	printf("新增联系人\n");
	// 需要先判定一下是不是已经通讯录满了. 
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON) {
		printf("通讯录已经满了, 新增失败!\n");
		return;
	}

	// 让用户输入新的联系人的电话和姓名
	// 创建好一个专门的变量把要修改的 Person 结构体变量给保存好. 
	// 此处不能直接使用结构体变量 Person p 这种形式, 
	// 必须使用结构体指针. 
	// 我们是希望修改全局变量中的 Person 结构体. 
	// 而使用结构体变量的话, 相当于创建了一个局部变量的结构体. 
	// 此时的修改只是针对该局部变量生效, 随着函数结束, 局部变量就被释放了. 
	Person* p = &addressBook->persons[currentSize];
	printf("请输入新联系人的姓名: ");
	scanf("%s", p->name);
	printf("请输入新联系人的电话: ");
	scanf("%s", p->tel);
	printf("新增联系人成功!\n");
	addressBook->size++;
}

void findPerson(AddressBook* addressBook) {
	// 查找联系人
	// 按照姓名查找电话号码
	printf("按照姓名查找联系人\n");
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		if (strcmp(name, p->name) == 0) {
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
		}
	}
	printf("查找联系人完成!\n");
}

void delPerson(AddressBook* addressBook) {
	// 删除联系人
	// 用户输入联系人的编号来进行删除(数组下标). 
	printf("删除联系人\n");
	printf("请输入要删除的联系人的编号: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressBook->size) {
		printf("您输入的编号有误!\n");
		return;
	}
	// 删除下标为 id 的元素
	// 如果 id 对应的元素就是最后一个, 直接 size--
	if (id == addressBook->size - 1) {
		addressBook->size--;
		printf("删除成功!\n");
		return;
	}
	// 如果 id 对应的元素是中间元素, 把最后一个元素给bia过来
	addressBook->persons[id]
		= addressBook->persons[addressBook->size - 1];
	// 再删除最后一个元素
	addressBook->size--;
	printf("删除成功!\n");
}

void updatePerson(AddressBook* addressBook) {

}

void printPerson(AddressBook* addressBook) {
	printf("打印所有联系人\n");
	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
	}
	printf("共计 [%d] 条记录\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook) {

}


typedef void(*Func)(AddressBook*);

AddressBook addressBook;

int main() {
	// 转移表
	Func funcs[] = {
		NULL,
		addPerson,
		findPerson,
		delPerson,
		updatePerson,
		printPerson,
		clearPerson
	};

	// 初始化通讯录
	init(&addressBook);

	// 进入主循环
	while (1) {
		int choice = menu();
		if (choice < 0
			|| choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("您的输入无效!\n");
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