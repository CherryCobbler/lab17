#ifdef HEADER_H
struct point {
	int x = 0;
	int y = 0;
	int z = 0;
	bool operator<(const point& p) const
	{
		if (sqrt(x * x + y * y + z * z) < sqrt(p.x * p.x + p.y * p.y + p.z * p.z)) return true;
		else return false;
	}
	bool operator>(const point& p) const
	{
		if (sqrt(x * x + y * y + z * z) > sqrt(p.x * p.x + p.y * p.y + p.z * p.z)) return true;
		else return false;
	}
};
std::ostream& operator<<(std::ostream& out, const point& p)
{
	out << "(" << p.x << ";" << p.y << ";" << p.z << ")";
	return out;
}
#endif 