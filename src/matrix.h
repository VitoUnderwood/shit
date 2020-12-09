//
// Created by vito on 2020/12/7.
//

#ifndef SHIT_MATRIX_H
#define SHIT_MATRIX_H

namespace shit {
	class Vector;

	class Matrix {
	public:
		float *data_;
		int64_t m_;
		int64_t n_;

		Matrix();

		Matrix(int64_t, int64_t);

		Matrix(const Matrix &);

		Matrix &operator=(const Matrix &);

		~Matrix();

		inline const float &at(int64_t i, int64_t j) const { return data_[i * n_ + j]; };

		inline float &at(int64_t i, int64_t j) { return data_[i * n_ + j]; };

		void zero();

		void uniform(float);

		float dotRow(const Vector &, int64_t) const;

		void addRow(const Vector &, int64_t, float);

		void multiplyRow(const Vector &nums, int64_t ib = 0, int64_t ie = -1);

		void divideRow(const Vector &denoms, int64_t ib = 0, int64_t ie = -1);

		float l2NormRow(int64_t i) const;

		void l2NormRow(Vector &norms) const;

		void save(std::ostream &);

		void load(std::istream &);
	};
}


#endif //SHIT_MATRIX_H
