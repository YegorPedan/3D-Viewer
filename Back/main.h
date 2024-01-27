/*!
 * \file
 * \brief Back headerfile.
 *
 * \details Here all libs, structs and declaration functions used in back part
 * of project
 *
 * Move functions are used to move the shape along the OX, OY and OZ axes. The
 * functions take a pointer to a variable of dots type, cyclically change the
 * points by 1.
 *
 * Turn functions are used to rotate the figure. If the rotation is along
 * the OZ axis, then X and Y points change, if OY, then XZ and if OX, then YZ.
 * The functions take a pointer to a variable of the dots type, cyclically
 * change the points by 15 degrees.
 *
 * The zoom functions are used to change the scale of the figure. They take a
 * pointer to a variable of the dots type, cyclically change all dots to 1.5.
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

void move_right(points *A);
void move_left(points *A);
void move_up(points *A);
void move_down(points *A);
void move_in(points *A);
void move_out(points *A);
void turnZ(points *A);
void turnX(points *A);
void turnY(points *A);
void zoomIn(points *A);
void zoomOut(points *A);
/*!
 * \brief Function for finding minimal and maximal value of coordinate
 *
 * \param A - pointer on coordinates
 * \param nums - pointer on result; nums[0] - min, nums[1] - max
 * \paran axis - which axis coords; 0 - OX, 1 - OY, 2 - OZ
 */
void minmax(points *A, double *nums, size_t axis);
/*!
 * \brief Function for center our figure and scale it on 0.7
 *
 * \param A - pointer on coordinates
 */
void CenterAndScaleCoords(points *A);

#endif // MAIN_H
