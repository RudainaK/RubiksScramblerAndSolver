//
//  Cube.cpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#include "Cube.h"
#include "Algorithms.h"
#include <stdlib.h>
#include <time.h>
#include "IndexListNode.h"

/*
    char orientation[faces] = {'U','F','R','B','L','D'};
 char colors[faces] = {'W','G','R','B','O','Y'};
 order of faces: 0 1 2 3 4 5 
 implies: 
 U = 0
 F = 1 
 R = 2
 B = 3
 L = 4
 D = 5
 face(char c, char p);
    */


//making a circular linked list





Cube::Cube(){
    for (int i =0; i<faces ; i++){
        cube3[i] = new face(colors[i],orientation[i]);
    }
    
}

Cube::~Cube(){
    
    for (int i =0; i<faces ; i++){
        delete cube3[i];
        cube3[i] = nullptr;
    }
    
}


void Cube::rTurn(){
    //r turn will affect the rightmost column of the F U B and D layers 
    
    //start with making a temp array to hold the D layer column 
    sticker D[3]; //basically a temp variable
    for(int i = 0; i < stickersPerLayer ; i++){ //holds the D layer column 1
        D[i] = *(cube3[5]->f[i][2]);//holds the D layer column 1
    }
    sticker test;
    test = D[1];
    //the shift 
    for(int i = 0; i <stickersPerLayer; i++){ //D = B
        *(cube3[5]->f[i][2]) = *(cube3[3]->f[2-i][0]);
        //so the 3rd col of the U and D face are connected the first col of the back face 
    }
    
    for(int i = 0; i <stickersPerLayer; i++){ //B = U
          *(cube3[3]->f[i][0]) = *(cube3[0]->f[2-i][2]); //the back face is flipped 
        //so the 3rd col of the U and D face are connected the first col of the back face 
    }
    
    for(int i = 0; i <stickersPerLayer; i++){ //U = F
          *(cube3[0]->f[i][2]) = *(cube3[1]->f[i][2]);
    }

    //temp variable 
    for(int i = 0; i <stickersPerLayer; i++){ //F = temp variable
          *(cube3[1]->f[i][2]) = D[i];
    }
    
    //also note that this rotates the R face
    sticker tempR[8];
    /*
     
     [1][2][3]
     [4][5][6]
     [7][8][9] //the order of the stickers in a face, so im rotating stickers 12369874 clockwise
     
     
     [7][4][1]
     [8][5][2]
     [9][6][3]

     */
    
    //not elegent but here it goes,copying the stickers in order 12369874:
    for(int i = 0; i < 3; i++){
        tempR[i] = *(cube3[2]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 
    tempR[3] = *(cube3[2]->f[1][2]);
    tempR[4] = *(cube3[2]->f[2][2]);
    tempR[5] = *(cube3[2]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempR[i] = *(cube3[2]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[2]->f[i][2]) = tempR[i];
    }
    *(cube3[2]->f[2][1]) = tempR[3];
    *(cube3[2]->f[0][1]) = tempR[7];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[2]->f[i][0]) = tempR[6-i];
    }
}


void Cube::lTurn(){
    //the lturn impacts the leftmost cols of the F U B and D layers, but is also in the opposite direction of rTurn
    sticker D[3]; //basically a temp variable
       for(int i = 0; i < stickersPerLayer ; i++){ //holds the D layer column 1
           D[i] = *(cube3[5]->f[i][0]);//holds the D layer column 1
       }
       sticker test;
       test = D[1];
       //the shift 
       for(int i = 0; i <stickersPerLayer; i++){ //D = F
           *(cube3[5]->f[i][0]) = *(cube3[1]->f[i][0]);
           //so the 3rd col of the U and D face are connected the first col of the back face 
       }
       
       for(int i = 0; i <stickersPerLayer; i++){ //F = U
             *(cube3[1]->f[i][0]) = *(cube3[0]->f[i][0]); //the back face is flipped 
           //so the srd col of the U and D face are connected the third col of the back face 
       }
       
       for(int i = 0; i <stickersPerLayer; i++){ //U = B
             *(cube3[0]->f[i][0]) = *(cube3[3]->f[2-i][2]);
       }

       //temp variable 
       for(int i = 0; i <stickersPerLayer; i++){ //B = temp variable
             *(cube3[3]->f[2-i][2]) = D[i];
       }
    
    sticker tempL[8];
    /*
    
    [1][2][3]
    [4][5][6]
    [7][8][9] //the order of the stickers in a face, so im rotating stickers 12369874 clockwise
    
    
    [7][4][1]
    [8][5][2]
    [9][6][3]

    */
    for(int i = 0; i < 3; i++){
        tempL[i] = *(cube3[4]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 
    tempL[3] = *(cube3[4]->f[1][2]);
    tempL[4] = *(cube3[4]->f[2][2]);
    tempL[5] = *(cube3[4]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempL[i] = *(cube3[4]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[4]->f[i][2]) = tempL[i];
    }
    *(cube3[4]->f[2][1]) = tempL[3];
    *(cube3[4]->f[0][1]) = tempL[7];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[4]->f[i][0]) = tempL[6-i];
    }
    
}

