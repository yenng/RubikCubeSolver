#include "solver.h"
#include "rotation.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
/***************Base Side Formula To solve the base into cross shape**********************************
 *
 *				Down Face													Down Face
 *				___________											 ___________
 *			 | X | X | X |										| X | Y | X |
 *			 |___|___|___|										|___|___|___|
 *			 | X | Y | X |			\\\\\					| Y | Y | Y |
 *			 |___|___|___|			/////					|___|___|___|
 *			 | X | X | X |										| X | Y | X |
 *			 |___|___|___|										|___|___|___|
 *
 ************************************************************************************************/
//formula when one of side of up face is yellow.												UP face
int baseFormulaUp0B[] = {Ui,F,F,EOA};									//								 x x x
int baseFormulaUp0G[] = {U,B,B,EOA};									//								 Y x x		
int baseFormulaUp0R[] = {L,L,EOA};										//								 x x x
int baseFormulaUp0O[] = {U,U,R,R,EOA};								//
								 
int baseFormulaUp1B[] = {F,F,EOA};										//								 x x x
int baseFormulaUp1G[] = {U,U,B,B,EOA};								//								 x x x
int baseFormulaUp1R[] = {U,L,L,EOA};									//								 x Y x
int baseFormulaUp1O[] = {Ui,R,R,EOA};									//	
							 
int baseFormulaUp2B[] = {U,F,F,EOA};									//								 x x x
int baseFormulaUp2G[] = {Ui,B,B,EOA};									//								 x x Y
int baseFormulaUp2R[] = {U,U,L,L,EOA};								//								 x x x
int baseFormulaUp2O[] = {R,R,EOA};										//	
							 
int baseFormulaUp3B[] = {U,U,F,F,EOA};								//								 x Y x
int baseFormulaUp3G[] = {B,B,EOA};										//								 x x x
int baseFormulaUp3R[] = {Ui,L,L,EOA};									//								 x x x
int baseFormulaUp3O[] = {U,R,R,EOA};									//

//formula when one of side of left face is yellow.
int baseFormulaLeft0B[] = {Di,L,L,D,F,EOA};						
int baseFormulaLeft0G[] = {B,EOA};
int baseFormulaLeft0R[] = {L,U,B,Li,Bi,EOA};
int baseFormulaLeft0O[] = {D,B,Di,EOA};

int baseFormulaLeft1B[] = {Li,Fi,EOA};
int baseFormulaLeft1G[] = {L,B,EOA};
int baseFormulaLeft1R[] = {Li,D,F,Di,EOA};
int baseFormulaLeft1O[] = {Li,Di,Fi,D,EOA};

int baseFormulaLeft2B[] = {Fi,EOA};
int baseFormulaLeft2G[] = {D,D,Fi,D,D,EOA};
int baseFormulaLeft2R[] = {D,Fi,Di,EOA};
int baseFormulaLeft2O[] = {Di,Fi,D,EOA};

int baseFormulaLeft3B[] = {Di,L,D,Fi,EOA};
int baseFormulaLeft3G[] = {D,Li,Di,B,EOA};
int baseFormulaLeft3R[] = {L,D,Fi,Di,EOA};
int baseFormulaLeft3O[] = {Ui,Di,F,D,Ri,EOA};

//formula when one of side of front face is yellow.
int baseFormulaFront0B[] = {Di,L,D,EOA};
int baseFormulaFront0G[] = {D,L,Di,EOA};
int baseFormulaFront0R[] = {L,EOA};
int baseFormulaFront0O[] = {Di,F,F,D,Ri,EOA};

int baseFormulaFront1B[] = {Fi,D,Ri,Di,EOA};
int baseFormulaFront1G[] = {Fi,Di,Ri,D,EOA};
int baseFormulaFront1R[] = {F,L,EOA};
int baseFormulaFront1O[] = {Fi,Ri,EOA};

int baseFormulaFront2B[] = {D,Ri,Di,EOA};
int baseFormulaFront2G[] = {Di,Ri,D,EOA};
int baseFormulaFront2R[] = {D,D,Ri,Di,Di,EOA};
int baseFormulaFront2O[] = {Ri,EOA};

