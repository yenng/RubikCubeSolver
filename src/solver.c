#include "solver.h"
#include "rotation.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
/***************Base Formula**********************************/
//formula when one of side of up face is yellow.
int baseFormulaUp0B[] = {Ui,F,F};
int baseFormulaUp0G[] = {U,B,B};
int baseFormulaUp0R[] = {L,L};
int baseFormulaUp0O[] = {U,U,R,R};
int baseFormulaUp1B[] = {F,F};
int baseFormulaUp1G[] = {U,U,B,B};
int baseFormulaUp1R[] = {U,L,L};
int baseFormulaUp1O[] = {Ui,R,R};
int baseFormulaUp2B[] = {U,F,F};
int baseFormulaUp2G[] = {Ui,B,B};
int baseFormulaUp2R[] = {U,U,L,L};
int baseFormulaUp2O[] = {R,R};
int baseFormulaUp3B[] = {U,U,F,F};
int baseFormulaUp3G[] = {B,B};
int baseFormulaUp3R[] = {Ui,L,L};
int baseFormulaUp3O[] = {U,R,R};

//formula when one of side of left face is yellow.
int baseFormulaleft0B[] = {Di,L,L,D,F};
int baseFormulaleft0G[] = {B};
int baseFormulaleft0R[] = {L,U,B,Li,Bi};
int baseFormulaleft0O[] = {D,D,L,Ui,D,F,D,Ri};
int baseFormulaleft1B[] = {Li,Fi};
int baseFormulaleft1G[] = {L,B};
int baseFormulaleft1R[] = {Li,D,F,Di};
int baseFormulaleft1O[] = {Li,Di,Fi,D};
int baseFormulaleft2B[] = {Fi};
int baseFormulaleft2G[] = {D,D,Fi,D,D};
int baseFormulaleft2R[] = {D,Fi,Di};
int baseFormulaleft2O[] = {Di,Fi,D};
int baseFormulaleft3B[] = {Di,L,D,Fi};
int baseFormulaleft3G[] = {D,Li,Di,B};
int baseFormulaleft3R[] = {L,D,Fi,Di};
int baseFormulaleft3O[] = {D,D,L,D,Fi,D};

//formula when one of side of front face is yellow.

/***************Side Corner formula****************/
// int FSRCFormula1[8] = {U,R,Ui,Ri,Ui,Fi,U,F};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Front face.
// int FSRCFormula2[8] = {Ui,Fi,U,F,U,R,Ui,Ri};    //Solve Front Side Right Corner(FSRC), where the FSRC on the Right face.
// int LSRCFormula1[8] = {U,F,Ui,Fi,Ui,Li,U,L};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Left face.
// int LSRCFormula2[8] = {Ui,Li,U,L,U,F,Ui,Fi};    //Solve Left Side Right Corner(LSRC), where the LSRC on the Front face.
// int BSRCFormula1[8] = {U,L,Ui,Li,Ui,Bi,U,B};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Back face.
// int BSRCFormula2[8] = {Ui,Bi,U,B,U,L,Ui,Li};    //Solve Back Side Right Corner(BSRC), where the BSRC on the Left face.
// int RSRCFormula1[8] = {U,B,Ui,Bi,Ui,Ri,U,R};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Right face.
// int RSRCFormula2[8] = {Ui,Ri,U,R,U,B,Ui,Bi};    //Solve Right Side Right Corner(RSRC), where the RSRC on the Back face.

// int *formulaPtr[] = {FSRCFormula1,FSRCFormula2,LSRCFormula1,LSRCFormula2,BSRCFormula1,BSRCFormula2,RSRCFormula1,RSRCFormula2};

/***************Side Corner formula***************************************/
int formulaRW[1] = {U};
int formulaBW[1] = {U};
int formulaOW[1] = {U};
int formulaGW[1] = {U};

int formulaBR[10] = {U,U,F,Ui,Fi,Ui,Li,U,L,U};        //FrontValue[1] is RED and UpValue[7] is BLUE
int formulaGR[10] = {U,Ui,Bi,U,B,U,L,Ui,Li,U};        //FrontValue[1] is RED and UpValue[7] is GREEN

