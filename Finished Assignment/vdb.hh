#include <vector>
#include "dbms2.hh"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
namespace dbms2
{
  class VectorDbTable : public AbstractDbTable{

  public:
    VectorDbTable();
    ~VectorDbTable();

    movie* get(int);
    bool remove(unsigned long int);
    bool add(movie);
    bool show(int);
    int rows(){
      return rowsUsed;
    };

    //stores a table of movies
    vector<movie> table;

    int rowsUsed=0;
  };
}
