//
// Created by vito on 2020/12/4.
//

#ifndef SHIT_ARGS_H
#define SHIT_ARGS_H

#include <iostream>
#include <string>
#include <vector>

namespace shit {
    enum class model_name : int {cbow=1, sg, sup}; //cbow,skipgram,supervise
    enum class loss_name : int {hs=1, ns, softmax}; //

    class Args {
    private:
        std::string lossToString(loss_name);
    public:
        Args()=default;

    };
}

#endif //SHIT_ARGS_H
