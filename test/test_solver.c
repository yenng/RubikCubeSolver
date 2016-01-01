#include "unity.h"
#include "rotation.h"
#include "cube.h"
#include "customAssertion.h"
#include "solver.h"

int correctValue[6][9] = {{0,0,0,0,0,0,0,0,0},
													{1,1,1,1,1,1,1,1,1},
													{2,2,2,2,2,2,2,2,2},
													{3,3,3,3,3,3,3,3,3},
													{4,4,4,4,4,4,4,4,4},
                          {5,5,5,5,5,5,5,5,5}};

void setUp(void){}

void tearDown(void){}

void test_front_side_corner_solver1(void){
  int value[6][9] = {{cW,cW,cW,cW,cW,cO,cW,cW,cW},
                    {cR,cG,cO,cR,cR,cW,cR,cR,cR},
                    {cG,cO,cR,cR,cB,cG,cB,cB,cB},
                    {cB,cB,cB,cO,cO,cR,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cB,cG,cB,cO}};
  Cube *cube = createCube(value);
  int expectedValue[6][9] = {{0,0,5,0,0,2,0,5,2},
               {3,5,3,1,1,0,1,1,1},
               {5,3,0,1,2,2,2,2,2},
               {1,0,1,3,3,1,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,2,2,3,0}};
  Cube *expectedCube = createCube(expectedValue);
  sideCornerSolver(cube);
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_front_side_corner_solver2(void){
  int value[6][9] = {{cG,cO,cG,cO,cW,cW,cO,cB,cR},
                    {cW,cW,cW,cR,cR,cR,cR,cR,cR},
                    {cB,cR,cB,cW,cB,cG,cB,cB,cB},
                    {cW,cB,cW,cO,cO,cG,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cW,cR,cB,cO}};
  int expectedValue[6][9] = {{1,3,0,3,0,2,5,1,2},
                             {0,2,1,1,1,1,1,1,1},
                             {0,0,3,2,2,5,2,2,2},
                             {0,0,3,3,3,5,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,0,2,0,5}};
  Cube *expectedCube = createCube(expectedValue);
  Cube *cube = createCube(value);
  sideCornerSolver(cube);
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_side_corner_solver_one_by_one(void){
  int value[6][9] = {{cW,cB,cB,cO,cW,cR,cR,cO,cG},
                    {cG,cW,cB,cR,cR,cR,cR,cR,cR},
                    {cW,cB,cR,cB,cB,cG,cB,cB,cB},
                    {cW,cW,cO,cO,cO,cG,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cW,cO,cW,cW}};
  int expectedValue[6][9] = {{5,5,5,1,0,3,0,2,0},
                             {3,0,2,1,1,1,1,1,1},
                             {3,0,1,2,2,2,2,2,2},
                             {2,0,1,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,0,0}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  sideCornerSolver(cube);
  sideCornerSolver(cube);
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}
void test_solver_side_corner(){
  int value[6][9] = {{cG,cR,cB,cW,cW,cR,cG,cG,cB},
                     {cO,cG,cR,cW,cR,cB,cR,cR,cR},
                     {cW,cO,cW,cO,cB,cO,cB,cB,cB},
                     {cR,cB,cO,cW,cO,cW,cO,cO,cO},
                     {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                     {cG,cG,cG,cR,cG,cB,cW,cG,cW}};
  int expectedValue[6][9] = {{2,0,5,0,0,0,5,0,2},
                             {1,5,1,1,1,1,1,1,1},
                             {0,1,3,2,2,2,2,2,2},
                             {0,2,0,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,3,3}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullSideCornerSolver(cube);
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_solver_side_corner1(){
  int value[6][9] = {{0,1,0,2,0,1,0,5,0},
                     {3,0,3,0,1,2,1,1,1},
                     {5,3,5,3,2,0,2,2,2},
                     {1,2,1,1,3,0,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,3,2,5,2}};
  int expectedValue[6][9] = {{0,1,0,2,0,0,0,0,0},
                             {1,0,3,1,1,1,1,1,1},
                             {5,5,1,2,2,2,2,2,2},
                             {2,3,2,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,0,3}};
  
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullSideCornerSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_top_face_solver(){
  int value[6][9] = {{0,1,0,2,0,0,0,0,0},
                     {1,0,3,1,1,1,1,1,1},
                     {5,5,1,2,2,2,2,2,2},
                     {2,3,2,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,5,0,3}};	 
  int expectedValue[6][9] = {{3,0,5,0,0,0,0,0,0},
                             {2,2,1,1,1,1,1,1,1},
                             {2,3,3,2,2,2,2,2,2},
                             {5,1,1,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,5,0}}; 
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  topFaceSideSolver(cube, 2,8);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_top_face_full_solver_with_pattern_0(){					//top Face
  int value[6][9] = {{cB,cO,cW,cG,cW,cB,cW,cR,cG},				//	X X X						X W X
                     {cR,cW,cO,1,1,1,1,1,1},							//	X W X		>>>>		W W W
                     {cG,cW,cR,2,2,2,2,2,2},							//	X X X						X W X
                     {cW,cW,cB,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cW,cW,cO}};
  int expectedValue[6][9] = {{1,0,3,0,0,0,0,0,0},
                             {5,2,2,1,1,1,1,1,1},
                             {3,3,1,2,2,2,2,2,2},
                             {2,5,5,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,1,0}}; 
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_top_face_full_solver_with_pattern_3(){							//white color form 『 shape
  int value[6][9] = {{0,1,0,2,0,0,0,0,0},											//TOP FACE
                     {1,0,3,1,1,1,1,1,1},											//	x x x						x W x
                     {5,5,1,2,2,2,2,2,2},											//  x W W   >>>     W W W
                     {2,3,2,3,3,3,3,3,3},											//  x W x						x W x
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,5,0,3}};
  int expectedValue[6][9] = {{3,0,5,0,0,0,0,0,0},
                             {2,2,1,1,1,1,1,1,1},
                             {2,3,3,2,2,2,2,2,2},
                             {5,1,1,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,5,0}}; 
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_top_face_full_solver_with_pattern_4(){						//Top Face
  int value[6][9] = {{cW,cB,cG,cW,cW,cW,cR,cR,cW},					// X W X								X W X
                     {cO,cO,cB,1,1,1,1,1,1},								// X W X				>>>>  	W W W
                     {cW,cW,cG,2,2,2,2,2,2},								// X W X								X W X
                     {cR,cG,cW,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cB,cW,cO}};
  int expectedValue[6][9] = {{5,0,3,0,0,0,0,0,2},
                             {3,3,5,1,1,1,1,1,1},
                             {1,2,0,2,2,2,2,2,2},
                             {1,1,0,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,0,5,2}}; 

  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_top_face_corner_solver(){														//	Top face
  int value[6][9] = {{cR,cW,cB,cW,cW,cW,cW,cW,cO},						//	X W X									W W W
                     {cG,cB,cO,1,1,1,1,1,1},									//	W W W				>>>>>>		W W W
                     {cG,cO,cW,2,2,2,2,2,2},									//	W W X									W W W
                     {cB,cG,cW,3,3,3,3,3,3},	
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cW,cR,cR}};
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {3,1,1,1,1,1,1,1,1},
                             {2,3,5,2,2,2,2,2,2},
                             {1,2,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,2,5,5}}; 
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  topFaceCornerSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_face_corner_solver(){											//	Top face
  int value[6][9] = {{cR,cW,cW,cW,cW,cW,cG,cW,cO},						//	X W W									W W W
                     {cW,cB,cR,1,1,1,1,1,1},									//	W W W				>>>>>>		W W W
                     {cW,cR,cG,2,2,2,2,2,2},									//	X W X									W W W
                     {cW,cG,cB,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cB,cO,cO}};
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {2,3,5,1,1,1,1,1,1},
                             {1,2,3,2,2,2,2,2,2},
                             {5,5,2,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,1,1,3}}; 
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceCornerSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_face_corner_solver_with_two_corners_is_white(){//	Top face
  int value[6][9] = {{cW,cW,cW,cW,cW,cW,cB,cW,cG},						//	W W W									W W W
                     {cO,cO,cW,1,1,1,1,1,1},									//	W W W				>>>>>>		W W W
                     {cR,cB,cR,2,2,2,2,2,2},									//	X W X									W W W
                     {cW,cR,cO,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cB,cG,cG}};
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {5,3,2,1,1,1,1,1,1},
                             {3,2,1,2,2,2,2,2,2},
                             {2,5,5,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,3,1,1}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceCornerSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_face_corner_solver_with_no_corner_is_white(){//	Top face
  int value[6][9] = {{cG,cW,cB,cW,cW,cW,cG,cW,cB},						//	X W X									W W W
                     {cW,cR,cW,1,1,1,1,1,1},									//	W W W				>>>>>>		W W W
                     {cO,cG,cO,2,2,2,2,2,2},									//	X W X									W W W
                     {cW,cO,cW,3,3,3,3,3,3},
                     {4,4,4,4,4,4,4,4,4},
                     {5,5,5,5,5,5,cR,cB,cR}};
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,3,3,1,1,1,1,1,1},
                             {5,5,2,2,2,2,2,2,2},
                             {3,2,1,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,1,2}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
  fullTopFaceCornerSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_top_corner_solver_A_and_B_is_correct(){		//pattern1
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,5,2,1,1,1,1,1,1},									//		| A |		|	B |										 	| A |	  |	B |
                     {3,3,1,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {2,1,3,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,2,5}};						 		//		| D |   | C |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,2,1,1,1,1,1,1,1},
                             {2,5,2,2,2,2,2,2,2},
                             {3,3,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,1,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerSolver(cube,1);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_top_corner_solver_A_and_C_is_correct(){		//pattern2
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,1,1,1,1,1,1,1,1},									//		| A |		|	D |										 	| A |	  |	B |
                     {2,2,3,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {5,5,2,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,3,3}};						 		//		| C |   | B |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,3,1,1,1,1,1,1,1},
                             {2,1,2,2,2,2,2,2,2},
                             {3,2,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerSolver(cube,2);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_corner_solver_A_and_B_is_correct(){		//pattern1
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,5,2,1,1,1,1,1,1},									//		| A |		|	B |										 	| A |	  |	B |
                     {3,3,1,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {2,1,3,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,2,5}};						 		//		| D |   | C |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,2,1,1,1,1,1,1,1},
                             {2,5,2,2,2,2,2,2,2},
                             {3,3,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,1,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_corner_solver_A_and_C_is_correct(){		//pattern2
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,1,1,1,1,1,1,1,1},									//		| A |		|	D |										 	| A |	  |	B |
                     {2,2,3,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {5,5,2,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,3,3}};						 		//		| C |   | B |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,3,1,1,1,1,1,1,1},
                             {2,1,2,2,2,2,2,2,2},
                             {3,2,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_full_top_corner_solver_B_and_C_is_correct(){		//pattern3
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {3,5,1,1,1,1,1,1,1},									//		| D |		|	B |										 	| A |	  |	B |
                     {2,3,5,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {1,1,3,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,2,2,5}};						 		//		| C |   | A |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,2,1,1,1,1,1,1,1},
                             {2,5,2,2,2,2,2,2,2},
                             {3,3,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,1,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_full_top_corner_solver_B_and_D_is_correct(){		//pattern4
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {2,5,5,1,1,1,1,1,1},									//		| A |		|	B |										 	| A |	  |	B |
                     {1,3,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,1,3,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,1,2,5}};						 		//		| C |   | D |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,2,1,1,1,1,1,1,1},
                             {2,5,2,2,2,2,2,2,2},
                             {3,3,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,1,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}

void test_full_top_corner_solver_C_and_D_is_correct(){		//pattern5
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {5,1,1,1,1,1,1,1,1},									//		| B |		|	A |										 	| A |	  |	B |
                     {2,2,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,5,5,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,3,3,1}};						 		//		| C |   | D |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,3,1,1,1,1,1,1,1},
                             {2,1,2,2,2,2,2,2,2},
                             {3,2,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,5,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_corner_solver_A_and_D_is_correct(){		//pattern6
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,3,3,1,1,1,1,1,1},									//		| A |		|	C |										 	| A |	  |	B |
                     {5,5,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,2,1,3,3,3,3,3,3},									//		|		|		|		|					\\\\				|		|		|		|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,1,2}};						 		//		| B |   | D |											| C |   | D |
																													//		|___|___|___|											|___|___|___|
  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},
                             {1,5,1,1,1,1,1,1,1},
                             {2,2,2,2,2,2,2,2,2},
                             {3,1,3,3,3,3,3,3,3},
                             {4,4,4,4,4,4,4,4,4},
                             {5,5,5,5,5,5,5,3,5}};
  Cube *cube = createCube(value);
  Cube *expectedCube = createCube(expectedValue);
	topCornerFullSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_full_top_side_solver_no_side_is_correct(){			//
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,5,1,1,1,1,1,1,1},									//		|   |	A |	  |										 	|   |	D |	  |
                     {2,3,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,2,3,3,3,3,3,3,3},									//		|	D	|		|	B	|					\\\\				|	A	|		|	C	|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,1,5}};						 		//		|   | C |   |											|   | B |   |
																													//		|___|___|___|											|___|___|___|
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	topSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}


void test_full_top_side_solver_side_A_is_correct(){			//
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,1,1,1,1,1,1,1,1},									//		|   |	C |	  |										 	|   |	D |	  |
                     {2,5,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,2,3,3,3,3,3,3,3},									//		|	A	|		|	B	|					\\\\				|	A	|		|	C	|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,3,5}};						 		//		|   | D |   |											|   | B |   |
																													//		|___|___|___|											|___|___|___|
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	topSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}


void test_full_top_side_solver_side_B_is_correct(){			//
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,3,1,1,1,1,1,1,1},									//		|   |	A |	  |										 	|   |	D |	  |
                     {2,2,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,5,3,3,3,3,3,3,3},									//		|	C	|		|	D	|					\\\\				|	A	|		|	C	|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,1,5}};						 		//		|   | B |   |											|   | B |   |
																													//		|___|___|___|											|___|___|___|
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	topSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}


void test_full_top_side_solver_side_C_is_correct(){			//
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,5,1,1,1,1,1,1,1},									//		|   |	B |	  |										 	|   |	D |	  |
                     {2,1,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,3,3,3,3,3,3,3,3},									//		|	D	|		|	C	|					\\\\				|	A	|		|	C	|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,2,5}};						 		//		|   | A |   |											|   | B |   |
																													//		|___|___|___|											|___|___|___|
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	topSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}


void test_full_top_side_solver_side_D_is_correct(){			//
  int value[6][9] = {{0,0,0,0,0,0,0,0,0},									//		 ___________											 ___________
                     {1,3,1,1,1,1,1,1,1},									//		|   |	B |	  |										 	|   |	D |	  |
                     {2,1,2,2,2,2,2,2,2},									//		|___|___|___|										 	|___|___|___|
                     {3,2,3,3,3,3,3,3,3},									//		|	D	|		|	C	|					\\\\				|	A	|		|	C	|
                     {4,4,4,4,4,4,4,4,4},									//		|___|___|___|					////				|___|___|___|
										 {5,5,5,5,5,5,5,5,5}};						 		//		|   | A |   |											|   | B |   |
																													//		|___|___|___|											|___|___|___|
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	topSideSolver(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}
	
void test_full_solver(void){
  int value[6][9] = {{cB,cR,cW,cW,cW,cO,cW,cB,cG},
                    {cW,cG,cG,cO,cR,cB,cR,cR,cR},
                    {cR,cW,cW,cO,cB,cR,cB,cB,cB},
                    {cO,cW,cR,cW,cO,cB,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cR,cO,cG,cB}};
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	fullSolver(cube);
	// displayCube(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}
	
void test_full_solver1(void){
  int value[6][9] = {{cG,cG,cB,cO,cW,cR,cB,cB,cG},
                    {cW,cW,cO,cO,cR,cB,cR,cR,cR},
                    {cW,cW,cW,cO,cB,cG,cB,cB,cB},
                    {cO,cW,cW,cR,cO,cB,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cR,cR,cW,cR}};
  Cube *cube = createCube(value);
	Cube *correctCube = createCube(correctValue);
	fullSolver(cube);
	displayCube(cube);
  TEST_ASSERT_EQUAL_CUBE(correctCube, cube); 
}