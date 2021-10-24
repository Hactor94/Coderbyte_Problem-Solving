#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <vector>

using namespace std;

string findInterction(string arryStr[2]);
vector<string> split(string x, char delim);

int main()
{
    string arryStr[2] = {"3, 1, 4, 7, 13", "1, 2, 4, 13, 15"};
    cout << findInterction(arryStr); // O(n^2)
}

string findInterction(string arryStr[2]) { // O(n^2)
    string str1 = arryStr[0];
    vector<string> strSpt1 = split(str1, ',');
    string str2 = arryStr[1];
    vector<string> strSpt2 = split(str2, ',');

    set<string> S; string returnS = "";
    for (int x = 0; x < strSpt1.size(); x++) {
        for (int y = 0; y < strSpt2.size(); y++) {
            if (strSpt1.at(x) == strSpt2.at(y)) {
                S.insert(strSpt1.at(x));
            }
        }
    }
    for (auto it : S) {
        if (it[0] == ' ') {
            vector<string> str = split(it, ' ');
            returnS = returnS + str.at(1) + " ";
        }
        else {
            returnS = returnS + it + " ";
        }
    }
    return returnS;
}

// splits a std::string into vector<string> at a delimiter
vector<string> split(string x, char delim) // O(n)
{
    x.erase(remove(x.begin(), x.end(), ' '), x.end());
    stringstream test(x);
    string segment;
    vector<string> seglist;

    while (getline(test, segment, delim))
    {
        seglist.push_back(segment); //Spit string at ',' character
    }

    return seglist;
}
