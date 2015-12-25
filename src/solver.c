#include "solver.h"
#include "rotation.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

/***************Side Corner formula****************/
int FSRCFormula1[8] = {U,R,Ui,Ri,Ui,Fi,U,F};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Front face.
int FSRCFormula2[8] = {Ui,Fi,U,F,U,R,Ui,Ri};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Right face.
int LSRCFormula1[8] = {U,F,Ui,Fi,Ui,Li,U,L};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Left face.
int LSRCFormula2[8] = {Ui,Li,U,L,U,F,Ui,Fi};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Front face.
int BSRCFormula1[8] = {U,L,Ui,Li,Ui,Bi,U,B};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Back face.
int BSRCFormula2[8] = {Ui,Bi,U,B,U,L,Ui,Li};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Left face.
int RSRCFormula1[8] = {U,B,Ui,Bi,Ui,Ri,U,R};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Right face.
int RSRCFormula2[8] = {Ui,Ri,U,R,U,B,Ui,Bi};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Back face.

int *formulaPtr[] = {FSRCFormula1,FSRCFormula2,LSRCFormula1,LSRCFormula2,BSRCFormula1,BSRCFormula2,RSRCFormula1,RSRCFormula2};

/***************Side Corner rotation before getting formula***************************************/
int formulaRW[1] = {U};
int formulaBW[1] = {U};
int formulaOW[1] = {U};
int formulaGW[1] = {U};

int formulaBR[9] = {U,U,F,Ui,Fi,Ui,Li,U,L};        //FrontValue[1] is RED and UpValue[7] is BLUE
int formulaGR[9] = {U,Ui,Bi,U,B,U,L,Ui,Li};        //FrontValue[1] is RED and UpValue[7] is GREEN

int formulaRB[8] = {Ui,Li,U,L,U,F,Ui,Fi};          //FrontValue[1] is BLUE and UpValue[7] is RED
int formulaOB[8] = {U,R,Ui,Ri,Ui,Fi,U,F};          //FrontValue[1] is BLUE and UpValue[7] is ORANGE

int formulaBO[9] = {Ui,Ui,Fi,U,F,U,R,Ui,Ri};       //FrontValue[1] is ORANGE and UpValue[7] is BLUE
int formulaGO[9] = {Ui,U,B,Ui,Bi,Ui,Ri,U,R};       //FrontValue[1] is ORANGE and UpValue[7] is GREEN

int formulaRG[10] = {U,U,U,L,Ui,Li,Ui,Bi,U,B};      //FrontValue[1] is GREEN and UpValue[7] is RED
int formulaOG[10] = {U,U,Ui,Ri,U,R,U,B,Ui,Bi};      //FrontValue[1] is GREEN and UpValue[7] is ORANGE

int *formulaWPtr[6] = {NULL,formulaRW,formulaBW,formulaOW,NULL,formulaGW};
int *formulaRPtr[6] = {NULL,NULL,formulaBR,NULL,NULL,formulaGR};
int *formulaBPtr[6] = {NULL,formulaRB,NULL,formulaOB,NULL,NULL};
int *formulaOPtr[6] = {NULL,NULL,formulaBO,NULL,NULL,formulaGO};
int *formulaGPtr[6] = {NULL,formulaRG,NULL,formulaOG,NULL,NULL};

int **formulaPtrPtr[6] = {formulaWPtr,formulaRPtr,formulaBPtr,formulaOPtr,NULL,formulaGPtr};

/***************************Top Face formula********************************/
/*														TOP FACE VALUE	
 * ____________________________________________________________________________
 * |topFormula0				topFormula1				topFormula2					topFormula3				 |
 * |	X W X							X W X							X X X								X X X						 |
 * |	W W X							X W W							X W W								W W X            |
 * |	X	X X 						X X X             X W X								X W X						 |
 * | pattern6					 pattern1					 pattern3						 pattern5					 |
 * |																																					 |
 * |topFormula0 x 2	 topFormula1 + topFormula0																 |
 * |	X W X										X X X																						 |
 * |	X W X										W W W																						 |
 * |	X W	X										X X	X																						 |
 * | pattern2							 	 pattern4																					 |
 * |___________________________________________________________________________|
 *		PS:  W = white colour, X = any color.
 */
 
