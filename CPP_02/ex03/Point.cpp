/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:19:30 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 22:48:16 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Default constructor.
 * 
 * Initializes the point in the origin(0,0)
*/
Point::Point() : _x(0), _y(0) {}

/**
 * @brief Constructor that takes float coords.
 * 
 * Initializes a point with given float
 * coordinates.
 * @param _x The x coord, as a float value.
 * @param _y The y coord, as a float value.
*/
Point::Point(float x, float y) : _x(x), _y(y) {}

/**
 * @brief Copy constructor.
 * 
 * Initializes this new Point with the values of
 * another Point object.
 * 
 * @param other The Point object to copy from.
*/
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

/**
 * @brief Copy assignment operator.
 * 
 * It assigns the resources of another Point object to 
 * this one.
 * 
 * @param other The Point object to get the data from.
 * @return A reference to this Point object.
*/
Point& Point::operator=(const Point& other) {
  if (this != &other) {
    this->_x = other._x;
    this->_y = other._y;
  }
  return *this;
}

/**
 * @brief Destructor.
 * 
 * Cleans up any resources.
*/
Point::~Point() {}

/**
 * @brief Getter for the x-coord, conveting from
 * fixed-point to float.
 * 
 * @return The x-coord as a float.
*/
float Point::getX() const {
    return _x.toFloat();
}

/**
 * @brief Getter for the y-coord, conveting from
 * fixed-point to float.
 * 
 * @return The y-coord as a float.
*/
float Point::getY() const {
    return _y.toFloat();
}
