#include <iostream>
#include "Ordered_list.h"
#include "RANDOM.H"
#include "sequential_search.h"
#include "recursive_binary_1.h"
#include "binary_search_1.h"
#include "recursive_binary_2.h"
#include "binary_search_2.h"
#include "SearchAnalyst.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

const int SEARCHES_PER_ALGORITHM = 20;
const int MAX_SEARCHABLE_MATERIAL_SIZE = 5000000;

void test_1();
void test_2();

int main()
{
	char command[2];

	cout << "Type the number of the test program(1, 2)" << endl;
	cin.getline(command, 2);

	switch (command[0]){
	case '1':
		test_1();
		break;
	case '2':
		test_2();
		break;
	};


	system("pause");
	return 0;
}

void test_1()
{
	List<Record> list;
	Key keyToSearch;
	int sizeOfMaterial = 0;
	int resultPosition;
	Random random(false);
	random.poisson(1.5);
	SearchAnalyst analyst;
	
	while (sizeOfMaterial < 1 || sizeOfMaterial > MAX_SEARCHABLE_MATERIAL_SIZE)
	{
		cout << "Input the size (1-" << MAX_SEARCHABLE_MATERIAL_SIZE << ") of the searchable material ";
		cin >> sizeOfMaterial;
	}
		
	// Generate the list
	for (int i = 0, pos = 0; list.size() < sizeOfMaterial; i++)
	{
		if (i % 2 == 1)
		{
			list.insert(pos, Record(i));
			pos++;
		}
	}


	// perform searches
	cout << "sequential_search" << endl;
	cout << "-----------------" << endl;
	analyst.reset();
	for (int i = 0; i < SEARCHES_PER_ALGORITHM; i++)
	{
		keyToSearch = Key(random.random_integer(0, sizeOfMaterial * 2));

		analyst.setTempComparisons(keyToSearch.comparisons);

		if (sequential_search(list, keyToSearch, resultPosition) == not_present)
		{
			analyst.failure(keyToSearch.comparisons);
		}
		else
		{
			analyst.success(keyToSearch.comparisons);
		}
	}
	analyst.print();
	
}
void test_2()
{
	List<Record> list;
	Ordered_list orderedList;
	Key keyToSearch;
	int sizeOfMaterial = 0;
	int resultPosition;
	Random random(false);
	random.poisson(1.5);
	SearchAnalyst analyst;

	while (sizeOfMaterial < 1 || sizeOfMaterial > MAX_SEARCHABLE_MATERIAL_SIZE)
	{
		cout << "Input the size (1-" << MAX_SEARCHABLE_MATERIAL_SIZE << ") of the searchable material ";
		cin >> sizeOfMaterial;
	}

	// Generate the lists
	for (int i = 0, pos = 0; list.size() < sizeOfMaterial; i++)
	{
		if (i % 2 == 1)
		{
			list.insert(pos, Record(i));
			orderedList.insert(pos, Record(i));
			pos++;
		}
	}


	// perform searches
	cout << "sequential_search" << endl;
	cout << "-----------------" << endl;
	analyst.reset();
	for (int i = 0; i < SEARCHES_PER_ALGORITHM; i++)
	{
		keyToSearch = Key(random.random_integer(0, sizeOfMaterial * 2));

		analyst.setTempComparisons(keyToSearch.comparisons);

		if (sequential_search(list, keyToSearch, resultPosition) == not_present)
		{
			analyst.failure(keyToSearch.comparisons);
		}
		else
		{
			analyst.success(keyToSearch.comparisons);
		}
	}
	analyst.print();

	cout << "\nrecursive_binary_1" << endl;
	cout << "-----------------" << endl;
	analyst.reset();
	for (int i = 0; i < SEARCHES_PER_ALGORITHM; i++)
	{
		keyToSearch = Key(random.random_integer(0, sizeOfMaterial * 2));

		analyst.setTempComparisons(keyToSearch.comparisons);

		if (recursive_binary_1(orderedList, keyToSearch, 0, orderedList.size() -1, resultPosition) == not_present)
		{
			analyst.failure(keyToSearch.comparisons);
		}
		else
		{
			analyst.success(keyToSearch.comparisons);
		}
	}
	analyst.print();
}