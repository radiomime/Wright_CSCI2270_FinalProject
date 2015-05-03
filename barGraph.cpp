//
//  barGraph.cpp
//  Final_Project_2
//
//  Created by Matthew Wright on 4/21/15.
//  Copyright (c) 2015 Matthew Wright. All rights reserved.
//

#include "barGraph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <math.h>

using namespace std;

barGraph::barGraph()
{
    //ctor
}

barGraph::~barGraph()
{
    //dtor
}



bool barGraph::isThereABarHere(int x, int y){
    vertex *tester;
    
    for (int i = 0; i<vertices.size(); i++) {
        tester = &vertices[i];
        if ( (x == tester->xValue) && (y == tester->yValue) ) {
            return true;
        }
    }
    return false;
}


void barGraph::AdjacentBarMenu(){
    string adjBarString;
    
    cout<<"Now lets find out which bars are adjacent to each other"<<endl;
    
    for (int i = 0; i<vertices.size()-1; i++) {
        cout<<"Please separate bar names with commas. Following is a list of bars to choose from:\n         ";
        for (int j = i+1; j < vertices.size(); j++) {
            cout<<vertices[j].barName<<",";
        }
        
        cout<<"\n\nAdjacent Bars to "<<vertices[i].barName<<" (separated by commas):"<<endl;
        getline(cin, adjBarString);
        getline(cin, adjBarString);
        istringstream ss(adjBarString);
        string adjBarName;
        
        while(getline(ss, adjBarName, ',')) {
            addAdjacentBars(vertices[i].barName, adjBarName);
        }
    }
}


void barGraph::addAdjacentBars(string barName, string adjBarName){
    vertex* newBar;
    vertex* adjBar;
    string adjResponse;
    
    bool adjBarFound = false;
    
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].barName == barName){
            newBar = &vertices[i];
        }
    }
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].barName == adjBarName){
            adjBar = &vertices[i];
            adjBarFound = true;
        }
    }
    if (adjBarFound) {
        int weightNewtoAdj;
        int weightAdjtoNew;
        
        weightNewtoAdj = findWeight(newBar, adjBar);
        weightAdjtoNew = findWeight(adjBar, newBar);
        
        addEdge(newBar->barName, adjBar->barName, weightNewtoAdj, weightAdjtoNew);
    }
    else{
        cout<<barName<<" Not Found. Not added.\nNote: A bar cannot be adjacent to itself."<<endl;
    }
    
    
}



void barGraph::printCity(){
    findDistricts();
    
    cout<<"Your city:\n\n  ";
    for (int i = 0; i<10; i++) {
        cout<<" "<<i<<" ";
    }
    cout<<endl;
    for (int y = 9; y>=0; y--) {
        cout<<y<<" ";
        for (int x = 0; x<10; x++) {
            
            if (!isThereABarHere(x, y)) {
                cout<< " _ ";
            }
            else{
                cout<< " X ";
            }
        }
        cout<<endl;
    }
    
    cout<<endl; //Formating
    
    
    for (int e = 1; e <= barSceneMax(); e++) {
        cout<<"Scene "<<e<<":"<<endl;
    
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].barScene == e) {
                cout<<"Name: "<<vertices[i].barName<<" Position: "<<vertices[i].xValue<<", "<<vertices[i].yValue<<"\n";
                for (int j =0; j < vertices[i].adj.size(); j++) {
                    cout<<"    Adj: "<<vertices[i].adj[j].adjV->barName<<"\n";
                }
            }
        }
        cout<<endl;
    }
    
    
    
}







/*
 Prints every bar, and underneath each bar, indented is the bars position.
 */

void barGraph::printVertices(){
    for (int i = 0; i < vertices.size(); i++) {
        cout<<"Bar Name: '"<<vertices[i].barName<<"'\n    Position: "<<vertices[i].xValue<<", "<<vertices[i].yValue<<"\n"<<endl;
    }
}






int barGraph::findWeight(vertex *barOne, vertex *destBar){
    
    int a = destBar->xValue - barOne->xValue;
    int b = destBar->yValue - barOne->yValue;
    
    a = a*a;
    b = b*b;
    
    return a+b;
}


