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
int valueTableB[12] = {8,5,8,  2,1,0,  0,3,6,  6,7,8};

int *ptrToTableU[4] = {valueTableL,valueTableB,valueTableR,valueTableF};
int *ptrToTableL[4] = {valueTableB,valueTableU,valueTableF,valueTableD};
int *ptrToTableF[4] = {valueTableL,valueTableU,valueTableR,valueTableD};
int *ptrToTableR[4] = {valueTableF,valueTableU,valueTableB,valueTableD};
int *ptrToTableD[4] = {valueTableL,valueTableF,valueTableR,valueTableB};
int *ptrToTableB[4] = {valueTableR,valueTableU,valueTableL,valueTableD};

int **ptrToPtrToTable[6] = {ptrToTableU,ptrToTableL,ptrToTableF,ptrToTableR,ptrToTableD,ptrToTableB};

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

void faceSideRotation(int direction, Cube *cube, int rotation){
  int sideValue_t[12];
  int i = 0;
  // int *ptr  = 
  
}







