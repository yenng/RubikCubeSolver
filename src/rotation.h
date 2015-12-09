#ifndef rotation_H
#define rotation_H

#include "cube.h"

#define	U		0		//top side rotate clockwise
#define	Ui	1		//top side rotate anti-clockwise
#define	L		2		//left side rotate clockwise
#define	Li	3		//left side rotate anti-clockwise
#define	F		4		//front side rotate clockwise
#define	Fi	5		//front side rotate anti-clockwise
#define	R		6		//right side rotate clockwise
#define	Ri	7		//right side rotate anti-clockwise
#define	D		8		//bottom side rotate clockwise
#define	Di	9		//bottom side rotate anti-clockwise
#define	B		10		//back side rotate clockwise
#define	Bi	11		//back side rotate anti-clockwise

#define CLOCKWISE			0
#define ANTICLOCKWISE	1

typedef struct Rotate_t Rotate;
struct Rotate_t{
	Face *face;
	int direction;      //CLOCKWISE or ANTICLOCKWISE
};

void faceRotation(int direction, Face *face);
Rotate *createRotation(Cube *cube, int rotation);
void faceSideRotation(Cube *cube, Rotate *rotate);
void fullRotation(Cube *cube, Rotate *rotate);
#endif // rotation_H
