//
// Created by vito on 2020/12/6.
//

#ifndef SHIT_VECTOR_H
#define SHIT_VECTOR_H

#include <iostream>

namespace shit {
	class Matrix;
	class QMatrix;
	
    class Vector {
    public:
        Vector() = default;
        explicit Vector(std::int64_t); //动态开辟具体大小数组
        ~Vector();

        std::int64_t size() const;
        void zero();
		float norm() const; //2范数
        void mul(float); //整体乘法

        void addVector(const Vector& source);
        void addVector(const Vector&, float);

        void addRow(const Matrix &, std::int64_t);
		void addRow(const QMatrix &, std::int64_t);
		void addRow(const Matrix &, std::int64_t, float);
		void mul(const QMatrix &, const Vector &);
		void mul(const Matrix &, const Vector &);

        std::int64_t argmax();

		float &operator[](int64_t);
		const float &operator[](int64_t) const;


    protected:
    private:
        std::int64_t sz_; //float array size
        float *data_;
    };
}

#endif //SHIT_VECTOR_H
