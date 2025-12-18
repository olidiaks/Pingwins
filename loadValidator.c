//
// Created by theVo on 12/17/2025.
//

#include "loadValidator.h"

bool checkHeader(FILE *file, int *rows, int *cols) {
    if (file == NULL) {
        fprintf(stderr, "Error: File pointer is NULL.\n");
        return false;
    }

    rewind(file);
    char buffer[128];

    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fprintf(stderr, "Error: File is empty or cannot be read.\n");
        return false;
    }

    int r, c;
    int count = sscanf(buffer, "%d %d", &r, &c);

    if (count != 2) {
        fprintf(stderr, "Error: Header format invalid. Expected 2 numbers, found %d.\n", count);
        return false;
    }

    if (r <= 0 || c <= 0) {
        fprintf(stderr, "Error: Dimensions must be positive. Found %d x %d.\n", r, c);
        return false;
    }

    *rows = r;
    *cols = c;
    return true;
}

bool checkDimensions(FILE *file, int expectedRows, int expectedCols) {
    if (file == NULL) return false;

    rewind(file);
    char buffer[1024]; // Just to be safe

    printf("Expected dim: %d, %d\n", expectedRows, expectedCols);

    //Skip
    fgets(buffer, sizeof(buffer), file);

    int rowCount = 0;
    while (rowCount < expectedRows && fgets(buffer, sizeof(buffer), file)) {

        int colCount = 0;
        char *ptr = buffer;
        int val;
        int charsRead;

        while (sscanf(ptr, "%d%n", &val, &charsRead) == 1) {
            colCount++;
            ptr += charsRead;
        }

        if (colCount != expectedCols) {
            fprintf(stderr, "Error: Row %d has incorrect column count. Expected %d, found %d.\n", rowCount + 1, expectedCols, colCount);
            return false;
        }

        rowCount++;
    }

    if (rowCount != expectedRows) {
        fprintf(stderr, "Error: Incorrect row count. Header stated %d, but found %d board rows.\n", expectedRows, rowCount);
        return false;
    }

    return true;
}

bool checkRectangularConsistency(FILE *file) {
    if (file == NULL) return false;

    rewind(file);
    char buffer[1024];

    //Skip
    fgets(buffer, sizeof(buffer), file);

    int firstRowCols = -1;
    int currentRow = 0;

    while (fgets(buffer, sizeof(buffer), file)) {

        int val, charsRead;
        if (sscanf(buffer, "%d%n", &val, &charsRead) != 1) {
            break;
        }

        int colCount = 0;
        char *ptr = buffer;
        while (sscanf(ptr, "%d%n", &val, &charsRead) == 1) {
            colCount++;
            ptr += charsRead;
        }

        if (firstRowCols == -1) {
            firstRowCols = colCount;
        }
        else if (colCount != firstRowCols) {
            fprintf(stderr, "Error: Irregular board shape. Row %d has length %d, but Row 1 had %d.\n", currentRow + 1, colCount, firstRowCols);
            return false;
        }
        currentRow++;
    }

    return true;
}

bool checkZeroConstraint(FILE *file) {
    if (file == NULL) return false;

    rewind(file);
    char buffer[1024];

    //Skip
    fgets(buffer, sizeof(buffer), file);

    int row = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        char *ptr = buffer;
        int val;
        int charsRead;

        if (sscanf(ptr, "%d", &val) != 1) break;

        int col = 0;
        while (sscanf(ptr, "%d%n", &val, &charsRead) == 1) {

            bool tensIsZero = (val / 10 == 0);
            bool onesIsZero = (val % 10 == 0);

            if (!tensIsZero && !onesIsZero) {
                fprintf(stderr, "Error: Invalid value '%02d' at Row %d, Col %d.\nOne digit must be zero (e.g., 10 or 02).\n", val, row + 1, col + 1);
                return false;
            }

            ptr += charsRead;
            col++;
        }
        row++;
    }
    return true;
}

bool checkFirstBoardValue(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error: File pointer is NULL.\n");
        return false;
    }

    rewind(file);
    char buffer[1024];

    // 1. Skip the Header Line (Dimensions)
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fprintf(stderr, "Error: File is empty.\n");
        return false;
    }

    // 2. Read the First Value of the Board
    // We try to read the first integer from the NEXT line (start of board data)
    int firstVal;

    // Loop to skip potential empty lines between header and data
    while (fgets(buffer, sizeof(buffer), file)) {
        // Try to read one integer from the start of the line
        if (sscanf(buffer, "%d", &firstVal) == 1) {

            // 3. Check if it is 0, 1, 2, or 3
            if (firstVal >= 0 && firstVal <= 3) {
                return true;
            } else {
                fprintf(stderr, "Error: First board value is %d. Expected 0, 1, 2, or 3.\n", firstVal);
                return false;
            }
        }
    }

    fprintf(stderr, "Error: Could not find any board data to check.\n");
    return false;
}