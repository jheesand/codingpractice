// 3.1
#pragma once
#include <utility>
#include <array>
#include <stack>
template <typename T, unsigned N, unsigned M>
class MultiStacks {
    public:
        MultiStacks(unsigned totalSize = M);
        ~MultiStacks();
        void push(unsigned stackId, T value);
        void pop(unsigned stackId);
        int top(unsigned stackId);
        T const getMin(unsigned stackId);
        unsigned const getCapacity();
        unsigned const getNumFilled(unsigned id = N+1);

    private:
        unsigned const getNextStackId_(unsigned id);
        void shiftRByOne_(unsigned id);

        unsigned total_;
        unsigned numFilled_[N];
        std::array<T, M> data_;
        std::pair<int, int> startEndInd_[N];

        //3.2: key will be where the min has been found
        std::array<std::stack<unsigned>, N> minIndices_;
        // unnecessary info here: since we're using a static array we can just index
        // using the minIndices to retrieve the minValues instead of storing it in minValues
        std::array<std::stack<T>, N> minValues_;
};

#include "threestacks.cpp"