#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include "treemm.h"
#include <fstream>

using namespace std;

MovieDatabase::MovieDatabase()
{
    // Replace this line with correct code.
}

bool MovieDatabase::load(const string& filename)
{
    //MovieID
    //movie name
    //movie release year
    //director1, director2, ...
    //actor1, actor2, ...
    //genre1, genre2, ...
    //rating out of 5 stars
    std::ifstream file(filename);
    if (!file)
    {
        cerr << "didn't open movie file " << endl;
        return false;
    }
    string line;
    if (file.is_open())
    {
        //remember, all of this should be case-insensitive
        while (std::getline(file, line))
        {
            if (line.size() == 1)
            {
                getline(file, line);
            }
            string movieID = line;
            string movieName;
            getline(file, movieName);
            cerr << "moviename: " << movieID << endl;

            int movieReleaseYear;
            file >> movieReleaseYear;
            file.ignore(100000, '\n');
            cerr << "movie release year: " << movieReleaseYear << endl;

            vector<string> directors;
            while (std::getline(file, line))
            {
                string substring;
                getline(file, substring, ',');
                cerr << "directors: " << substring << " " << endl;
                directors.push_back(substring);
            }

            vector<string> actors;
            while (std::getline(file, line))
            {
                string substring;
                getline(file, substring, ',');
                cerr << "acrors: " << substring << " " << endl;
                actors.push_back(substring);
            }

            vector<string> genres;
            while (file.good())
            {
                string substring;
                getline(file, substring, ',');
                cerr << "genres: " << substring << " " << endl;
                genres.push_back(substring);
            }

            float rating;
            file >> rating;
            cerr << "rating: " << rating << endl;
           
            //for (int i = 0; i < )
            getline(file, line);
        }
        return true;
    }
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

    return vectorDirector;
    //return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    vector<Movie*> vectorActor;
    TreeMultimap<std::string, Movie>::Iterator it = m_movieActor.find(actor);

    while (it.is_valid())
    {
        vectorActor.push_back(&(it.get_value()));
        it.advance();
    }

    return vectorActor;
    //return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{

    vector<Movie*> vectorGenre;
    TreeMultimap<std::string, Movie>::Iterator it = m_movieGenre.find(genre);

    while (it.is_valid())
    {
        vectorGenre.push_back(&(it.get_value()));
        it.advance();
    }

    return vectorGenre;
    //return vector<Movie*>();  // Replace this line with correct code.
}
