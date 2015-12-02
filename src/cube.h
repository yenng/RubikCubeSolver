#ifndef cube_H
#define cube_H
#include <string.h>

/*						 _____
							|			|
							|	 0	|
				 _____|_____|_____
			  |			|			|			|
				|  1	|	 2	|	 3	|
				|_____|_____|_____|
							|			|
							|	 4	|
							|_____|
							|			|
							|	 5	|
							|_____|
							
 */
 /*      0 0 0              
         0 0 0              
         0 0 0              
 
 1 1 1   2 2 2   3 3 3      
 1 1 1   2 2 2   3 3 3      
 1 1 1   2 2 2   3 3 3      
 
         4 4 4              
         4 4 4              
         4 4 4              

         5 5 5              
         5 5 5              
         5 5 5
*/
#define TOP 		0
#define LEFT 		1
#define FRONT 	2
#define RIGHT 	3
#define BOTTOM	4
#define BACK		5

#define cW	 0	//WHITE
#define cR	 1	//RED
#define cB	 2	//BLUE
#define cO	 3	//ORANGE
#define cY	 4	//YELLOW
#define cG	 5	//GREEN


typedef struct Face_t Face;
struct Face_t{
	int faceType;
	int faceValue[9];
};

typedef struct Cube_t Cube;
struct Cube_t{
  Face *topFace;
  Face *leftFace;
  Face *frontFace;
  Face *rightFace;
  Face *bottomFace;
  Face *backFace;
};

Face *createFace(int type, int value[9]);
void displayFace(Face *cubeFace);
void displayCube(Cube *cube);
Cube *createCube(int value[6][9]);

#endif // cube_H
