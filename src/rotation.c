#include "rotation.h"
#include "cube.h"

void faceRotation(int direction, Face *face){
	int faceValue_t[9];
	int i = 0;
	int translationTable1[9] = {6,3,0,7,4,1,8,5,2};				//anti-clockwise
	int translationTable2[9] = {2,5,8,1,4,7,0,3,6};				//clockwise
	if(direction){
		while (i < 9){
			faceValue_t[translationTable1[i]] = face->faceValue[i];
			i++;
		}
	}
	else{
		while (i < 9){
			faceValue_t[translationTable2[i]] = face->faceValue[i];
			i++;
		}
	}
	i = 0;
	while (i < 9){
		face->faceValue[i] = faceValue_t[i];
		i++;
	}
}