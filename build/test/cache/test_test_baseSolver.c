#include "solver.h"
#include "customAssertion.h"
#include "cube.h"
#include "rotation.h"
#include "unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}





void test_base_corner_full_solver_to_solve_four_corner1232(){

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

 ; customTestAssertCube(expectedCube, cube, 34);;

}





void test_base_corner_full_solver_to_solve_four_corner1232432(){

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

  createMessyCube(cube);

 baseSideFullSolver(cube,0);

 baseCornerFullSolver(cube,0);

 displayCube(cube);

 ; customTestAssertCube(expectedCube, cube, 57);;

}
