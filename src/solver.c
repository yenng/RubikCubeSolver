#include "solver.h"
#include "rotation.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

/***************Side Corner formula****************/
int FSRCFormula1[8] = {U,R,Ui,Ri,Ui,Fi,U,F};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Front face.
int FSRCFormula2[8] = {Ui,Fi,U,F,U,R,Ui,Ri};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Right face.
int LSRCFormula1[8] = {U,F,Ui,Fi,Ui,Li,U,L};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Left face.
int LSRCFormula2[8] = {Ui,Li,U,L,U,F,Ui,Fi};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Front face.
int BSRCFormula1[8] = {U,L,Ui,Li,Ui,Bi,U,B};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Back face.
int BSRCFormula2[8] = {Ui,Bi,U,B,U,L,Ui,Li};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Left face.
int RSRCFormula1[8] = {U,B,Ui,Bi,Ui,Ri,U,R};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Right face.
int RSRCFormula2[8] = {Ui,Ri,U,R,U,B,Ui,Bi};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Back face.

int *formulaPtr[] = {FSRCFormula1,FSRCFormula2,LSRCFormula1,LSRCFormula2,BSRCFormula1,BSRCFormula2,RSRCFormula1,RSRCFormula2};

/***************Side Corner rotation before getting formula***************************************/
int formulaRW[1] = {U};
int formulaBW[1] = {U};
int formulaOW[1] = {U};
int formulaGW[1] = {U};

int formulaBR[9] = {U,U,F,Ui,Fi,Ui,Li,U,L};        //FrontValue[1] is RED and UpValue[7] is BLUE
int formulaGR[9] = {U,Ui,Bi,U,B,U,L,Ui,Li};        //FrontValue[1] is RED and UpValue[7] is GREEN

int formulaRB[8] = {Ui,Li,U,L,U,F,Ui,Fi};          //FrontValue[1] is BLUE and UpValue[7] is RED
int formulaOB[8] = {U,R,Ui,Ri,Ui,Fi,U,F};          //FrontValue[1] is BLUE and UpValue[7] is ORANGE

int formulaBO[9] = {Ui,Ui,Fi,U,F,U,R,Ui,Ri};       //FrontValue[1] is ORANGE and UpValue[7] is BLUE
int formulaGO[9] = {Ui,U,B,Ui,Bi,Ui,Ri,U,R};       //FrontValue[1] is ORANGE and UpValue[7] is GREEN

int formulaRG[10] = {U,U,U,L,Ui,Li,Ui,Bi,U,B};      //FrontValue[1] is GREEN and UpValue[7] is RED
int formulaOG[10] = {U,U,Ui,Ri,U,R,U,B,Ui,Bi};      //FrontValue[1] is GREEN and UpValue[7] is ORANGE

int *formulaWPtr[6] = {NULL,formulaRW,formulaBW,formulaOW,NULL,formulaGW};
int *formulaRPtr[6] = {NULL,NULL,formulaBR,NULL,NULL,formulaGR};
int *formulaBPtr[6] = {NULL,formulaRB,NULL,formulaOB,NULL,NULL};
int *formulaOPtr[6] = {NULL,NULL,formulaBO,NULL,NULL,formulaGO};
int *formulaGPtr[6] = {NULL,formulaRG,NULL,formulaOG,NULL,NULL};

int **formulaPtrPtr[6] = {formulaWPtr,formulaRPtr,formulaBPtr,formulaOPtr,NULL,formulaGPtr};

void baseSolver(Cube *cube){
  
}

void sideCornerSolver(Cube *cube){
  int **ptrToPtr = formulaPtrPtr[cube->frontFace->faceValue[1]];
  int *formula = ptrToPtr[cube->upFace->faceValue[7]];
  int i = 0;
  while(i<(10)){
    // printf("%d %d\n", formula[i],(sizeof(formula)/4));
    fullRotation(cube,formula[i]);
    i++;
  }
  // while(cube->frontFace->faceValue[3] != 2 && cube->frontFace->faceValue[5] != 2 
    // &&  cube->rightFace->faceValue[3] != 3 && cube->rightFace->faceValue[5] != 2 
    // &&  cube->backFace->faceValue[3] != 5  && cube->backFace->faceValue[5] != 5 
    // &&  cube->leftFace->faceValue[3] != 1  && cube->leftFace->faceValue[5] != 1 ){
     
    // }  
}


void sideCornerSolver1(Cube *cube){
  //declare side corner of the up face.
  int sideConer0[2] = {cube->upFace->faceValue[5],cube->rightFace->faceValue[1]};
  int sideConer1[2] = {cube->upFace->faceValue[1],cube->backFace->faceValue[7]};
  int sideConer2[2] = {cube->upFace->faceValue[3],cube->leftFace->faceValue[1]};
  int sideConer3[2] = {cube->upFace->faceValue[7],cube->frontFace->faceValue[1]};
  
  int *sideCornerPtr[4] = {sideConer0,sideConer1,sideConer2,sideConer3};
  
  int *ptrToSide;
  int *ptrToFormula;
  int i = 0;
  int j = 0;
  
  while(j<4){
    ptrToSide = sideCornerPtr[j];
    int turnCount = j;
    if(ptrToSide[0]==cB&&ptrToSide[1]==cO){
      while(turnCount > 0){
        fullRotation(cube,U);
        turnCount --;
      }
      ptrToFormula = formulaPtr[1];
    }
    else if(ptrToSide[1]==cB&&ptrToSide[0]==cO){
      while(turnCount+1 > 0){
        fullRotation(cube,U);
        turnCount --;
      }
      ptrToFormula = formulaPtr[0];
    }
    j++;
  }
  while(i<8){
    fullRotation(cube,ptrToFormula[i]);
    i++;
  }
}