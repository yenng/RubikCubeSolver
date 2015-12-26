#ifndef solver_H
#define solver_H
#include "rotation.h"
#include "cube.h"

//top face pattern
#define pattern0 0			//only middle is white color
#define pattern1 1			//white color form a |_ shape
#define pattern2 2			//white color form a |  shape
#define pattern3 3			//white color form a 『  shape
#define pattern4 4			//white color form a _  shape
#define pattern5 5			//white color form a 7  shape
#define pattern6 6			//white color form a 』 shape



void sideCornerSolver1(Cube *cube);
void fullSideCornerSolver(Cube *cube);
void sideCornerSolver(Cube *cube);
void topSideSolver(Cube *cube, int formulaNo, int arrSize);
void fullTopSideSolver(Cube *cube);
int topFaceDetermination(Cube *cube);
void topFaceCornerSolver(Cube *cube);
void fullTopFaceCornerSolver(Cube *cube);
#endif // solver_H
