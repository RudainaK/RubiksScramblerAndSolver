//
//  IndexList.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 2021-01-13.
//  Copyright © 2021 Rudaina Khalil. All rights reserved.
//

#ifndef IndexList_hpp
#define IndexList_hpp

#include <iostream>
#include "IndexListNode.h"

class IndexList{
    public:
    FindexN* head;
    IndexList();
    ~IndexList();
    
    
    int getFaceIndex(int n); //n is the number of turns 
    
    
    
};

#endif /* IndexList_hpp */
