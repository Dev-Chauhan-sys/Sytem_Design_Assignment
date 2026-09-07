#include <string>
using namespace std;
class Movie { private: string title, language; int duration; public: Movie(string title,string language,int duration):title(title),language(language),duration(duration){} Movie():Movie("","",0){} const string& getTitle()const{return title;} const string& getLanguage()const{return language;} int getDuration()const{return duration;} };
