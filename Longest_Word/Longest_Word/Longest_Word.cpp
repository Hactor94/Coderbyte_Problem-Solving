#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string LongestWord(string sen);
vector<string> split(string x, char delim);

int main() {
    string sen = "fun&!! time";
    cout << LongestWord(sen) << endl;
}
string LongestWord(string sen) {
    int s = sen.size();
    for (int i = 0; i < 5; i++) {
        if (ispunct(sen[i])) {
            sen.erase(i--, 1);
            s = sen.size();
        }
    }
    vector<string> v = split(sen, ' ');
    string h = "";
    for (int i = 0; i < v.size(); i++) {
        if (h.size() < v.at(i).size()) {
            h = v.at(i);
        }
    }
    return h;
}
vector<string> split(string x, char delim) // O(n)
{
    stringstream test(x);
    string segment;
    vector<string> seglist;

    while (getline(test, segment, delim))
    {
        seglist.push_back(segment);
    }
    return seglist;
}