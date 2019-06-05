
#include <cstdlib>
#include "dbms2.hh"
namespace dbms2
{
  class LinkedListDbTable : public AbstractDbTable{
  public:
    LinkedListDbTable();
    ~LinkedListDbTable();

    struct node {
      movie m;
      node *next;
    };

    movie* get(int);
    //removes a movie from the table with the given id
    bool remove(unsigned long int);
    //adds a movie to the table
    bool add(movie);
    //Displays information of something store in the table
    bool show(int);
    //returns amount of rows used in the table
    int rows(){
      return rowsUsed;
    }

    int rowsUsed=0;
    node *head;
  };
}
