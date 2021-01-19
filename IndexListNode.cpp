//
//  IndexListNode.cpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 2021-01-08.
//  Copyright © 2021 Rudaina Khalil. All rights reserved.
//

#include "IndexListNode.h"

FindexN::FindexN(){
    faceID = 0;
    next = nullptr;
    
    
    
    
    
    
}


FindexN::FindexN(int faceID, FindexN* nextPtr){
    
    
    
}

FindexN& FindexN::operator=(FindexN* rhs){
    faceID = rhs->faceID;
    next = rhs->next;
    
    
    
    return (*this);
}

