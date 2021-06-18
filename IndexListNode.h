//
//  IndexListClass.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 2021-01-08.
//  Copyright © 2021 Rudaina Khalil. All rights reserved.
//

#pragma once

#include <iostream>

class FindexN { 
    public: 
    int faceID;
    FindexN* next;
    
    FindexN();
    FindexN(int faceID, FindexN* nextPtr);
    
    FindexN& operator=(FindexN* rhs);
    
    //FindexN operator=(FindexN rhs);
    
};



