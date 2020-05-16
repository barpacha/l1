
template <typename T>
class Vector
{
public:
	Vector();
	Vector(T mas[]);
	Vector(Vector& obj);
	Vector~();
	T& operator[] (const int index);
	T& at(const int ind)
	class Iterator
	{
	public:
		Iterator();
		~Iterator();
		Iterator operator++(Iterator& i, int);
		T& operator*();
		bool operator==(const Iterator& left, const Iterator& right);
		bool operator!=(const Iterator& left, const Iterator& right);
	};
	Iterator begin();
	Iterator end();
};