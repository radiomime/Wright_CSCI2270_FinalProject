//
//  main.cpp
//  Final_Project_2
//
//  Created by Matthew Wright on 4/19/15.
//  Copyright (c) 2015 Matthew Wright. All rights reserved.
//


#include <iostream>
#include <string>
#include <sstream>
#include "barGraph.h"


using namespace std;





int main(int argc, const char * argv[]) {
    bool quit = false;
    int response;
    int responseLevelTwo;
    barGraph myBarGraph;
    
    
    // Set up City Graph
    cout<<"Welcome to Build a Bar Crawl! Lets get started...\n"<<endl;
    
    cout<<"    Here you will specify the bars by their name, their location by their block (using a standard of 500 ft per block) in an east-west and north-south direction, and their relative height in feet.\n"<<endl;
    
    cout<<"You will be working with a 10 by 10 city, measured by values 0 through 9. Here is what it looks like now.\n"<<endl;
    
    myBarGraph.printCity();
    cout<<endl;
    
    
    bool back = false;
    while (!back) {
        bool Continue = false;
        
        
        while (!Continue) {
            cout<<"====== Set up bar crawl Menu ======"<<endl;
            cout<<"1. Add a Bar"<<endl;
            cout<<"2. Print Bars"<<endl;
            cout<<"3. Continue"<<endl;
            cin>>responseLevelTwo;
            
            if (responseLevelTwo == 1) {
                
                // Add a Bar function
                
                string barName;
                int x;
                int y;
                bool correctInfo = false;
                
                // Get Info about the bar:
                cout<<"\nWhat's the bar named? (No Commas Please!)"<<endl;
                cin>>ws;
                getline(cin, barName);
                cout<<"Where is the bar located ? (eastwestValue northsouthValue)"<<endl;
                cin>>x>>y;
                // Loop if info is incorrect/impossible
                if (x > -1 && x < 11 && y > -1 && y < 11) {
                    correctInfo = true;
                }
                while (!correctInfo) {
                    cout<<"Incorrect input information! Remember the city is only 10 by 10"<<endl;
                    cout<<"Where is the bar located ? (eastwestValue northsouthValue)"<<endl;
                    cin>>x>>y;
                    if (x > -1 && x < 11 && y > -1 && y < 11) {
                        correctInfo = true;
                    }
                }
                
                // Call function to add a bar to the graph of my bars
                myBarGraph.addABar(barName, x, y);
                
            }
            else if (responseLevelTwo == 2) {
                // Print Bar Function
                
                myBarGraph.printVertices();
            }
            
            else if (responseLevelTwo ==3){
                Continue = true;
            }
            else{
                cout<<"Incorrect input"<<endl;
                break;
            }
        }
        Continue = false;
        myBarGraph.AdjacentBarMenu();
        back = true;
    }
    
    
    
    
    
    while(!quit){
        back = false;
        
        cout<< "====== Main Menu =====" <<endl;
        cout<<"1. Print City Map"<<endl;
        cout<<"2. Find a Party Plan"<<endl;
        cout<<"3. Quit"<<endl;
        cin>>response;
        
        switch (response) {
            case 1:
                myBarGraph.printCity();
                break;
                
            case 2:
                while (!back) {
                    cout<<"====== Find a Party Plan ======"<<endl;
                    cout<<"1. Shortest Path Between Two Bars."<<endl;
                    cout<<"2. Shortest Distance between Two Bars."<<endl;
                    cout<<"3. Go Back"<<endl;
                    cin>>responseLevelTwo;
                    string startBar;
                    string endBar;
                    
                    if (responseLevelTwo == 1) {
                        cout<<"Enter a starting bar: ";
                        cin>>ws;
                        getline(cin, startBar);
                        cout<<"Enter an ending bar: ";
                        cin>>ws;
                        getline(cin, endBar);
                        myBarGraph.shortestPath(startBar, endBar);
                        break;
                    }
                    else if (responseLevelTwo == 2) {
                        cout<<"Enter a starting bar: ";
                        cin>>ws;
                        getline(cin, startBar);
                        cout<<"Enter an ending bar: ";
                        cin>>ws;
                        getline(cin, endBar);
                        myBarGraph.shortestDistance(startBar, endBar);
                        break;
                    }
                    else if (responseLevelTwo == 3) {
                        back = true;
                        break;
                    }
                }
                break;
            case 3:
                cout<<"Goodbye!"<<endl;
                quit = true;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                quit = true;
                break;
        }
        
        
        
        
        
    }
    return 0;
}