#include "UserDatabase.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

#include "treemm.h"
class Iterator;
#include <cassert>

//////////////////////////i/////////////////////////////////////////////////////
//
// You are free to do whatever you want with this file, since you won't
// be turning it in.  Presumably, you will make changes to help you test
// your classes.  For example, you might try to implement only some User
// member functions to start out with, and so replace our main routine with
// one that simply creates a User and verifies that the member functions you
// implemented work correctly.
//
//////////////////////////i/////////////////////////////////////////////////////


  // If your program is having trouble finding these files. replace the
  // string literals with full path names to the files.  Also, for test
  // purposes, you may want to create some small, simple user and movie
  // data files to makde debuggiing easier, so you can replace the string
  // literals with the names of those smaller files.

//const string USER_DATAFILE  = "C:/Users/gongt/Desktop/Pnetphlix/users.txt" /*"users.txt"*/;
const string USER_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/shortUsers.txt";
const string MOVIE_DATAFILE = "movies.txt";

int main()
{
	UserDatabase udb;
	if (!udb.load(USER_DATAFILE))  // In skeleton, load always return false
	{
		cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
		return 1;
	}
	for (;;)
	{
		cout << "Enter user email address (or quit): ";
		string email;
		getline(cin, email);
		if (email == "quit")
			return 0;
		User* u = udb.get_user_from_email(email);
		if (u == nullptr)
			cout << "No user in the database has that email address." << endl;
		else
			cout << "Found " << u->get_full_name() << endl;
	}
}

//int main()
//{
	//TreeMultimap<int, int> emptryTree;
	//TreeMultimap<int, int>::Iterator it = emptryTree.find(2); // doesn't point to any value
	/*TreeMultimap<int, int> multiTree;
	multiTree.insert(10, 20);
	it = multiTree.find(10);*/
	//if (!it.is_valid()) std::cout << "This will print!\n";
//}

//int main()
//{
//	TreeMultimap<int, int> tmm;
//	tmm.insert(1, 10);
//	tmm.insert(2, 20);
//	tmm.insert(3, 30);
//	tmm.insert(1, 100);
//	tmm.insert(2, 200);
//	tmm.insert(3, 300);
//	TreeMultimap<int, int>::Iterator it = tmm.find(1);
//	assert(it.is_valid());
//	assert(it.get_value() == 10);
//	it.advance();
//	assert(it.is_valid());
//	assert(it.get_value() == 100);
//	it.advance();
//	assert(!it.is_valid());
//	cout << "passed " << endl;
//
//	TreeMultimap<int, int> emptryTree;
//	TreeMultimap<int, int>::Iterator it = emptryTree.find(2); // doesn't point to any value
//	TreeMultimap<int, int> multiTree;
//	multiTree.insert(10, 20);
//	it = multiTree.find(10);
//	if (!it.is_valid()) std::cout << "This will print!\n";
//
//	//TreeMultimap<std::string, int> tmm;
//	//tmm.insert("carey", 5);
//	//tmm.insert("carey", 6);
//	//tmm.insert("carey", 7);
//	//tmm.insert("david", 25);
//	//tmm.insert("david", 425);
//	//TreeMultimap<std::string, int>::Iterator it = tmm.find("carey");
//	//// prints 5, 6, and 7 in some order
//	//while (it.is_valid()) {
//	//	std::cout << it.get_value() << std::endl;
//	//	it.advance();
//	//}
//	// it = tmm.find("laura");
//	//if (!it.is_valid())
//	//	std::cout << "laura is not in the multimap!\n";
//	//fix this --- not printing 
//}

//int main() 
//{
//	TreeMultimap<std::string, int> tmm;
//	tmm.insert("carey", 5);
//	tmm.insert("carey", 6);
//	tmm.insert("carey", 7);
//	tmm.insert("david", 25);
//	tmm.insert("david", 425);
//	TreeMultimap<std::string, int>::Iterator it = tmm.find("carey");
//	// prints 5, 6, and 7 in some order
//	while (it.is_valid()) {
//		std::cout << it.get_value() << std::endl;
//		it.advance();
//		//std::cout << "im here " << std::endl;
//	}
//	it = tmm.find("david");
//	while (it.is_valid()) {
//		std::cout << it.get_value() << std::endl;
//		it.advance();
//		//std::cout << "im here " << std::endl;
//	}
//	it = tmm.find("laura");
//	if (!it.is_valid())
//	{
//		
//		std::cout << "laura is not in the multimap!\n";
//	}
//}