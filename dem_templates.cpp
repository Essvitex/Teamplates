#include <iostream>
#include "List.h"

using namespace std;


template <class T>
void RunTheProgram(Node<T>* begin)
{
	begin = new Node<T>;
	begin = NULL;

	int n;	
	cout << "Enter the number of list items:";
	cin >> n;

	CreateList(&begin, n);
	PrintList(begin);
	cout << endl;

	T del_el;
	cout << "Enter the element you want to delete:";
	cin >> del_el;
	cout << endl;

	DeleteNode(&begin, del_el);
	PrintList(begin);
	cout << endl;

	int k;	
	cout << "Enter the number of elements to add to the beginning and end of the list:";
	cin >> k;
	cout << endl;

	AddExtremeElements(&begin, k);
	PrintList(begin);
	cout << endl;

	WriteToFile(begin, "Letter.txt");
	cout << endl;

	cout << "Output of elements from the file:" << endl;
	ReadFromFile(&begin, "Letter.txt");
	
	cout << "Deleting the entire list." << endl;
	ClearList(&begin);
	PrintList(begin);
	cout << endl;
}

/*
Author: Sergeev Victor, 2016.
Tusk: (V. №20) Entries in the linear list contain a key field of type * char (character string). 
Create a bi-directional list. Delete an item with a key member. 
Add items to the top and bottom of the list.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "Demonstration of the work of a doubly-linked list based on function templates." << endl << endl;

	int choice;
	printf_s ("Select the data type for the list items: \ n");
	printf_s("1 - int; 2 - float; 3 - double; 4 - char: ");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
	{
		Node<int>* begin = (Node<int>*)NULL;

		RunTheProgram(begin);
		break;
	}
	case 2:
	{
		Node<float>* begin = (Node<float>*)NULL;

		RunTheProgram(begin);
		break;
	}
	case 3:
	{
		Node<double>* begin = (Node<double>*)NULL;

		RunTheProgram(begin);
		break;
	}
	case 4:
	{
		Node<char>* begin = (Node<char>*)NULL;

		RunTheProgram(begin);
		break;
	}
	default:
	{
		cout << "Wrong type...\n";
		break;
	}
	}

	system("pause");
	return 0;
}
