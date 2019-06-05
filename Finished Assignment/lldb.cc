#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include "dbms2.hh"
#include "lldb.hh"
using namespace std;
using namespace dbms2;

//initialises a linked list data base
LinkedListDbTable::LinkedListDbTable(){
  rowsUsed=0;
}

LinkedListDbTable::~LinkedListDbTable(){
  //frees up all dynamically allocated data
  if((*head).next==nullptr){
    free(head);
  }else{
    node *remove=head;
    node*temp;
    while((*remove).next!=nullptr){
      temp=remove;
      remove=(*remove).next;
      free(temp);
    }
  }
}
w
movie* LinkedListDbTable::get(int rowNum){
  //out of bounds checker
  if(rowNum>rowsUsed ||rowNum<0)
  return nullptr;
  //finds movie
  node *temp=head;
  for(int i; i<rowNum; i++){
    temp=(*temp).next;
  }
  return &((*temp).m);
}

//removes a movie from the table with the given id
bool LinkedListDbTable::remove(unsigned long int id){

  if(rowsUsed==0)
  return false;
  //finds node if there
  node *find=head;
  node *previous=nullptr;
  while((*find).m.id!=id &&(*find).next!=nullptr ){
    previous=find;
    find=(*find).next;
  }
  if((*find).m.id!=id) //not found
  return false;

  if(previous==nullptr){
    free(head);
  }else{
    (*previous).next=(*find).next;
    free(find);
  }
  rowsUsed--;
  return true;
}

//adds a movie to the table
bool LinkedListDbTable::add(movie mov){
  if(rowsUsed==0){
    head=(node*) malloc(sizeof(node));
    (*head).m=mov;
    (*head).next=nullptr;
    rowsUsed++;
    return true;
  }

  node *temp=head;
  while((*temp).next!=nullptr){//loops till last node
    temp=(*temp).next;
  }
  //adds a new node with movie obj
  node *add=(node*) malloc(sizeof(node));
  (*add).next=nullptr;
  (*add).m=mov;
  (*temp).next=add;
  rowsUsed++;
  return true;
}

//Displays information of something store in the table
bool LinkedListDbTable::show(int rowNum){
  //out of bounds checker
  if(rowNum>rowsUsed ||rowNum<0)
  return false;

  //finds movie
  node *temp=head;
  for(int i=0; i<rowNum; i++){
    temp=(*temp).next;
  }
  cout << "Movie id: " << (*temp).m.id << " Title: "<<(*temp).m.title << " Year: " <<(*temp).m.year << " Director: "<<(*temp).m.director <<endl;
  return true;
}
