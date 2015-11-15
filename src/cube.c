#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

Face createFace(int type, char value[9]){
	Face	cubeFace;
	cubeFace.faceType = type;
	cubeFace.topSide = NULL;
	cubeFace.leftSide = NULL;
	cubeFace.rightSide = NULL;
	cubeFace.bottomSide = NULL;
	int i = 0;
	while(i <9){
		cubeFace.faceValue[i] = value[i];
	  i++;
	}
	
	return cubeFace;
}

void displayFace(Face cubeFace){
	int i = 0;
	switch(cubeFace.faceType){
		case FRONT:
			printf("FRONT:\n");
			break;
		case TOP:
			printf("TOP:\n");
			break;
		case LEFT:
			printf("LEFT:\n");
			break;
		case RIGHT:
			printf("RIGHT:\n");
			break;
		case BOTTOM:
			printf("BOTTOM:\n");
			break;
		case BACK:
			printf("BACK:\n");
			break;
	}
	while(i<9){
		printf("%c ", cubeFace.faceValue[i]);
		if ((i+1)%3==0){
			printf("\n");
		}
		i++;
	}
}