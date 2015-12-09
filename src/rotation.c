#include "rotation.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

/********Face translationTable declaration.*************************/
int translationTable0[9] = {2,5,8,1,4,7,0,3,6};				//clockwise
int translationTable1[9] = {6,3,0,7,4,1,8,5,2};				//anti-clockwise

int *translationTable[2] = {translationTable0,translationTable1};

/********Face side translationTable declaration.*************************/
int sideTranslationTable0[12] = {9,10,11, 0,1,2,  3,4,5,    6,7,8};   //clockwise
int sideTranslationTable1[12] = {3,4,5,   6,7,8,  9,10,11,  0,1,2};   //anti-clockwise

int *sideTranslationTable[2] = {sideTranslationTable0,sideTranslationTable1};

/********Face side valueTable declaration.*************************/
int valueTableU[12] = {2,1,0,  6,7,8,  2,1,0,  2,1,0};
int valueTableL[12] = {0,3,6,  0,3,6,  0,3,6,  0,3,6};
int valueTableF[12] = {8,5,2,  6,7,8,  0,3,6,  2,1,0};
int valueTableR[12] = {8,5,2,  8,5,2,  8,5,2,  8,5,2};
int valueTableD[12] = {6,7,8,  6,7,8,  6,7,8,  2,1,0};
int valueTableB[12] = {8,5,2,  2,1,0,  0,3,6,  6,7,8};

int *ptrToTable[6] = {valueTableU,valueTableL,valueTableF,valueTableR,valueTableD,valueTableB};

Rotate *createRotation(Cube *cube, int rotation){
  Rotate *rotate = malloc(sizeof(Rotate));
  switch(rotation){
    case U: 
      rotate->face         = cube->upFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Ui: 
      rotate->face         = cube->upFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    case L: 
      rotate->face         = cube->leftFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Li: 
      rotate->face         = cube->leftFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    case F: 
      rotate->face         = cube->frontFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Fi: 
      rotate->face         = cube->frontFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    case R: 
      rotate->face         = cube->rightFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Ri: 
      rotate->face         = cube->rightFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    case D: 
      rotate->face         = cube->downFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Di: 
      rotate->face         = cube->downFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    case B: 
      rotate->face         = cube->backFace;
      rotate->direction    = CLOCKWISE;
      break;
    case Bi: 
      rotate->face         = cube->backFace;
      rotate->direction    = ANTICLOCKWISE;
      break;
    default:
      rotate->face         = cube->upFace;
      rotate->direction    = CLOCKWISE;
  }
  return rotate;
}

void faceRotation(int direction, Face *face){
	int faceValue_t[9];
	int i = 0;
	int *ptr = translationTable[direction];
  while (i < 9){
    faceValue_t[ptr[i]] = face->faceValue[i];
    i++;
  }
	i = 0;
	while (i < 9){
		face->faceValue[i] = faceValue_t[i];
		i++;
	}
}

void faceSideRotation(Cube *cube, Rotate *rotate){
  /**************************faceValue pointer declaration.*******************************************/ 
  int *ptrToValueU[4] = { cube->leftFace->faceValue,cube->backFace->faceValue,
                          cube->rightFace->faceValue,cube->frontFace->faceValue};
  int *ptrToValueL[4] = { cube->backFace->faceValue,cube->upFace->faceValue,
                          cube->frontFace->faceValue,cube->downFace->faceValue};
  int *ptrToValueF[4] = { cube->leftFace->faceValue,cube->upFace->faceValue,
                          cube->rightFace->faceValue,cube->downFace->faceValue};
  int *ptrToValueR[4] = { cube->frontFace->faceValue,cube->upFace->faceValue,
                          cube->backFace->faceValue,cube->downFace->faceValue};
  int *ptrToValueD[4] = { cube->leftFace->faceValue,cube->frontFace->faceValue,
                          cube->rightFace->faceValue,cube->backFace->faceValue};
  int *ptrToValueB[4] = { cube->rightFace->faceValue,cube->upFace->faceValue,
                          cube->leftFace->faceValue,cube->downFace->faceValue};

  int **ptrToPtrToValue[6] = {ptrToValueU,ptrToValueL,ptrToValueF,ptrToValueR,ptrToValueD,ptrToValueB};
  /************************declaration ended.**********************************************************/
  
  int sideValue_t[12], sideValue_t1[12];
  int i = 0; int j = 0;
  int **ptrPtrValue  = ptrToPtrToValue[rotate->face->faceType];
  int *ptrValue, *ptrTable;
  ptrTable = ptrToTable[rotate->face->faceType];
	int *translationPtr = sideTranslationTable[rotate->direction];
  while (i<12){
    ptrValue = ptrPtrValue[i/3];
    sideValue_t[i] = ptrValue[ptrTable[i]];
    i++;
  }
  
  i = 0;
  while (i < 12){
    sideValue_t1[i] = sideValue_t[translationPtr[i]];
    i++;
  }
  
  i = 0;
  while (i<12){
    ptrValue = ptrPtrValue[i/3];
    ptrValue[ptrTable[i]] = sideValue_t1[i];
    i++;
  }
}

void fullRotation(Cube *cube, Rotate *rotate){
  faceSideRotation(cube, rotate);
  faceRotation(rotate->direction, rotate->face);
}



