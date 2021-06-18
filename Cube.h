//
//  Cube.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#pragma once

#include <iostream>
#include "Face.h"
#include <string>

class Cube{
    public:
   
    face* cube3[faces]; 
    
    Cube(); //constructor, note that pos is the orientation, so U L R F etc
    ~Cube();//destructor 
    
    //movements 
    //not that p refers to 'prime', so the inverse of normal moves. therefore rp is 'r prime'
    //turns
    void rTurn();
    void rpTurn();
    
    void uTurn();
    void upTurn();
    
    void lTurn();
    void lpTurn();
    
    void bTurn();
    void bpTurn();
    
    void fTurn();
    void fpTurn();
    
    void dTurn();
    void dpTurn();
    
    //rotations
    void xRotation(); //along R
    void xpRotation();
    void yRotation(); //along U
    void ypRotation();
    
    
    
    //utility functions
    string generateScramble(); //generate random scramble and prints it to to user as well
    void printC(); //prints cube(specifically the color)
    
    void doSeq(string name);
    
    
    
    void Solve(); //solves the cube, prints movements, CFOP method only 
    //will print each stage
            //Cross (Done with white)
            //F2L (beginners or advanced)?
            //OLL (2look)
            //PLL (2look + additional 
    
    
    
    
    
    
    
    
};


