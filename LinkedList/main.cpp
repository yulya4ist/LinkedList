#include"LinkedList.h"
int main()
{

	LinkedList list1, list2, list3;
	list1.Append(3.1415926535);
	list2.Append(9);
	list1.Prepend(1);
	list1.Print();
	list2.Print();
	list3.Print();
	list3 = list2 = list1;
	list1.Print();
	list2.Print();
	list3.Print();
}