int formulaRB[10] = {Ui,Li,U,L,U,F,Ui,Fi,U,U};          //FrontValue[1] is BLUE and UpValue[7] is RED
int formulaOB[10] = {U,R,Ui,Ri,Ui,Fi,U,F,U,U};          //FrontValue[1] is BLUE and UpValue[7] is ORANGE

int formulaBO[10] = {Ui,Ui,Fi,U,F,U,R,Ui,Ri,U};       //FrontValue[1] is ORANGE and UpValue[7] is BLUE
int formulaGO[10] = {Ui,U,B,Ui,Bi,Ui,Ri,U,R,U};       //FrontValue[1] is ORANGE and UpValue[7] is GREEN

int formulaRG[10] = {U,U,U,L,Ui,Li,Ui,Bi,U,B};      //FrontValue[1] is GREEN and UpValue[7] is RED
int formulaOG[10] = {U,U,Ui,Ri,U,R,U,B,Ui,Bi};      //FrontValue[1] is GREEN and UpValue[7] is ORANGE

int *formulaWPtr[6] = {NULL,formulaRW,formulaBW,formulaOW,NULL,formulaGW};
int *formulaRPtr[6] = {NULL,NULL,formulaBR,NULL,NULL,formulaGR};
int *formulaBPtr[6] = {NULL,formulaRB,NULL,formulaOB,NULL,NULL};
int *formulaOPtr[6] = {NULL,NULL,formulaBO,NULL,NULL,formulaGO};
int *formulaGPtr[6] = {NULL,formulaRG,NULL,formulaOG,NULL,NULL};

int *formulaForRandom[8] = {formulaBR,formulaGR,formulaRB,formulaOB,formulaBO,formulaGO,formulaRG,formulaOG};

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
 * |topFormula4			 			 topFormula5																				 |
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
int topFormula4[7] = {U,F,R,U,Ri,Ui,Fi};
int topFormula5[6] = {F,R,U,Ri,Ui,Fi};

int *ptrTopFormula[] = {topFormula0,topFormula1,topFormula2,topFormula3,topFormula4,topFormula5};

//××××××××××××××Top Face Corner Solver×××××××××××××××××××××××××××××××××××××××/
int topFaceCornerFormula[8]={R,U,Ri,U,R,U,U,Ri};					//solve the top face corner only. Ignore the location of the top corner.

/***************Top corner correct sequence***********************************************/
int topAcorrect[2] = {cR,cG}; //1 5
int topBcorrect[2] = {cG,cO}; //5 3
int topCcorrect[2] = {cB,cR}; //2 1
int topDcorrect[2] = {cO,cB}; //3 2

int *topCornerCorrect[4] = {topAcorrect,topBcorrect,topCcorrect,topDcorrect};
	
/**********************Top Corner Solver***************************/
int topCornerFormula1[13] = {Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui};
int topCornerFormula2[15] = {U,Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui,Ui};
int topCornerFormula3[29] = {Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui,U,U,Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui,Ui};
int topCornerFormula4[15] = {Ui,Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui,U};
int topCornerFormula5[17] = {Ui,Ui,Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,Ui,U,U};
int topCornerFormula6[25] = {Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R,U,Ri,F,Ri,B,B,R,Fi,Ri,B,B,R,R};

int *ptrTopCornerFormula[7] = {NULL,topCornerFormula1,topCornerFormula2,topCornerFormula3,topCornerFormula4,topCornerFormula5,topCornerFormula6};
int topCornerFormulaLength[7] = {0,13,15,29,15,17,25};

/****************Top side Formula*****************************************/
int topSideCorrect[4] = {cR,cB,cO,cG};

