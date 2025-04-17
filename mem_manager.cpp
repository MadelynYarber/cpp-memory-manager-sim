#include "mymemoryblock.h"
#include "mymemory.h"
#include <iostream>
using namespace std;

void print_menu() {
	cout << string(20, '=') << endl;
	cout << "d: memory dump" << endl;
	cout << "r: request memory" << endl;
	cout << "l: release memory" << endl;
	cout << "m: merge memory" << endl;
	cout << "x: quit program" << endl;
	cout << "Your choice: ";	
}


int main ()
{
	char choice;
	bool keep_going = true;
	int config;
	int memblock;
	//MyMemory blocks(5, 100);

	cout << "Memory configuration:";
	cin >> config;
	cout << "Number of memory blocks (integer): "; 
	cin >> memblock;

	MyMemory blocks(config, memblock);

while (keep_going)
{
	print_menu();
	cin >> choice;

	if (choice == 'd')
	{
		cout << "memory dump" << endl;
		blocks.dump();
	}
	else if (choice == 'r')
	{	
		int requestmem;
		cout << "how much memory do you want to request" << endl;
		cin >> requestmem;
		blocks.req_mem(requestmem);
	}
	else if (choice == 'l')
	{
		int reindex;
		int remem;
		cout << "What index do you want to release memory from (starting at 0)" << endl;
		cin >> reindex;
		cout << "How much memory do you want to release?" << endl;
		cin >> remem;
		blocks.release_mem(reindex, remem);
	}
	else if (choice == 'm')
	{
		cout << "merge memory" << endl;
		blocks.merge_mem();
	}
	else if (choice == 'x')
	{
		cout << "exit" << endl;
		keep_going = false;
		//break;
	}
}	
	return 0;
}
