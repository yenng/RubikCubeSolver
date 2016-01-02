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
extern void test_base_side_solver_one_time(void);
extern void test_base_side_solver_two_times(void);
extern void test_base_side_solver_three_times(void);
extern void test_base_side_solver_four_times(void);
extern void test_base_side_full_solver_with_same_cube_above(void);
extern void test_base_side_full_solver_with_different_cube(void);
extern void test_base_corner_solver_to_solve_one_corner(void);
extern void test_base_corner_solver_to_solve_two_corner_by_run_base_corner_solver_twice(void);
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
extern void test_full_top_side_solver_no_side_is_correct(void);
extern void test_full_top_side_solver_side_A_is_correct(void);
extern void test_full_top_side_solver_side_B_is_correct(void);
extern void test_full_top_side_solver_side_C_is_correct(void);
extern void test_full_top_side_solver_side_D_is_correct(void);
extern void test_full_solver(void);
extern void test_full_solver1(void);


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
  RUN_TEST(test_base_side_solver_one_time, 18);
  RUN_TEST(test_base_side_solver_two_times, 37);
  RUN_TEST(test_base_side_solver_three_times, 57);
  RUN_TEST(test_base_side_solver_four_times, 78);
  RUN_TEST(test_base_side_full_solver_with_same_cube_above, 100);
  RUN_TEST(test_base_side_full_solver_with_different_cube, 119);
  RUN_TEST(test_base_corner_solver_to_solve_one_corner, 139);
  RUN_TEST(test_base_corner_solver_to_solve_two_corner_by_run_base_corner_solver_twice, 159);
  RUN_TEST(test_front_side_corner_solver1, 180);
  RUN_TEST(test_front_side_corner_solver2, 200);
  RUN_TEST(test_side_corner_solver_one_by_one, 220);
  RUN_TEST(test_solver_side_corner, 239);
  RUN_TEST(test_solver_side_corner1, 258);
  RUN_TEST(test_top_face_solver, 278);
  RUN_TEST(test_top_face_full_solver_with_pattern_0, 297);
  RUN_TEST(test_top_face_full_solver_with_pattern_3, 316);
  RUN_TEST(test_top_face_full_solver_with_pattern_4, 336);
  RUN_TEST(test_top_face_corner_solver, 357);
  RUN_TEST(test_full_top_face_corner_solver, 377);
  RUN_TEST(test_full_top_face_corner_solver_with_two_corners_is_white, 397);
  RUN_TEST(test_full_top_face_corner_solver_with_no_corner_is_white, 417);
  RUN_TEST(test_top_corner_solver_A_and_B_is_correct, 437);
  RUN_TEST(test_top_corner_solver_A_and_C_is_correct, 458);
  RUN_TEST(test_full_top_corner_solver_A_and_B_is_correct, 479);
  RUN_TEST(test_full_top_corner_solver_A_and_C_is_correct, 500);
  RUN_TEST(test_full_top_corner_solver_B_and_C_is_correct, 520);
  RUN_TEST(test_full_top_corner_solver_B_and_D_is_correct, 540);
  RUN_TEST(test_full_top_corner_solver_C_and_D_is_correct, 560);
  RUN_TEST(test_full_top_corner_solver_A_and_D_is_correct, 581);
  RUN_TEST(test_full_top_side_solver_no_side_is_correct, 602);
  RUN_TEST(test_full_top_side_solver_side_A_is_correct, 617);
  RUN_TEST(test_full_top_side_solver_side_B_is_correct, 632);
  RUN_TEST(test_full_top_side_solver_side_C_is_correct, 647);
  RUN_TEST(test_full_top_side_solver_side_D_is_correct, 662);
  RUN_TEST(test_full_solver, 676);
  RUN_TEST(test_full_solver1, 690);

  return (UnityEnd());
}
