#include "solver.h"
#include "customAssertion.h"
#include "cube.h"
#include "rotation.h"
#include "unity.h"




int correctValue[6][9] = {{0,0,0,0,0,0,0,0,0},

             {1,1,1,1,1,1,1,1,1},

             {2,2,2,2,2,2,2,2,2},

             {3,3,3,3,3,3,3,3,3},

             {4,4,4,4,4,4,4,4,4},

                          {5,5,5,5,5,5,5,5,5}};



void setUp(void){}



void tearDown(void){}



void test_base_side_solver_one_time(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{0,0,0,1,0,1,4,2,2},

              {2,5,1,2,1,2,3,2,1},

              {5,0,4,4,2,3,5,3,1},

              {3,0,2,5,3,5,2,3,4},

              {0,0,4,1,4,4,0,4,5},

              {5,1,3,3,5,4,1,5,3}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 36);;

}



void test_base_side_solver_two_times(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{1,0,0,3,0,1,1,2,2},

              {5,2,2,3,1,5,3,2,4},

              {0,0,4,1,2,3,1,2,1},

              {3,0,2,5,3,5,4,3,4},

              {2,4,5,1,4,4,0,4,5},

              {5,1,3,0,5,4,0,5,3}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 56);;

}



void test_base_side_solver_three_times(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{3,0,0,3,0,1,1,2,2},

              {5,2,2,2,1,5,4,1,5},

              {0,0,4,1,2,3,3,2,1},

              {3,0,2,5,3,5,4,3,1},

              {0,4,5,4,4,4,1,0,0},

              {2,3,5,1,5,4,4,5,3}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 77);;

}



void test_base_side_solver_four_times(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{3,0,4,3,0,3,1,2,1},

              {5,2,2,2,1,5,0,1,5},

              {0,0,0,1,2,0,3,2,1},

              {5,5,3,3,3,0,4,3,1},

              {0,4,5,4,4,4,3,4,4},

              {2,5,2,1,5,1,4,5,2}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 baseSideSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 99);;

}

void test_base_side_full_solver_with_same_cube_above(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{3,0,4,3,0,3,1,2,1},

              {5,2,2,2,1,5,0,1,5},

              {0,0,0,1,2,0,3,2,1},

              {5,5,3,3,3,0,4,3,1},

              {0,4,5,4,4,4,3,4,4},

              {2,5,2,1,5,1,4,5,2}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideFullSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 117);;

}



void test_base_side_full_solver_with_different_cube(){

  int value[6][9] = {{4,3,2,3,0,2,2,4,5},

                    {2,0,3,5,1,4,2,2,5},

                    {0,3,0,2,2,4,1,4,4},

                    {3,0,1,1,3,0,3,0,1},

                    {4,5,5,3,4,5,1,1,0},

                    {0,2,5,1,5,1,3,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{3,0,1,3,0,3,0,2,2},

              {4,2,2,3,1,5,0,1,3},

              {3,0,1,1,2,5,5,2,1},

              {4,5,0,0,3,2,4,3,0},

              {4,4,5,4,4,4,2,4,3},

              {1,5,5,0,5,1,2,1,5}};

  Cube *expectedCube = createCube(expectedValue);

 baseSideFullSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 136);;

}



void test_base_corner_solver_to_solve_one_corner(){

  int value[6][9] = {{3,3,3,0,0,1,3,5,5},

                    {0,5,4,1,1,0,2,1,1},

                    {5,1,4,3,2,2,5,2,2},

                    {1,2,2,3,3,0,4,3,0},

                    {0,4,1,4,4,4,0,4,1},

                    {3,5,2,0,5,2,5,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{3,1,2,3,0,3,3,5,5},

              {4,5,4,1,1,0,1,1,1},

              {5,1,0,3,2,5,5,2,2},

              {3,2,3,0,3,0,4,3,0},

              {0,4,1,4,4,4,4,4,1},

              {5,5,2,0,5,2,2,2,0}};

  Cube *expectedCube = createCube(expectedValue);

 baseCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 155);;

}



