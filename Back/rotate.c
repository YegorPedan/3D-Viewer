#include "main.h"

void move_right(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].x += 0.1;
}

void move_left(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].x -= 0.1;
}

void move_up(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].y += 0.1;
}

void move_down(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].y -= 0.1;
}

void move_in(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].z -= 0.1;
}

void move_out(points *A) {
  for (size_t i = 0; i < A->quantity; i++)
    A->coordinates[i].z += 0.1;
}

void turnZ(points *A) {
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
}

void turnX(points *A) {
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
}

void turnY(points *A) {
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
}

void zoomIn(points *A) {
  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x *= 1.1;
    A->coordinates[i].y *= 1.1;
    A->coordinates[i].z *= 1.1;
  }
}

void zoomOut(points *A) {
  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x /= 1.1;
    A->coordinates[i].y /= 1.1;
    A->coordinates[i].z /= 1.1;
  }
}

// nums[0] == min; nums[1] == max
// axis 0 == OX; 1 == OY; 2 == OZ
void minmax(points *A, double *nums, size_t axis) {
  switch (axis) {
  case 0:
    nums[0] = A->coordinates[0].x;
    nums[1] = nums[0];
    for (size_t i = 1; i < A->quantity; i++) {
      if (A->coordinates[i].x < nums[0])
        nums[0] = A->coordinates[i].x;
      else if (A->coordinates[i].x > nums[1])
        nums[1] = A->coordinates[i].x;
    }
    break;
  case 1:
    nums[0] = A->coordinates[0].y;
    nums[1] = nums[0];
    for (size_t i = 1; i < A->quantity; i++) {
      if (A->coordinates[i].y < nums[0])
        nums[0] = A->coordinates[i].y;
      else if (A->coordinates[i].x > nums[1])
        nums[1] = A->coordinates[i].y;
    }
    break;
  case 2:
    nums[0] = A->coordinates[0].z;
    nums[1] = nums[0];
    for (size_t i = 1; i < A->quantity; i++) {
      if (A->coordinates[i].z < nums[0])
        nums[0] = A->coordinates[i].z;
      else if (A->coordinates[i].z > nums[1])
        nums[1] = A->coordinates[i].z;
    }
    break;
  }
}

void CenterAndScaleCoords(points *A) {
  double minmaxCoods[2];
  double minX, minY, minZ, maxX, maxY, maxZ;
  double centerX, centerY, centerZ;
  double scaleX, scaleY, scaleZ, Dmax, scaleVal;

  minmax(A, minmaxCoods, 0);
  minX = minmaxCoods[0];
  maxX = minmaxCoods[1];

  minmax(A, minmaxCoods, 1);
  minY = minmaxCoods[0];
  maxY = minmaxCoods[1];

  minmax(A, minmaxCoods, 2);
  minZ = minmaxCoods[0];
  maxZ = minmaxCoods[1];

  centerX = minX + (maxX - minX) / 2;
  centerY = minY + (maxY - minY) / 2;
  centerZ = minZ + (maxZ - minZ) / 2;

  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x -= centerX;
    A->coordinates[i].y -= centerY;
    A->coordinates[i].z -= centerZ;
  }

  scaleX = maxX - minX;
  scaleY = maxY - minY;
  scaleZ = maxZ - minZ;
  Dmax = scaleX;

  if (Dmax < scaleY)
    Dmax = scaleY;
  if (Dmax < scaleZ)
    Dmax = scaleZ;

  scaleVal = (2 * 0.7) / Dmax;

  for (size_t i = 0; i < A->quantity; i++) {
    A->coordinates[i].x *= scaleVal;
    A->coordinates[i].y *= scaleVal;
    A->coordinates[i].z *= scaleVal;
  }
}
