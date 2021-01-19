//
//  Sticker.cpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#include "Sticker.h"


sticker::sticker(char c, char p,int id){
    color = c;
    position = p;
    ID = id;
};


sticker::sticker(){
    color = 'X';
    position = 'X';
    ID = 0;
    
    
}

sticker sticker::operator= (sticker rhs){ //check this later 
    color = rhs.color;
    position = rhs.position;
    ID = rhs.ID;
    
    return (*this);
}
