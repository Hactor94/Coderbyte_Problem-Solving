#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "HashTable.h"

using namespace std;

string FindIntersection(string strArr[]);
string FindIntersection2(string strArr[]);
vector<string> split(string x, char delim);

int main()
{
    HashTable ht;
    string arryStr[2] = { "3, 1, 4, 7, 13", "1, 2, 4, 13, 15" };
    cout << "First Solution with O(n^2)" << endl;
    cout << FindIntersection(arryStr) << endl; // O(n^2)
    cout << "Second Solution with O(n)" << endl;
    cout << FindIntersection2(arryStr); // O(1)
}

string FindIntersection2(string strArr[]) { // O(1)

    string str = "";
    vector<string> strSpt1 = split(strArr[0], ',');
    vector<string> strSpt2 = split(strArr[1], ',');
    set<string, greater<string>> S;
    HashTable ht;

    ht.insert(strSpt1);
    for (int i = 0; i < strSpt2.size(); i++) {
        if (ht.search(strSpt2.at(i))) {
            S.insert(strSpt2.at(i));
        }
    }
    for (auto it : S) {
        str = str + it + ',';
    }
    return str.substr(0, str.length() - 1);
}

string FindIntersection(string strArr[]) { // O(n^2)

    vector<string> strSpt1 = split(strArr[0], ',');
    vector<string> strSpt2 = split(strArr[1], ',');

    set<string, greater<string>> S; string returnS = "";
    for (int x = 0; x < strSpt1.size(); x++) {
        for (int y = 0; y < strSpt2.size(); y++) {
            if (strSpt1.at(x) == strSpt2.at(y)) {
                S.insert(strSpt1.at(x));
            }
        }
    }
    for (auto it : S) { 
        returnS = returnS + it + ',';  
    }
    return returnS.substr(0, returnS.length() - 1);
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

