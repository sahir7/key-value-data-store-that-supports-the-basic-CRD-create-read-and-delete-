#include<bits/stdc++.h>
#include<thread>
#include "json.hpp"
#include "DataBase.h"

using namespace std;

using json = nlohmann::json;


int main(){
        dataBase d;
      
  //     for reading json file
 //     std::ifstream i("inputfile.json");
  //     json j1;
    //   i >> j1;
      
  
       json j1 = {  {"Name", "Sahir"}, {"Class","Btech" },{"Roll no", "1701"}  };

       json j2 = {  {"Name", "Mohd"}, {"Class","Btech" },{"Roll no", "1702"}  };


       //for create
	d.create("SectionA",j1,3);
	d.create("SectionB",j2,1);
	
	//for read
	this_thread::sleep_for(chrono::seconds(1));

	d.read("SectionA");
	d.read("SectionC");
         
	d.read("SectionB");
       
	//for read
	d.dElete("SectionA");
	d.dElete("SectionB");

       
       // multithreading
       //




        this_thread::sleep_for(chrono::seconds(1));

        thread t1(&dataBase::read,&d,"SectionA");

        thread t2(&dataBase::read,&d,"SectionB");
	
        cout<<endl;


        t1.join();
        t2.join();


        cout<<"program end"<<endl;

        return 0;
}
