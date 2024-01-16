#include "main.h"
#include <math.h>
#include <stddef.h>

points *move_right(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].x++;

  return A;
}

points *move_left(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].x--;

  return A;
}

points *move_up(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].y++;

  return A;
}

points *move_down(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].y--;

  return A;
}

points *move_in(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].z--;

  return A;
}

points *move_out(points *A) {
  for (int i = 0; i < A->quantity; i++)
    A->coordinates[i].z++;

  return A;
}

points *turnZ(points *A) {
  double degree = (15 * M_PI) / 180.0;
  double copy_dots[2] = {};

  for (size_t i = 0; i < A->quantity; i++) {
    copy_dots[0] = A->coordinates[i].x;
    copy_dots[1] = A->coordinates[i].y;

    A->coordinates[i].x =
        cos(degree) * copy_dots[0] + sin(degree) * copy_dots[1];
    A->coordinates[i].y =
        -sin(degree) * copy_dots[0] + cos(degree) * copy_dots[1];
  }

  return A;
}

points *turnX(points *A) {
  double degree = (15 * M_PI) / 180.0;
  double copy_dots[2] = {};

  for (size_t i = 0; i < A->quantity; i++) {
    copy_dots[0] = A->coordinates[i].z;
    copy_dots[1] = A->coordinates[i].y;

    A->coordinates[i].z =
        cos(degree) * copy_dots[0] + sin(degree) * copy_dots[1];
    A->coordinates[i].y =
        -sin(degree) * copy_dots[0] + cos(degree) * copy_dots[1];
  }

  return A;
}

points *turnY(points *A) {
  double degree = (15 * M_PI) / 180.0;
  double copy_dots[2] = {};

  for (size_t i = 0; i < A->quantity; i++) {
    copy_dots[0] = A->coordinates[i].x;
    copy_dots[1] = A->coordinates[i].z;

    A->coordinates[i].x =
        cos(degree) * copy_dots[0] + sin(degree) * copy_dots[1];
    A->coordinates[i].z =
        -sin(degree) * copy_dots[0] + cos(degree) * copy_dots[1];
  }

  return A;
}

points *zoomIn(points *A) {
  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x *= 1.5;
    A->coordinates[i].y *= 1.5;
    A->coordinates[i].z *= 1.5;
  }

  return A;
}

points *zoomOut(points *A) {
  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x /= 1.5;
    A->coordinates[i].y /= 1.5;
    A->coordinates[i].z /= 1.5;
  }

  return A;
}
