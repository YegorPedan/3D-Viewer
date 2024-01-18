/*!
 * \file
 * \brief Back headerfile.
 *
 * \details Here all libs, structs and declaration functions used in back part
 * of project
 *
 * Move functions are used to move the shape along the OX, OY and OZ axes. The
 * functions take a pointer to a variable of dots type, cyclically change the
 * points by 1 and return a pointer to the same variable.
 *
 * Turn functions are used to rotate the figure. If the rotation is along
 * the OZ axis, then X and Y points change, if OY, then XZ and if OX, then YZ.
 * The functions take a pointer to a variable of the dots type, cyclically
 * change the points by 15 degrees and return a pointer to the same variable.
 *
 * The zoom functions are used to change the scale of the figure. They take a
 * pointer to a variable of the dots type, cyclically change all dots to 1.5 and
 * return a pointer to the same variable
 */
#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stddef.h>

/*!
 * \brief substructure for points struct.
 *  Used for store coordinates from .obj file
 */
typedef struct {
  double x;
  double y;
  double z;
} dot;

/*!
 * \brief Structure for storing V variables from .obj file
 *
 * \param quantity - num of points
 * \param coordinates - pointer of dot mas.
 */
typedef struct {
  unsigned int quantity;
  dot *coordinates;
} points;

/*!
 * \brief Structure for storing F variables from .obj file
 *
 * \param quantity - num of points
 * \param facet_matrix - matrix of vactors for F variables
 */
typedef struct {
  unsigned int quantity;
  int **facet_matrix;
} facet;

points *move_right(points *A);
points *move_left(points *A);
points *move_up(points *A);
points *move_down(points *A);
points *move_in(points *A);
points *move_out(points *A);
points *turnZ(points *A);
points *turnX(points *A);
points *turnY(points *A);
points *zoomIn(points *A);
points *zoomOut(points *A);

#endif // MAIN_H