/*
 add and Adjacent bar will add adjacent bars
 
 
 */







void barGraph::addABar(std::string barName, int xValue, int yValue){
    bool added;
    vertex* newBar;
    string adjBarString;
    string adjResponse;
    
    
    // Add the vertex to the graph
    
    added = addVertex(barName, xValue, yValue);
    
    /* Adjacent bars.
     Here we will add all of the adjacent bars, or reachable bars, to the current vertex. We don't want to run into the police, and we want the weight between the bars to be reflective of both the distance and the amount of hill between each bar. God knows we don't want to be walking up a 45 percent grade just to get to another pub.
     
     We will execute the second part of this endeavor if (added) is true. (added) will be true if the bar has successfully been added as a vertex, or there are no bars with the same name. The same place is okay, or even good, because bars next door to one another are like best friend bars.
     */
    
    if (added) {
        
        // *newBar will point to the newly created bar
        // The new bar was just added to the vertices vector, so it will be the last bar, at position (size-1)
        
        newBar = &vertices[vertices.size()-1];
        cout<<newBar->barName<<" has been added."<<endl;
                
    }
}



/*
 This function adds a vertex, or a bar, to our graph of vertices.
 
 
 */

bool barGraph::addVertex(std::string barName, int xValue, int yValue){
    bool added = false;
    bool found = false;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].barName == barName){
            found = true;
            cout<<vertices[i].barName<<"Bar with that name already Exists.\nNot Added to Graph"<<endl;
            added = false;
        }
    }
    
    if(found == false){
        vertex x;
        x.barName = barName;
        x.xValue = xValue;
        x.yValue = yValue;
        x.barScene = -1;
        vertices.push_back(x);
        added = true;
    }
    
    return added;
}

/*
 This function adds an edge between vertices, or a bars, to our graph of vertices.
 */

