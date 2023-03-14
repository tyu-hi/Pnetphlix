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

    cerr << "im here in .load() " << endl;
    std::ifstream infile(filename);
    if (!infile)
    {
        cerr << "error: didn't open txt file!" << endl;
        return false;
    }
    //read input from file --- CS32 Website File I/O
    string line;
    //vector<string> movieIDs;
    if (infile.is_open())
    {
        while (std::getline(infile, line))    //getline returns infile, the while tests its success/failure state
        {
            if (line.size() == 1) //checking for an empty line
            {
                getline(infile, line);
                cerr << "entering new line " << endl;
            }
            string name = line;

            string email;
            getline(infile, email);
            cerr << "email:" << email << endl;

            int numMovies;
            infile >> numMovies;
            //getline(infile, numMovies);
            infile.ignore(100000, '\n'); //because we are reading an int before string
            cerr << "NumMovies " << numMovies << endl;
            
            vector<string> movieIDs;    //this is watch history
            //vector<> movieID;
            for (int i = 0; i < numMovies; i++)
            {
                string movieID;
                getline(infile, movieID);
                cerr << "movie ID: " << movieID << endl;
                movieIDs.push_back(movieID);
            }

            User user(name, email, movieIDs);
            //User* user = new User(name, email, movieIDs);
                
                //User user(name, email, movieIDs);
                //m_users.insert();
                //get_watch_history();
                //if size of string is 1 == empty line, since empty lien is 1
                //if yes, adavnce
                //infile reads in a line, and advances to the next
                //get line reads the line and puts it in string s

            //Map email to user  
            cerr << "Map " << email << " to user " << name << endl;
            m_userData.insert(email, user);
            movieIDs.clear();
            //user->insert(email, m_userEmail);
            getline(infile, line);

        }
        infile.close();
        return true;
    }

    return false;
    cerr << "didn't open" << endl;
    /*return false; */ // Replace this line with correct code.
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    TreeMultimap<std::string, User>::Iterator it = m_userData.find(email);
    if (!it.is_valid())
    {
        return nullptr;
    }
    return &(it.get_value());
    //return userEmail;
    //User* userData = userEmail.find(email);
  
    //return nullptr;  // Replace this line with correct code.
}
