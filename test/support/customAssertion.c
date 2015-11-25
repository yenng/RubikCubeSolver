#include "customAssertion.h"
#include "unity.h"
#include "Token.h"

void customTestAssertCube(Cube *expectedCube, Cube *actualCube, int lineNumber){
  int i = 0;
  while(i<9){
    if(expectedCube->topFace->faceValue[i] != actualCube->topFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "TopFace value[%d] Expected %d was %d", i, 
      expectedCube->topFace->faceValue[i], actualCube->topFace->faceValue[i]);
    }
    if(expectedCube->leftFace->faceValue[i] != actualCube->leftFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "LeftFace value[%d] Expected %d was %d", i, 
      expectedCube->leftFace->faceValue[i], actualCube->leftFace->faceValue[i]);
    }
    if(expectedCube->frontFace->faceValue[i] != actualCube->frontFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "FrontFace value[%d] Expected %d was %d", i, 
      expectedCube->frontFace->faceValue[i], actualCube->frontFace->faceValue[i]);
    }
    if(expectedCube->rightFace->faceValue[i] != actualCube->rightFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "RightFace value[%d] Expected %d was %d", i, 
      expectedCube->rightFace->faceValue[i], actualCube->rightFace->faceValue[i]);
    }
    if(expectedCube->bottomFace->faceValue[i] != actualCube->bottomFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "BottomFace value[%d] Expected %d was %d", i, 
      expectedCube->bottomFace->faceValue[i], actualCube->bottomFace->faceValue[i]);
    }
    if(expectedCube->backFace->faceValue[i] != actualCube->backFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "BackFace value[%d] Expected %d was %d", i, 
      expectedCube->backFace->faceValue[i], actualCube->backFace->faceValue[i]);
    }
  }
}

void customTestAssertFace(Face *expectedFace, Face *actualFace, int lineNumber){
  int i = 0;
  while(i<9){
    if(expectedFace->faceValue[i] != actualFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "Face value[%d] Expected %d was %d", i, 
      expectedFace->faceValue[i], actualFace->faceValue[i]);
    }
  }
}