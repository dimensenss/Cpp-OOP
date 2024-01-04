#include "Header.h"
template Array <int>;

template <class T> Array<T>::Array(const T& ind, const T& size) {
	try {
		this->size = size;
		this->arr = new T[size];
		if (ind < size && ind >= 0)
			this->ind = ind;
		else {
			this->ind = 0;
			throw exception("Error constructor");
		}
	}
	catch (const exception ex) {
		cout << ex.what()<<"\n";
		
	}
}

template <class T> void Array<T>::fill_arr(const T& n, const T& idx) {
	this->arr[idx] = n;
}
template <class T> void Array<T>::sum_arr() {
	int sum = 0;
	for (int i = 0; i < ind; i++) {
		sum += this->arr[i];
	}
	cout << "sum = " << sum << "\n";
}
template <class T> void Array<T>::average_arr() {
	double sum = 0;
	for (int i = 0; i < ind; i++) {
		sum += this->arr[i];
	}
	cout << "average = " << sum / ind << "\n";
}

template <class T> void Array<T>::print() {
	for (int i = 0; i < ind; i++) {
		cout << this->arr[i] << " ";
	}
}

template <class T> T& Array<T>::operator[](const int& idx) {
	try {
		if (idx >= ind || idx < 0)
			throw exception("Error []");
		else {
			T max = *arr;
			T pos = 0;
			for (int i = 0; i < idx; i++) {
				if (max < arr[i+1]) {
					max = arr[i+1];
					pos = i+1;
				}
			}
			return arr[pos];
		}
	}
	catch (const exception ex) {
		cout << ex.what()<<"\n";
	}
}
template <class T> T& Array<T>::operator()(const T& ind, const T& size) {
	try {
		this->size = size;
		this->arr = new T[size];
		if (ind < size && ind > 0)
			this->ind = ind;
		else {
			this->ind = 0;
			throw exception("Error constructor");
		}
	}
	catch (const exception ex) {
		cout << ex.what() << "\n";

	}
}