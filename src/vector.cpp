//
// Created by vito on 2020/12/6.
//

#include "vector.h"

namespace shit {
    Vector::Vector(std::int64_t sz) {
        sz_ = sz;
        data_ = new float[sz];
        std::cout << sz_ << std::endl;
    }

    Vector::~Vector() {
        delete [] data_;
    }

    float Vector::operator[](std::int64_t i) {
        return data_[i];
    }

    std::int64_t Vector::size() const {
        return sz_;
    }

    void Vector::zero() {
        for (auto start = std::cbegin(data_), start != std::cend(data_), ++start)
            *start = 1.0;
    }
}