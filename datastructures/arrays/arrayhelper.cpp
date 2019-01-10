#include "arrayhelper.h"
#include <unordered_set>
namespace ArrayHelper {
    void _rotateLayer(std::vector<std::vector<char> >& matrix, unsigned nDimen, unsigned startInd) {
        char* leftTop = &(matrix[startInd][startInd]);

        unsigned topIndexIter = startInd;
		char* topRight = &(matrix[topIndexIter][startInd + nDimen - 1]);
        char* rightBot = &(matrix[startInd + nDimen - 1][startInd + nDimen - 1]);

        unsigned botIndexIter = startInd + nDimen - 1;
        char* botLeft =  &(matrix[botIndexIter][startInd]);
        char* const botLeftGoal = &(matrix[startInd][startInd]);

        while (botLeft != botLeftGoal) {
            char temp = *botLeft;
            *botLeft = *rightBot;
            *rightBot = *topRight;
            *topRight = *leftTop;
            *topRight = *leftTop;
            *leftTop = temp;

            ++leftTop;
            ++topIndexIter;
			topRight = &(matrix[topIndexIter][nDimen - 1]);
            --rightBot;
            --botIndexIter;
            botLeft = &(matrix[botIndexIter][startInd]);
        }
    }

    void rotateMatrix(std::vector<std::vector<char> >& matrix) {
        int nDimen = matrix.size();

        for (unsigned i = 0; i < nDimen; ++i) {
            int nextDim = nDimen - i*2;  //dimensions decrease by 2 since it's a square
            if (nextDim <= 0) {
                break;
            }
            _rotateLayer(matrix, nDimen - i*2, i);
        }
    }

    void zeroMatrix(std::vector<std::vector<int> >& matrix) {
        std::unordered_set<unsigned> zeroRows;  //contains indicies of rows that need to be 0'd out
        std::unordered_set<unsigned> zeroCols;

        for (unsigned i = 0; i < matrix.size(); ++i) {
            for (unsigned j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        while (!zeroRows.empty()) {
            std::unordered_set<unsigned>::iterator it = zeroRows.begin();
            unsigned ithRow = *it;
            for (unsigned i = 0; i < matrix[ithRow].size(); ++i) {
                matrix[ithRow][i] = 0;
            }
            zeroRows.erase(it);
        }

        while (!zeroCols.empty()) {
            std::unordered_set<unsigned>::iterator it = zeroCols.begin();
            unsigned ithCol = *it;
            for (unsigned i = 0; i < matrix.size(); ++i) {
                matrix[i][ithCol] = 0;
            }
            zeroCols.erase(it);
        }
    }
}