int topSideFormula0[12] = {R,R,U,F,Bi,R,R,Fi,B,U,R,R};				//Left side is correct
int topSideFormula1[12] = {R,R,Ui,F,Bi,R,R,Fi,B,Ui,R,R};
int topSideFormula2[12] = {B,B,U,R,Li,B,B,Ri,L,U,B,B};				//Front side is correct
int topSideFormula3[12] = {B,B,Ui,R,Li,B,B,Ri,L,Ui,B,B};
int topSideFormula4[12] = {L,L,U,B,Fi,L,L,Bi,F,U,L,L};				//Right side is correct
int topSideFormula5[12] = {L,L,Ui,B,Fi,L,L,Bi,F,Ui,L,L};	
int topSideFormula6[12] = {F,F,U,L,Ri,F,F,Li,R,U,F,F};				//Back side is correct
int topSideFormula7[12] = {F,F,Ui,L,Ri,F,F,Li,R,Ui,F,F};

int *ptrTopSideFormula0[2] = {topSideFormula0,topSideFormula1};
int *ptrTopSideFormula1[2] = {topSideFormula2,topSideFormula3};
int *ptrTopSideFormula2[2] = {topSideFormula4,topSideFormula5};
int *ptrTopSideFormula3[2] = {topSideFormula6,topSideFormula7};

int **ptrPtrTopSideFormula[4] = {ptrTopSideFormula0,ptrTopSideFormula1,ptrTopSideFormula2,ptrTopSideFormula3};
	
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
  int sideSequence[24] = {cube->upFace->faceValue[3],cube->upFace->faceValue[7],cube->upFace->faceValue[5],cube->upFace->faceValue[1],
													cube->leftFace->faceValue[3],cube->leftFace->faceValue[7],cube->leftFace->faceValue[5],cube->leftFace->faceValue[1],
													cube->frontFace->faceValue[3],cube->frontFace->faceValue[7],cube->frontFace->faceValue[5],cube->frontFace->faceValue[1],
													cube->rightFace->faceValue[3],cube->rightFace->faceValue[7],cube->rightFace->faceValue[5],cube->rightFace->faceValue[1],
													cube->downFace->faceValue[3],cube->downFace->faceValue[7],cube->downFace->faceValue[5],cube->downFace->faceValue[1],
													cube->backFace->faceValue[3],cube->backFace->faceValue[7],cube->backFace->faceValue[5],cube->backFace->faceValue[1]};
  int sideRespectiveSequence[24] = {cube->leftFace->faceValue[1],cube->frontFace->faceValue[1],cube->rightFace->faceValue[5],cube->backFace->faceValue[7],
																		cube->backFace->faceValue[3],cube->downFace->faceValue[3],cube->frontFace->faceValue[3],cube->upFace->faceValue[3],
																		cube->leftFace->faceValue[5],cube->downFace->faceValue[1],cube->rightFace->faceValue[3],cube->upFace->faceValue[7],
																		cube->frontFace->faceValue[5],cube->downFace->faceValue[5],cube->backFace->faceValue[5],cube->upFace->faceValue[5],
																		cube->leftFace->faceValue[7],cube->backFace->faceValue[1],cube->rightFace->faceValue[7],cube->frontFace->faceValue[7],
																		cube->leftFace->faceValue[3],cube->upFace->faceValue[1],cube->rightFace->faceValue[5],cube->downFace->faceValue[7]};
	int i = 0;
	while(i<24){
		if(sideSequence[i]==cY){
			
		}
	}
}

