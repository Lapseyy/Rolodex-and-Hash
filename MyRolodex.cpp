

//
#include "MyRolodex.hpp"
#include "MyHashTable.hpp"
#include "Address.hpp"

#include <string>	//I added this.


/**
 * TODO: Finish the implementation for this class
 */


//	More includes?


//
namespace CPSC131::MyRolodex
{
	/// Your welcome
	MyRolodex::MyRolodex() {}
	
	/**
	 * Return true if a person exists in the Rolodex
	 */
	bool MyRolodex::exists(std::string name) const
	{
		return this->table_.exists(name);	
	}
	
	/*
	 * Allow the user to add an address using its parts.
	 * This should probably just call on the other overload
	 */
	void MyRolodex::add(std::string name, std::string line1, std::string line2, std::string city, std::string state, int zip, std::string country)
	{
		Address a1; 
		a1.line1 = line1; 
		a1.line2 = line2;
		a1.city = city;
		a1.state = state; 
		a1.zip = zip;
		a1.country = country;
		this->add(name, a1);
	}
	
	/**
	 * Add an entry into the Rolodex
	 * The person's name is the key, and their Address is the value.
	 * The Address comes in the form of the Address struct, defined in another source file.
	 */
	void MyRolodex::add(std::string name, Address address)
	{
		this->table_.add(name, address);
		
	}
	
	/**
	 * Return an address structure associated with a person
	 */
	Address MyRolodex::get(std::string name) const
	{
		return this->table_.get(name);
	}
	
	/**
	 * Remove a person from the Rolodex
	 */
	void MyRolodex::remove(std::string name)
	{
		//
		if(!this->table_.exists(name)){
			throw std::runtime_error("Entry not found: " + name);
		}
		if (this->table_.exists(name)){
        this->table_.remove(name);
    }
    else{
        throw std::runtime_error("Entry not found: " + name);
		return;
    }
		//
		//this->table_.remove(name);
	}
	
	/**
	 * Clear the Rolodex of all information.
	 * (Hint: The table also has this method)
	 */
	void MyRolodex::clear()
	{
		this->table_.clear();
	}
	
	/**
	 * Return true if the Rolodex is empty, false otherwise
	 */
	bool MyRolodex::empty()
	{
		return this->table_.empty();
	}
	
	/**
	 * Return the number of entries in this Rolodex
	 */
	size_t MyRolodex::size()
	{
		return this->table_.size();
	}
}






















