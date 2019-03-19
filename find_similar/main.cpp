//
//  main.cpp
//  find_similar
//
//  Created by Jonathan Raysor on 3/19/19.
//  Copyright © 2019 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    string file1 = "";   
    string file2 = "";    
    string similar = "";
    ifstream stream1;
    ifstream stream2;
    ofstream stream3;
    
    stream3.open(similar);
    stream1.open(file1, ios::in);
    stream2.open(file2, ios::in);
    
    vector<string> similarClasses;

    if (!stream1) cerr << "Can't open input file!";
    
    unordered_set<string> f1;
    unordered_set<string> f2;
    
    string className;
    
    while(getline(stream1, className)){
        f1.insert(className);
    }
    
    while(getline(stream2, className)){
        f2.insert(className);
    }
    
    for (const auto& elem: f1) {
        if (f2.count(elem) > 0){
            similarClasses.push_back(elem);
        }
    }
    
    sort(similarClasses.begin(), similarClasses.end()-1);
    
    for (const auto& element : similarClasses){
        stream3 << element << endl;
    }
        
    return 0;
}
