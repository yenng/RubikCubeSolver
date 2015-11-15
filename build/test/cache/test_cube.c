#include "cube.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_create_face(){

 Face face = createFace(0, "WWWWWWWWW");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((face.faceType)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[0])), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[1])), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[3])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[4])), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[5])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[6])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[7])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('W')), (_U_SINT)((face.faceValue[8])), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_display_face(void){

 Face face = createFace(0, "RRRRRRRRR");

 displayFace(face);

}
