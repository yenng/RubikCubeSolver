#include "unity.h"
#include "cube.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_create_face(){
	Face face = createFace(FRONT, "WWWWWWWWW");
	TEST_ASSERT_EQUAL(FRONT, face.faceType);
	TEST_ASSERT_EQUAL('W', face.faceValue[0]);
	TEST_ASSERT_EQUAL('W', face.faceValue[1]);
	TEST_ASSERT_EQUAL('W', face.faceValue[3]);
	TEST_ASSERT_EQUAL('W', face.faceValue[4]);
	TEST_ASSERT_EQUAL('W', face.faceValue[5]);
	TEST_ASSERT_EQUAL('W', face.faceValue[6]);
	TEST_ASSERT_EQUAL('W', face.faceValue[7]);
	TEST_ASSERT_EQUAL('W', face.faceValue[8]);
}

void test_display_face(void){
	Face face = createFace(FRONT, "RRRRRRRRR");
	displayFace(face);
}
