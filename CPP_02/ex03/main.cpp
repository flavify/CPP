/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:25:42 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 23:45:21 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Point.hpp"

static void testBsp(const Point& a, const Point& b, const Point& c, \
            const Point& p, const std::string& description) {
  std::cout << "Is point " << "\"" << description << "\""
              << " inside triangle? "
              << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;
}

int main() {
  Point a(0, 0);
  Point b(1, 0);
  Point c(0, 1);

  // Test cases
  Point inside(0.1f, 0.1f);             // Inside the triangle
  Point outside(2.f, 2.f);              // Clearly outside the triangle
  Point onEdge(0.5f, 0.f);              // On the edge of the triangle
  Point atVertex(0.f, 0.f);             // At a vertex of the triangle
  Point nearVertex(0.01f, 0.01f);       // Very close to a vertex but inside
  Point outsideNearEdge(0.5f, -0.01f);  // Near an edge, but outside

  // Run tests and output results
  testBsp(a, b, c, inside, "inside");
  testBsp(a, b, c, outside, "outside");
  testBsp(a, b, c, onEdge, "on the edge");
  testBsp(a, b, c, atVertex, "at a vertex");
  testBsp(a, b, c, nearVertex, "near a vertex inside");
  testBsp(a, b, c, outsideNearEdge, "outside near an edge");

  return 0;
}

