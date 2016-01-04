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
extern void test_base_corner_solver_to_solve_three_corner_by_run_base_corner_solver_three_times(void);
extern void test_base_corner_solver_to_solve_four_corner_by_run_base_corner_solver_four_times(void);
extern void test_base_corner_full_solver_to_solve_four_corner(void);
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
extern void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube(void);
extern void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube1(void);
extern void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube(void);
extern void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube1(void);
extern void test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube2(void);
extern void test_base_side_full_solver_with_random_cube(void);


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
  RUN_TEST(test_base_side_solver_one_time, 20);
  RUN_TEST(test_base_side_solver_two_times, 39);
  RUN_TEST(test_base_side_solver_three_times, 59);
  RUN_TEST(test_base_side_solver_four_times, 80);
  RUN_TEST(test_base_side_full_solver_with_same_cube_above, 101);
  RUN_TEST(test_base_side_full_solver_with_different_cube, 120);
  RUN_TEST(test_base_corner_solver_to_solve_one_corner, 139);
  RUN_TEST(test_base_corner_solver_to_solve_two_corner_by_run_base_corner_solver_twice, 158);
  RUN_TEST(test_base_corner_solver_to_solve_three_corner_by_run_base_corner_solver_three_times, 179);
  RUN_TEST(test_base_corner_solver_to_solve_four_corner_by_run_base_corner_solver_four_times, 201);
  RUN_TEST(test_base_corner_full_solver_to_solve_four_corner, 224);
  RUN_TEST(test_front_side_corner_solver1, 245);
  RUN_TEST(test_front_side_corner_solver2, 265);
  RUN_TEST(test_side_corner_solver_one_by_one, 285);
  RUN_TEST(test_solver_side_corner, 304);
  RUN_TEST(test_solver_side_corner1, 325);
  RUN_TEST(test_top_face_solver, 346);
  RUN_TEST(test_top_face_full_solver_with_pattern_0, 365);
  RUN_TEST(test_top_face_full_solver_with_pattern_3, 384);
  RUN_TEST(test_top_face_full_solver_with_pattern_4, 404);
  RUN_TEST(test_top_face_corner_solver, 425);
  RUN_TEST(test_full_top_face_corner_solver, 445);
  RUN_TEST(test_full_top_face_corner_solver_with_two_corners_is_white, 465);
  RUN_TEST(test_full_top_face_corner_solver_with_no_corner_is_white, 485);
  RUN_TEST(test_top_corner_solver_A_and_B_is_correct, 505);
  RUN_TEST(test_top_corner_solver_A_and_C_is_correct, 526);
  RUN_TEST(test_full_top_corner_solver_A_and_B_is_correct, 547);
  RUN_TEST(test_full_top_corner_solver_A_and_C_is_correct, 568);
  RUN_TEST(test_full_top_corner_solver_B_and_C_is_correct, 588);
  RUN_TEST(test_full_top_corner_solver_B_and_D_is_correct, 608);
  RUN_TEST(test_full_top_corner_solver_C_and_D_is_correct, 628);
  RUN_TEST(test_full_top_corner_solver_A_and_D_is_correct, 649);
  RUN_TEST(test_full_top_side_solver_no_side_is_correct, 670);
  RUN_TEST(test_full_top_side_solver_side_A_is_correct, 685);
  RUN_TEST(test_full_top_side_solver_side_B_is_correct, 700);
  RUN_TEST(test_full_top_side_solver_side_C_is_correct, 715);
  RUN_TEST(test_full_top_side_solver_side_D_is_correct, 730);
  RUN_TEST(test_full_solver, 744);
  RUN_TEST(test_full_solver1, 759);
  RUN_TEST(test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube, 772);
  RUN_TEST(test_full_solver_with_random_cube_by_using_createMessyCube_function_with_correct_cube1, 780);
  RUN_TEST(test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube, 794);
  RUN_TEST(test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube1, 808);
  RUN_TEST(test_full_solver_with_random_cube_by_using_createMessyCube_function_with_random_cube2, 822);
  RUN_TEST(test_base_side_full_solver_with_random_cube, 836);

  return (UnityEnd());
}
