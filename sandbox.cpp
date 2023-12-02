
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
#include "MyRolodex.hpp"
#include <string>
#include <vector>
#include "Address.hpp"
using CPSC131::MyHashTable::MyHashTable;
using CPSC131::MyRolodex::Address;
using CPSC131::MyRolodex::MyRolodex;
 
//
using std::cout, std::cin, std::endl, std::string;


//
int main()
{
	
	cout << "Hi. Put anything here you'd like." << endl;
	cout << "Testing git" << endl;
	MyHashTable<string> table(20);
	cout << table.capacity() << endl;
	string name = "Edmarck" ;
	string address = "ace";
	table.add(name, address);
	table.add("karl", "hello");
	table.add("barl", address);
	cout << table.get(name) << endl;

	std::forward_list<std::string> keys = table.getAllKeys();
	for(auto& i : keys){
		cout << i << endl;
	}
	// table.add("a", "abc");
	// table.remove("a");
	//table.get(name);
	//cout << table.get("a") << endl;
	//table.clear();
	// cout << "HERE" << endl;
	// cout << table.get("a") << endl;
	table.setCapacity(100000);
	cout << table.capacity();
	table.clear();
	//cout << table.midSquareHash("iuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiuniuI1U11W1EH3F3I4U4b4w4eiun");
	// cout << "COMPLETED" << endl;

	// MyHashTable<string> table2(20);
	// cout << "table  works " <<  table.get("karl") << endl;
	// table2 = table;
	// cout << "table 2 works " << table2.get("karl") << endl; 
	// MyHashTable<string> table3(table);
	// cout <<"tABLE 3 WORKS " << table3.get("karl") << endl;


	// table.clear();

	// 	//
	// MyRolodex dex;
	
	// //
	// std::shared_ptr<Address> larry_address(new Address);
	// larry_address->line1 = "1212122 Lane Road";
	// larry_address->line2 = "";
	// larry_address->city = "Fullerton";
	// larry_address->state = "CA";
	// larry_address->zip = 92831;
	// larry_address->country = "US";

	// dex.add("Gary", "1212121 Lane Way", "", "Fullerton", "CA", 92831, "US");
	// dex.add("Larry", *larry_address);
	// dex.add("Harry", "1212123 Lane Place", "", "Fullerton", "CA", 92831, "US");
	// dex.add("Sally", "1212124 Lane Blvd", "", "Fullerton", "CA", 92831, "US");
	// Address larryReturn = dex.get("Larry");
	// cout << dex.exists("Larry") << endl;



	return 0;

}

