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

  int expectedValue[6][9] = {{2,5,0,2,0,0,5,0,0},

               {1,0,1,1,1,0,1,1,1},

               {0,3,2,1,2,2,2,2,2},

               {3,5,3,3,3,1,3,3,3},

               {4,4,4,4,4,4,4,4,4},

               {5,5,5,5,5,2,0,3,5}};

  Cube *expectedCube = createCube(expectedValue);

  sideCornerSolver1(cube);

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

 displayCube(cube);

  ; customTestAssertCube(expectedCube, cube, 107);;

   topFaceSolver(cube);

   displayCube(cube);

}
