#include"LinkedList.h"
#include<vector>

int main()
{

	LinkedList list1, list2, list3;
	/*std::vector<int> a;
	auto it1 = a.begin();
	std::vector<int>::iterator it = a.begin();*/
	list1.Append(3.1415926535);
	list2.Append(9);
	list1.Prepend(1);
	//list3.Append(7);
	list1.Print();
	list2.Print();
	list3.Print();
	list3 = list2 = list1;
	list1.Print();
	list2.Print();
	list3.Print();
	//double x = *it;
}

