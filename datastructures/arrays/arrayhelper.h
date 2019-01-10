#pragma once
#include <vector>

namespace ArrayHelper {
    typedef char fakePixel;
    // struct fakePixel {
    //     char bytes[4];
    // };

    void _rotateLayer (std::vector<std::vector<fakePixel> > & matrix, unsigned nDimen, unsigned startInd);
    /* 1.7 Assumption that the matrix is nxn - rotating elements by +90 deg/clock-wise */
    void rotateMatrix(std::vector<std::vector<fakePixel> >& matrix);
    /* 1.8 identify 0s in matrix and set its row and column to 0s */
    void zeroMatrix(std::vector<std::vector<int> >& matrix);
}
