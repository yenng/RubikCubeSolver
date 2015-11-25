#include "unity.h"
#include "cube.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_create_face(){
  int value[] = {0,0,0,0,0,0,0,0,0};
	Face *face = createFace(FRONT, value);
	TEST_ASSERT_EQUAL(FRONT, face->faceType);
	TEST_ASSERT_EQUAL(W, face->faceValue[0]);
	TEST_ASSERT_EQUAL(W, face->faceValue[1]);
	TEST_ASSERT_EQUAL(W, face->faceValue[3]);
	TEST_ASSERT_EQUAL(W, face->faceValue[4]);
	TEST_ASSERT_EQUAL(W, face->faceValue[5]);
	TEST_ASSERT_EQUAL(W, face->faceValue[6]);
	TEST_ASSERT_EQUAL(W, face->faceValue[7]);
	TEST_ASSERT_EQUAL(W, face->faceValue[8]);
}

void test_create_cube(){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
}

void test_display_face(void){
  int value[] = {2,2,2,2,2,2,2,2,2};
	Face *face = createFace(FRONT, value);
	displayFace(face);
}
