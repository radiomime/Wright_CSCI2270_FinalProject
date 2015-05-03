//
//  barGraph.h
//  Final_Project_2
//
//  Created by Matthew Wright on 4/21/15.
//  Copyright (c) 2015 Matthew Wright. All rights reserved.
//

#ifndef __Final_Project__barGraph__
#define __Final_Project__barGraph__

#include <stdio.h>

#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *adjV;
    int weightThere;
    int pathWeight;
    
};

struct vertex{
    std::string barName;
    int barScene;
    bool visited;
    int distance;
    int xValue;
    int yValue;
    vertex *previous;
    std::vector<adjVertex> adj;
};

class barGraph{
    
    
public:
    barGraph();
    virtual ~barGraph();
    void printCity();
    bool isThereABarHere(int x, int y);
    void addAdjacentBars(std::string barName, std::string adjBarName);
    void AdjacentBarMenu();
    void addABar(std::string barName, int xValue, int yValue);
    void addEdge(std::string nameOne, std::string nameTwo, int barOne, int barTwo);
    bool addVertex(std::string name, int xValue, int yValue);
    int findWeight(vertex* barOne, vertex* destBar);
    void printVertices();
    int barSceneMax();
    void findDistricts();
    void shortestPath(std::string, std::string);
    void shortestDistance(std::string, std::string);
protected:
private:
    std::vector<vertex> vertices;
};




#endif /* defined(__Final_Project__barGraph__) */
