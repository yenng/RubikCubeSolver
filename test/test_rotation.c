#include "unity.h"
#include "rotation.h"
#include "cube.h"
#include "customAssertion.h"

void setUp(void){}

void tearDown(void){}

void test_face_rotation_clockwise(void){
  int value[] = {0,1,2,3,4,5,1,2,0};
  int value_actual[] = {1,3,0,2,4,1,0,5,2};
	int direction = CLOCKWISE;
	Face *face = createFace(FRONT, value);
	Face *face_actual = createFace(FRONT, value_actual);
	faceRotation(direction, face);
	
	TEST_ASSERT_EQUAL_FACE(face, face_actual); 
}

void test_face_rotation_anticlockwise(void){
  int value[] = {0,1,2,3,4,5,1,2,0};
  int value_actual[] = {2,5,0,1,4,2,0,3,1};
	int direction = ANTICLOCKWISE;
	Face *face = createFace(FRONT, value);
	Face *face_actual = createFace(FRONT, value_actual);
	faceRotation(direction, face);
	
	TEST_ASSERT_EQUAL_FACE(face, face_actual); 
}