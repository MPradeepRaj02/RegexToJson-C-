#include <iostream>
#include "NamedReToJson.cc"

using namespace std;
NamedReToJson ReJson;

int main() {
    //Pattern to Parse the Access log
    string RePattern = "^(?P<IP>\\d{1,3}(\\.\\d{1,3}){3})( - - )\\[(?P<Time>.*)\\] \"(?P<Request>.*)\" (?P<StatusCode>.*) (?P<Port>.*) \"(?P<URL>.*)\" \"(?P<User>.*)\" \"(.*)\" response-time=(?P<ResponseTime>.*)";
    string data = "106.195.46.185 - - [10/Mar/2022:06:17:48 +0000] \"GET /static/admin/fonts/Roboto-Light- webfont.woff HTTP / 1.1\" 304 0 \"http://dorzibik.pythonanywhere.com/static/admin/css/fonts.css\" \"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36\" \"106.195.46.185\" response-time=0.001";
    
    sregex LogPattern = sregex::compile(RePattern);
    smatch match;

    //Check whether the data matches pattern 
    if (regex_search(data, match, LogPattern)) {
        //Converts Matches into Json
        string OpJson = ReJson.parser(RePattern, match);
        cout << OpJson << endl;
    }

    return 0;
}
