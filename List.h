#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
struct Node
{
	T value;

	Node* next;
	Node* prev;
};

template<class T>
Node<T>* CreateNode(T elem)
{
	Node<T>* el = new Node<T>;

	el->next = NULL;
	el->prev = NULL;

	if (elem != NULL)
	{
		el->value = elem;
	}
	else
		el->value = NULL;

	return el;
}

template<class T>
void AddToEnd(Node<T> **b, T add_el)
{	
	cout << "Adding an element" << add_el << "to the end of the list." << endl;

	if (*b == NULL)
	{
		Node<T> *first = new Node<T>;

		*b = first;

		first->value = add_el;
		first->prev = NULL;
		first->next = NULL;
		return;
	}

	Node<T>* cur = new Node<T>;
	cur = *b;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	Node<T> *end = new Node<T>;

	end->value = add_el;
	end->next = NULL;
	end->prev = cur;
	cur->next = end;
}

template<class T>
void AddToBegin(Node<T> **b, T add_el)
{	
	cout << "Adding an element" << add_el << "to the beginning of the list." << endl;

	Node<T>* helper = new Node<T>;

	helper->value = add_el;
	helper->next = *b;
	helper->prev = NULL;
	*b = helper;
}

template<class T>
void CreateList(Node<T>** b, int n)
{
	Node<T> *first;

	if (n == 0)
	{
		cout << "There are no entries!" << endl;
		return;
	}
	first = new Node<T>;
	*b = first;	
	cout << "Enter the first element of the list:";
	cin >> first->value;

	first->prev = NULL;
	first->next = NULL;

	for (int i = 1; i < n; i++)
	{
		Node<T>* cur = new Node<T>;		
		cout << "Enter the following list item:";
		cin >> cur->value;
		cur = CreateNode(cur->value);
		AddToEnd(b, cur->value);
		first = cur;
	}
}

template<class T>
void PrintList(Node<T> *b)
{
	if (b == NULL)
	{
		cout << "Ñïèñîê ïóñò!";
		return;
	}

	Node<T> *cur = b;	
	cout << "Received list items:";
	cout << "NULL <-> ";
	while (cur != NULL)
	{
		cout << cur->value << " <-> ";
		cur = cur->next;
	}
	cout << "NULL\n";
}

template<class T>
Node<T>* GetNode(Node<T>* b, int n)
{
	if (n < 1)
		return NULL;

	if (b == NULL)
		return NULL;

	Node<T>* cur = b;
	int i = 1;

	while (i < n && (*cur).next != NULL)
	{
		cur = (*cur).next;
		i++;
	}
	if (i < n)
		return NULL;

	return  cur;
}

template<class T>
void AddExtremeElements(Node<T> **b, int k)
{
	if (k < 1)
		return;

	
	//if the list is empty, then create a new list with the required number of nodes 2*k:
	if (*b == NULL)
	{
		CreateList(&(*b), k);
		return;
	}

	const int size = k;
	T* add_el = new T[size];	
	cout << "Enter the elements that you want to add to the beginning and end of the list:";

	for (int i = 0; i < k; i++)
	{
		cin >> add_el[i];
		cout << endl;
		AddToEnd(b, add_el[i]);
		AddToBegin(b, add_el[i]);
	}
}

template<class T>
bool DeleteNode(Node<T> **b, T del_el)
{
	if (*b == NULL)
		return false;

	Node<T>* cur = *b;
	Node<T>* delme = NULL;

	while (delme == NULL  &&   cur != NULL)
	{
		if ((cur->value == del_el))
		{
			delme = cur;
		}
		cur = cur->next;
	}

	if (delme == NULL)
		return false;

	Node<T>* prev = delme->prev;
	Node<T>* next = delme->next;

	if (prev != NULL)
		prev->next = next;
	else
		*b = next;

	if (next != NULL)
		(*next).prev = prev;

	delete delme;
	return true;
}

template<class T>
void ClearList(Node<T> **b)
{
	Node<T>* delme = NULL;
	Node<T>* cur = *b;

	while (cur != NULL)
	{
		delme = cur;
		cur = (*cur).next;
		delete delme;
		delme = NULL;
	}

	*b = NULL;
}

template<class T>
void WriteToFile(Node<T> *b, const char* fname)
{
	if (b == NULL)
	{
		cout << "No items found for recording!" << endl;
		return;
	}
	
	cout << "The data of list items is written to a text file!" << endl;
	if (strcmp(fname, "") == 0)
		return;

	Node<T>* cur = b;
	ofstream fout(fname);

	fout << (*cur).value;

	while ((*cur).next != NULL)
	{
		cur = (*cur).next;
		fout << endl << (*cur).value;
	}

	fout.close();
}

template<class T>
void ReadFromFile(Node<T> **b, const char* fname)
{
	if (*b == NULL)
	{
		cout << "File is empty!" << endl;
		return;
	}
	ClearList(b);

	if (strcmp(fname, "") == 0)
		return;

	ifstream fin(fname);
	char str[1000];
	int n = 0;

	while (!fin.eof())
	{
		fin.getline(str, 1000);		
		cout << "Reading" << n << "of the element from the file:" << str << endl;
		n++;
	}
	cout << endl;	
	cout << "Number of read nodes from file =" << n << '.' << endl;
	fin.close();
}
