#ifndef MAIN_H
#define MAIN_H

typedef struct {
  double x;
  double y;
  double z;
} dot;

typedef struct {
  unsigned int quantity;
  dot *coordinates;
} points;

typedef struct {
  unsigned int quantity;
  int **facet_matrix;
} facet;

#endif // MAIN_H
