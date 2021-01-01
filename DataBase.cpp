#include<bits/stdc++.h>
using namespace std;

#include "json.hpp"

#include "DataBase.h"

using json = nlohmann::json;

bool isLetter(string s){
        int n=s.length();
        for(int i=0;i<n;i++){
                if(!isalpha(s[i])){
                    return false;
                    }
        }
        return true;
}



void dataBase::create(string key,json value,int expiretime){
        if(m.find(key)!=m.end()){
                cout<<"error : key already exist"<<endl;
        }
        else{
                if(isLetter(key)){
                        if(m.size() < (1024*1024*1024) && value.size()<=(16*1024*1024)){
                                pair<json,time_t> p;
                                p={value,time(nullptr)+expiretime};
                                if(key.length()<=32){
                                        m.insert({key,p});
                                }
                        }
                        else{
                                cout<<"error : file size should be less than 1GB"<<endl;
                        }
                }
                else{
                        cout<<"error : key only contains alphabet"<<endl;
                }
        }
}

void dataBase::read(string key){
        if(m.find(key)==m.end()){
                cout<<"error : key does not exist in data base"<<endl;
        }
        else{
                time_t a=m[key].second;
                if(time(nullptr) < a){
                //        json o=m[key].first;
                        cout<<key<<": "<<m[key].first<<endl;

                //      for (auto &e : o.items()) {
                //            cout << e.key() << " : " << e.value() << "\n";
                //            }
                }
                else{
                        cout<<"error : time to live off "<<key<<" has expired"<<endl;
                }

        }

}


void dataBase::dElete(string key){
         if(m.find(key)==m.end()){
                cout<<"error:  key does not exist in data base"<<endl;
        }
        else{
                time_t a=m[key].second;
                if(time(nullptr) < a){
                        m.erase(key);
                        cout<<key<<"is deleted is deleted succesfully "<<endl;
                }
                else{
                        cout<<"error : time to live off "<<key<<"  has expired"<<endl;
                }

        }

}
