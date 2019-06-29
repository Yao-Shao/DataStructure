#include "HeterList.h"
#include <iostream>
#include <string>

int main()
{
	HeterList a = HeterList();
	HeterList b = HeterList();
	int data1 = 1;
	double data2 = 5.5;
	string data3 = "hello";
	int data4 = 2;
	double data5 = 7.7;
	string data6 = "world";

	int data7 = 3;
	double data8 = 6.6;
	string data9 = "Good";

	cout << "**********************Test for Heter List******************" << endl;

	cout << "*************Test for inset************" << endl;
	cout << "分别在链表的头(0)、尾(-1)、中间任意位置插入" << endl;
	a.insert(data1, 0);
	a.print();
	a.insert(data2, -1);
	a.print();
	a.insert(data3, 1);
	a.print();
	a.insert(data4, -1);
	a.print();
	a.insert(data5, 0);
	a.print();
	a.insert(data6, 2);
	a.print();

	cout << "*************Test for reverse************" << endl;
	cout << "逆置前：";
	a.print();
	cout << "逆置后：";
	a.reverse();
	a.print();

	cout << "*************Test for delete************" << endl;
	cout << "分别删除链表的头(0)、尾(-1)、中间位置(第二个数据)" << endl;
	cout << "删除前：";
	a.print();
	a.deleteByPos(0);
	a.print();
	a.deleteByPos(-1);
	a.print();
	a.deleteByPos(1);
	a.print();

	cout << "*************Test for merge************" << endl;
	b.insert(data7, 0);
	b.insert(data8, 0);
	b.insert(data9, 0);
	cout << "Before:\nList1: ";
	a.print();
	cout << "List2: ";
	b.print();
	a.merge(b);
	cout << "Result: ";
	a.print();

	cout << "*************Test for destroy************" << endl;
	cout << "List1: ";
	a.print();
	cout << "After destroy: ";
	a.destory();
	a.print();


	return 0;
}
