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
        Args();
        std::string input;
        std::string output;
        std::string test;
        double lr;
        int lrUpdateRate;
        int dim;
        int ws;
        int epoch;
        int minCount;
        int minCountLabel;
        int neg;
        int wordNgrams;
        loss_name loss;
        model_name model;
        int bucket;
        int minn;
        int maxn;
        int thread;
        double t;
        std::string label;
        int verbose;
        std::string pretrainedVectors;
        int saveOutput;

        bool qout;
        bool retrain;
        bool qnorm;
        size_t cutoff;
        size_t dsub;

        void parseArgs(const std::vector<std::string>& args);
        void printHelp();
        void printBasicHelp();
        void printDictionaryHelp();
        void printTrainingHelp();
        void printQuantizationHelp();
        void save(std::ostream&);
        void load(std::istream&);

    };
}

#endif //SHIT_ARGS_H