void test_base_corner_solver_to_solve_two_corner_by_run_base_corner_solver_twice(){

  int value[6][9] = {{3,3,3,0,0,1,3,5,5},

                    {0,5,4,1,1,0,2,1,1},

                    {5,1,4,3,2,2,5,2,2},

                    {1,2,2,3,3,0,4,3,0},

                    {0,4,1,4,4,4,0,4,1},

                    {3,5,2,0,5,2,5,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{2,3,3,1,0,3,2,5,3},

              {0,2,1,1,1,0,1,1,1},

              {4,0,5,3,2,5,5,2,2},

              {0,5,4,1,3,0,3,3,0},

              {0,4,4,4,4,4,4,4,1},

              {5,5,2,0,5,2,3,2,5}};

  Cube *expectedCube = createCube(expectedValue);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 175);;

}





void test_base_corner_solver_to_solve_three_corner_by_run_base_corner_solver_three_times(){

  int value[6][9] = {{3,3,3,0,0,1,3,5,5},

                    {0,5,4,1,1,0,2,1,1},

                    {5,1,4,3,2,2,5,2,2},

                    {1,2,2,3,3,0,4,3,0},

                    {0,4,1,4,4,4,0,4,1},

                    {3,5,2,0,5,2,5,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{2,3,2,1,0,1,3,3,1},

              {0,2,5,1,1,0,1,1,1},

              {0,5,4,3,2,0,5,2,2},

              {2,5,0,5,3,0,3,3,3},

              {0,4,4,4,4,4,4,4,4},

              {5,5,5,0,5,2,3,2,1}};

  Cube *expectedCube = createCube(expectedValue);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 197);;

}





void test_base_corner_solver_to_solve_four_corner_by_run_base_corner_solver_four_times(){

  int value[6][9] = {{3,3,3,0,0,1,3,5,5},

                    {0,5,4,1,1,0,2,1,1},

                    {5,1,4,3,2,2,5,2,2},

                    {1,2,2,3,3,0,4,3,0},

                    {0,4,1,4,4,4,0,4,1},

                    {3,5,2,0,5,2,5,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{2,1,5,3,0,5,3,3,3},

              {1,2,5,1,1,0,1,1,1},

              {0,5,0,3,2,2,2,2,2},

              {2,0,1,1,3,0,3,3,3},

              {4,4,4,4,4,4,4,4,4},

              {5,5,5,0,5,2,0,5,0}};

  Cube *expectedCube = createCube(expectedValue);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 baseCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 220);;

}





void test_base_corner_full_solver_to_solve_four_corner(){

  int value[6][9] = {{3,3,3,0,0,1,3,5,5},

                    {0,5,4,1,1,0,2,1,1},

                    {5,1,4,3,2,2,5,2,2},

                    {1,2,2,3,3,0,4,3,0},

                    {0,4,1,4,4,4,0,4,1},

                    {3,5,2,0,5,2,5,5,4}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{2,1,5,3,0,5,3,3,3},

              {1,2,5,1,1,0,1,1,1},

              {0,5,0,3,2,2,2,2,2},

              {2,0,1,1,3,0,3,3,3},

              {4,4,4,4,4,4,4,4,4},

              {5,5,5,0,5,2,0,5,0}};

  Cube *expectedCube = createCube(expectedValue);

 baseCornerFullSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 240);;

}







void test_front_side_corner_solver1(void){

  int value[6][9] = {{0,0,0,0,0,3,0,0,0},

                    {1,5,3,1,1,0,1,1,1},

                    {5,3,1,1,2,5,2,2,2},

                    {2,2,2,3,3,1,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,2,5,2,3}};

  Cube *cube = createCube(value);

  int expectedValue[6][9] = {{2,5,0,2,0,0,5,0,0},

               {1,0,1,1,1,0,1,1,1},

               {0,3,2,1,2,2,2,2,2},

               {3,5,3,3,3,1,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,2,0,3,5}};

  Cube *expectedCube = createCube(expectedValue);

  sideCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 261);;

}





