#ifndef customAssertion_H
#define customAssertion_H

#include "unity.h"
#include "Token.h"

// ... can represent any arguement.
#define CUSTOM_TEST_FAIL(lineNo, msg, ...)                                                        \
                {                                                                                 \
                char buffer[256];                                                                 \
                sprintf(buffer, msg, ## __VA_ARGS__);                                             \
                UNITY_TEST_FAIL(lineNo,buffer);                                                   \
                }

#define TEST_ASSERT_EQUAL_CUBE(expectedOper, token1, token2, actualOper);                   \
           customTestAssertCube(expectedCube, actualCube, __LINE__);
        
#define TEST_ASSERT_EQUAL_FACE(expectedOper, actualOper);                                     \
           customTestAssertFace(expectedFace, actualFace, __LINE__);

void customTestAssertCube(Cube* expectedCube, Cube *actualCube, int lineNumber);
void customTestAssertFace(Face* expectedFace, Face *actualFace, int lineNumber);


#endif // customAssertion_H