int baseFormulaFront3B[] = {F,D,Ri,Di,EOA};
int baseFormulaFront3G[] = {Ui,Di,R,D,Bi,EOA};
int baseFormulaFront3R[] = {D,Fi,Di,L,EOA};
int baseFormulaFront3O[] = {Di,F,D,Ri,EOA};

//formula when one of side of right face is yellow.
int baseFormulaRight0B[] = {F,EOA};
int baseFormulaRight0G[] = {D,D,F,D,D,EOA};
int baseFormulaRight0R[] = {D,F,Di,EOA};
int baseFormulaRight0O[] = {Di,F,D,EOA};

int baseFormulaRight1B[] = {R,F,EOA};
int baseFormulaRight1G[] = {Ri,Bi,EOA};
int baseFormulaRight1R[] = {R,D,F,Di,EOA};
int baseFormulaRight1O[] = {Ri,D,Bi,Di,EOA};

int baseFormulaRight2B[] = {D,D,Bi,D,D,EOA};
int baseFormulaRight2G[] = {Bi,EOA};
int baseFormulaRight2R[] = {Di,Bi,D,EOA};
int baseFormulaRight2O[] = {D,Bi,Di,EOA};

int baseFormulaRight3B[] = {D,Ri,Di,F,EOA};
int baseFormulaRight3G[] = {Di,R,D,Bi,EOA};
int baseFormulaRight3R[] = {U,D,Fi,Di,L,EOA};
int baseFormulaRight3O[] = {R,D,Bi,Di,EOA};

//formula when one of side of back face is yellow.
int baseFormulaBack0B[] = {D,R,Di,EOA};
int baseFormulaBack0G[] = {Di,R,D,EOA};
int baseFormulaBack0R[] = {D,D,R,Di,Di,EOA};
int baseFormulaBack0O[] = {R,EOA};

int baseFormulaBack1B[] = {B,D,R,Di,EOA};
int baseFormulaBack1G[] = {Di,R,D,EOA};
int baseFormulaBack1R[] = {Bi,Di,B,D,EOA};
int baseFormulaBack1O[] = {B,R,EOA};

int baseFormulaBack2B[] = {Di,Li,D,EOA};
int baseFormulaBack2G[] = {D,Li,Di,EOA};
int baseFormulaBack2R[] = {Li,EOA};
int baseFormulaBack2O[] = {D,D,Li,Di,Di,EOA};

int baseFormulaBack3B[] = {Ui,Di,L,D,Fi,EOA};
int baseFormulaBack3G[] = {B,D,Li,Di,EOA};
int baseFormulaBack3R[] = {Di,B,D,Li,EOA};
int baseFormulaBack3O[] = {D,Bi,Di,R,EOA};

//formula when one of side of down face is yellow.
int baseFormulaDown0B[] = {D,F,Di,Fi,EOA};
int baseFormulaDown0G[] = {Di,Bi,D,B,EOA};
int baseFormulaDown0R[] = {EOA};
int baseFormulaDown0O[] = {D,D,R,D,D,Ri,EOA};

int baseFormulaDown1B[] = {B,B,U,U,F,F,EOA};
int baseFormulaDown1G[] = {EOA};
int baseFormulaDown1R[] = {D,Li,Di,L,EOA};
int baseFormulaDown1O[] = {Di,Ri,D,R,EOA};

int baseFormulaDown2B[] = {Di,Fi,D,F,EOA};
int baseFormulaDown2G[] = {D,Bi,Di,B,EOA};
int baseFormulaDown2R[] = {R,R,U,U,L,L,EOA};
int baseFormulaDown2O[] = {EOA};

int baseFormulaDown3B[] = {EOA};
int baseFormulaDown3G[] = {F,F,U,U,B,B,EOA};
int baseFormulaDown3R[] = {Di,Li,D,L,EOA};
int baseFormulaDown3O[] = {D,R,Di,Ri,EOA};

