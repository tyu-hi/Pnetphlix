#ifndef MOVIEDATABASE_INCLUDED
#define MOVIEDATABASE_INCLUDED

#include <string>
#include <vector>
#include "treemm.h"
class Movie;

class MovieDatabase
{
  public:
    MovieDatabase();
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;

  private:
      //string makeUpper(string& word);

      TreeMultimap<std::string, Movie> m_movieID;
      
      TreeMultimap<std::string, Movie> m_movieDirector;
      TreeMultimap<std::string, Movie> m_movieActor;
      TreeMultimap<std::string, Movie> m_movieGenre;

};

#endif // MOVIEDATABASE_INCLUDED
