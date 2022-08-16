#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
using namespace boost::xpressive;

class NamedReToJson {
private:
    char Pattern[512];
    string name = ""; int l = 0;
    string json;

public:
    string parser(string,smatch);
};

string NamedReToJson::parser(string rePattern,smatch data) {
    // Regex To char
    for (int i = 0; i < rePattern.length(); i++) {
        Pattern[i] = rePattern[i];
    }
    // char to string
    for (int i = 0; i <= strlen(Pattern); i++) {
        if (Pattern[i] == '<') {
            i++;
            for (int j = i, k = 0 ;; j++, k++) {
                if (Pattern[j] == '>') {
                    i = j; l++;
                    name += ",";
                    break;
                }
                name += Pattern[j];
            }
        }
        else continue;
    }
    // String to Json Parsing
    stringstream line(name);
    string str; int i = 1;

    json += "{";
    while (getline(line, str, ',')) {
        if (i == l) {
            json += "\"" + str + "\":\"" + data[str] + "\"}";
        }
        else {
            json += "\"" + str + "\":\"" + data[str] + "\", ";
        }i++;
    }


    return json;
}