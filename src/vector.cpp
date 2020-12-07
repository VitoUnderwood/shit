//
// Created by vito on 2020/12/6.
//

#include "vector.h"
#include <iterator>

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
        for (size_t i = 0; i < sz_; ++i)
            data_[i] = 0;
    }
}