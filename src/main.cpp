#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int>& a,
         pair<char, int>& b) {
    
    return a.second > b.second;
}

int main(int argc, char const *argv[]) {
    std::ifstream file;

    file.open("hamlet.txt");

    if(!file.is_open()){
        return -1;
    }

    string line;

    map<char, int> occurences;

    while (getline(file, line)) {
        for (auto &&c : line) {
            if(occurences.count(c) == 0)
            {
                occurences[c] = 0;    
            }

            occurences[c] = occurences[c] + 1;
        }
    }

    file.close();



    vector<pair<char, int>> vec;

    for (auto &&pair : occurences) {
        vec.push_back(pair);
    }

    sort(vec.begin(), vec.end(), cmp);


    file.open("hamlet.txt");

    if(!file.is_open()){
        return -1;
    }

    while (getline(file, line)) {
        for (auto &&c : line) {
            unsigned char b = 0;

            for(auto &&pair : vec){
                if(pair.first == c){
                    break;
                }
                b += 1;
            }

            std::cout << b;
        }
    }

    file.close();
    
    return 0;
}
