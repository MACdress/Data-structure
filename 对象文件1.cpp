#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(void) {
	string name;
	cout << "请输入您的姓名：";
	getline(cin, name);
	if (name.empty()) {
	cout << "您的输入为空！" << endl;
	system("pause");
	return 0;
	}
	if (name == "imooc") {
	cout << "您的角色是一个管理员！" << endl;
	}
	cout << "Hello " + name << endl;
	cout << "您的名字长度为：" << name.size() << endl;
	cout << "您的名字的首字母是：" << name[0] << endl;
	system("pause");
	return 0;
}