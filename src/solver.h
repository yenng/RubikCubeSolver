#ifndef solver_H
#define solver_H
#include "rotation.h"
#include "cube.h"

//top face pattern			/*****For top face************/						/**********For top corner*******************/
#define pattern0 0			//only middle is white color										//not used												 ___________
#define pattern1 1			//white color form a |_ shape										//A and B is correct							| A |		|	B |
#define pattern2 2			//white color form a |  shape										//A and C is correct							|___|___|___|
#define pattern3 3			//white color form a 『  shape										//B and C is correct							|		|   |   |
#define pattern4 4			//white color form a _  shape										//B and D is correct							|___|___|___|
#define pattern5 5			//white color form a 7  shape										//C and D is correct							| C |   | D |
#define pattern6 6			//white color form a 』 shape										//A and D is correct							|___|___|___|



void sideCornerSolver(Cube *cube);
void fullSideCornerSolver(Cube *cube);

void topFaceSideSolver(Cube *cube, int formulaNo, int arrSize);
void fullTopFaceSideSolver(Cube *cube);

int topFaceDetermination(Cube *cube);	//to make sure top face is all White color
void topFaceCornerSolver(Cube *cube);
void fullTopFaceCornerSolver(Cube *cube);

void topCornerSolver(Cube *cube, int formulaNo);
void topCornerFullSolver(Cube *cube);

void topSideSolver(Cube *cube);
#endif // solver_H
