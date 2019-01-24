
template <typename T, unsigned N, unsigned M>
MultiStacks<T, N, M>::MultiStacks(unsigned totalSize) : total_(totalSize) {
    for (unsigned i = 0; i < N; ++i) {
        startEndInd_[i].first = (total_ / N) * i;
        startEndInd_[i].second = (total_ / N) * i;
    }

    for (unsigned i = 0; i < N; ++i) {
        numFilled_[i] = 0;
    }
}

template <typename T, unsigned N, unsigned M>
MultiStacks<T, N, M>::~MultiStacks() {
}

template <typename T, unsigned N, unsigned M>
unsigned const MultiStacks<T, N, M>::getNextStackId_(unsigned id) {
    unsigned stackIdNext = id + 1;
    if (stackIdNext < N) {
        return stackIdNext;
    }

    return stackIdNext - N;  // or just return 0
}

template <typename T, unsigned N, unsigned M>
void MultiStacks<T, N, M>::shiftRByOne_(unsigned id) {
    unsigned startInd = startEndInd_[id].first;
    unsigned endInd = startEndInd_[id].second;
    int numElements = static_cast<int>(endInd) - static_cast<int>(startInd);

    if (endInd < startInd) {
        numElements = total_ - numElements;
    }

    while (numElements > 0) {
        int backInd = (static_cast<int>(endInd) - 1);
        if (backInd < 0) {
            backInd += total_;
        }

        data_[endInd] = data_[backInd];
        endInd = backInd;
        --numElements;
    }
    startEndInd_[id].first = (startEndInd_[id].first + 1) % total_;
    startEndInd_[id].second = (startEndInd_[id].second + 1) % total_;
}

template <typename T, unsigned N, unsigned M>
void MultiStacks<T, N, M>::push(unsigned stackId, T value) {
    // assert(stackId >= 0 && stackId < 3, "Invalid stack id!")
    if (getNumFilled() >= getCapacity()) {
        //filled
        return;
    }

    int& stackEndInd = startEndInd_[stackId].second;
    unsigned stackIdNext = getNextStackId_(stackId);

    //my current stack is full
    if (stackEndInd == startEndInd_[stackIdNext].first) {
        unsigned stackIdNextNext = getNextStackId_(stackIdNext);   
        if (startEndInd_[stackIdNext].second == startEndInd_[stackIdNextNext].first) {
            shiftRByOne_(stackIdNextNext);
        }
        shiftRByOne_(stackIdNext);
    }

    data_[stackEndInd] = value;

    ++stackEndInd;
    stackEndInd = stackEndInd % total_;
    ++numFilled_[stackId];
}

template <typename T, unsigned N, unsigned M>
void MultiStacks<T, N, M>::pop(unsigned stackId) {
    if (numFilled_[stackId] == 0) {
        return;
    }

    int stackEndInd = startEndInd_[stackId].second - 1;
    if (stackEndInd < 0) {
        stackEndInd += total_;
    }
    startEndInd_[stackId].second = stackEndInd;
    --numFilled_[stackId];
}

template <typename T, unsigned N, unsigned M>
int MultiStacks<T, N, M>::top(unsigned stackId) {
    //throw/assert if stackId invalid or stack is empty -- check numFilled_[stackId]
    int topIndex = startEndInd_[stackId].second - 1;
    if (topIndex < 0) {
        topIndex += total_;
    }
    return data_[topIndex];
}

template <typename T, unsigned N, unsigned M>
unsigned const MultiStacks<T, N, M>::getCapacity() {
    return total_;
}

template <typename T, unsigned N, unsigned M>
unsigned const MultiStacks<T, N, M>::getNumFilled(unsigned id) {
    //valid id or will treat as all the stacks
    if (id < N) {
        return numFilled_[id];
    }

    unsigned total = 0;

    for (unsigned i = 0; i < N; ++i) {
        total += numFilled_[i];
    }

    return total;
}
