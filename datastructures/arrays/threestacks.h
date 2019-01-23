#pragma once
#include <utility>
#include <array>
template <typename T, unsigned N, unsigned M>
class MultiStacks {
    public:
        MultiStacks(unsigned totalSize = M);
        ~MultiStacks();
        void push(unsigned stackId, T value);
        void pop(unsigned stackId);
        int top(unsigned stackId);
        unsigned const getCapacity();
        unsigned const getNumFilled();

    private:
        unsigned getNextStackId_(unsigned id);
        bool overlaps(unsigned id1, unsigned id2);
        void shiftRByOne_(unsigned id);

        unsigned total_;
        unsigned numFilled_[N];
        std::array<T, M> data_;
        std::pair<int, int> startEndInd_[N];
};

#include "threestacks.cpp"