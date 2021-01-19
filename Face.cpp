//
//  Face.cpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/24/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#include "Face.h"





//the constructors will generate 1 array of pointers to each layer in a face 
//the array will point to dynamically allocated layer objects, created with new



face::face(char c, char p){
    color = c;
    pos = p;
    
    
    //char evenLayerStickers[stickersPerLayer] = {'C','E','C'}; //so layer 0 and 2
   // char oddLayerStickers[stickersPerLayer] = {'E','M','E'};  //layer 1
    
    //sticker(char c,char p, int id);
    for(int i = 0; i < layersPerFace;i++){
        for(int j = 0; j < stickersPerLayer;j++){
            if(i!=1){ //layers 0 and 2
                f[i][j] = new sticker(c,evenLayerStickers[j],(3*i+1+j));
            } else { //layer 1
                f[i][j] = new sticker(c,oddLayerStickers[j],(3*i+1+j));
                if(j==1){ //(this will be when i and j are (1,1), which is the center sticker
                    center = f[i][j];
                }
            }
        }
    }
    
    
}

face::face(){
    
     
     
     //char evenLayerStickers[stickersPerLayer] = {'C','E','C'}; //so layer 0 and 2
    // char oddLayerStickers[stickersPerLayer] = {'E','M','E'};  //layer 1
     
     //sticker(char c,char p, int id);
     for(int i = 0; i < layersPerFace;i++){
         for(int j = 0; j < stickersPerLayer;j++){
             if(i!=1){ //layers 0 and 2
                 f[i][j] = new sticker('X',evenLayerStickers[j],(3*i+1+j));
             } else { //layer 1
                 f[i][j] = new sticker('X',oddLayerStickers[j],(3*i+1+j));
                 if(j==1){ //(this will be when i and j are (1,1), which is the center sticker
                     center = f[i][j];
                 }
             }
         }
     }
     
    
    
    
}

face::~face(){
    for(int i = 0; i < layersPerFace;i++){
        for(int j = 0; j < stickersPerLayer;j++){
            delete f[i][j];
            f[i][j] = nullptr;
        }
    }
    center = nullptr; //deleting center would cause a double deletion, so i just need to set it to nullptr
    
}

void face::printC(){
    for(int i = 0; i < layersPerFace; i++){
        for(int j = 0; j < stickersPerLayer; j++){
            cout << f[i][j]->color << " " << endl;
        }
    }
    
    
}

void face::printID(){
    for(int i = 0; i < layersPerFace; i++){
        for(int j = 0; j < stickersPerLayer; j++){
            cout << f[i][j]->ID << " " << endl;
        }
    }
    
    
}

void face::printPos(){
    for(int i = 0; i < layersPerFace; i++){
        for(int j = 0; j < stickersPerLayer; j++){
            cout << f[i][j]->position << " " << endl;
        }
    }
    
    
}

face & face::operator=(face & rhs){
    
    //to avoid double deletion, im doing a deep operator=, otherwise it'd be closer to a shallow copy 
    for(int i = 0; i < layersPerFace; i++){
        for(int j = 0; j < stickersPerLayer;j++){ //sticker(char c, char p,int id)
            f[i][j] = new sticker(rhs.f[i][j]->color,rhs.f[i][j]->position,(3*i+1+j));
        }
    }
    //the positions U F B are relative, so they shouldn't be changed, but the stickers of those faces are 
    center = rhs.center;
    color = rhs.color; //(color of the center) 
    
    return (*this);
}
