/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:19:26 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 23:43:48 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Computes the absolute value of a float.
 * 
 * @param value The input float value.
 * @return Absolute value of teh input.
*/
static float absVal(float value) {
  return value < 0 ? -value : value;
}

/**
 * @brief Computes teh area of a triangle given it's vertices.
 * 
 * @param p1 First vertex.
 * @param p2 Second vertex.
 * @param p1 Third vertex.
 * @return The area of the tringle.
*/
static float area(const Point& p1, const Point& p2, const Point& p3) {
  return absVal((p1.getX() * (p2.getY() - p3.getY()) +
                 p2.getX() * (p3.getY() - p1.getY()) +
                 p3.getX() * (p1.getY() - p2.getY())) / 2.0);
}

/**
 * @brief Determine if a point is inside the tringle using the
 * are methd.
 * 
 * @param a First vertex of the triangle
 * @param b Second vertex of the triangle
 * @param c Third vertex of the triangle
 * @param p Point to check
 * @return True if the point is inside the triangle, 
 * false otherwise.
*/
bool bsp(Point const a, Point const b, Point const c, \
        Point const point) {
  float totalArea = area(a, b, c);
  float area1 = area(point, b, c);
  float area2 = area(a, point, c);
  float area3 = area(a, b, point);
    
  const float epsilon = 1e-6;
  bool isInside = absVal((area1 + area2 + area3) \
                        - totalArea) < epsilon;

  return isInside && area1 > 0 && area2 > 0 && area3 > 0;
}
