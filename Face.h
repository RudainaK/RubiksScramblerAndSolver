//
//  Face.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#pragma once

#include "Sticker.h"

class face {
    public:
    sticker* center; //a pointer to the sticker in the center, not sure if will be used, but here just in case
    char color; //of the center
    char pos; //U F R etc
    sticker* f[layersPerFace][stickersPerLayer]; //array[row][col] (note its an array of pointers)
    
    
    face(char c, char p);
    face(); //add default constructor later 
    ~face();
    void printC();
    void printID();
    void printPos(); 
    
    face & operator=(face & rhs);
    
    
};
