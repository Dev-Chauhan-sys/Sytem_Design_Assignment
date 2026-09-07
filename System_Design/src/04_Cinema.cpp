#include <vector>
#include <memory>
#include <string>
using namespace std;
class Screen;
class Cinema { private: string name; vector<unique_ptr<Screen>> screens; public: explicit Cinema(string name):name(move(name)){} const string& getName()const{return name;} void addScreen(unique_ptr<Screen> s){screens.push_back(move(s));} Screen* getScreen(int n)const; };
