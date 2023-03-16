#include "Recommender.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"

//#include "User.h"
#include "User.cpp"
//#include "Movie.h"
#include "Movie.cpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <algorithm>    //for sort function

using namespace std;

Recommender::Recommender(const UserDatabase& user_database,
                         const MovieDatabase& movie_database)
    :m_userData(user_database), m_movieData(movie_database)
{
    // Replace this line with correct code.
}

vector<MovieAndRank> Recommender::recommend_movies(const string& user_email, int movie_count)
{
    //make a vector for recommendations
    vector<MovieAndRank> recommendations;

    /*const */User* user = m_userData.get_user_from_email(user_email);
    //check if accessing invalid email address
    if (user == nullptr)
    {
        //return vector without making changes
        return recommendations;
    }

    //get user watch history vector --- const because we are not modifying vector content
                                  //--- reference because it's more efficent than making a copy of entire vector
    std::vector<string> watchHistory = user->get_watch_history();
    
    //create hash table to keep track of compatiblity score of each movie ID
        //so, this maps movieIDs to their corresponding scores
    //compatibility_score varaible in struct is used to store the overall comptability score, which we use to sort recommendations
    unordered_map<string, int> compatibilityScore;
        //unordered sets stores only keys
        //unordered maps stores key-value pairs, use if we want to lookup by key quickly

    ///compare movies and updata compatiblity score
    //"for each movie the user has previously wathced, determine the compatiblity score"
    for (/*const */string watched_movieID : watchHistory)
    {
        //get movie from movie ID
        /*const*/ 
        Movie* watchedMovie = m_movieData.get_movie_from_id(watched_movieID);
        if (!watchedMovie)
        {
            continue;
        }

        //"for each director asociated with each movie user has watched, 
        //every movie with that director in the list of directors, adds 20 points"
        /*const */
        vector<string> directors = watchedMovie->get_directors();
        for (/*const */string director : directors)
        {
            /*const*/ 
            vector<Movie*> moviesWithDirector = m_movieData.get_movies_with_director(director);
            for (Movie* movie_with_director : moviesWithDirector)
            {
                if (find(watchHistory.begin(), watchHistory.end(), movie_with_director->get_id()) != watchHistory.end())
                {
                    //find() returns iterator pointing to first occurecne of value of actor in vector
                    //if it's not found, then it returns watchHistory.end(), meaning it reached the end and didn't find it
                    compatibilityScore[movie_with_director->get_id()] += 20;
                }
            }
        }

        //"for each actor associated with each movie user has watched, 
        //each movie that has that actor in the list of actors, adds 30 points"
        vector<string> actors = watchedMovie->get_actors();
        for (string actor : actors)
        {
            vector<Movie*> moviesWithActor;
            for (Movie* movie_with_actor : moviesWithActor)
            {
                if (find(watchHistory.begin(), watchHistory.end(), movie_with_actor->get_id()) != watchHistory.end())
                {
                    compatibilityScore[movie_with_actor->get_id()] += 30;
                }
            }
        }
        
        //"for each genre associated with each movie user has watched, 
        //each movie that has that genre in its list of genres, add 1 point"
        vector<string> genres = watchedMovie->get_genres();
        for (string genre : genres)
        {
            vector<Movie*> moviesWithGenre = m_movieData.get_movies_with_genre(genre);
            for (Movie* movie_with_genre : moviesWithGenre)
            {
                if (find(watchHistory.begin(), watchHistory.end(), movie_with_genre->get_id()) != watchHistory.end())
                {
                    compatibilityScore[movie_with_genre->get_id()] += 1;
                }
            }
        }
    }

    //"for movies with comptaiblity score of at least 1, 
    //filter out movies user has already watched
    vector<MovieAndRank> recommendTheseMovies;
    //.first refers to key of comptabilityScore map, which is movieID
    //.second refers to value, which is compatibility score
   
    for (auto pair : compatibilityScore)
    {
        if (find(watchHistory.begin(), watchHistory.end(), pair.first) == watchHistory.end() && pair.second > 0)
        {
            //add movie to recomendation list
            //only if movie is not watched before (== watchHistory.end() means didn't fine movie in watch history)
            //and if compatiblity score is greater than 0
            recommendTheseMovies.emplace_back(pair.first, pair.second);
        }
    }

    //lambda function
    sort(recommendTheseMovies.begin(), recommendTheseMovies.end(), [&](MovieAndRank a, MovieAndRank b)    //
    {
        if (a.compatibility_score != b.compatibility_score)
        {
            return a.compatibility_score > b.compatibility_score;
        }
        if (m_movieData.get_movie_from_id(a.movie_id)->get_rating() != m_movieData.get_movie_from_id(b.movie_id)->get_rating())
        {
            return m_movieData.get_movie_from_id(a.movie_id)->get_rating() > m_movieData.get_movie_from_id(b.movie_id)->get_rating();
        }
        return a.movie_id < b.movie_id;
    });

    //return requested movies
   /* for (int i = 0; i < movie_count; i++)
    {
        recommendations.emplace_back();
    }*/
    return recommendTheseMovies;


    //return vector<MovieAndRank>();  // Replace this line with correct code.
}
