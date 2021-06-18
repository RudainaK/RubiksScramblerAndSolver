//
//  globals.h
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 12/25/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#pragma once

//specifically for a 3x3 cube, may be changed later 
#define totalStickers 54
#define faces 6
#define stickersPerFace 9
#define layersPerFace 3
#define stickersPerLayer 3


static char colors[faces] = {'W','G','R','B','O','Y'};
//top face white W
//starting from front facing face, CCW, Green G red R Blue B Orange O
//bottom face Yellow Y

static char orientation[faces] = {'U','F','R','B','L','D'};

static char evenLayerStickers[stickersPerLayer] = {'C','E','C'}; //so layer 0 and 2
static char oddLayerStickers[stickersPerLayer] = {'E','M','E'};  //layer 1

static int edgeCoords[4][2] = {{0,1},{1,0},{1,2},{2,1}};

//each face will be represented by 9 stickers with IDs in the following order

//123     layer0
//456     layer1
//789     layer2

//knowing how a cube behaves, the sticker with 5 never really moves, but corners 1379 and edges 2468 are free 
//to swap around 

