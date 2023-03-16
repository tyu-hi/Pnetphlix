#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include "treemm.h"
#include <fstream>
#include <sstream>
#include <cstring>
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
            std::string movieID = line;
            cerr << "movieID: " << movieID << endl;

            std::string movieName;
            getline(file, movieName);
            cerr << "moviename: " << movieName << endl;

            std::string movieReleaseYear;
            getline(file, movieReleaseYear);
            cerr << "movie release year: " << movieReleaseYear << endl;

            //push_Back all data with multiple values into a vector, parsing by comma
            vector<string> directors;
            getline(file, line);
            istringstream iss_directors(line);
            string directorNames;
            while (std::getline(iss_directors, directorNames, ','))
            {
                cerr << "director: " << directorNames << endl;
                directors.push_back(directorNames);
            }

            vector<string> actors;
            getline(file, line);
            istringstream iss_actors(line);
            string actorNames;
            while (getline(iss_actors, actorNames, ','))
            {
                cerr << "actors: " << actorNames << endl;
                actors.push_back(actorNames);
            }

            vector<string> genres;
            getline(file, line);
            istringstream iss_genres(line);
            string genreNames;
            while (getline(iss_genres, genreNames, ','))
            {
                //makeUpper(genreNames);
                cerr << "Genres: " << genreNames << endl;
                genres.push_back(genreNames);
            }

            float rating;
            file >> rating;
            cerr << "rating: " << rating << endl;

            Movie movie(movieID, movieName, movieReleaseYear, directors, actors, genres, rating);   //passing in vectors and values
            
            //for case insensitivity, toupper everything
            for (int i = 0; i < movieID.size(); i++) {
                movieID[i] = tolower(movieID[i]);
            }
            for (int i = 0; i < directorNames.size(); i++) {
                directorNames[i] = tolower(directorNames[i]);
            }
            for (int i = 0; i < actorNames.size(); i++) {
                actorNames[i] = tolower(actorNames[i]);
            }
            for (int i = 0; i < genreNames.size(); i++) {
                genreNames[i] = tolower(genreNames[i]);
            }


            //map movieID to movie object
            m_movieID.insert(movieID, movie);
            //map tree directors to movie object
            m_movieDirector.insert(directorNames, movie);
            //map actors to movie object
            m_movieActor.insert(actorNames, movie);
            //map string genres to movie object
            m_movieGenre.insert(genreNames, movie);

            //suspicious
            getline(file, line);
            getline(file, line);
        }
        return true;
    }
    return false;  // Replace this line with correct code.
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    std::string u_id = id;
    //for case-inensitivity
    for (int i = 0; i < u_id.size(); i++) {
        u_id[i] = tolower(u_id[i]);
    }

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

    string newdirector = director;
    for (int i = 0; i < newdirector.size(); i++) {
        newdirector[i] = tolower(newdirector[i]);
    }

    TreeMultimap<std::string, Movie>::Iterator it = m_movieDirector.find(newdirector);

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

    string newactor = actor;
    for (int i = 0; i < newactor.size(); i++) {
        newactor[i] = tolower(newactor[i]);
    }

    TreeMultimap<std::string, Movie>::Iterator it = m_movieActor.find(newactor);

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

    string newgenre = genre;
    for (int i = 0; i < newgenre.size(); i++) {
        newgenre[i] = tolower(newgenre[i]);
    }

    TreeMultimap<std::string, Movie>::Iterator it = m_movieGenre.find(newgenre);

    while (it.is_valid())
    {
        vectorGenre.push_back(&(it.get_value()));
        it.advance();
    }

    return vectorGenre;
    //return vector<Movie*>();  // Replace this line with correct code.
}

//string makeUpper(string& word)
//{
//    for (int i = 0; i < word.size(); i++) {
//        word[i] = toupper(word[i]);
//    }
//    return word;
//}