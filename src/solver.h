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

#define EOA 100 		//EOA is end of array

void baseSideSolver(Cube *cube, int print);
void baseSideFullSolver(Cube *cube, int print);

void baseCornerSolver(Cube *cube, int print);
void baseCornerFullSolver(Cube *cube, int print);

void sideCornerSolver(Cube *cube, int print);
void fullSideCornerSolver(Cube *cube, int print);

void topFaceSideSolver(Cube *cube, int formulaNo, int arrSize, int print);
void fullTopFaceSideSolver(Cube *cube, int print);

int topFaceDetermination(Cube *cube);	//to make sure top face is all White color
void topFaceCornerSolver(Cube *cube, int print);
void fullTopFaceCornerSolver(Cube *cube, int print);

void topCornerSolver(Cube *cube, int formulaNo, int print);
void topCornerFullSolver(Cube *cube, int print);

void topSideSolver(Cube *cube, int print);
#endif // solver_H