//base side Formula pointer declaration
int *baseFormulaUp0[] = {NULL,baseFormulaUp0R,baseFormulaUp0B,baseFormulaUp0O,NULL,baseFormulaUp0G};
int *baseFormulaUp1[] = {NULL,baseFormulaUp1R,baseFormulaUp1B,baseFormulaUp1O,NULL,baseFormulaUp1G};
int *baseFormulaUp2[] = {NULL,baseFormulaUp2R,baseFormulaUp2B,baseFormulaUp2O,NULL,baseFormulaUp2G};
int *baseFormulaUp3[] = {NULL,baseFormulaUp3R,baseFormulaUp3B,baseFormulaUp3O,NULL,baseFormulaUp3G};

int *baseFormulaLeft0[] = {NULL,baseFormulaLeft0R,baseFormulaLeft0B,baseFormulaLeft0O,NULL,baseFormulaLeft0G};
int *baseFormulaLeft1[] = {NULL,baseFormulaLeft1R,baseFormulaLeft1B,baseFormulaLeft1O,NULL,baseFormulaLeft1G};
int *baseFormulaLeft2[] = {NULL,baseFormulaLeft2R,baseFormulaLeft2B,baseFormulaLeft2O,NULL,baseFormulaLeft2G};
int *baseFormulaLeft3[] = {NULL,baseFormulaLeft3R,baseFormulaLeft3B,baseFormulaLeft3O,NULL,baseFormulaLeft3G};

int *baseFormulaFront0[] = {NULL,baseFormulaFront0R,baseFormulaFront0B,baseFormulaFront0O,NULL,baseFormulaFront0G};
int *baseFormulaFront1[] = {NULL,baseFormulaFront1R,baseFormulaFront1B,baseFormulaFront1O,NULL,baseFormulaFront1G};
int *baseFormulaFront2[] = {NULL,baseFormulaFront2R,baseFormulaFront2B,baseFormulaFront2O,NULL,baseFormulaFront2G};
int *baseFormulaFront3[] = {NULL,baseFormulaFront3R,baseFormulaFront3B,baseFormulaFront3O,NULL,baseFormulaFront3G};

int *baseFormulaRight0[] = {NULL,baseFormulaRight0R,baseFormulaRight0B,baseFormulaRight0O,NULL,baseFormulaRight0G};
int *baseFormulaRight1[] = {NULL,baseFormulaRight1R,baseFormulaRight1B,baseFormulaRight1O,NULL,baseFormulaRight1G};
int *baseFormulaRight2[] = {NULL,baseFormulaRight2R,baseFormulaRight2B,baseFormulaRight2O,NULL,baseFormulaRight2G};
int *baseFormulaRight3[] = {NULL,baseFormulaRight3R,baseFormulaRight3B,baseFormulaRight3O,NULL,baseFormulaRight3G};

int *baseFormulaBack0[] = {NULL,baseFormulaBack0R,baseFormulaBack0B,baseFormulaBack0O,NULL,baseFormulaBack0G};
int *baseFormulaBack1[] = {NULL,baseFormulaBack1R,baseFormulaBack1B,baseFormulaBack1O,NULL,baseFormulaBack1G};
int *baseFormulaBack2[] = {NULL,baseFormulaBack2R,baseFormulaBack2B,baseFormulaBack2O,NULL,baseFormulaBack2G};
int *baseFormulaBack3[] = {NULL,baseFormulaBack3R,baseFormulaBack3B,baseFormulaBack3O,NULL,baseFormulaBack3G};

int *baseFormulaDown0[] = {NULL,baseFormulaDown0R,baseFormulaDown0B,baseFormulaDown0O,NULL,baseFormulaDown0G};
int *baseFormulaDown1[] = {NULL,baseFormulaDown1R,baseFormulaDown1B,baseFormulaDown1O,NULL,baseFormulaDown1G};
int *baseFormulaDown2[] = {NULL,baseFormulaDown2R,baseFormulaDown2B,baseFormulaDown2O,NULL,baseFormulaDown2G};
int *baseFormulaDown3[] = {NULL,baseFormulaDown3R,baseFormulaDown3B,baseFormulaDown3O,NULL,baseFormulaDown3G};

