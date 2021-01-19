//
//  main.cpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#include <iostream>
#include "Cube.h"

int main(int argc, const char * argv[]) {
    // insert code here...
   // cout << "Hello, World!\n";
    Cube myCube;
    myCube.printC();
    cout << endl;
    
    
    string scramble = myCube.generateScramble();
    myCube.doSeq(scramble);
    cout << endl;
    myCube.printC();
    myCube.Solve();
    
    
    //myCube.lTurn();
    //myCube.printC();
   
    //Plan:
    //check user input: selfScramble(using generateScramble and doSeq) or user inputted scramble(pass to doSeq)
        //note that for user inputted scramble, sequence needs to be checked for valid input 
    
    //print out original cube 
    //do scramble
    //print scrambled cube 
    
    //use solve function 
        //solve function needs to print each step and what the cube looks like after a step 

    //restart and ask for user input until EOF detected
    
    

    

    return 0;
}
