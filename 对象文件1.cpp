#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(void) {
	string name;
	cout << "����������������";
	getline(cin, name);
	if (name.empty()) {
	cout << "��������Ϊ�գ�" << endl;
	system("pause");
	return 0;
	}
	if (name == "imooc") {
	cout << "���Ľ�ɫ��һ������Ա��" << endl;
	}
	cout << "Hello " + name << endl;
	cout << "�������ֳ���Ϊ��" << name.size() << endl;
	cout << "�������ֵ�����ĸ�ǣ�" << name[0] << endl;
	system("pause");
	return 0;
}