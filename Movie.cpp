#include "Movie.h"

#include <string>
#include <vector>
using namespace std;

Movie::Movie(const string& id, const string& title, const string& release_year,
             const vector<string>& directors, const vector<string>& actors,
             const vector<string>& genres, float rating)
    :m_id(id), m_title(title), m_releaseYear(release_year), m_directors(directors), m_actors(actors),
    m_genres(genres), m_rating(rating)
{
    // Replace this line with correct code.
}

string Movie::get_id() const
{
    return m_id;
    //return "DUMMY";  // Replace this line with correct code.
}

string Movie::get_title() const
{
    return m_title;
    //return "DUMMY";  // Replace this line with correct code.
}

string Movie::get_release_year() const
{
    return m_releaseYear;
    //return "DUMMY";  // Replace this line with correct code.
}

float Movie::get_rating() const
{
    return m_rating;
    //return -999;  // Replace this line with correct code.
}

vector<string> Movie::get_directors() const
{
    return m_directors;
    //return vector<string>();  // Replace this line with correct code.
}

vector<string> Movie::get_actors() const
{
    return m_actors;
    //return vector<string>();  // Replace this line with correct code.
}

vector<string> Movie::get_genres() const
{
    return m_genres;
    //return vector<string>();  // Replace this line with correct code.
}
