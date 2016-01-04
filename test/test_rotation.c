#include "unity.h"
#include "rotation.h"
#include "cube.h"
#include "customAssertion.h"

int correctValue[6][9] = {{0,0,0,0,0,0,0,0,0},
													{1,1,1,1,1,1,1,1,1},
													{2,2,2,2,2,2,2,2,2},
													{3,3,3,3,3,3,3,3,3},
													{4,4,4,4,4,4,4,4,4},
                          {5,5,5,5,5,5,5,5,5}};

void setUp(void){}

void tearDown(void){}

void test_face_rotation_clockwise(void){
  int value[] = {0,1,2,3,4,5,1,2,0};
  int value_expected[] = {1,3,0,2,4,1,0,5,2};
	int direction = CLOCKWISE;
	Face *face = createFace(FRONT, value);
	Face *face_expected = createFace(FRONT, value_expected);
	faceRotation(direction, face);
	
	TEST_ASSERT_EQUAL_FACE(face_expected,face); 
}

void test_face_rotation_anticlockwise(void){
  int value[] = {0,1,2,3,4,5,1,2,0};
  int value_expected[] = {2,5,0,1,4,2,0,3,1};
	int direction = ANTICLOCKWISE;
	Face *face = createFace(FRONT, value);
	Face *face_expected = createFace(FRONT, value_expected);
	faceRotation(direction, face);
	
	TEST_ASSERT_EQUAL_FACE(face_expected,face); 
}

void test_create_rotation_clockwise(void){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  
  int rotation = F;
  Rotate *rotate = createRotation(cube, rotation);
	Face *face_expected = createFace(FRONT, value[2]);
	
  TEST_ASSERT_EQUAL(CLOCKWISE,rotate->direction);
	TEST_ASSERT_EQUAL_FACE(face_expected,rotate->face); 
}


void test_create_rotation_anticlockwise(void){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  
  int rotation = Ui;
  Rotate *rotate = createRotation(cube, rotation);
	Face *face_expected = createFace(UP, value[0]);
	
  TEST_ASSERT_EQUAL(ANTICLOCKWISE,rotate->direction);
	TEST_ASSERT_EQUAL_FACE(face_expected,rotate->face); 
}

void test_create_side_rotation_up_face_anticlockwise(void){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  int expectedValue[6][9] = 
              {{0,0,0,0,0,0,0,0,0},
               {cG,cG,cG,1,1,1,1,1,1},
               {cR,cR,cR,2,2,2,2,2,2},
               {cB,cB,cB,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,cO,cO,cO}};
  Cube *expectedCube = createCube(expectedValue);
  
  int rotation = Ui;
  Rotate *rotate = createRotation(cube, rotation);
	faceSideRotation(cube, rotate);
  
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_create_side_rotation_down_face_clockwise(void){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,5,5,5},
               {2,2,2,2,2,2,1,1,1},
               {3,3,3,3,3,3,2,2,2},
               {4,4,4,4,4,4,4,4,4},
               {3,3,3,5,5,5,5,5,5}};
  Cube *expectedCube = createCube(expectedValue);
  
  int rotation = D;
  Rotate *rotate = createRotation(cube, rotation);
	faceSideRotation(cube, rotate);
  
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_create_rotation_down_face_clockwise(void){
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,1,1,1},
               {2,2,2,2,2,2,2,2,2},
               {3,3,3,3,3,3,3,3,3},
               {4,4,4,1,4,4,4,4,4},
               {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
               {1,1,1,1,1,1,5,5,5},
               {2,2,2,2,2,2,1,1,1},
               {3,3,3,3,3,3,2,2,2},
               {4,1,4,4,4,4,4,4,4},
               {3,3,3,5,5,5,5,5,5}};
  Cube *expectedCube = createCube(expectedValue);
  
  int rotation = D;
  
	fullRotation(cube, rotation,0);
  
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_create_messy_cube_and_display(void){
	Cube *correctCube = createCube(correctValue);
  createMessyCube(correctCube);
	//dsafd
}









