#include "UserDatabase.h"
#include "User.h"
#include "Movie.h"
#include "MovieDatabase.h"
#include <iostream>
#include <string>
#include "Recommender.h"
using namespace std;

#include "treemm.h"
class Iterator;
#include <cassert>
#include <chrono>

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

//const string USER_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/shortUsers.txt";

const string USER_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/userTests.txt";
//const string MOVIE_DATAFILE = "movies.txt";
//const string MOVIE_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/movies.txt";

//const string MOVIE_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/shortMovies.txt";

const string MOVIE_DATAFILE = "C:/Users/gongt/Desktop/Pnetphlix/moviesTest.txt";

//void findMatches(const Recommender& r, const MovieDatabase& md, const string& user_email, int num_recommendations) 
//{
//	// get up to ten movie recommendations for the user
//	vector<MovieAndRank> recommendations =
//		r.recommend_movies(user_email, 10);
//		if (recommendations.empty())
//			cout << "We found no movies to recommend :(.\n";
//		else {
//			for (int i = 0; i < recommendations.size(); i++) 
//			{
//				const MovieAndRank& mr = recommendations[i]) 
//				{
//					Movie* m = md.get_movie_from_id(mr.movie_id);
//					cout << i << ". " << m->get_title() << " ("
//						<< m->get_release_year() << ")\n Rating: "
//						<< m->get_rating() << "\n Compatibility Score: "
//						<< mr.compatibility_score << "\n";
//				}
//			}
//		}
//}
int main()
{
	//UserDatabase udb;
	//if (!udb.load(USER_DATAFILE))  // In skeleton, load always return false
	//{
	//	cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
	//	return 1;
	//}
	//for (;;)
	//{
	//	cout << "Enter user email address (or quit): ";
	//	string email;
	//	getline(cin, email);
	//	if (email == "quit")
	//		return 0;
	//	User* u = udb.get_user_from_email(email);
	//	if (u == nullptr)
	//		cout << "No user in the database has that email address." << endl;
	//	else
	//		cout << "Found " << u->get_full_name() << endl;
	//}

	//MovieDatabase mdb;
	//if (!mdb.load(MOVIE_DATAFILE))  // In skeleton, load always return false
	//{
	//	cout << "Failed to load movie data file " << MOVIE_DATAFILE << "!" << endl;
	//	return 1;
	//}
	//for (;;)
	//{
	//	cout << "Enter movie ID (or quit): ";
	//	string movie;
	//	getline(cin, movie);
	//	if (movie == "quit")
	//		return 0;
	//	Movie* u = mdb.get_movie_from_id(movie);
	//	//Movie* u = mdb.get_movies_with_director(movie);
	//	if (u == nullptr)
	//		cout << "No movie in the database has that ID." << endl;
	//	else
	//	{
	//		cout << "found movieID: " << u->get_id() << endl;
	//		cout << "movie: " << u->get_title() << endl; //u->get_full_name() << endl;*/
	//		cout << "release year: " << u->get_release_year() << endl;
	//		vector<string> list;
	//		for (int i = 0; i < (u->get_directors()).size(); i++) {
	//			list.push_back((u->get_directors())[i]);
	//			cout << "directors: " << list[i] << endl;
	//		}
	//		vector<string> list3;
	//		for (int i = 0; i < (u->get_actors()).size(); i++) {
	//			list3.push_back((u->get_actors())[i]);
	//			cout << "actors: " << list3[i] << endl;
	//		}
	//		vector<string> list2;
	//		for (int i = 0; i < (u->get_genres()).size(); i++) {
	//			list2.push_back((u->get_genres())[i]);
	//			cout << "genres: " << list2[i] << endl;
	//		}
	//	}
	//}

	UserDatabase udb1;
	assert(udb1.load(USER_DATAFILE1));

	stop = std::chrono::steady_clock::now();

	std::cout << "Took " << (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()) << "ms to load USER_DATAFILE1." << std::endl;

	start = std::chrono::steady_clock::now();

	assert(udb1.get_user_from_email("caimberkip@gmail.com") == nullptr);
	assert(udb1.get_user_from_email("czimberkip@gmail.com") == nullptr);

	MovieDatabase mdb1;
	assert(mdb1.load(MOVIE_DATAFILE1));

	stop = std::chrono::steady_clock::now();

	std::cout << "Took " << (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()) << "ms to load MOVIE_DATAFILE1." << std::endl;

	start = std::chrono::steady_clock::now();

	Recommender r(udb1, mdb1);
	const std::vector<MovieAndRank> recommendations = r.recommend_movies("climberkip@gmail.com", 100);

	stop = std::chrono::steady_clock::now();

	std::cout << "Took " << (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()) << "ms to recommend movies." << std::endl;

	assert(recommendations.size() == 5);
	//cerr << recommendations.size() << endl;
	assert(recommendations.at(0).movie_id == "ID00004"
		&& recommendations.at(1).movie_id == "ID00008"
		&& recommendations.at(2).movie_id == "ID00007"
		&& recommendations.at(3).movie_id == "ID00005"
		&& recommendations.at(4).movie_id == "ID00006");
	assert(recommendations.at(0).compatibility_score == 166
		&& recommendations.at(1).compatibility_score == 32
		&& recommendations.at(2).compatibility_score == 2
		&& recommendations.at(3).compatibility_score == 2
		&& recommendations.at(4).compatibility_score == 2);

	const std::vector<MovieAndRank> recommendations2 = r.recommend_movies("climberkip@gmail.com", -5);
	assert(recommendations2.empty());

	TreeMultimap<int, int>::Iterator it1;  // doesn't point to any value
	assert(!it1.is_valid());


	TreeMultimap<std::string, int> tmm;
	tmm.insert("carey", 5);
	tmm.insert("carey", 7);
	tmm.insert("carey", 6);
	tmm.insert("david", 25);
	tmm.insert("david", 425);
	TreeMultimap<std::string, int>::Iterator it = tmm.find("carey"); // prints 5, 6, and 7 in some order
	assert(it.is_valid());
	bool a = false, b = false, c = false;
	int n = 0;
	while (it.is_valid())
	{
		if (it.get_value() == 5) a = true;
		else if (it.get_value() == 6) b = true;
		else if (it.get_value() == 7) c = true;
		++n;
		it.advance();
	}
	assert(n == 3);
	assert(a && b && c); // iterator iterates through 5, 6, 7
	it = tmm.find("laura");
	assert(!it.is_valid());

	int testInt = 5;
	TreeMultimap<std::string, int> f;
	f.insert("test", testInt);
	testInt = 10;
	it = f.find("test");
	assert(it.is_valid() && it.get_value() == 5); // TreeMultimap must store a COPY of the value


	std::cout << "Passed all tests." << std::endl;
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