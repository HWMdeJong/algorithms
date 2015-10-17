#include <vector>
#include <stdint.h>
#include <algorithm>

using namespace std;

struct Point {
	int64_t x, y;
};

bool sort_by_x(Point a, Point b) {
	if(a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int64_t angle(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> monotone_chain_convex_hull(vector<Point> points) {
	int64_t n = points.size();
	if(n == 0) {
		return vector<Point>();
	}

	sort(points.begin(), points.end(), sort_by_x);
	vector<Point> upper_hull, lower_hull;
	int64_t lhs = 0, uhs = 0;

	for(int64_t i = 0; i < n; i++) {
		while(lhs > 1 && angle(lower_hull[lhs - 2], lower_hull[lhs - 1], points[i]) <= 0) {
			lower_hull.pop_back();
			lhs--;
		}
		lower_hull.push_back(points[i]);
		lhs++;
	}

	for(int64_t i = n - 1; i >= 0; i--) {
		while(uhs > 1 && angle(upper_hull[uhs - 2], upper_hull[uhs - 1], points[i]) <= 0) {
			upper_hull.pop_back();
			uhs--;
		}
		lower_hull.push_back(points[i]);
		uhs++;
	}

	lower_hull.pop_back();
	upper_hull.pop_back();
	vector<Point> hull(lower_hull);
	hull.insert(hull.end(), upper_hull.begin(), upper_hull.end());
	return hull;
}

int main() {
	return 0;
}