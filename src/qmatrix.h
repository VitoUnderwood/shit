//
// Created by vito on 2020/12/7.
//

#ifndef SHIT_QMATRIX_H
#define SHIT_QMATRIX_H

#include "matrix.h"
#include "vector.h"

namespace shit {

	class QMatrix {
	private:
		std::unique_ptr <ProductQuantizer> pq_;
		std::unique_ptr <ProductQuantizer> npq_;

		uint8_t *codes_;
		uint8_t *norm_codes_;

		bool qnorm_;

		int64_t m_;
		int64_t n_;

		int32_t codesize_;

	public:

		QMatrix();

		QMatrix(const Matrix &, int32_t, bool);

		~QMatrix();

		int64_t getM() const;

		int64_t getN() const;

		void quantizeNorm(const Vector &);

		void quantize(const Matrix &);

		void addToVector(Vector &x, int32_t t) const;

		float dotRow(const Vector &, int64_t) const;

		void save(std::ostream &);

		void load(std::istream &);
	};

}


#endif //SHIT_QMATRIX_H
