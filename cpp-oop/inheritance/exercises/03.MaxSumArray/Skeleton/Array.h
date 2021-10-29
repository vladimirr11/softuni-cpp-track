#ifndef ARRAY_H
#define ARRAY_H

template <typename T> 
class Array {
public:
    Array(size_t size) : _data(new T[size]), _size(size) {}

    // optional constructor
    Array(std::initializer_list<T> initList) : _data(new T[initList.size()]), _size(initList.size()) {
		int index = 0;
		for (auto item : initList) {
			this->_data[index] = item;
			index++;
		}
	}

    Array(const Array& other) : _data(new T[other._size]{}), _size(other._size) {
		for (size_t i = 0; i < other._size; i++) {
			this->_data[i] = other._data[i];
		}
	}

    friend void swap(Array& a, Array& b) {
		using std::swap;

		swap(a._data, b._data);
		swap(a._size, b._size);
	}

    Array& operator=(Array other) {
		if (this != &other) {
			swap(*this, other);
		}

		return *this;
	}

    T* begin() const { return this->_data; }

    T* end() const { return this->_data + this->_size; }

    size_t getSize() const {
        return this->_size;
    }

    T& operator[](size_t index) {
        return this->_data[index];
    }

    ~Array() {
        if (_data) {
            delete[] _data;
            _data = nullptr;
        }
    }

private:
    T* _data;
    size_t _size;
};

#endif // !ARRAY_H