int **ptrToPtrFormula[24] = {baseFormulaUp0,baseFormulaUp1,baseFormulaUp2,baseFormulaUp3,baseFormulaLeft0,baseFormulaLeft1,baseFormulaLeft2,baseFormulaLeft3,
														 baseFormulaFront0,baseFormulaFront1,baseFormulaFront2,baseFormulaFront3,baseFormulaRight0,baseFormulaRight1,baseFormulaRight2,baseFormulaRight3,
														 baseFormulaDown0,baseFormulaDown1,baseFormulaDown2,baseFormulaDown3,baseFormulaBack0,baseFormulaBack1,baseFormulaBack2,baseFormulaBack3};
/*******************End of base Side Formula******************************/

/*******************Base corner Formula******************************/
 /*      X X X          	      	   X X X              
         X X X           		   			 X X X              	R = Red
         X X X          	   			   X X X              	B = Blue
																													O = Orange
 X X X   X X X   X X X   	   X X X   X X X   X X X      	G = Green	
 X R X   X B X   X O X  >> 	 X R X   X B X   X O X      	Y = Yellow
 X R X   X B X   X O X  	 	 R R R   B B B   O O O      	X = unknown
 
         X Y X            					 Y Y Y              
         Y Y Y              				 Y Y Y              
         X Y X            					 Y Y Y              
	
         X G X	            				 G G G              
         X G X  	         					 X G X              
         X X X    	   							 X X X
*/
int baseCornerFormula0[] = {Fi,Ui,F,EOA};
int baseCornerFormula1[] = {R,U,Ri,EOA};
int baseCornerFormula2[] = {R,U,U,Ri,Ui,R,U,Ri,EOA};

int *ptrBaseCornerFormula[] = {baseCornerFormula0,baseCornerFormula1,baseCornerFormula2};




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
void baseSideSolver(Cube *cube, int print){
  int sideSequence[24] = {cube->upFace->faceValue[3],cube->upFace->faceValue[7],cube->upFace->faceValue[5],cube->upFace->faceValue[1],
													cube->leftFace->faceValue[3],cube->leftFace->faceValue[7],cube->leftFace->faceValue[5],cube->leftFace->faceValue[1],
													cube->frontFace->faceValue[3],cube->frontFace->faceValue[7],cube->frontFace->faceValue[5],cube->frontFace->faceValue[1],
													cube->rightFace->faceValue[3],cube->rightFace->faceValue[7],cube->rightFace->faceValue[5],cube->rightFace->faceValue[1],
													cube->downFace->faceValue[3],cube->downFace->faceValue[7],cube->downFace->faceValue[5],cube->downFace->faceValue[1],
													cube->backFace->faceValue[5],cube->backFace->faceValue[1],cube->backFace->faceValue[3],cube->backFace->faceValue[7]};
  int sideRespectiveSequence[24] = {cube->leftFace->faceValue[1],cube->frontFace->faceValue[1],cube->rightFace->faceValue[1],cube->backFace->faceValue[7],
																		cube->backFace->faceValue[3],cube->downFace->faceValue[3],cube->frontFace->faceValue[3],cube->upFace->faceValue[3],
																		cube->leftFace->faceValue[5],cube->downFace->faceValue[1],cube->rightFace->faceValue[3],cube->upFace->faceValue[7],
																		cube->frontFace->faceValue[5],cube->downFace->faceValue[5],cube->backFace->faceValue[5],cube->upFace->faceValue[5],
																		cube->leftFace->faceValue[7],cube->backFace->faceValue[1],cube->rightFace->faceValue[7],cube->frontFace->faceValue[7],
																		cube->rightFace->faceValue[5],cube->downFace->faceValue[7],cube->leftFace->faceValue[3],cube->upFace->faceValue[1]};
	int i = 0;
	int j = 0;
	int **ptrPtrFormula;
	int *ptrFormula;
	while(sideSequence[i]!=cY)
		i++;
	while((i==16&&sideRespectiveSequence[i]==1)||(i==17&&sideRespectiveSequence[i]==5)||(i==18&&sideRespectiveSequence[i]==3)||(i==19&&sideRespectiveSequence[i]==2)){
		i++;
		while(sideSequence[i]!=cY)
			i++;		
	}
	// printf("i = %d	Side = %d	SideSequnce = %d\n",i,sideRespectiveSequence[i],sideSequence[i]);
	ptrPtrFormula = ptrToPtrFormula[i];
	ptrFormula = ptrPtrFormula[sideRespectiveSequence[i]];
	while(ptrFormula[j] != EOA){
		fullRotation(cube,ptrFormula[j], print);
		// printf("rotation = %d\n", ptrFormula[j]);
		j++;
	}
}

