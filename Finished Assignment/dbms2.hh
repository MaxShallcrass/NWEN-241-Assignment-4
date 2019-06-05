
#ifndef __DBMS2_HH__
#define __DBMS2_HH__

#include <iostream>
#include <cstring>
#include <cstdlib>


#include <fstream>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace dbms2
{
  struct movie {
    unsigned long id;
    char title[50];
    unsigned short year;
    char director[50];
  };


  class AbstractDbTable{

  public:

    virtual ~AbstractDbTable(){};
    //Gets a movie from the structure from the table
    virtual movie* get(int)=0;
    //removes a movie from the table with the given id
    virtual bool remove(unsigned long int)=0;
    //adds a movie to the table
    virtual bool add(movie)=0;
    //Displays information of something store in the table
    virtual bool show(int)=0;
    //returns amount of rows used in the table
    virtual int rows(void)=0;


/**
*Loads data from file into the database
*/
    bool loadCSV(const char *infn){
      if(infn==nullptr)
        return false;


      ifstream csv;
      csv.open(infn);
      if(!csv.is_open()) {
        printf("Failed to open .csv file\n");
        return false;
      }

      movie m;
      while(!csv.eof()) {
        string t;

        // id
        if(!getline(csv, t, ',')) break;
        if(atoi(t.c_str())==0){csv.close(); return false;}//invalid checker
        m.id=atoi(t.c_str());

        // title
        if(!getline(csv, t, ',')) break;
        if(t.size()>50 ||t.size()==0){csv.close(); return false;}//invalid checker
        strncpy(m.title, t.c_str(), t.length()+1);

        // year
        if(!getline(csv, t, ',')) break;
        if(t.size()!=4 ||atoi(t.c_str())==0) {csv.close(); return false;}//invalid checker
        m.year=atoi(t.c_str());

        //director
        if(!getline(csv, t)) break;
        if(t.size()>50 ||t.size()==0) {csv.close(); return false;}//invalid checker
        strncpy(m.director, t.c_str(), t.length()+1);
        add(m);
      }
      csv.close();
      return true;
    }

    /**
    *Saves data from database into a file
    */
    bool saveCSV(const char *outfn){
      //opening output stream and checking for errors
      ofstream outF;
      outF.open (outfn);
      if(!outF.is_open()) {
        printf("Failed to open scifi.csv\n");
        outF.close();
        return false;
      }


      //outputting data ino file
      for(int i=0;i<rows(); i++){
        string line;
        string temp;
        movie m=*get(i);
        //id
        temp=to_string(m.id);
        line+=temp +",";
        //Title
        temp=m.title;
        line+=temp +",";
        //Year
        temp=to_string(m.year);
        line+=temp +",";
        //Director
        temp=m.director;
        line+=temp +"\n";
        outF << line;
      }

outF.close();
return true;
    }
  };
}

#endif