void barGraph::addEdge(std::string nameOne, std::string nameTwo, int barOnetoTwo, int barTwotoOne){
    
    for(int i = 0; i < vertices.size(); i++){
        
        if(vertices[i].barName == nameOne){
            
            for(int j = 0; j < vertices.size(); j++){
                
                if((vertices[j].barName == nameTwo) && (i != j)){
                    adjVertex av;
                    av.adjV = &vertices[j];
                    av.weightThere = barOnetoTwo;
                    vertices[i].adj.push_back(av);
                    
                    
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.adjV = &vertices[i];
                    av2.weightThere = barTwotoOne;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}




















int barGraph::barSceneMax(){
    int max = -1;
    for (int i = 0; i<vertices.size(); i++) {
        if (vertices[i].barScene > max) {
            max = vertices[i].barScene;
        }
    }
    return max;
}




void barGraph::findDistricts()
{
    int i;
    int barSceneCounter = 1;
    for(i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
    for(int k = 0; k < vertices.size();k++)
    {
        if(vertices[k].visited == false)
        {
            vertices[k].visited = true;
            vertices[k].barScene = barSceneCounter;
            queue <vertex*> q;
            q.push(&vertices[k]);
            while(!q.empty())
            {
                vertex A = *q.front();
                q.pop();
                for(int w = 0; w < A.adj.size(); w++)
                {
                    if(A.adj[w].adjV->visited == false && A.adj[w].weightThere != -1)
                    {
                        A.adj[w].adjV->barScene = barSceneCounter;
                        A.adj[w].adjV->visited = true;
                        //cout<<A.adj[w].v->name<<endl;
                        q.push(A.adj[w].adjV);
                    }
                }
            }
            barSceneCounter++;
        }
    }
}


void barGraph::shortestPath(std::string starting, std::string destination)
{
    vertex *start = NULL;
    vertex *ending= NULL;
    vector<vertex*> solved;
    int sTail=0;
    int minDistance = 32000;
    
    for(int i=0; i<vertices.size();i++)
    {
        vertices[i].visited=false;
        vertices[i].previous=NULL;
        vertices[i].distance=32000;
        if(vertices[i].barName == starting)
        {
            start = &vertices[i];
            start->visited=true;
            start->distance=0;
        }
        else if(vertices[i].barName == destination)
        {
            ending= &vertices[i];
        }
    }
    if(start == NULL || ending == NULL)
    {
        cout<<"One or more cities doesn't exist"<<endl;
    }
    else if(start->barScene != ending->barScene)
    {
        cout<<"No safe path between cities"<<endl;
    }
    else if(start->barScene == -1 || ending->barScene == -1)
    {
        cout<<"Please identify the districts before checking distances"<<endl;
    }
    else
    {
        solved.push_back(start);
        sTail++;
        
        while(ending->visited == false)
        {
            minDistance = 32000;
            vertex* minVertex=NULL;
            vertex* minPrev;
            int tempDistance=0;
            for(int i=0;i<sTail;i++)
            {
                solved[i]->visited=true;
                for(int j=0; j<solved[i]->adj.size();j++)
                {
                    if(solved[i]->adj[j].adjV->visited==false && solved[i]->adj[j].weightThere != -1)
                    {
                        tempDistance= solved[i]->distance+solved[i]->adj[j].pathWeight;
                        if(tempDistance<minDistance)
                        {
                            solved[i]->adj[j].adjV->distance=tempDistance;
                            minDistance=tempDistance;
                            minVertex=solved[i]->adj[j].adjV;
                            minPrev=solved[i];
                            
                        }
                        
                    }
                }
                
            }
            minVertex->previous=minPrev;
            solved.push_back(minVertex);
            sTail++;
        }
        
        cout<<"Shortest Path"<<endl;
        vector<string> path;
        vertex* x = ending;
        while(x != NULL)
        {
            path.push_back(x->barName);
            x=x->previous;
        }
        cout<<minDistance<<", " <<path[path.size()-1];
        for(int i = path.size()-2; i>-1; i--)
        {
            cout<<", " <<path[i];
        }
        cout<<endl;
    }
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
        vertices[i].distance = 32000;
    }
}

void barGraph::shortestDistance(std::string starting, std::string destination)
{
    
    vertex *start = NULL;
    vertex *ending= NULL;
    vector<vertex*> solved;
    int sTail=0;
    int minDistance = 32000;
    
    for(int i=0; i<vertices.size();i++)
    {
        vertices[i].visited=false;
        vertices[i].previous=NULL;
        vertices[i].distance=32000;
        if(vertices[i].barName == starting)
        {
            start = &vertices[i];
            start->visited=true;
            start->distance=0;
        }
        else if(vertices[i].barName == destination)
        {
            ending= &vertices[i];
        }
    }
    if(start == NULL || ending == NULL)
    {
        cout<<"One or more cities doesn't exist"<<endl;
    }
    else if(start->barScene != ending->barScene)
    {
        cout<<"No safe path between cities"<<endl;
    }
    else if(start->barScene == -1 || ending->barScene == -1)
    {
        cout<<"Please identify the districts before checking distances"<<endl;
    }
    else
    {
        solved.push_back(start);
        sTail++;
        
        while(ending->visited == false)
        {
            minDistance = 32000;
            vertex* minVertex=NULL;
            vertex* minPrev;
            int tempDistance=0;
            for(int i=0;i<sTail;i++)
            {
                solved[i]->visited=true;
                for(int j=0; j<solved[i]->adj.size();j++)
                {
                    if(solved[i]->adj[j].adjV->visited==false && solved[i]->adj[j].weightThere != -1)
                    {
                        tempDistance= solved[i]->distance+solved[i]->adj[j].weightThere;
                        if(tempDistance<minDistance)
                        {
                            solved[i]->adj[j].adjV->distance=tempDistance;
                            minDistance=tempDistance;
                            minVertex=solved[i]->adj[j].adjV;
                            minPrev=solved[i];
                            
                        }
                        
                    }
                }
                
            }
            minVertex->previous=minPrev;
            solved.push_back(minVertex);
            sTail++;
        }
        
        cout<<"Shortest Path"<<endl;
        vector<string> path;
        vertex* x = ending;
        while(x != NULL)
        {
            path.push_back(x->barName);
            x=x->previous;
        }
        cout<<minDistance<<", " <<path[path.size()-1];
        for(int i= path.size()-2; i>-1; i--)
        {
            cout<<", " <<path[i];
        }
        cout<<endl;
    }
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
        vertices[i].distance = 32000;
    }
    
    
}