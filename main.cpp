#include <iostream>
#include "classes.h"


int main() {

	List list;

	int key;

	list.AddToEnd(5);

	list.AddToEnd(6);

	list.AddToEnd(7);

	list.AddToEnd(8);

	list.AddToBegin(4);

	list.AddToBegin(3);

	list.AddToBegin(2);

	list.AddToBegin(1);

	list.ForwardPrint();

	list.DeleteNodeEnd();

	list.DeleteNodeBeg();

	list.ForwardPrint();

	std::cout << "Enter key: ";

	std::cin >> key;

	list.Find(key);

	list.Remove(100, 4);

	list.ForwardPrint();

	list.Insert(200, 4);

	list.ForwardPrint();

	system("pause");

	return 0;

}