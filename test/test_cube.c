#include "unity.h"
#include "cube.h"
#include "customAssertion.h"

void setUp(void){}

void tearDown(void){}

void test_create_face(){
  int value[] = {0,0,0,0,0,0,0,0,0};
	Face *face = createFace(FRONT, value);
	TEST_ASSERT_EQUAL(FRONT, face->faceType);
	TEST_ASSERT_EQUAL(cW, face->faceValue[0]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[1]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[3]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[4]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[5]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[6]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[7]);
	TEST_ASSERT_EQUAL(cW, face->faceValue[8]);
}

void test_create_cube(){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  
	TEST_ASSERT_EQUAL(TOP, cube->topFace->faceType);
	TEST_ASSERT_EQUAL(LEFT, cube->leftFace->faceType);
	TEST_ASSERT_EQUAL(FRONT, cube->frontFace->faceType);
	TEST_ASSERT_EQUAL(RIGHT, cube->rightFace->faceType);
	TEST_ASSERT_EQUAL(BOTTOM, cube->bottomFace->faceType);
	TEST_ASSERT_EQUAL(BACK, cube->backFace->faceType);
  
  TEST_ASSERT_EQUAL(cW,cube->topFace->faceValue[0]);
  TEST_ASSERT_EQUAL(cR,cube->leftFace->faceValue[0]);
  TEST_ASSERT_EQUAL(cB,cube->frontFace->faceValue[0]);
  TEST_ASSERT_EQUAL(cO,cube->rightFace->faceValue[0]);
  TEST_ASSERT_EQUAL(cY,cube->bottomFace->faceValue[0]);
  TEST_ASSERT_EQUAL(cG,cube->backFace->faceValue[0]);
}

void test_display_face(void){
  int value[] = {2,2,2,2,2,2,2,2,2};
	Face *face = createFace(FRONT, value);
	displayFace(face);
}

/*  printing result:
 *        0 0 0
 *        0 0 0
 *        0 0 0
 *
 *1 1 1   2 2 2   3 3 3
 *1 1 1   2 2 2   3 3 3
 *1 1 1   2 2 2   3 3 3
 *
 *        4 4 4
 *        4 4 4
 *        4 4 4
 *
 *        5 5 5
 *        5 5 5
 *        5 5 5 
 *        
 */
void test_display_cube(){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  displayCube(cube);
}