int topFormula0[6] = {Ri,Ui,Fi,U,F,R};						
int topFormula1[7] = {U,Ri,Ui,Fi,U,F,R};
int topFormula2[8] = {U,U,Ri,Ui,Fi,U,F,R};
int topFormula3[7] = {Ui,Ri,Ui,Fi,U,F,R};

int *ptrTopFormula[] = {topFormula0,topFormula1,topFormula2,topFormula3};

 /*baseSolver solve the cube to the following result.
				 X X X              X: any color
         X X X              R: Red color
         X X X              B: Blue color
														O: Orange color
 X X X   X X X   X X X      Y: Yellow color
 X R X   X B X   X O X      G: Green color  
 R R R   B B B   O O O      
 
         Y Y Y              
         Y Y Y              
         Y Y Y              

         G G G               
         X G X              
         X X X
*/
void baseSolver(Cube *cube){
  
}

void sideCornerSolver(Cube *cube){
  while(cube->frontFace->faceValue[1]==cW ||cube->upFace->faceValue[7]==cW){
    fullRotation(cube,U);
  }
  int **ptrToPtr = formulaPtrPtr[cube->frontFace->faceValue[1]];
  int *formula = ptrToPtr[cube->upFace->faceValue[7]];
  int i = 0;
  while(i<(10)){
    fullRotation(cube,formula[i]);
    i++;
  }
}

 /* Side corner solver solve the cube to the following result.
				 X X X              X: any color
         X X X              R: Red color
         X X X              B: Blue color
														O: Orange color
 X X X   X X X   X X X      Y: Yellow color
 R R R   B B B   O O O      G: Green color
 R R R   B B B   O O O      
 
         Y Y Y              
         Y Y Y              
         Y Y Y              

         G G G              
         G G G              
         X X X
*/
void fullSideCornerSolver(Cube *cube){
  while(cube->frontFace->faceValue[3] != cB || cube->leftFace->faceValue[5]  != cR ||
        cube->frontFace->faceValue[5] != cB || cube->rightFace->faceValue[3] != cO || 
        cube->rightFace->faceValue[5] != cO || cube->backFace->faceValue[5]  != cG ||
        cube->backFace->faceValue[3]  != cG || cube->leftFace->faceValue[3]  != cR){
    sideCornerSolver(cube);
    //displayCube(cube);
  }
}

 /*Top face solver solve the cube to the following result.
				 X W X              X: any color
         W W W              R: Red color
         X W X              B: Blue color
														O: Orange color
 X X X   X X X   X X X      Y: Yellow color
 R R R   B B B   O O O      G: Green color
 R R R   B B B   O O O      W: White color
 
         Y Y Y              
         Y Y Y              
         Y Y Y              

         G G G              
         G G G              
         X X X
*/
void topFaceSolver(Cube *cube, int formulaNo, int arrSize){
	int *upFormula = ptrTopFormula[formulaNo]; 
	int i = 0;
  while(i<arrSize){
    fullRotation(cube,upFormula[i]);
    i++;
  }
}


void fullTopFaceSolver(Cube *cube){
	int upFaceCrossValue[4] = {cube->upFace->faceValue[1],cube->upFace->faceValue[5],
														 cube->upFace->faceValue[7],cube->upFace->faceValue[3]};
	int i = 0;
	int pattern = 0;
	while(i<4){
		if(upFaceCrossValue[i] == 0){
			pattern = pattern + i;
			if(i == 3 && pattern == 3)
				pattern *= 2;
		}
		i++;
	}
	switch(pattern){
		case pattern0:
			topFaceSolver(cube,0,6);
			fullTopFaceSolver(cube);
			break;
		case pattern1:
			topFaceSolver(cube,3,7);
			break;
		case pattern2:
			topFaceSolver(cube,0,6);
			topFaceSolver(cube,0,6);
			break;
		case pattern3:
			topFaceSolver(cube,2,8);
			break;
		case pattern4:
			topFaceSolver(cube,1,7);
			topFaceSolver(cube,0,6);
			break;
		case pattern5:
			topFaceSolver(cube,1,7);
			break;
		case pattern6:
			topFaceSolver(cube,0,6);
			break;
	}
}









