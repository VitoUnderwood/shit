//
// Created by vito on 2020/12/6.
//

#ifndef SHIT_VECTOR_H
#define SHIT_VECTOR_H

#include <iostream>

namespace shit {
    class Vector {
    public:
//        class Matrix;
//        class QMatrix;

        Vector() = default;
        explicit Vector(std::int64_t); //动态开辟具体大小数组
        ~Vector();

        std::int64_t size() const;
        void zero();
        void mul(float);
        float norm() const;
        void addVector(const Vector& source);
        void addVector(const Vector&, float);

        std::int64_t argmax();

        float operator[](std::int64_t);


    protected:
    private:
        std::int64_t sz_; //float array size
        float *data_;
    };
}

#endif //SHIT_VECTOR_H
