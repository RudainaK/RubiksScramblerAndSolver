//
//  Algorithms.hpp
//  RubiksScramblerAndSolver
//
//  Created by Rudaina Khalil on 2021-01-06.
//  Copyright © 2021 Rudaina Khalil. All rights reserved.
//

#pragma once

//OLL algs
    
//edges
//NOTE, DEFINE LOWERCASE f 
static string dotOLL = "F R U R' U' F' f R U R' U' f'";
static string iOLL = "F R U R' U' F'";
static string lOLL = "f R U R' U' f'";

//corner
static string AntiSune = "R U2 R' U' R U' R'";
static string HOLL = "R U R' U R U' R' U R U2 R'";
//NOTE, DEFINE LOWERCASE r
static string LCOLL = "F R' F' r U R U' r'"; //the L oll for corners
static string piOLL = "R U2 R2 U' R2 U' R2 U2 R";
static string Sune = "R U R' U R U2 R'";
//NOTE, DEFINE LOWERCASE r
static string TOLL = "r u R' U' r' F R F'";
static string UOLL = "R2 D R' U2 R D' R' U2 R'";



//PLL algs 

//corners
static string Yperm = "F R U' R' U' R U R' F' R U R' U' R' F R F'";
static string Tperm = "R U R' U' R' F R2 U' R' U' R U R' F'";

//edges
static string Hperm = "M2 U M2 U2 M2 U M2";
static string UAperm = "R U' R U R U R U' R' U' R2";
static string UBperm = "R2 U R U R' U' R' U' R' U R'";
static string Zperm = "M' U M2 U M2 U M' U2 M2";





#pragma once
