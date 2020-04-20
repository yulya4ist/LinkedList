#include"LinkedList.h"

int main()
{
	int i = 0;
	LinkedList list1, list2, list3;
	
	for (size_t j = 0; j < 3; j++)
	{
		list1.Append(j);
		list2.Append(j*5);
	}
	
	list1.Print();
	list2.Print();

	for (LinkedList::Iterator it = list1.Begin(); it != list1.End();it++)
	{
	      *it= (*it)*7;
	}

	std::cout << "Write list: " << std::endl;

	LinkedList list4(list1); 	

	list3 = list2 = list1;
	list1.Print();
	list2.Print();
	list3.Print();
}