void sideCornerSolver(Cube *cube){
	int *formula;
	int **ptrToPtr;
	int count = 0;
	int i = 0;
	int sideCornerSequence[8] = {cube->upFace->faceValue[3],cube->leftFace->faceValue[1],cube->upFace->faceValue[7],cube->frontFace->faceValue[1],
															cube->upFace->faceValue[5],cube->rightFace->faceValue[1],cube->upFace->faceValue[1],cube->backFace->faceValue[7]};
	while(i<8){
		if(sideCornerSequence[i]==cW)
			count++;
		i++;
	}
	i = 0;
	if(count<4){
		while(cube->frontFace->faceValue[1]==cW ||cube->upFace->faceValue[7]==cW)
			fullRotation(cube,U);
		ptrToPtr = formulaPtrPtr[cube->frontFace->faceValue[1]];
		formula = ptrToPtr[cube->upFace->faceValue[7]];
	}
	else
		formula = formulaForRandom[rand()%8];
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
  }
}

 /*Top face side solver solve the cube to the following result.
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
void topFaceSideSolver(Cube *cube, int formulaNo, int arrSize){
	int *upFormula = ptrTopFormula[formulaNo]; 
	int i = 0;
  while(i<arrSize){
    fullRotation(cube,upFormula[i]);
    i++;
  }
}


void fullTopFaceSideSolver(Cube *cube){
	int upFaceCrossValue[4] = {cube->upFace->faceValue[1],cube->upFace->faceValue[5],
														 cube->upFace->faceValue[7],cube->upFace->faceValue[3]};
	int i = 0;
	int count = 0;
	int pattern = 0;
	while(i<4){
		if(upFaceCrossValue[i] == 0){
			pattern = pattern + i;
			count ++;
			if(i == 3 && pattern == 3)
				pattern *= 2;
		}
		i++;
	}
	if(count != 4){												//if count == 4, top face side is all white.
		switch(pattern){
			case pattern0:
				topFaceSideSolver(cube,0,6);
				fullTopFaceSideSolver(cube);
				break;
			case pattern1:
				topFaceSideSolver(cube,3,7);
				break;
			case pattern2:
				topFaceSideSolver(cube,4,7);
				break;
			case pattern3:
				topFaceSideSolver(cube,2,8);
				break;
			case pattern4:
				topFaceSideSolver(cube,5,6);
				break;
			case pattern5:
				topFaceSideSolver(cube,1,7);
				break;
			case pattern6:
				topFaceSideSolver(cube,0,6);
				break;
		}
	}
}
 /*Top face corner solver solve the cube to the following result.
				 W W W              X: any color
         W W W              R: Red color
         W W W              B: Blue color
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
void topFaceCornerSolver(Cube *cube){
	int upCornerValue[4] = {cube->upFace->faceValue[0],cube->upFace->faceValue[2],
														 cube->upFace->faceValue[6],cube->upFace->faceValue[8]};
	int i = 0;
	int j = 0;
	int count = 0;
	while(i<4){
		if(upCornerValue[i] == 0)
			count++;
		i++;
	}
	if(count == 1){
		while(cube->upFace->faceValue[6]!= 0)
			fullRotation(cube,U);
	}
	else{
		while(cube->leftFace->faceValue[2]!=0)
			fullRotation(cube,U);
	}
	while(j<8){
		fullRotation(cube,topFaceCornerFormula[j]);
		j++;
	}
}

int topFaceDetermination(Cube *cube){									//if topFace is all White color
	int i = 0;																					//			W W W
	int count = 0;																			//			W W W
	while(i<9){																					//			W W W
		if(cube->upFace->faceValue[i]==0)									//return 1. Else return 0.
			count++;
		i++;
	}
	if(count == 9)
		return 1;
	else
		return 0;
}

void fullTopFaceCornerSolver(Cube *cube){
	int topAllWhite = topFaceDetermination(cube);
	while(topAllWhite != 1){
		topFaceCornerSolver(cube);
		topAllWhite = topFaceDetermination(cube);
	}
}

 /*Top corner solver solve the cube to the following result.
				 W W W              X: any color
         W W W              R: Red color
         W W W              B: Blue color
														O: Orange color
 R X R   B X B   O X O      Y: Yellow color
 R R R   B B B   O O O      G: Green color
 R R R   B B B   O O O      W: White color
 
         Y Y Y              
         Y Y Y              
         Y Y Y              

         G G G              
         G G G              
         G X G
*/

/************top corner solver **************************
 *	solve the top corner to the correct sequence.				*
 ********************************************************/
//		Correct Sequence.
//		 ___________
//		| A |		|	B |
//		|___|___|___|
//		|		|   |   |
//		|___|___|___|
//		| C |   | D |
//		|___|___|___|

