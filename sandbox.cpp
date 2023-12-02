
/**
 * You don't need to edit this file, although you can if you wish.
 * This source file will not be graded.
 * 
 * This is just an extra program you can use to debug your code.
 * Put whatever you want here, and use "make sandbox" to execute it.
 */

//
#include <iostream>
#include "MyHashTable.hpp"
#include <string>
#include "Address.hpp"
using CPSC131::MyHashTable::MyHashTable;
using CPSC131::MyRolodex::Address;
 
//
using std::cout, std::cin, std::endl, std::string;


//
int main()
{
	//
	cout << "Hi. Put anything here you'd like." << endl;
	cout << "Testing git" << endl;
	MyHashTable<string> table(20);
	cout << table.capacity() << endl;
	string name = "Edmarck" ;
	string address = "ace";
	table.add(name, address);
	table.add("a", "hello");
	table.add("b", address);
	cout << table.get(name) << endl;

				std::forward_list<std::string> keys = table.getAllKeys();
				for(auto& i : keys){
					cout << i << endl;
				}
	// table.remove(name);
	// //table.get(name);
	// cout << table.get("a") << endl;
	// table.clear();
	// cout << "HERE" << endl;
	// cout << table.get("a") << endl;

	MyHashTable<string> table2(20);
	table2 = table;
	cout << table.get("a") << endl;
	cout << table2.get("a") << endl; 

	return 0;

}

