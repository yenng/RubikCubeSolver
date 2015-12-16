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

  Cube *cube = createCube(value);

  displayCube(cube);

  sideCornerSolver(cube);

  displayCube(cube);

}



void test_front_side_corner_solver3(void){

  int value[6][9] = {{0,2,2,3,0,1,1,3,5},

                    {5,0,2,1,1,1,1,1,1},

                    {0,2,1,2,2,5,2,2,2},

                    {0,0,3,3,3,5,3,3,3},

                    {4,4,4,4,4,4,4,4,4},

                    {5,5,5,5,5,0,3,0,0}};

  Cube *cube = createCube(value);

  displayCube(cube);

  sideCornerSolver(cube);

  displayCube(cube);

  sideCornerSolver(cube);

  displayCube(cube);

}
