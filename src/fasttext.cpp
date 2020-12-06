//
// Created by vito on 2020/12/5.
//

#include "fasttext.h"

namespace shit {
    Fasttext::Fasttext(): quant_(false) {}

    void Fasttext::train(std::shared_ptr<Args> args) {
        args_ = args;
        std::ifstream ifs(args_->input);
        if (!ifs.is_open()) {
            std::cerr << "Input file cannot be opened!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}