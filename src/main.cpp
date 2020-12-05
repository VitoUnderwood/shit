#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "args.h"


void printUsage() {
    std::cerr
            << "usage: shit code <command> <args>\n\n"
            << "The commands supported by shit code are:\n\n"
            << "  supervised              train a supervised classifier\n"
            << "  quantize                quantize a model to reduce the memory usage\n"
            << "  test                    evaluate a supervised classifier\n"
            << "  predict                 predict most likely labels\n"
            << "  predict-prob            predict most likely labels with probabilities\n"
            << "  skipgram                train a skipgram model\n"
            << "  cbow                    train a cbow model\n"
            << "  print-word-vectors      print word vectors given a trained model\n"
            << "  print-sentence-vectors  print sentence vectors given a trained model\n"
            << "  nn                      query for nearest neighbors\n"
            << "  analogies               query for analogies\n"
            << "  --help                  commend details\n"
            << std::endl;
}

void train(const std::vector<std::string> args) {
    std::shared_ptr<Args> a = std::make_shared<Args>();
}

int main(int argc, char **argv) {
    std::unordered_map<std::string, int> commend{
            {"skipgram",               1},
            {"cbow",                   2},
            {"supervised",             3},
            {"test",                   4},
            {"quantize",               5},
            {"print_word_vectors",     6},
            {"print_sentence_vectors", 7},
            {"print_ngrams",           8},
            {"nn",                     9},
            {"analogies",              10},
            {"predict",                11},
            {"predict_prob",           12},
            {"--help",                 13}
    };

    std::vector <std::string> args(argv, argv + argc);

    if (args.size() < 2) {
        printUsage();
        exit(EXIT_FAILURE);
    }

    switch (commend[args[1]]) {
        case 1:
        case 2:
        case 3:{
            train(args);
            break;
        }
        case 13: {
            std::cout << args[1] << std::endl;
            std::cout << commend[args[1]] << std::endl;
            printUsage();
            break;
        }
        default: {
            std::cout << "未知命令，请使用--help查看使用手册";
            exit(EXIT_FAILURE);
        }
    }
//    printUsage();
    std::cerr << "hello shit!" << std::endl;
    return 0;
}
