#include<bits/stdc++.h>
using namespace std;

#include "json.hpp"
using json = nlohmann::json;
class dataBase{

        
        unordered_map<string,pair<json,time_t>> m;
        public:
        	
        void create(string key, json value,int expiretime);
        void read(string key);
        void dElete(string key);

};
