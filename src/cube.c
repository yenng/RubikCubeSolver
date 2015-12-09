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
  cube->upFace = face[0];
  cube->leftFace = face[1];
  cube->frontFace = face[2];
  cube->rightFace = face[3];
  cube->downFace = face[4];
  cube->backFace = face[5];
  return cube;
}

void displayFace(Face *cubeFace){
	int i = 0;
	switch(cubeFace->faceType){
		case FRONT:
			printf("FRONT:\n");
			break;
		case UP:
			printf("UP:\n");
			break;
		case LEFT:
			printf("LEFT:\n");
			break;
		case RIGHT:
			printf("RIGHT:\n");
			break;
		case DOWN:
			printf("DOWN:\n");
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

void displayCube(Cube *cube){
  int i = 0;
  while(i<9){
    printf("        %d %d %d \t\t\n", cube->upFace->faceValue[i],cube->upFace->faceValue[i+1],cube->upFace->faceValue[i+2]);
		i+=3;
	}
	printf("\n");
  i = 0;
  while(i<9){
    printf("%d %d %d   %d %d %d   %d %d %d \t\n",
    cube->leftFace->faceValue[i],cube->leftFace->faceValue[i+1],cube->leftFace->faceValue[i+2],
    cube->frontFace->faceValue[i],cube->frontFace->faceValue[i+1],cube->frontFace->faceValue[i+2],
    cube->rightFace->faceValue[i],cube->rightFace->faceValue[i+1],cube->rightFace->faceValue[i+2]);
		i+=3;
  }
	printf("\n");
  i = 0;
  while(i<9){
    printf("        %d %d %d \t\t\n", cube->downFace->faceValue[i],cube->downFace->faceValue[i+1],cube->downFace->faceValue[i+2]);
		i+=3;
	}
	printf("\n");
  i = 0;
  while(i<9){
    printf("        %d %d %d \t\t\n", cube->backFace->faceValue[i],cube->backFace->faceValue[i+1],cube->backFace->faceValue[i+2]);
		i+=3;
	}
}