void test_front_side_corner_solver2(void){

  int value[6][9] = {{5,3,5,3,0,0,3,2,1},

                    {0,0,0,1,1,1,1,1,1},

                    {2,1,2,0,2,5,2,2,2},

                    {0,2,0,3,3,5,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,0,1,2,3}};

  int expectedValue[6][9] = {{0,2,2,3,0,1,1,3,5},

                             {5,0,2,1,1,1,1,1,1},

                             {0,2,1,2,2,5,2,2,2},

                             {0,0,3,3,3,5,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,0,3,0,0}};

  Cube *expectedCube = createCube(expectedValue);

  Cube *cube = createCube(value);

  sideCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 281);;

}





void test_side_corner_solver_one_by_one(void){

  int value[6][9] = {{0,2,2,3,0,1,1,3,5},

                    {5,0,2,1,1,1,1,1,1},

                    {0,2,1,2,2,5,2,2,2},

                    {0,0,3,3,3,5,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,0,3,0,0}};

  int expectedValue[6][9] = {{5,3,0,5,0,2,5,1,0},

                             {0,0,0,1,1,1,1,1,1},

                             {3,0,2,2,2,2,2,2,2},

                             {3,0,1,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,1,0,2}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  sideCornerSolver(cube,0);

  sideCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 302);;

}

void test_solver_side_corner(){

  int value[6][9] = {{5,1,2,0,0,1,5,5,2},

                     {3,5,1,0,1,2,1,1,1},

                     {0,3,0,3,2,3,2,2,2},

                     {1,2,3,0,3,0,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,1,5,2,0,5,0}};

  int expectedValue[6][9] = {{0,3,0,2,0,5,0,1,0},

                             {3,0,3,1,1,1,1,1,1},

                             {5,0,5,2,2,2,2,2,2},

                             {1,0,1,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,2,0,2}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullSideCornerSolver(cube,0);

 ; customTestAssertCube(expectedCube, cube, 320);;

}







void test_solver_side_corner1(){

  int value[6][9] = {{0,1,0,2,0,1,0,5,0},

                     {3,0,3,0,1,2,1,1,1},

                     {5,3,5,3,2,0,2,2,2},

                     {1,2,1,1,3,0,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

                     {5,5,5,5,5,3,2,5,2}};

  int expectedValue[6][9] = {{2,0,5,3,0,0,2,5,5},

                             {1,0,3,1,1,1,1,1,1},

                             {0,0,0,2,2,2,2,2,2},

                             {3,2,1,3,3,3,3,3,3},

                             {4,4,4,4,4,4,4,4,4},

                             {5,5,5,5,5,5,0,1,0}};



  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(expectedValue);

  fullSideCornerSolver(cube,0);



  ; customTestAssertCube(expectedCube, cube, 343);;

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

  topFaceSideSolver(cube, 2,8,0);

  ; customTestAssertCube(expectedCube, cube, 362);;

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

  fullTopFaceSideSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 381);;

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

  fullTopFaceSideSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 400);;

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

  fullTopFaceSideSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 421);;

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

  topFaceCornerSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 441);;

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

  fullTopFaceCornerSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 461);;

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

  fullTopFaceCornerSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 481);;

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

  fullTopFaceCornerSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 501);;

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

 topCornerSolver(cube,1,0);

  ; customTestAssertCube(expectedCube, cube, 522);;

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

 topCornerSolver(cube,2,0);

  ; customTestAssertCube(expectedCube, cube, 543);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 564);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 585);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 605);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 625);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 645);;

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

 topCornerFullSolver(cube,0);

  ; customTestAssertCube(expectedCube, cube, 666);;

}





void test_full_top_side_solver_no_side_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,5,1,1,1,1,1,1,1},

                     {2,3,2,2,2,2,2,2,2},

                     {3,2,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,1,5}};



  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 topSideSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 681);;

}





void test_full_top_side_solver_side_A_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,1,1,1,1,1,1,1,1},

                     {2,5,2,2,2,2,2,2,2},

                     {3,2,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,3,5}};



  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 topSideSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 696);;

}





void test_full_top_side_solver_side_B_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,3,1,1,1,1,1,1,1},

                     {2,2,2,2,2,2,2,2,2},

                     {3,5,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,1,5}};



  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 topSideSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 711);;

}





void test_full_top_side_solver_side_C_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,5,1,1,1,1,1,1,1},

                     {2,1,2,2,2,2,2,2,2},

                     {3,3,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,2,5}};



  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 topSideSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 726);;

}





