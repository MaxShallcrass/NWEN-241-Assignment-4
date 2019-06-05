#include "dbms2.hh"
#include "vdb.hh"
#include <iostream>
using namespace std;
using namespace dbms2;


int main(int argc, char *argv[]) {
  VectorDbTable *db;
  db = new VectorDbTable();
  db->loadCSV("default.csv");
  string command=argv[1];
  //Shows movie at index of the second command line input
  if(command=="show"){
    int id = atoi(argv[2]);
    db->show(id);
    //shows all movies contained in database
  }else if(command=="showall"){
    int index=0;
    for (auto i = db->table.begin(); i != db->table.end(); ++i){
      db->show(index++);
    }
  }
  delete db;
}
