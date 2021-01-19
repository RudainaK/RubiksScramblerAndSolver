//
//  Sticker.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#ifndef Sticker_h
#define Sticker_h

#include <iostream>
using namespace std;
#include "globals.h"


class sticker{
    public: 
    char color;
    //white: W, green: G, blue: B, red: R, black: Z, orange: O, yellow: Y;
    char position;
    //center(Middle): M, corner: C, edge: E
    int ID; //essentially an ID of the each piece ON A FACE
    
    sticker(char c,char p, int id); //constructor 
    sticker(); //'default constructor'
    
    sticker operator= (sticker rhs);
    
};

#endif /* Sticker_h */