void baseSideFullSolver(Cube *cube, int print){
	while(cube->downFace->faceValue[1] != cY || cube->downFace->faceValue[3] != cY || cube->downFace->faceValue[5] != cY || cube->downFace->faceValue[7] != cY){
		baseSideSolver(cube, print);
	}
}

void baseCornerSolver(Cube *cube, int print){
	int noTurn = 0;
	while(cube->frontFace->faceValue[2]!=cY&&cube->rightFace->faceValue[0]!=cY&&cube->upFace->faceValue[8]!=cY&&noTurn<4){
		fullRotation(cube,U, print);
		noTurn++;
	}
	int frontTopRightCorner[3] = {cube->frontFace->faceValue[2],cube->rightFace->faceValue[0],cube->upFace->faceValue[8]};
	int respectiveColor[2];
	int i = 0;
	int j = 0;
	int *ptrTobaseCornerFormula, pattern;
	if(noTurn>=4){
		ptrTobaseCornerFormula = ptrBaseCornerFormula[rand()%3];
		while(i<(rand()%4)){
			fullRotation(cube,Di, print);
			i++;
		}	
		i=0;
	}
	else{
		noTurn=0;
		while(i<3){
			if(frontTopRightCorner[i]==cY)
				pattern = i;
			else{
				respectiveColor[j] = frontTopRightCorner[i];
				j++;
			}
			i++; 
		}
		j = 0;
		while((respectiveColor[0]!=cube->frontFace->faceValue[7]||respectiveColor[1]!=cube->rightFace->faceValue[7])&&
					(respectiveColor[1]!=cube->frontFace->faceValue[7]||respectiveColor[0]!=cube->rightFace->faceValue[7])){
						fullRotation(cube,D,print);
						noTurn++;
					}
		ptrTobaseCornerFormula = ptrBaseCornerFormula[pattern];
	}
	while(ptrTobaseCornerFormula[j] != EOA){
		fullRotation(cube,ptrTobaseCornerFormula[j],print);
		j++;
	}
	while(noTurn>0){
		fullRotation(cube,Di,print);
		noTurn--;
	}
}

void baseCornerFullSolver(Cube *cube, int print){
	int cornerCorrectSequence[8] = {cR,cR,cB,cB,cO,cO,cG,cG};
	int i = 0;
	while(cube->downFace->faceValue[0] != cY || cube->downFace->faceValue[2] != cY || cube->downFace->faceValue[6] != cY || cube->downFace->faceValue[8] != cY){
		baseCornerSolver(cube, print);
	}
	int cornerCorrespondingSequence[8] = {cube->leftFace->faceValue[6],cube->leftFace->faceValue[8],cube->frontFace->faceValue[6],cube->frontFace->faceValue[8],
																			 cube->rightFace->faceValue[6],cube->rightFace->faceValue[8],cube->backFace->faceValue[2],cube->backFace->faceValue[0]};
	
	while(i<8){
		if(cornerCorrespondingSequence[i]!=cornerCorrectSequence[i])
			baseCornerFullSolver(cube, print);
		i++;
	}
}


