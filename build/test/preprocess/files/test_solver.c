#include "solver.h"
#include "customAssertion.h"
#include "cube.h"
#include "rotation.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_front_side_corner_solver1(void){

  int value[6][9] = {{0,0,0,0,0,3,0,0,0},

                    {1,5,3,1,1,0,1,1,1},

                    {5,3,1,1,2,5,2,2,2},

                    {2,2,2,3,3,1,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,2,5,2,3}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{0,0,5,0,0,2,0,5,2},

               {3,5,3,1,1,0,1,1,1},

               {5,3,0,1,2,2,2,2,2},

               {1,0,1,3,3,1,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,2,2,3,0}};

  Cube *expectedCube = createCube(expectedValue);

  sideCornerSolver(cube);

 ; customTestAssertCube(expectedCube, cube, 27);;

}





void test_front_side_corner_solver2(void){

  int value[6][9] = {{5,3,5,3,0,0,3,2,1},

                    {0,0,0,1,1,1,1,1,1},

                    {2,1,2,0,2,5,2,2,2},

                    {0,2,0,3,3,5,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,0,1,2,3}};

  int expectedValue[6][9] = {{1,3,0,3,0,2,5,1,2},

                             {0,2,1,1,1,1,1,1,1},

                             {0,0,3,2,2,5,2,2,2},

                             {0,0,3,3,3,5,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,0,2,0,5}};

  Cube *expectedCube = createCube(expectedValue);

  Cube *cube = createCube(value);

  sideCornerSolver(cube);

 ; customTestAssertCube(expectedCube, cube, 47);;

}





void test_side_corner_solver_one_by_one(void){

  int value[6][9] = {{0,2,2,3,0,1,1,3,5},

                    {5,0,2,1,1,1,1,1,1},

                    {0,2,1,2,2,5,2,2,2},

                    {0,0,3,3,3,5,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,0,3,0,0}};

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

 ; customTestAssertCube(expectedCube, cube, 68);;

}

void test_solver_side_corner(){

  int value[6][9] = {{5,1,2,0,0,1,5,5,2},

                     {3,5,1,0,1,2,1,1,1},

                     {0,3,0,3,2,3,2,2,2},

                     {1,2,3,0,3,0,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,1,5,2,0,5,0}};

  int expectedValue[6][9] = {{2,0,5,0,0,0,5,0,2},

                             {1,5,1,1,1,1,1,1,1},

                             {0,1,3,2,2,2,2,2,2},

                             {0,2,0,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,0,3,3}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullSideCornerSolver(cube);

 ; customTestAssertCube(expectedCube, cube, 86);;

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

  ; customTestAssertCube(expectedCube, cube, 106);;

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

  topSideSolver(cube, 2,8);

  ; customTestAssertCube(expectedCube, cube, 125);;

}



void test_top_face_full_solver_with_pattern_0(){

  int value[6][9] = {{2,3,0,5,0,2,0,1,5},

                     {1,0,3,1,1,1,1,1,1},

                     {5,0,1,2,2,2,2,2,2},

                     {0,0,2,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,0,0,3}};

  int expectedValue[6][9] = {{1,0,3,0,0,0,0,0,0},

                             {5,2,2,1,1,1,1,1,1},

                             {3,3,1,2,2,2,2,2,2},

                             {2,5,5,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,0,1,0}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullTopSideSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 144);;

}



void test_top_face_full_solver_with_pattern_3(){

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

  fullTopSideSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 163);;

}





void test_top_face_full_solver_with_pattern_4(){

  int value[6][9] = {{0,2,5,0,0,0,1,1,0},

                     {3,3,2,1,1,1,1,1,1},

                     {0,0,5,2,2,2,2,2,2},

                     {1,5,0,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,2,0,3}};

  int expectedValue[6][9] = {{5,0,3,0,0,0,0,0,2},

                             {3,3,5,1,1,1,1,1,1},

                             {1,2,0,2,2,2,2,2,2},

                             {1,1,0,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,0,5,2}};



  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullTopSideSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 184);;

}





void test_top_face_corner_solver(){

  int value[6][9] = {{1,0,2,0,0,0,0,0,3},

                     {5,2,3,1,1,1,1,1,1},

                     {5,3,0,2,2,2,2,2,2},

                     {2,5,0,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,0,1,1}};

  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {3,1,1,1,1,1,1,1,1},

                             {2,3,5,2,2,2,2,2,2},

                             {1,2,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,2,5,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  topFaceCornerSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 204);;

}





