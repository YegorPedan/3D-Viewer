#include "Back/main.h"
#include <check.h>

const dot V[] = {{1, -1, -1}, {1, -1, 1}, {-1, -1, 1}, {-1, -1, -1},
                 {1, 1, -1},  {1, 1, 1},  {-1, 1, 1},  {-1, 1, -1}};

START_TEST(Test1) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_right(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x + 1);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test2) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_left(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x - 1);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test3) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_up(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y + 1);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test4) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_down(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y - 1);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test5) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_in(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z - 1);
  }
}
END_TEST

START_TEST(Test6) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  move_out(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z + 1);
  }
}
END_TEST

START_TEST(Test7) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  zoomIn(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x * 1.5);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y * 1.5);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z * 1.5);
  }
}
END_TEST

START_TEST(Test8) {
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  zoomOut(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x / 1.5);
    ck_assert_float_eq(A.coordinates[i].y, V[i].y / 1.5);
    ck_assert_float_eq(A.coordinates[i].z, V[i].z / 1.5);
  }
}
END_TEST

START_TEST(Test9) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  turnZ(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x,
                       V[i].x * cos(degree) + V[i].y * sin(degree));
    ck_assert_float_eq(A.coordinates[i].y,
                       V[i].x * -sin(degree) + V[i].y * cos(degree));
    ck_assert_float_eq(A.coordinates[i].z, V[i].z);
  }
}
END_TEST

START_TEST(Test10) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  turnX(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x, V[i].x);
    ck_assert_float_eq(A.coordinates[i].y,
                       V[i].z * -sin(degree) + V[i].y * cos(degree));
    ck_assert_float_eq(A.coordinates[i].z,
                       V[i].z * cos(degree) + V[i].y * sin(degree));
  }
}
END_TEST

START_TEST(Test11) {
  double degree = (15 * M_PI) / 180.0;
  dot mas[8];
  memcpy(mas, V, sizeof(V));
  points A = {8, mas};

  turnY(&A);

  for (size_t i = 0; i < A.quantity; i++) {
    ck_assert_float_eq(A.coordinates[i].x,
                       V[i].x * cos(degree) + V[i].z * sin(degree));
    ck_assert_float_eq(A.coordinates[i].y, V[i].y);
    ck_assert_float_eq(A.coordinates[i].z,
                       V[i].x * -sin(degree) + V[i].z * cos(degree));
  }
}
END_TEST

int main() {
  Suite *suite = suite_create("Unit");
  TCase *tcase = tcase_create("Tests");
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, Test1);
  tcase_add_test(tcase, Test2);
  tcase_add_test(tcase, Test3);
  tcase_add_test(tcase, Test4);
  tcase_add_test(tcase, Test5);
  tcase_add_test(tcase, Test6);
  tcase_add_test(tcase, Test7);
  tcase_add_test(tcase, Test8);
  tcase_add_test(tcase, Test9);
  tcase_add_test(tcase, Test10);
  tcase_add_test(tcase, Test11);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? 0 : 1;
}