void Cube::uTurn(){
    //the u turn impacts the FLBR facees
    sticker F[3]; //basically a temp variable
    for(int i = 0; i < stickersPerLayer ; i++){ //holds the D layer column 1
        F[i] = *(cube3[1]->f[0][i]);//holds the F layer row 1
    }
    for(int i = 0; i <stickersPerLayer; i++){ //F = R
          *(cube3[1]->f[0][i]) = *(cube3[2]->f[0][i]);
    }
    for(int i = 0; i <stickersPerLayer; i++){ //R=B
          *(cube3[2]->f[0][i]) = *(cube3[3]->f[0][i]); 
    }
    for(int i = 0; i <stickersPerLayer; i++){ //B=L
          *(cube3[3]->f[0][i]) = *(cube3[4]->f[0][i]);
    }
    for(int i = 0; i <stickersPerLayer; i++){ //L=F
          *(cube3[4]->f[0][i]) = F[i];
    }
   
    
     sticker tempU[8];
    
    for(int i = 0; i < 3; i++){
        tempU[i] = *(cube3[0]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 ]
   //   []
   // [][]
    tempU[3] = *(cube3[0]->f[1][2]);
    tempU[4] = *(cube3[0]->f[2][2]);
    tempU[5] = *(cube3[0]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempU[i] = *(cube3[0]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[0]->f[i][2]) = tempU[i];
    }
    *(cube3[0]->f[0][1]) = tempU[7];
    *(cube3[0]->f[2][1]) = tempU[3];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[0]->f[i][0]) = tempU[6-i];
    }
    
}

