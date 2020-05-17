#include <cstdlib>
#include <iostream>
template <typename T>
class Vector
{
public:
	Vector() 
	{
		size = 0;
		pointer = nullptr;
	}
	Vector(T mas[], int size)
	{
		this->size = size;
		T *new_mas = (T*)calloc(size, sizeof(T));
		for (int i = 0; i < size; i++)
			new_mas[i] = mas[i];
		pointer = new_mas;
	}
	~Vector() { if (!pointer) free(pointer); }
	T& operator[] (const int index) { return pointer[index]; }
	T& at(const int index) { return pointer[index]; }
	int get_size() { return this->size; }
	class Iterator
	{
		friend Iterator Vector<T>::begin();
		friend Iterator Vector<T>::end();
	public:
		Iterator() {};
		Iterator(Iterator &obj) :pointer(obj.pointer) {};
		const Iterator operator++()
		{
			pointer += sizeof(T);
			return *this;
		}
		const Iterator operator++(int)
		{
			Vector<T>::Iterator copy(this);
			pointer += sizeof(T);
			return copy;
		}
		T& operator*() { return *pointer; }
		Iterator &operator=(const Iterator& right)
		{
			this->pointer = right.pointer;
			return *this;
		}
		bool operator==(const Iterator& right) { return (pointer == right.pointer); }
		bool operator!=(const Iterator& right) { return !(pointer == right.pointer); }
	private:
		T * pointer;
	};
	Iterator begin()
	{
		Iterator beg;
		beg.pointer = pointer;
		return beg;
	}
	Iterator end()
	{
		Iterator beg;
		beg.pointer = pointer + sizeof(T) * size;
		return beg;
	}
	Vector(Vector& obj)
	{
		this->size = size;
		T *new_mas = (T*)calloc(size, sizeof(T));
		int i = 0;
		Iterator iter = obj.begin();
		while (iter != obj.end())
			pointer[i++] = *iter++;
	}
private:
	T *pointer;
	int size;
};

void main() {
	int m[3] = { 1,2,3 };
	Vector<int> a(m, 3);
	std::cout << a[2] << std::endl;
	system("pause");

}
