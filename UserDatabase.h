#ifndef USERDATABASE_INCLUDED
#define USERDATABASE_INCLUDED

#include <string>
#include <map>
#include <list>
#include "treemm.h"

class User;

class UserDatabase
{
  public:
      UserDatabase();
    bool load(const std::string& filename);
    User* get_user_from_email(const std::string& email) const;

  private:
      //map email addresses to users
      std::list<User> m_users;
      TreeMultimap<std::string, User> userEmail;
};

#endif // USERDATABASE_INCLUDED