void test_full_top_side_solver_side_D_is_correct(){

  int value[6][9] = {{0,0,0,0,0,0,0,0,0},

                     {1,3,1,1,1,1,1,1,1},

                     {2,1,2,2,2,2,2,2,2},

                     {3,2,3,3,3,3,3,3,3},

                     {4,4,4,4,4,4,4,4,4},

           {5,5,5,5,5,5,5,5,5}};



  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 topSideSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 741);;

}



void test_full_solver(void){

  int value[6][9] = {{2,1,0,0,0,3,0,2,5},

                    {0,5,5,3,1,2,1,1,1},

                    {1,0,0,3,2,1,2,2,2},

                    {3,0,1,0,3,2,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,1,3,5,2}};

  Cube *cube = createCube(value);

 int print = 0;



 Cube *correctCube = createCube(correctValue);

 fullSolver(cube);

  ; customTestAssertCube(correctCube, cube, 756);;

}



void test_full_solver1(void){

  int value[6][9] = {{5,5,2,3,0,1,2,2,5},

                    {0,0,3,3,1,2,1,1,1},

                    {0,0,0,3,2,5,2,2,2},

                    {3,0,0,1,3,2,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,1,1,0,1}};

  Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 769);;

}



void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube(){

 Cube *correctCube = createCube(correctValue);

 Cube *cube = createCube(correctValue);

  createMessyCube(cube);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 777);;

}



void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube1(){

 Cube *correctCube = createCube(correctValue);

  int value[6][9] = {{5,5,2,3,0,1,2,2,5},

                    {0,0,3,3,1,2,1,1,1},

                    {0,0,0,3,2,5,2,2,2},

                    {3,0,0,1,3,2,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,1,1,0,1}};

 Cube *cube = createCube(value);

  createMessyCube(cube);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 791);;

}



void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube(){

  int value[6][9] = {{2,1,0,0,0,3,0,2,5},

                    {0,5,5,3,1,2,1,1,1},

                    {1,0,0,3,2,1,2,2,2},

                    {3,0,1,0,3,2,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,1,3,5,2}};

 Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

  createMessyCube(cube);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 805);;

}



void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube1(){

  int value[6][9] = {{0,0,4,1,0,4,4,2,5},

                    {2,5,1,2,1,2,3,2,1},

                    {5,0,3,4,2,4,5,3,3},

                    {4,3,2,5,3,5,2,0,3},

                    {0,0,0,1,4,1,0,4,2},

                    {5,1,4,3,5,3,1,5,1}};

 Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

  createMessyCube(cube);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 819);;

}



void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube2(){

  int value[6][9] = {{1,1,0,5,0,0,4,0,5},

                    {5,3,2,1,1,4,2,1,4},

                    {1,2,0,5,2,5,5,2,3},

                    {3,3,2,1,3,0,5,3,2},

                    {1,4,4,0,4,2,3,3,0},

                    {4,4,1,2,5,5,0,4,3}};

 Cube *cube = createCube(value);

 Cube *correctCube = createCube(correctValue);

  createMessyCube(cube);

 fullSolver(cube,0);

  ; customTestAssertCube(correctCube, cube, 833);;

}



void test_base_side_full_solver_with_random_cube(){

  int value[6][9] = {{2,0,5,2,0,3,0,0,5},

                    {0,1,5,1,1,3,3,1,4},

                    {1,2,3,5,2,0,1,2,2},

                    {4,2,4,3,3,1,3,3,0},

                    {2,4,4,5,4,4,0,5,1},

                    {5,4,2,4,5,0,3,5,1}};

  Cube *cube = createCube(value);

  Cube *expectedCube = createCube(correctValue);

 int print = 10;

 baseSideFullSolver(cube,print);

 baseCornerFullSolver(cube,print);

 fullSideCornerSolver(cube,print);

 fullTopFaceSideSolver(cube,print);

 fullTopFaceCornerSolver(cube,print);

 topCornerFullSolver(cube,print);

 topSideSolver(cube,print);



 ; customTestAssertCube(expectedCube, cube, 854);;

}
