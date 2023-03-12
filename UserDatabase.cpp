#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <fstream>
#include <vector>
#include "treemm.h"
#include <iostream>
using namespace std;

UserDatabase::UserDatabase()
{
    // Replace this line with correct code.
}

bool UserDatabase::load(const string& filename)
{
    //You need to open the file and read user data lien by line
    //parse each user and store as User Object.
    // insert object into TreeMap
  
    std::ifstream file(filename);
    if (!file)
    {
        return false;
    }
    /*return false; */ // Replace this line with correct code.

    //read records
    string line;
    int numMovies;
    vector<string> movieIDs;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            //User user(name, email, movieIDs);
            //m_users.insert();
            //get_watch_history();
        }
        
    }
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    return nullptr;  // Replace this line with correct code.
}
