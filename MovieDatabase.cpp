#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include "treemm.h"

using namespace std;

MovieDatabase::MovieDatabase()
{
    // Replace this line with correct code.
}

bool MovieDatabase::load(const string& filename)
{

    return false;  // Replace this line with correct code.
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    std::string u_id = id;

    TreeMultimap<std::string, Movie>::Iterator it = m_movieID.find(u_id);

    if (!(it.is_valid()))
    {
        return nullptr;
    }
    return &it.get_value();

    //return nullptr;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    //create vector, push back (*(it.get_value), then return
    vector<Movie*> vectorDirector;
    TreeMultimap<std::string, Movie>::Iterator it = m_movieDirector.find(director);

    while (it.is_valid())
    {
        vectorDirector.push_back(&(it.get_value()));
        it.advance();
    }

    
    return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}
