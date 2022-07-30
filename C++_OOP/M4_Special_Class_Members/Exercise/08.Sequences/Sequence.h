#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <list>

template<typename T>
class SeqIterator {
public:
    using self = SeqIterator<T>;

public:
    SeqIterator(const std::vector<T>& elements, size_t idx) : _elements(elements), _currIdx(idx) {}

    static self begin(const std::vector<T>& seq) { return SeqIterator(seq, 0); }

    static self end(const std::vector<T>& seq) { return SeqIterator(seq, -1); }

    self& operator++() { 
        _currIdx++;
        return *this;
    }

    self& operator++(int) { 
        self tmp = *this; 
        ++_currIdx;
        return tmp;
    }

    const T& operator*() const { return _elements[_currIdx]; }

    bool operator==(const SeqIterator& other) const {
        return _elements == other._elements && 
            (_currIdx == other._currIdx || other._elements.size() == _currIdx);
    }

    bool operator!=(const SeqIterator& other) const {
        return !operator==(other);
    }

private:
    const std::vector<T>& _elements;
    size_t _currIdx = 0;
};

template<typename T, typename Generator>
class Sequence {
public:
    using iterator = SeqIterator<T>;

public:
    Sequence() = default;

    void generateNext(int num);

    iterator begin();

    iterator end();

private:
    Generator gen;
    std::vector<T> _sequence;
};

template<typename T, typename Generator>
void Sequence<T, Generator>::generateNext(int num) {
    for (int i = 0; i < num; i++) {
        _sequence.push_back(gen());
    }
}

template<typename T, typename Generator>
typename Sequence<T, Generator>::iterator Sequence<T, Generator>::begin() {
    return SeqIterator<T>::begin(_sequence);
}

template<typename T, typename Generator>
typename Sequence<T, Generator>::iterator Sequence<T, Generator>::end() {
    return SeqIterator<T>::end(_sequence);
}

#endif // !SEQUENCE_H
