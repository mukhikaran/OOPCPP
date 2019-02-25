//
//  main.cpp
//  Assignment3
//
//  Created by Karan Mukhi on 13/02/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool nameSort(const string a, const string b){
    string A = a.substr(5,20);
    string B = b.substr(5,20);
    return A < B;
}


int main() {
    // open file containing example courses
    fstream courseData;
    courseData.open("/Users/karanmukhi/Desktop/oop/Assignment3/courselist.dat");
    if(!courseData.good()){
        cerr<<"Error: File could not be opened\n";
        return 1;
    }
    string line;
    vector <string> courseList;

    int cont(1);
    char c;
    while(cont){
        cout << "Please enter a course number followed by the course title.\n";
        
        //getline(courseData,line);
        getline(cin,line);
        cout << "You entered: " << line << endl;
        courseList.push_back(line);
        cout << "Would you like to enter another course? (y/n)" << endl;
        cin >> c;
        //c = 'y';
        cin.ignore();
        bool good(1);
        while(good){
            if (c == 'y') {cont = 1; good = 0;}
            else if(c == 'n') {cont = 0; good = 0;}
            else {cout << "Invlaid input. (y/n)"; cin >> c; cin.ignore();}
            }
    }
    //Initialise iterators
    vector<string>::iterator start{courseList.begin()}, end{courseList.end()};
    vector<string>::iterator current;
    cout << "You have entered:\n";
    for (current = start; current < end; current++){
        cout << * current << endl;
    }
    cout << "Would you like to see a year split? (y/n)" << endl;
    cin >> c;
    cin.ignore();

    while(true){
        if (c == 'y') {cont = 1; break;}
        else if(c == 'n') {cont = 0; break;}
        else {cout << "Invlaid input. (y/n)"; cin >> c; cin.ignore();}
    }
    
    if(cont){
        cout << "\nYour first year subjects are:\n";
        for (current = start; current < end; current++){
            line = *current;
            if (line[0] == '1') {cout << *current << endl;}
        }
        cout << "\nYour second year subjects are:\n";
        for (current = start; current < end; current++){
            line = *current;
            if (line[0] == '2') {cout << *current << endl;}
        }
        cout << "\nYour third year subjects are:\n";
        for (current = start; current < end; current++){
            line = *current;
            if (line[0] == '3') {cout << *current << endl;}
        }
        cout << "\nYour fourth year subjects are:\n";
        for (current = start; current < end; current++){
            line = *current;
            if (line[0] == '4') {cout << *current << endl;}
        }
    }
    
    cout << "Would you like to sort by unit number? (y/n)";
    cin >> c;
    cin.ignore();
    while(true){
        if (c == 'y') {cont = 1; break;}
        else if(c == 'n') {cont = 0; break;}
        else {cout << "Invlaid input. (y/n)"; cin >> c; cin.ignore();}
    }
    if(cont){
        sort(courseList.begin(), courseList.end());
        for (current = start; current < end; current++){
            cout << * current << endl;
        }
    }
    
    cout << "Would you like to sort by name? (y/n)";
    cin >> c;
    cin.ignore();
    while(true){
        if (c == 'y') {cont = 1; break;}
        else if(c == 'n') {cont = 0; break;}
        else {cout << "Invlaid input. (y/n)"; cin >> c; cin.ignore();}
    }
    cout << cont;
    if(cont){
        sort(courseList.begin(), courseList.end(), nameSort);
        for (current = start; current < end; current++){
            cout << * current << endl;
        }
    }
    
    return 0;
}


