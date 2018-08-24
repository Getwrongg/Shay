#include <vector>

#pragma once

	/**
	* @class Vector
	* @brief  templated dynamic array
	*
	* encapsulates the required parts of the STL vector, and is used as a minimal dynamic array
	*
	* @author ClickBait Inc
	* @version 01
	* @date 24/08/2018 // date is in Australian format.
	*
	* @todo
	*
	* @bug none
	*/
template <class T>
class Vector
{
public:
		/**
		* @brief  Returns data from the array from a given indez
		*
		*@param i (const unsigned)
		*
		* @return const T&
		*/
	const T & getData(const int i);

		/**
		* @brief  Puts data into the array
		*
		*@param input (const T&)
		*
		* @return void
		*/
	void setData(const T & input);

		/**
		* @brief clears the vector of data and resets the size
		*
		*
		* @return void
		*/
	void clearVector();

private:
	std::vector<T> data; //Data storage
};

template <class T>
const T & Vector<T>::getData(const int i) {
	return data.at(i);
}

template <class T>
void Vector<T>::setData(const T &input) {
	data.push_back(input);
}

template <class T>
void Vector<T>::clearVector() {
	data.clear();
}

