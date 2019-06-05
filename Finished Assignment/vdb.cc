

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include "dbms2.hh"
#include "vdb.hh"
using namespace std;
using namespace dbms2;

VectorDbTable::VectorDbTable(){rowsUsed=0;}
VectorDbTable::~VectorDbTable(){}

movie* VectorDbTable::get(int rowNum){
  if(rowNum<0 || rowNum>rows())
  return nullptr;

  movie *ptr= &table.at(rowNum);
  return ptr;
}

bool VectorDbTable::show(int rowNum){
  if(rowNum<0 || rowNum>rows()){
printf("Error: row %d does not exist\n", rowNum);
  return false;
}
  cout << "Movie id: " << table.at(rowNum).id << " Title: "<<table.at(rowNum).title << " Year: " <<table.at(rowNum).year << " Director: "<<table.at(rowNum).director <<endl;
  return true;
}

bool VectorDbTable::add(movie mov){
  table.push_back(mov);
  rowsUsed++;

  return true;
}

bool VectorDbTable::remove(unsigned long int movieId){
  bool found=false;
  int rowNum=0;

  for(int i=0; i<rowsUsed; i++){
    if(table.at(i).id==movieId){
      rowNum=i;
      found=true;
      break;
    }
  }

  if(!found) //incorrect id
  return false;

  auto it = table.begin();
  table.erase((it + rowNum));

  rowsUsed--;
  return true;
}
