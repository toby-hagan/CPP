#ifndef TWO_VALUES_H
#define TWO_VALUES_H

template<typename T>
class TwoValues
{
public:
	TwoValues(T i, T j);
	bool equal();

private:
	T a, b;
};

template<typename T>
TwoValues<T>::TwoValues(T i, T j)
	: a(i), b(j)
{
}

template<typename T>
bool TwoValues<T>::equal()
{
	return a == b;
}

#endif