void topCornerSolver(Cube *cube, int formulaNo){
	int *topFormula = ptrTopCornerFormula[formulaNo];
	int topFormulaArrSize = topCornerFormulaLength[formulaNo];
	int i = 0;
  while(i<topFormulaArrSize){
    fullRotation(cube,topFormula[i]);
    i++;
  }
}

void topCornerFullSolver(Cube *cube){																																	//		 ___________
	int topA[2] = {cube->leftFace->faceValue[0],cube->backFace->faceValue[6]};													//		| A |		|	B |
	int topB[2] = {cube->backFace->faceValue[8],cube->rightFace->faceValue[2]};													//		|___|___|___|
	int topC[2] = {cube->frontFace->faceValue[0],cube->leftFace->faceValue[2]};													//		|		|   |   |
	int topD[2] = {cube->rightFace->faceValue[0],cube->frontFace->faceValue[2]};												//		|___|___|___|
																																																			//		| C |   | D |
	int *topCorner[4] = {topA,topB,topC,topD};																													//		|___|___|___|
	
	int topCornerFormulaNo;
	
	int topCornerSequence[4];
	int i = 0;
	int j = 0;
	int count = 0;
	int topCornerPattern = 0;
	int *actualCorner;
	int *expectedCorner;
	while(j<4){
		expectedCorner = topCornerCorrect[j];
		actualCorner = topCorner[j];
		if(actualCorner[0]==expectedCorner[0] && actualCorner[1]==expectedCorner[1])
			count++;
		while(i<4){
			actualCorner = topCorner[i];
			if(actualCorner[0]==expectedCorner[0] && actualCorner[1]==expectedCorner[1])
				topCornerSequence[j] = i;
			i++;
		}
		i = 0;
		if(topCornerSequence[j] == j){
			topCornerPattern += j;
			if(topCornerPattern == 3 && j == 3)
				topCornerPattern *= 2;
		}
		j++;
	}
	if(count!=2){
		fullRotation(cube,U);
		topCornerFullSolver(cube);
	}
	else{
		while(i<7){
			if(topCornerPattern == i){
				topCornerFormulaNo = i;
			}
			i++;
		}
		topCornerSolver(cube, topCornerFormulaNo);
	}
}

//××××××××××××××××× Top side Solver××××××××××××××××××××××××××××××××××××/
// This is the final step to solve the rubik's cube
// this solver solve the top side of the cube
// and the cube is done.


void topSideSolver(Cube *cube){
	int topSide[4] = {cube->leftFace->faceValue[1],cube->frontFace->faceValue[1],cube->rightFace->faceValue[1],cube->backFace->faceValue[7]};
	int topSideSequence[4], topPattern[3];
	int **ptrPtrFormula;
	int *ptrFormula;
	int i = 0;
	int j = 0;
	int count = 0;
	while(i<4){
		if(topSide[i] == topSideCorrect[i]){
			count++;
			ptrPtrFormula = ptrPtrTopSideFormula[i];
		}
		while(j<4){
			if(topSide[i]==topSideCorrect[j]){
				topSideSequence[i] = j;
			}
			j++;
		}
		j=0;
		i++;
	}
	i = 0;
	if(count == 0){
		while(i<12){
			fullRotation(cube,topSideFormula0[i]);
			i++;
		}	
		topSideSolver(cube);
	}
	else{
		while(i<3){
			if(topSideSequence[j]==j){
				j++;
			}
			topPattern[i]=topSideSequence[j];
			j++;
			i++;
		}
		if(topPattern[0]>topPattern[1]){
			ptrFormula = ptrPtrFormula[0];
		}
		else 
			ptrFormula = ptrPtrFormula[1];
		i = 0;
		while(i<12){
			fullRotation(cube,ptrFormula[i]);
			i++;
		}	
	}
}


void fullSolver(Cube *cube){
	fullSideCornerSolver(cube);
	fullTopFaceSideSolver(cube);
	fullTopFaceCornerSolver(cube);
	topCornerFullSolver(cube);
	topSideSolver(cube);
}



