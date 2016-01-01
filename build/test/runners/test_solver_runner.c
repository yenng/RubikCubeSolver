/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_front_side_corner_solver1(void);
extern void test_front_side_corner_solver2(void);
extern void test_side_corner_solver_one_by_one(void);
extern void test_solver_side_corner(void);
extern void test_solver_side_corner1(void);
extern void test_top_face_solver(void);
extern void test_top_face_full_solver_with_pattern_0(void);
extern void test_top_face_full_solver_with_pattern_3(void);
extern void test_top_face_full_solver_with_pattern_4(void);
extern void test_top_face_corner_solver(void);
extern void test_full_top_face_corner_solver(void);
extern void test_full_top_face_corner_solver_with_two_corners_is_white(void);
extern void test_full_top_face_corner_solver_with_no_corner_is_white(void);
extern void test_top_corner_solver_A_and_B_is_correct(void);
extern void test_top_corner_solver_A_and_C_is_correct(void);
extern void test_full_top_corner_solver_A_and_B_is_correct(void);
extern void test_full_top_corner_solver_A_and_C_is_correct(void);
extern void test_full_top_corner_solver_B_and_C_is_correct(void);
extern void test_full_top_corner_solver_B_and_D_is_correct(void);
extern void test_full_top_corner_solver_C_and_D_is_correct(void);
extern void test_full_top_corner_solver_A_and_D_is_correct(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_solver.c");
  RUN_TEST(test_front_side_corner_solver1, 11);
  RUN_TEST(test_front_side_corner_solver2, 31);
  RUN_TEST(test_side_corner_solver_one_by_one, 51);
  RUN_TEST(test_solver_side_corner, 70);
  RUN_TEST(test_solver_side_corner1, 89);
  RUN_TEST(test_top_face_solver, 109);
  RUN_TEST(test_top_face_full_solver_with_pattern_0, 128);
  RUN_TEST(test_top_face_full_solver_with_pattern_3, 147);
  RUN_TEST(test_top_face_full_solver_with_pattern_4, 167);
  RUN_TEST(test_top_face_corner_solver, 188);
  RUN_TEST(test_full_top_face_corner_solver, 208);
  RUN_TEST(test_full_top_face_corner_solver_with_two_corners_is_white, 228);
  RUN_TEST(test_full_top_face_corner_solver_with_no_corner_is_white, 248);
  RUN_TEST(test_top_corner_solver_A_and_B_is_correct, 268);
  RUN_TEST(test_top_corner_solver_A_and_C_is_correct, 289);
  RUN_TEST(test_full_top_corner_solver_A_and_B_is_correct, 310);
  RUN_TEST(test_full_top_corner_solver_A_and_C_is_correct, 331);
  RUN_TEST(test_full_top_corner_solver_B_and_C_is_correct, 351);
  RUN_TEST(test_full_top_corner_solver_B_and_D_is_correct, 371);
  RUN_TEST(test_full_top_corner_solver_C_and_D_is_correct, 391);
  RUN_TEST(test_full_top_corner_solver_A_and_D_is_correct, 413);

  return (UnityEnd());
}