void sideCornerSolver(Cube *cube, int print){
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
			fullRotation(cube,U, print);
		ptrToPtr = formulaPtrPtr[cube->frontFace->faceValue[1]];
		formula = ptrToPtr[cube->upFace->faceValue[7]];
	}
	else
		formula = formulaForRandom[rand()%8];
	while(i<(10)){
		fullRotation(cube,formula[i], print);
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
void fullSideCornerSolver(Cube *cube, int print){
  while(cube->frontFace->faceValue[3] != cB || cube->leftFace->faceValue[5]  != cR ||
        cube->frontFace->faceValue[5] != cB || cube->rightFace->faceValue[3] != cO || 
        cube->rightFace->faceValue[5] != cO || cube->backFace->faceValue[5]  != cG ||
        cube->backFace->faceValue[3]  != cG || cube->leftFace->faceValue[3]  != cR){
    sideCornerSolver(cube, print);
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
void topFaceSideSolver(Cube *cube, int formulaNo, int arrSize, int print){
	int *upFormula = ptrTopFormula[formulaNo]; 
	int i = 0;
  while(i<arrSize){
    fullRotation(cube,upFormula[i], print);
    i++;
  }
}


void fullTopFaceSideSolver(Cube *cube, int print){
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
				topFaceSideSolver(cube,0,6, print);
				fullTopFaceSideSolver(cube, print);
				break;
			case pattern1:
				topFaceSideSolver(cube,3,7,print);
				break;
			case pattern2:
				topFaceSideSolver(cube,4,7,print);
				break;
			case pattern3:
				topFaceSideSolver(cube,2,8,print);
				break;
			case pattern4:
				topFaceSideSolver(cube,5,6,print);
				break;
			case pattern5:
				topFaceSideSolver(cube,1,7,print);
				break;
			case pattern6:
				topFaceSideSolver(cube,0,6,print);
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
void topFaceCornerSolver(Cube *cube, int print){
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
			fullRotation(cube,U,print);
	}
	else{
		while(cube->leftFace->faceValue[2]!=0)
			fullRotation(cube,U,print);
	}
	while(j<8){
		fullRotation(cube,topFaceCornerFormula[j],print);
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

void fullTopFaceCornerSolver(Cube *cube, int print){
	int topAllWhite = topFaceDetermination(cube);
	while(topAllWhite != 1){
		topFaceCornerSolver(cube,print);
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
/*		Correct Sequence.
			___________
			| A |		|	B |
			|___|___|___|
			|		|   |   |
			|___|___|___|
			| C |   | D |
			|___|___|___|
 */
void topCornerSolver(Cube *cube, int formulaNo, int print){
	int *topFormula = ptrTopCornerFormula[formulaNo];
	int topFormulaArrSize = topCornerFormulaLength[formulaNo];
	int i = 0;
  while(i<topFormulaArrSize){
    fullRotation(cube,topFormula[i],print);
    i++;
  }
}

void topCornerFullSolver(Cube *cube, int print){																											//		 ___________
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
		fullRotation(cube,U,print);
		topCornerFullSolver(cube,print);
	}
	else{
		while(i<7){
			if(topCornerPattern == i){
				topCornerFormulaNo = i;
			}
			i++;
		}
		topCornerSolver(cube, topCornerFormulaNo,print);
	}
}
/******************Top side Solver***********************
 *This is the final step to solve the rubik's cube
 *this solver solve the top side of the cube
 *and the cube is done.
**********************************************************/


void topSideSolver(Cube *cube, int print){
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
			fullRotation(cube,topSideFormula0[i],print);
			i++;
		}	
		topSideSolver(cube,print);
	}
	else if(count != 4){
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
			fullRotation(cube,ptrFormula[i],print);
			i++;
		}	
	}
}


void fullSolver(Cube *cube, int print){
	baseSideFullSolver(cube,print);
	baseCornerFullSolver(cube,print);
	fullSideCornerSolver(cube,print);
	fullTopFaceSideSolver(cube,print);
	fullTopFaceCornerSolver(cube,print);
	topCornerFullSolver(cube,print);
	topSideSolver(cube,print);
}



