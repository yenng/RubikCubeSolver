#include "customAssertion.h"
#include "cube.h"
#include "rotation.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_face_rotation_clockwise(void){

  int value[] = {0,1,2,3,4,5,1,2,0};

  int value_actual[] = {1,3,0,2,4,1,0,5,2};

 int direction = 0;

 Face *face = createFace(2, value);

 Face *face_actual = createFace(2, value_actual);

 faceRotation(direction, face);



 ; customTestAssertFace(face, face_actual, 18);;

}



void test_face_rotation_anticlockwise(void){

  int value[] = {0,1,2,3,4,5,1,2,0};

  int value_actual[] = {2,5,0,1,4,2,0,3,1};

 int direction = 1;

 Face *face = createFace(2, value);

 Face *face_actual = createFace(2, value_actual);

 faceRotation(direction, face);



 ; customTestAssertFace(face, face_actual, 29);;

}
