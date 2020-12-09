//
// Created by vito on 2020/12/6.
//

#include "vector.h"
#include <iterator>
#include <cmath>
#include <cassert>
#include "matrix.h"
#include "qmatrix.h"

namespace shit {
	Vector::Vector(int64_t sz) {
		sz_ = sz;
		data_ = new float[sz];
		std::cout << sz_ << std::endl;
	}

	Vector::~Vector() {
		delete[] data_;
	}

	int64_t Vector::size() const {
		return sz_;
	}

	void Vector::zero() {
		for (int64_t i = 0; i < sz_; ++i)
			data_[i] = 0;
	}

	float Vector::norm() const {
		float sum = 0.0;
		for (int64_t i = 0; i < sz_; ++i)
			sum += data_[i] * data_[i];
		return std::sqrt(sum);
	}

	void Vector::mul(float x) {
		for (int64_t i = 0; i < sz_; ++i)
			data_[i] *= x;
	}

	void Vector::addVector(const Vector &source) {
		assert(sz_ == source.sz_);
		for (int64_t i = 0; i < sz_; ++i)
			data_[i] += source[i];
	}

	void Vector::addVector(const Vector &source, float x) {
		assert(sz_ == source.sz_);
		for (int64_t i = 0; i < sz_; i++) {
			data_[i] += x * source.data_[i];
		}
	}

	void Vector::addRow(const Matrix &A, int64_t i) {
		assert(i >= 0);
		assert(i < A.m_);
		assert(sz_ == A.n_);
		for (int64_t j = 0; j < A.n_; j++) {
			data_[j] += A.at(i, j);
		}
	}

	void Vector::addRow(const Matrix &A, int64_t i, float a) {
		assert(i >= 0);
		assert(i < A.m_);
		assert(sz_ == A.n_);
		for (int64_t j = 0; j < A.n_; j++) {
			data_[j] += a * A.at(i, j);
		}
	}

	void Vector::addRow(const QMatrix &A, int64_t i) {
		assert(i >= 0);
		A.addToVector(*this, i);
	}

	void Vector::mul(const Matrix &A, const Vector &vec) {
		assert(A.m_ == sz_);
		assert(A.n_ == vec.sz_);
		for (int64_t i = 0; i < sz_; i++) {
			data_[i] = A.dotRow(vec, i);
		}

	}

	void Vector::mul(const QMatrix &A, const Vector &vec) {
		assert(A.getM() == sz_);
		assert(A.getN() == vec.sz_);
		for (int64_t i = 0; i < sz_; i++) {
			data_[i] = A.dotRow(vec, i);
		}
	}

	float &Vector::operator[](int64_t i) {
		return data_[i];
	}

	const float &Vector::operator[](int64_t i) const {
		return data_[i];
	}
}