void test_full_top_face_corner_solver(){

  int value[6][9] = {{1,0,0,0,0,0,5,0,3},

                     {0,2,1,1,1,1,1,1,1},

                     {0,1,5,2,2,2,2,2,2},

                     {0,5,2,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,2,3,3}};

  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {2,3,5,1,1,1,1,1,1},

                             {1,2,3,2,2,2,2,2,2},

                             {5,5,2,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,1,1,3}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullTopFaceCornerSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 224);;

}





void test_full_top_face_corner_solver_with_two_corners_is_white(){

  int value[6][9] = {{0,0,0,0,0,0,2,0,5},

                     {3,3,0,1,1,1,1,1,1},

                     {1,2,1,2,2,2,2,2,2},

                     {0,1,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,2,5,5}};

  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {5,3,2,1,1,1,1,1,1},

                             {3,2,1,2,2,2,2,2,2},

                             {2,5,5,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,3,1,1}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullTopFaceCornerSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 244);;

}





void test_full_top_face_corner_solver_with_no_corner_is_white(){

  int value[6][9] = {{5,0,2,0,0,0,5,0,2},

                     {0,1,0,1,1,1,1,1,1},

                     {3,5,3,2,2,2,2,2,2},

                     {0,3,0,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,5,1,2,1}};

  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,3,3,1,1,1,1,1,1},

                             {5,5,2,2,2,2,2,2,2},

                             {3,2,1,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,1,2}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullTopFaceCornerSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 264);;

}





void test_top_corner_solver_A_and_B_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,5,2,1,1,1,1,1,1},

                     {3,3,1,2,2,2,2,2,2},

                     {2,1,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,2,5}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,2,1,1,1,1,1,1,1},

                             {2,5,2,2,2,2,2,2,2},

                             {3,3,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,1,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerSolver(cube,1);

  ; customTestAssertCube(expectedCube, cube, 285);;

}





void test_top_corner_solver_A_and_C_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,1,1,1,1,1,1,1,1},

                     {2,2,3,2,2,2,2,2,2},

                     {5,5,2,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,3,3}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,3,1,1,1,1,1,1,1},

                             {2,1,2,2,2,2,2,2,2},

                             {3,2,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerSolver(cube,2);

  ; customTestAssertCube(expectedCube, cube, 306);;

}





void test_full_top_corner_solver_A_and_B_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,5,2,1,1,1,1,1,1},

                     {3,3,1,2,2,2,2,2,2},

                     {2,1,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,2,5}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,2,1,1,1,1,1,1,1},

                             {2,5,2,2,2,2,2,2,2},

                             {3,3,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,1,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 327);;

}





void test_full_top_corner_solver_A_and_C_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,1,1,1,1,1,1,1,1},

                     {2,2,3,2,2,2,2,2,2},

                     {5,5,2,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,3,3}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,3,1,1,1,1,1,1,1},

                             {2,1,2,2,2,2,2,2,2},

                             {3,2,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 348);;

}



void test_full_top_corner_solver_B_and_C_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {3,5,1,1,1,1,1,1,1},

                     {2,3,5,2,2,2,2,2,2},

                     {1,1,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,2,2,5}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,2,1,1,1,1,1,1,1},

                             {2,5,2,2,2,2,2,2,2},

                             {3,3,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,1,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 368);;

}



void test_full_top_corner_solver_B_and_D_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {2,5,5,1,1,1,1,1,1},

                     {1,3,2,2,2,2,2,2,2},

                     {3,1,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,1,2,5}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,2,1,1,1,1,1,1,1},

                             {2,5,2,2,2,2,2,2,2},

                             {3,3,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,1,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 388);;

}



void test_full_top_corner_solver_C_and_D_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {5,1,1,1,1,1,1,1,1},

                     {2,2,2,2,2,2,2,2,2},

                     {3,5,5,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,3,3,1}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,3,1,1,1,1,1,1,1},

                             {2,1,2,2,2,2,2,2,2},

                             {3,2,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,5,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);



  ; customTestAssertCube(expectedCube, cube, 409);;

}





void test_full_top_corner_solver_A_and_D_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,3,3,1,1,1,1,1,1},

                     {5,5,2,2,2,2,2,2,2},

                     {3,2,1,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,1,2}};



  int expectedValue[6][9] = {{0,0,0,0,0,0,0,0,0},

                             {1,5,1,1,1,1,1,1,1},

                             {2,2,2,2,2,2,2,2,2},

                             {3,1,3,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,5,3,5}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

 topCornerFullSolver(cube);

  ; customTestAssertCube(expectedCube, cube, 430);;

}
