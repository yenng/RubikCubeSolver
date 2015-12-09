#include "customAssertion.h"
#include "unity.h"
#include "cube.h"

void customTestAssertCube(Cube *expectedCube, Cube *actualCube, int lineNumber){
  int i = 0;
  while(i<9){
    if(expectedCube->upFace->faceValue[i] != actualCube->upFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "UpFace value[%d] Expected %d was %d", i, 
      expectedCube->upFace->faceValue[i], actualCube->upFace->faceValue[i]);
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
    if(expectedCube->downFace->faceValue[i] != actualCube->downFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "DownFace value[%d] Expected %d was %d", i, 
      expectedCube->downFace->faceValue[i], actualCube->downFace->faceValue[i]);
    }
    if(expectedCube->backFace->faceValue[i] != actualCube->backFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "BackFace value[%d] Expected %d was %d", i, 
      expectedCube->backFace->faceValue[i], actualCube->backFace->faceValue[i]);
    }
		i++;
  }
}

void customTestAssertFace(Face *expectedFace, Face *actualFace, int lineNumber){
  int i = 0;
  if(expectedFace->faceType != actualFace->faceType){
      CUSTOM_TEST_FAIL(lineNumber, "Face type Expected %d was %d", i, 
      expectedFace->faceType, actualFace->faceType);
  }
  while(i<9){
    if(expectedFace->faceValue[i] != actualFace->faceValue[i]){
      CUSTOM_TEST_FAIL(lineNumber, "Face value[%d] Expected %d was %d", i, 
      expectedFace->faceValue[i], actualFace->faceValue[i]);
    }
		i++;
  }
}