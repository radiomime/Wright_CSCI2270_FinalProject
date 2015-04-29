//
//  main.cpp
//  Final_Project
//
//  Created by Matthew Wright on 4/26/15.
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
    int citySize = 0;
    
    
    
    // Set up City Graph
    cout<<"Welcome to Build a Bar Crawl! Lets get started..."<<endl;
    
    
    /* This set is to set up the size of a city, this can be viewed as a matrix.
     Each position in the city can have multiple bars.
     */
    
    while (citySize == 0 || citySize > 999) {
        cout<<"How big of a city are we working with? (enter an integer for your city size < 1000)"<<endl;
        cin>>citySize;
        
        if (citySize == 0 || citySize > 999) {
            cout<<"Invalid Input, lets try again."<<endl;
        }
    }
    
    
    
    
    while(!quit){
        bool back = false;
        
        
        cout<< "====== Main Menu =====" <<endl;
        cout<<"1. Edit Bars"<<endl;
        cout<<"2. Remove some Bars"<<endl;
        cout<<"3. Find a Party Plan"<<endl;
        cout<<"4. Quit"<<endl;
        cin>>response;
        
        switch (response) {
            case 1:
                while (!back) {
                    cout<<"====== Edit Bars Menu ======"<<endl;
                    cout<<"1. Add a Bar"<<endl;
                    cout<<"2. Remove a Bar"<<endl;
                    cout<<"3. Go Back"<<endl;
                    cin>>responseLevelTwo;
                    
                    if (responseLevelTwo == 1) {
                        // Add a Bar function
                        string barName;
                        char dummyChar;
                        int x;
                        int y;
                        
                        
                        // Get Info about the bar
                        
                        cout<<"What's the bar named?"<<endl;
                        cin>>ws;
                        getline(cin, barName);
                        
                        cout<<"Where is the bar located? (xValue yValue)"<<endl;
                        cin>>x>>y;
                        
                        
                        
                        
                        
                        
                        
                    }
                    
                    if (responseLevelTwo) {
                        // Remove a Bar function
                    }
                    
                    if (responseLevelTwo == 3) {
                        back = true;
                        break;
                    }
                    
                    
                }
                break;
            case 2:
                while (!back) {
                    cout<<"======  ======"<<endl;
                    cout<<"1. "<<endl;
                    cout<<"2. "<<endl;
                    cout<<"3. Go Back"<<endl;
                    cin>>responseLevelTwo;

                    if (responseLevelTwo == 3) {
                        back = true;
                        break;
                    }
                }
                break;
            case 3:
                while (!back) {
                    cout<<"======  ======"<<endl;
                    cout<<"1. "<<endl;
                    cout<<"2. "<<endl;
                    cout<<"3. Go Back"<<endl;
                    cin>>responseLevelTwo;

                    if (responseLevelTwo == 3) {
                        back = true;
                        break;
                    }
                }
                break;
            case 4:
                cout<<"Goodbye!"<<endl;
                quit = true;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                break;
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
    return 0;
}
