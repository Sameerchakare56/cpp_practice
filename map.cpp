#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<string , int> m;
    m["Tv"] = 10;
    m["fan"] = 2;
    m["table"] = 3;

    m["camera"] = 5;
    m.emplace("laptop", 15);

    m.erase("table");
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    cout <<"Count of items in map : "<<m.count("Tv") << endl;
    cout <<"value of Tv : "<<m["Tv"] << endl;
    if(m.find("TV") != m.end()) {
        cout << "Tv found in the map." << endl;
    }else {
        cout << "Tv not found in the map." << endl;
    }

    multimap<string , int> mm;
    mm.emplace("Tv", 10);
    mm.emplace("Tv", 20);
    mm.emplace("table", 3);
    mm.emplace("Tv", 30);
    mm.emplace("fan", 2);
    // mm.erase("Tv");
    mm.erase(mm.find("Tv"));
    for(auto p : mm){
        cout << p.first << " " << p.second << endl;
    }
    cout <<" Unordered map : " << endl;
    unordered_map<string , int> unOmap;
    unOmap["Tv"] = 10;
    unOmap["Tv"] = 20;
    unOmap["fan"] = 2;
    unOmap["table"] = 3;
    for(auto p : unOmap){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}