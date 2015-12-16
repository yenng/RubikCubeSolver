#include "unity.h"
#include "rotation.h"
#include "cube.h"
#include "customAssertion.h"
#include "solver.h"

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
  int expectedValue[6][9] = {{2,5,0,2,0,0,5,0,0},
               {1,0,1,1,1,0,1,1,1},
               {0,3,2,1,2,2,2,2,2},
               {3,5,3,3,3,1,3,3,3},
               {4,4,4,4,4,4,4,4,4},
               {5,5,5,5,5,2,0,3,5}};
  Cube *expectedCube = createCube(expectedValue);
  sideCornerSolver1(cube);
	TEST_ASSERT_EQUAL_CUBE(expectedCube, cube); 
}


void test_front_side_corner_solver2(void){
  int value[6][9] = {{cG,cO,cG,cO,cW,cW,cO,cB,cR},
                    {cW,cW,cW,cR,cR,cR,cR,cR,cR},
                    {cB,cR,cB,cW,cB,cG,cB,cB,cB},
                    {cW,cB,cW,cO,cO,cG,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cW,cR,cB,cO}};
  Cube *cube = createCube(value);
  displayCube(cube);
  sideCornerSolver(cube);
  displayCube(cube);
}

void test_front_side_corner_solver3(void){
  int value[6][9] = {{cW,cB,cB,cO,cW,cR,cR,cO,cG},
                    {cG,cW,cB,cR,cR,cR,cR,cR,cR},
                    {cW,cB,cR,cB,cB,cG,cB,cB,cB},
                    {cW,cW,cO,cO,cO,cG,cO,cO,cO},
                    {cY,cY,cY,cY,cY,cY,cY,cY,cY},
                    {cG,cG,cG,cG,cG,cW,cO,cW,cW}};
  Cube *cube = createCube(value);
  displayCube(cube);
  sideCornerSolver(cube);
  displayCube(cube);
  sideCornerSolver(cube);
  displayCube(cube);
}