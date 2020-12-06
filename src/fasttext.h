//
// Created by vito on 2020/12/5.
//

#ifndef SHIT_FASTTEXT_H
#define SHIT_FASTTEXT_H

#include "args.h"
#include "vector.h"

namespace shit {
    class Fasttext {
    public:
        Fasttext();
        void getVector(Vector&, const std::string&) const;
        void train(std::shared_ptr<Args>);

    protected:

    private:
        bool quant_;
        std::shared_ptr<Args> args_;
    };
}

#endif //SHIT_FASTTEXT_H
