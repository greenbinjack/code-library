template <typename DT>
class Point {
public:
  DT x, y, z;
  Point(){};
  Point(DT x, DT y, DT z) : x(x), y(y), z(z) {}
  template <typename X> Point(Point<X> p) : x(p.x), y(p.y), z(p.z) {}
  Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y, z + rhs.z); }
  Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y, z - rhs.z); }
  Point operator * (DT M) const { return Point(M * x, M * y, M * z); }
  Point operator / (DT M) const { return Point(x / M, y / M, z / M); }
  // cross product
  Point operator & (const Point &rhs) const { return Point(y * rhs.z - z * rhs.y,z * rhs.x - x * rhs.z,x * rhs.y - y * rhs.x); }
  // dot product
  DT operator ^ (const Point &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
  bool operator == (const Point &rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
  bool operator != (const Point &rhs) const { return !(*this == rhs); }
  friend std::istream& operator >> (std::istream &is, Point &p) { return is >> p.x >> p.y >> p.z; }
  friend std::ostream& operator << (std::ostream &os, const Point &p) { return os << p.x << " " << p.y << " " << p.z; }
  friend DT DisSq(const Point &a, const Point &b) { return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z); }
};

optional < Point <double> > ray_intersects_triangle(const Point<double> &origin,const Point<double> &ray_vector,const array <Point<double>, 3> &triangle) {
  constexpr double epsilon = std::numeric_limits<double>::epsilon();
  auto [A, B, C] = triangle;
  Point<double> edge1 = B - A;
  Point<double> edge2 = C - A;
  Point<double> ray_cross_e2 = ray_vector & edge2;
  double det = edge1 ^ ray_cross_e2;
  if (det > -epsilon && det < epsilon) return {}; // Ray is parallel to this triangle.
  double inv_det = 1.0 / det;
  Point<double> s = ray_origin - A;
  double u = inv_det * (s ^ ray_cross_e2);
  if (u < 0 || u > 1) return {};
  Point<double> s_cross_e1 = s & edge1;
  double v = inv_det * (ray_vector ^ s_cross_e1);
  if (v < 0 || u + v > 1) return {};
  // Compute t to find the intersection Point
  double t = inv_det * (edge2 ^ s_cross_e1);
  if (t > epsilon) return ray_origin + ray_vector * t; // ray intersection
  else return {}; // Line intersection but not ray intersection
}
// HOW TO IMPLEMENT
// auto tmp = ray_intersects_triangle (origin, ray, v[i]);
// if (tmp.has_value ()) Point <double> intersection_point = tmp.value ();