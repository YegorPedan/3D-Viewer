#include "main.h"

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
