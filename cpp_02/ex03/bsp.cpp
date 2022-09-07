#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point prob) {
	float a_x = a.getX().toFloat();
	float a_y = a.getY().toFloat();
	float b_x = b.getX().toFloat();
	float b_y = b.getY().toFloat();
	float c_x = c.getX().toFloat();
	float c_y = c.getY().toFloat();
	float prob_x = prob.getX().toFloat();
	float prob_y = prob.getY().toFloat();

	float test_1 = (a_x - prob_x) * (b_y - a_y) - (b_x - a_x) * (a_y - prob_y);
	float test_2 = (b_x - prob_x) * (c_y - b_y) - (c_x - b_x) * (b_y - prob_y);
	float test_3 = (c_x - prob_x) * (a_y - c_y) - (a_x - c_x) * (c_y - prob_y);

	if ((test_1 > 0 && test_2 > 0 && test_3 > 0) || (test_1 < 0 && test_2 < 0 && test_3 < 0)) {
		return true;
	}
	return false;
}