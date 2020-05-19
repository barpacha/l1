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
	~Vector() { if (!pointer) free(pointer); }
	T& operator[] (const int index) { return pointer[index]; }
	T& at(const int index) { return pointer[index]; }
	int get_size() { return this->size; }
	class Iterator
	{
		friend Iterator Vector<T>::begin();
		friend Iterator Vector<T>::end();
		friend void Vector<T>::insert(Iterator iter, T data);
	public:
		Iterator() {};
		Iterator(const Iterator &obj) 
		{
			pointer = obj.pointer;
		};
		const Iterator operator++()
		{
			pointer++;
			return *this;
		}
		const Iterator operator++(int)
		{
			Vector<T>::Iterator copy(*this);
			pointer ++;
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
		beg.pointer = pointer + size;
		return beg;
	}
	Vector(Vector &obj)
	{
		this->size = size;
		T *new_mas = (T*)calloc(size, sizeof(T));
		int i = 0;
		Iterator iter = obj.begin();
		while (iter != obj.end())
			pointer[i++] = *iter++;
	}
	void push_back(T data)
	{
		size++;
		T *new_mas = (T*)calloc(size, sizeof(T));
		for (int i = 0; i < size - 1; i++)
			new_mas[i] = pointer[i];
		new_mas[size - 1] = data;
		free(pointer);
		pointer = new_mas;
	}
	void pop_back()
	{
		size--;
		T *new_mas = (T*)calloc(size, sizeof(T));
		for (int i = 0; i < size; i++)
			new_mas[i] = pointer[i];
		free(pointer);
		pointer = new_mas;
	}
	void insert(Iterator iter, T data)
	{
		if (!(iter.pointer >= pointer && iter.pointer <= pointer + size)) return;
		size++;
		T *new_mas = (T*)calloc(size, sizeof(T));
		int i;
		for (i = 0; i < (iter.pointer - pointer)/ sizeof(T); i++)
			new_mas[i] = pointer[i];
		new_mas[i] = data;
		for (; i < size; i++)
			new_mas[i + 1] = pointer[i];
		free(pointer);
		pointer = new_mas;
	}
	T &front() { return pointer[0]; }
	T &back() { return pointer[size - 1]; }
private:
	T *pointer;
	int size;
};

void main() {
	Vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.pop_back();
	a.insert(a.begin(), 3);
	for (Vector<int>::Iterator b = a.begin(); b != a.end(); b++)
		std::cout << *b << std::endl;
	system("pause");

}
