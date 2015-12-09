#include "customAssertion.h"
#include "cube.h"
#include "rotation.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_face_rotation_clockwise(void){

  int value[] = {0,1,2,3,4,5,1,2,0};

  int value_expected[] = {1,3,0,2,4,1,0,5,2};

 int direction = 0;

 Face *face = createFace(2, value);

 Face *face_expected = createFace(2, value_expected);

 faceRotation(direction, face);



 ; customTestAssertFace(face_expected, face, 18);;

}



void test_face_rotation_anticlockwise(void){

  int value[] = {0,1,2,3,4,5,1,2,0};

  int value_expected[] = {2,5,0,1,4,2,0,3,1};

 int direction = 1;

 Face *face = createFace(2, value);

 Face *face_expected = createFace(2, value_expected);

 faceRotation(direction, face);



 ; customTestAssertFace(face_expected, face, 29);;

}



void test_create_rotation_clockwise(void){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

               {1,1,1,1,1,1,1,1,1},

               {2,2,2,2,2,2,2,2,2},

               {3,3,3,3,3,3,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);



  int rotation = 4;

  Rotate *rotate = createRotation(cube, rotation);

 Face *face_expected = createFace(2, value[2]);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((rotate->direction)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 ; customTestAssertFace(face_expected, rotate->face, 46);;

}





void test_create_rotation_anticlockwise(void){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

               {1,1,1,1,1,1,1,1,1},

               {2,2,2,2,2,2,2,2,2},

               {3,3,3,3,3,3,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);



  int rotation = 1;

  Rotate *rotate = createRotation(cube, rotation);

 Face *face_expected = createFace(0, value[0]);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((rotate->direction)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 ; customTestAssertFace(face_expected, rotate->face, 64);;

}
