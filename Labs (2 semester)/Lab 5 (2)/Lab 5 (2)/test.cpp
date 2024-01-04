//#include <stdio.h>
//
//typedef unsigned short u16_t;
//const u16_t size = 7; //<-- CHANGE HERE!!! just odd numbers and bigger than 3
//const u16_t maxTimes = 2;
//u16_t array_cont[size][size] = { 0 };
//
//u16_t counter = 3, curr = 0;
//u16_t endColumn = (size - 1) / 2, endRow = endColumn;
//u16_t startColumn = endColumn + 1, startRow = endColumn + 1;
//u16_t posLoop = 2, buffer = startColumn, i = 0;
//
//void fillArray() {
//    if (curr < maxTimes) {
//        if (posLoop == 0) { //Top
//            for (i = buffer; i <= startColumn && curr < maxTimes; i++, curr++)
//                array_cont[endRow][i] = counter++;
//            if (curr == maxTimes) {
//                if (i <= startColumn) {
//                    buffer = i;
//                }
//                else {
//                    buffer = endRow;
//                    startColumn++;
//                    posLoop++;
//                }
//            }
//            else {
//                buffer = endRow;
//                startColumn++;
//                posLoop++;
//                fillArray();
//            }
//        }
//        else if (posLoop == 1) { //Right
//            for (i = buffer; i <= startRow && curr < maxTimes; i++, curr++)
//                array_cont[i][startColumn] = counter++;
//            if (curr == maxTimes) {
//                if (i <= startRow) {
//                    buffer = i;
//                }
//                else {
//                    buffer = startColumn;
//                    startRow++;
//                    posLoop++;
//                }
//            }
//            else {
//                buffer = startColumn;
//                startRow++;
//                posLoop++;
//                fillArray();
//            }
//        }
//        else if (posLoop == 2) { //Bottom
//            for (i = buffer; i >= endColumn && curr < maxTimes; i--, curr++)
//                array_cont[startRow][i] = counter++;
//            if (curr == maxTimes) {
//                if (i >= endColumn) {
//                    buffer = i;
//                }
//                else {
//                    buffer = startRow;
//                    endColumn--;
//                    posLoop++;
//                }
//            }
//            else {
//                buffer = startRow;
//                endColumn--;
//                posLoop++;
//                fillArray();
//            }
//        }
//        else if (posLoop == 3) { //Left
//            for (i = buffer; i >= endRow && curr < maxTimes; i--, curr++)
//                array_cont[i][endColumn] = counter++;
//            if (curr == maxTimes) {
//                if (i >= endRow) {
//                    buffer = i;
//                }
//                else {
//                    buffer = endColumn;
//                    endRow--;
//                    posLoop = 0;
//                }
//            }
//            else {
//                buffer = endColumn;
//                endRow--;
//                posLoop = 0;
//                fillArray();
//            }
//        }
//    }
//}
//
//int main(void) {
//    array_cont[endColumn][endColumn] = 1;
//    array_cont[endColumn][endColumn + 1] = 2;
//    //DO STUFF
//
//    u16_t max = ((size * size) - 1) / maxTimes;
//    for (u16_t j = 0; j < max; j++) {
//        fillArray();
//        curr = 0;
//        //DO STUFF
//    }
//
//    //Demostration
//    for (u16_t x = 0; x < size; x++) {
//        for (u16_t y = 0; y < size; y++)
//            printf("%-4d ", array_cont[x][y]);
//        printf("\n");
//    }
//
//    return 0;
//}