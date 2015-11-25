#include "cube.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_create_face(){

  int value[] = {0,0,0,0,0,0,0,0,0};

 Face *face = createFace(2, value);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((face->faceType)), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[0])), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[1])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[3])), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[4])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[5])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[6])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[7])), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face->faceValue[8])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

}



void test_create_cube(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

               {1,1,1,1,1,1,1,1,1},

               {2,2,2,2,2,2,2,2,2},

               {3,3,3,3,3,3,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cube->topFace->faceType)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cube->leftFace->faceType)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((cube->frontFace->faceType)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((cube->rightFace->faceType)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((cube->bottomFace->faceType)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cube->backFace->faceType)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cube->topFace->faceValue[0])), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cube->leftFace->faceValue[0])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((cube->frontFace->faceValue[0])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((cube->rightFace->faceValue[0])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((cube->bottomFace->faceValue[0])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cube->backFace->faceValue[0])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

}



void test_display_face(void){

  int value[] = {2,2,2,2,2,2,2,2,2};

 Face *face = createFace(2, value);

 displayFace(face);

}



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
