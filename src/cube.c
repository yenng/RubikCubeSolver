#include "cube.h"
#include <stdio.h>
#include <stdlib.h>

Face *createFace(int type, int value[9]){
	Face	*cubeFace = malloc(sizeof(Face));
	cubeFace->faceType = type;
	int i = 0;
	while(i <9){
		cubeFace->faceValue[i] = value[i];
	  i++;
	}
	return cubeFace;
}

Cube *createCube(int value[6][9]){
  Face *face[6];
  Cube *cube = malloc(sizeof(Cube));
  int i=0;
  while(i<6){
      face[i] = createFace(i,value[i]);
      i++;
  }
  cube->topFace = face[0];
  cube->leftFace = face[1];
  cube->frontFace = face[2];
  cube->rightFace = face[3];
  cube->bottomFace = face[4];
  cube->backFace = face[5];
  return cube;
}

void displayFace(Face *cubeFace){
	int i = 0;
	switch(cubeFace->faceType){
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
		printf("%d ", cubeFace->faceValue[i]);
		if ((i+1)%3==0){
			printf("\n");
		}
		i++;
	}
}