void Cube::dTurn(){
    sticker F[3]; //basically a temp variable
     for(int i = 0; i < stickersPerLayer ; i++){ //holds the D layer column 1
         F[i] = *(cube3[1]->f[2][i]);//holds F layer row 3
     }
     for(int i = 0; i <stickersPerLayer; i++){ //F = L
           *(cube3[1]->f[2][i]) = *(cube3[4]->f[2][i]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //L=B
           *(cube3[4]->f[2][i]) = *(cube3[3]->f[2][i]); 
     }
     for(int i = 0; i <stickersPerLayer; i++){ //B=R
           *(cube3[3]->f[2][i]) = *(cube3[2]->f[2][i]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //R = F
           *(cube3[2]->f[2][i]) = F[i];
     }
    
     
    sticker tempD[8];
     
     for(int i = 0; i < 3; i++){
         tempD[i] = *(cube3[5]->f[0][i]); //gets stickers 1 2 3
     }
     
     //gets stickers 6 9 8 
     tempD[3] = *(cube3[5]->f[1][2]);
     tempD[4] = *(cube3[5]->f[2][2]);
     tempD[5] = *(cube3[5]->f[2][1]);
     
     for(int i = 6; i < 8; i++){
         tempD[i] = *(cube3[5]->f[8-i][0]); //gets stickers 7 4
     }
     
     //reording the face
     for(int i = 0; i <stickersPerLayer; i++){ 
           *(cube3[5]->f[i][2]) = tempD[i];
     }
     *(cube3[5]->f[2][1]) = tempD[3];
     *(cube3[5]->f[0][1]) = tempD[7];
     for(int i = 0; i <layersPerFace; i++){ 
           *(cube3[5]->f[i][0]) = tempD[6-i];
     }

    
}


void Cube::fTurn(){
    sticker U[3]; //basically a temp variable
     for(int i = 0; i < stickersPerLayer ; i++){ //holds the U layer row 3
         U[i] = *(cube3[0]->f[2][i]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //U = L
           *(cube3[0]->f[2][i]) = *(cube3[4]->f[2-i][2]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //L=D
           *(cube3[4]->f[i][2]) = *(cube3[5]->f[0][i]); 
     }
     for(int i = 0; i <stickersPerLayer; i++){ //D=R
           *(cube3[5]->f[0][2-i]) = *(cube3[2]->f[i][0]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //R=U
           *(cube3[2]->f[i][0]) = U[i];
     }
    
     
      sticker tempF[8];
     
     for(int i = 0; i < 3; i++){
         tempF[i] = *(cube3[1]->f[0][i]); //gets stickers 1 2 3
     }
     
     //gets stickers 6 9 8 
     tempF[3] = *(cube3[1]->f[1][2]);
     tempF[4] = *(cube3[1]->f[2][2]);
     tempF[5] = *(cube3[1]->f[2][1]);
     
     for(int i = 6; i < 8; i++){
         tempF[i] = *(cube3[1]->f[8-i][0]); //gets stickers 7 4
     }
     
     //reording the face
     for(int i = 0; i <stickersPerLayer; i++){ 
           *(cube3[1]->f[i][2]) = tempF[i];
     }
     *(cube3[1]->f[2][1]) = tempF[3];
     *(cube3[1]->f[0][1]) = tempF[7];
     for(int i = 0; i <layersPerFace; i++){ 
           *(cube3[1]->f[i][0]) = tempF[6-i];
     }
    
    
}


void Cube::bTurn(){

    sticker U[3]; //basically a temp variable
     for(int i = 0; i < stickersPerLayer ; i++){ //holds the U layer row 1
         U[i] = *(cube3[0]->f[0][i]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //U = R
           *(cube3[0]->f[0][i]) = *(cube3[2]->f[i][2]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //R=D
           *(cube3[2]->f[2-i][2]) = *(cube3[5]->f[2][i]); 
     }
     for(int i = 0; i <stickersPerLayer; i++){ //D=L
           *(cube3[5]->f[2][i]) = *(cube3[4]->f[i][0]);
     }
     for(int i = 0; i <stickersPerLayer; i++){ //L=U
           *(cube3[4]->f[i][0]) = U[2-i];
     }
    
     
    sticker tempB[8];
     
     for(int i = 0; i < 3; i++){
         tempB[i] = *(cube3[3]->f[0][i]); //gets stickers 1 2 3
     }
     
     //gets stickers 6 9 8 
     tempB[3] = *(cube3[3]->f[1][2]);
     tempB[4] = *(cube3[3]->f[2][2]);
     tempB[5] = *(cube3[3]->f[2][1]);
     
     for(int i = 6; i < 8; i++){
         tempB[i] = *(cube3[3]->f[8-i][0]); //gets stickers 7 4
     }
     
     //reording the face
     for(int i = 0; i <stickersPerLayer; i++){ 
           *(cube3[3]->f[i][2]) = tempB[i];
     }
     *(cube3[3]->f[2][1]) = tempB[3];
     *(cube3[3]->f[0][1]) = tempB[7];
     for(int i = 0; i <layersPerFace; i++){ 
           *(cube3[3]->f[i][0]) = tempB[6-i];
     }
    
}

//prime turns are equivelant to 3 normal turns, its a bit slower but shouldn't be by too much
//if anything, this might be expanded later
void Cube::rpTurn(){
    rTurn();
    rTurn();
    rTurn();
}
void Cube::lpTurn(){
    lTurn();
    lTurn();
    lTurn();
}
void Cube::upTurn(){
    uTurn();
    uTurn();
    uTurn();
}
void Cube::dpTurn(){
    dTurn();
    dTurn();
    dTurn();
}
void Cube::fpTurn(){
    fTurn();
    fTurn();
    fTurn();
}
void Cube::bpTurn(){
    bTurn();
    bTurn();
    bTurn();
}

void Cube::xRotation(){ //affects faces U F D and B
    face TempFace;
    TempFace = *(cube3[0]); //temporarily holds U 
    *(cube3[0]) = *(cube3[1]); //U = F
    *(cube3[1]) = *(cube3[5]); //F = D 
    
    
    //D = B is flipped
    for(int i = 0; i<layersPerFace;i++){
        for(int j = 0; j < stickersPerLayer;j++){
            *(cube3[5]->f[i][j]) = *(cube3[3]->f[2-i][2-j]); 
        }
    }
    
    //B = U(now held by temp variable
    for(int i = 0; i<layersPerFace;i++){
        for(int j = 0; j < stickersPerLayer;j++){
            *(cube3[3]->f[i][j]) = *(TempFace.f[2-i][2-j]); 
        }
    }
    
    
    sticker tempR[8];
    for(int i = 0; i < 3; i++){
        tempR[i] = *(cube3[2]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 
    tempR[3] = *(cube3[2]->f[1][2]);
    tempR[4] = *(cube3[2]->f[2][2]);
    tempR[5] = *(cube3[2]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempR[i] = *(cube3[2]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[2]->f[i][2]) = tempR[i];
    }
    *(cube3[2]->f[2][1]) = tempR[3];
    *(cube3[2]->f[0][1]) = tempR[7];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[2]->f[i][0]) = tempR[6-i];
    }
    
    
    sticker tempL[8];
    for(int i = 0; i < 3; i++){
        tempL[i] = *(cube3[4]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 
    tempL[3] = *(cube3[4]->f[1][2]);
    tempL[4] = *(cube3[4]->f[2][2]);
    tempL[5] = *(cube3[4]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempL[i] = *(cube3[4]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[4]->f[2-i][0]) = tempL[i];
    }
    *(cube3[4]->f[2][1]) = tempL[7];
    *(cube3[4]->f[0][1]) = tempL[3];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[4]->f[2-i][2]) = tempL[6-i];
    }
    
}

void Cube::xpRotation(){
    xRotation();
    xRotation();
    xRotation();
}

void Cube::yRotation(){
    
    //yrotation impacts F R B L faces 
    
    face TempFace;
    TempFace = *(cube3[4]); //temporarily holds L face 
    *(cube3[4]) = *(cube3[1]); //L = F
    *(cube3[1]) = *(cube3[2]); //F = R
    *(cube3[2]) = *(cube3[3]); //R = B
    
    for(int i = 0; i<layersPerFace;i++){
        for(int j = 0; j < stickersPerLayer;j++){
            *(cube3[3]->f[i][j]) = *(TempFace.f[i][j]); 
        }
    }
    
   
    sticker tempU[8];
    
    for(int i = 0; i < 3; i++){
        tempU[i] = *(cube3[0]->f[0][i]); //gets stickers 1 2 3
    }
    
    
    tempU[3] = *(cube3[0]->f[1][2]);
    tempU[4] = *(cube3[0]->f[2][2]);
    tempU[5] = *(cube3[0]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempU[i] = *(cube3[0]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[0]->f[i][2]) = tempU[i];
    }
    *(cube3[0]->f[0][1]) = tempU[7];
    *(cube3[0]->f[2][1]) = tempU[3];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[0]->f[i][0]) = tempU[6-i];
    }
    
    
    sticker tempD[8];
    
    for(int i = 0; i < 3; i++){
        tempD[i] = *(cube3[5]->f[0][i]); //gets stickers 1 2 3
    }
    
    //gets stickers 6 9 8 
    tempD[3] = *(cube3[5]->f[1][2]);
    tempD[4] = *(cube3[5]->f[2][2]);
    tempD[5] = *(cube3[5]->f[2][1]);
    
    for(int i = 6; i < 8; i++){
        tempD[i] = *(cube3[5]->f[8-i][0]); //gets stickers 7 4
    }
    
    //reording the face
    for(int i = 0; i <stickersPerLayer; i++){ 
          *(cube3[5]->f[2-i][0]) = tempD[i];
    }
    *(cube3[5]->f[2][1]) = tempD[7];
    *(cube3[5]->f[0][1]) = tempD[3];
    for(int i = 0; i <layersPerFace; i++){ 
          *(cube3[5]->f[2-i][2]) = tempD[6-i];
    }
    
    
}


void Cube::ypRotation(){
    yRotation();
    yRotation();
    yRotation();
}


string Cube::generateScramble(){
    string turn[6] = {"R", "L", "U", "D", "F", "B"};
    string type[3] = {"","2","'"};
    srand(time(NULL)); //random seed
    string scramble = "";
    
    int prevT = 0; //holds previous move 
    int prevt = 0;
    
    
    for(int i = 0; i < 20; i++){ //20 turns
        int indexT = rand() % 6; //from 0 to 5
        int indext = rand() % 3; //from 0 to 2
        
        //a few conditions need to be met 
            //no two moves can be repeteated 
                //ie F F or F' F' is not valid becuse that should be F2 (case 1)
                //or F2 F2 because that just undoes the first F2 (case 2) 
            //no prime can follow an original 
                //ie F F' or F' F just undoes previous move (case 3)
                //something like F F2 is also just F', so it's uneccesary 
        
        if(i >= 1){//the second move and above, no need to check previous move of first 
            if(indexT == prevT && indext == prevt){ //case1 and case2
                //nothing added to scramble, 
                i--; //decrement i by one, so when it increments, it's in the same place as previously 
            } else if ((indexT == prevT && ((indext == 0 && prevt == 2) || (indext == 2 && prevt == 0))) || (indexT == prevT && ((indext == 0 && prevt == 1) || (indext == 1 && prevt == 0)))){ //case3
                //nothing added to scramble
                i--;
            } else {
                //add to scramble
                scramble = scramble + turn[indexT] + type[indext] + " ";
                prevT = indexT;
                prevt = indext;
                
            }
            
        } else { //just for the first 
            scramble = scramble + turn[indexT] + type[indext] + " ";
            prevT = indexT;
            prevt = indext;
        }
            
        
    } //end of loop 
    
    
    
    cout << "Scramble generated: " << scramble << endl;
    return scramble; //return this, will be passed to the doSeq function
}





void Cube::doSeq(string sequence){
    //NOTE THAT SEQUENCE NEEDS TO HAVE SPACES BETWEEN MOVES, SO R F2 L NOT RF2L
    int len = 0;
    for(int i = 0; sequence[i] != '\0';i++){ //this is to avoid any conversion issues
        len++;
    }
    //len is the size without the null terminator
    
    string move = "";
    string next = "";
    string special = ""; //the special move, like ' for prime or 2 for double
    int incrementor = 1;
    for(int i = 0; i<len;i+=incrementor){
        if (sequence==""){
            break;//do nothing 
        }
        move = sequence[i]; //first character should always be a letter, not one of the special characters
        next = sequence[i+1]; //double check indexing issues
        if(next == "'" || next == "2"){
            move = move + next;
            special = next;
            incrementor = 3; //needs to skip over space 
        } else {
            //in this case, no special character, needs, to incrememnt by 2 to to get to next character 
            special = next; //to make sure it doesnt hold previous value 
            incrementor = 2;
        }
        //at this point, we have the move itself, and the special character
        if(move[0] == 'R'){ //check turns
            if(special == "'"){ //prime
                rpTurn();
            } else if (special == "2"){ //double
                rTurn();
                rTurn();
            } else { //normal
                rTurn();
            }
            //cout << endl;
            //printC();
        } else if(move[0] == 'L'){
            if(special == "'"){ //prime
                lpTurn();
            } else if (special == "2"){ //double
                lTurn();
                lTurn();
            } else { //normal
                lTurn();
            }
           // cout << endl;
          //  printC();
        } else if(move[0] == 'U'){
            if(special == "'"){ //prime
                upTurn();
            } else if (special == "2"){ //double
                uTurn();
                uTurn();
            } else { //normal
                uTurn();
            }
           // cout << endl;
          //  printC();
        } else if(move[0] == 'D'){
            if(special == "'"){ //prime
                dpTurn();
            } else if (special == "2"){ //double
                dTurn();
                dTurn();
            } else { //normal
                dTurn();
            }
          //  cout << endl;
         //   printC();
        } else if(move[0] == 'F'){
            if(special == "'"){ //prime
                fpTurn();
            } else if (special == "2"){ //double
                fTurn();
                fTurn();
            } else { //normal
                fTurn();
            }
          //  cout << endl;
          //  printC();
        } else if(move[0] == 'B'){
            if(special == "'"){ //prime
                bpTurn();
            } else if (special == "2"){ //double
                bTurn();
                bTurn();
            } else { //normal
                bTurn();
            }
           // cout << endl;
           // printC();
        } else if(move[0] == 'X'){ //check rotations
            if(special == "'"){ //prime
                xpRotation();
            } else if (special == "2"){ //double
                xRotation();
                xRotation();
            } else { //normal
                xRotation();
            }
            
        } else if(move[0] == 'Y'){
            if(special == "'"){ //prime
                ypRotation();
            } else if (special == "2"){ //double
                yRotation();
                yRotation();
            } else { //normal
                yRotation();
            }
            
        }
        
        
        
    }
    
    
    

}



void Cube::printC(){
    
/*
 [FacePosition,correspoding number]
     [U,0]
[L,4][F,1][R,2][B,3]
     [D,5]
 
 */
    
//prints top face 
    for(int i = 0; i < layersPerFace; i++){
        cout << "    ";
        for(int j = 0; j <stickersPerLayer; j++){
            cout << cube3[0]->f[i][j]->color;
        }
        cout << endl;
        
    }

    
    
//prints L F R B ( 4 1 2 3)

    for(int i = 0; i < layersPerFace; i++){
        for(int j = 0; j <stickersPerLayer; j++){
            cout << cube3[4]->f[i][j]->color;
        }
        cout << " ";
        for(int face = 1; face < 4; face++){
            for(int j = 0; j <stickersPerLayer; j++){
                cout << cube3[face]->f[i][j]->color;
            }
            cout << " ";
        }
        cout << endl;
        
    }

    
    
//prints bottom face
    for(int i = 0; i < layersPerFace; i++){
        cout << "    ";
        for(int j = 0; j <stickersPerLayer; j++){
            cout << cube3[5]->f[i][j]->color;
        }
        cout << endl;
        
    }
    
    
}



void Cube::Solve(){
    //Cross
    cout << "White cross: " << endl;
    //the white cross is typically done with white as the D Face, so 2 xRotations, which is X2
    doSeq("X2");
    cout << "X2 ";
    
    //this is for incrementing
    FindexN f1;
    FindexN f2;
    FindexN f3;
    FindexN f4;
    
    f1.faceID = 1;
    f2.faceID = 2;    
    f3.faceID = 3;
    f4.faceID = 4;
    
    f1.next = &f2;
    f2.next = &f3;
    f3.next = &f4;
    f4.next = &f1; //circular linked list
    
    
    

    
    //this means that the top center is now yellow, and the F center is blue 
    //need to align white edges with their respective center 
    //check top face first, only 4 checks and so nested 4 loops feels too extra 
    //THE BEST AND MOST BASIC CASE
    
    //there are 4 possible positions, that means with the turning, this should need to be checked a minimum of 4 times i think
    for(int i = 1; i <= 4; i++){//for each face
        //check for white on top face
        char color = cube3[i]->f[(edgeCoords[i-1][0])][(edgeCoords[i-1][1])]->color; //top middle of each face
        char face = cube3[i]->f[0][1]->position; 
        string move = "";
        int index = 0;
        FindexN temp;
        temp = f1;
        
        
        
        
        
        
        
        for(int j = 1; j < 4; j++){ //the face that matches the color 
            if(color == cube3[j]->f[1][1]->color){//same face
                
            } else if(0){
                
            }//add more else statements 
            
            temp.faceID =(temp.next)->faceID; //modify this with linked list FindeX
            temp.next = temp.next->next;
            //at this point, temp should be equal to the next node
            
            int a = 0;
        }
    }
    
    
    
}


