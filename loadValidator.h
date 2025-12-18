//
// Created by theVo on 12/17/2025.
//

#ifndef PROJECT_LOADVALIDATOR_H
#define PROJECT_LOADVALIDATOR_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Checks if the first row of the file contains exactly two integers.
 *
 * This function reads the first line of the provided file and attempts to parse
 * two integers, which represent the number of rows and columns. It validates that
 * the file is not empty and that the header format is correct.
 *
 * @param file A pointer to the open file to be checked.
 * @param rows A pointer to an integer where the row count will be stored if successful.
 * @param cols A pointer to an integer where the column count will be stored if successful.
 * @return Returns true if the header contains exactly two valid integers; otherwise, returns false.
 */
bool checkHeader(FILE *file, int *rows, int *cols);

/**
 * @brief Verifies that the actual file content matches the stated dimensions.
 *
 * This function checks two things:
 * 1. The number of data rows matches the `expectedRows`.
 * 2. Each data row contains exactly `expectedCols` numbers.
 * It ignores metadata lines (lines not starting with numbers) once the expected
 * row count is met.
 *
 * @param file A pointer to the open file to be checked.
 * @param expectedRows The number of rows expected, usually parsed from the header.
 * @param expectedCols The number of columns expected, usually parsed from the header.
 * @return Returns true if the row and column counts match the expected values; otherwise, returns false.
 */
bool checkDimensions(FILE *file, int expectedRows, int expectedCols);

/**
 * @brief Checks if every row in the file has the same number of columns.
 *
 * This function ensures the board is rectangular by comparing the number of
 * columns in every subsequent row against the number of columns in the first row.
 * It is useful for detecting irregular board shapes even if the header is incorrect.
 *
 * @param file A pointer to the open file to be checked.
 * @return Returns true if all data rows have the same number of columns; otherwise, returns false.
 */
bool checkRectangularConsistency(FILE *file);

/**
 * @brief Validates that every number on the board follows the "one zero" rule.
 *
 * This function scans every number on the board to ensure it adheres to the
 * game rule: "At least one digit must be zero".
 * Valid examples: 10, 20, 30 (tens digit is non-zero, ones digit is zero).
 * Valid examples: 01, 02, 05 (tens digit is zero, ones digit is non-zero).
 * Valid examples: 00 (both are zero).
 * Invalid examples: 11, 12, 35 (neither digit is zero).
 *
 * @param file A pointer to the open file to be checked.
 * @return Returns true if every number on the board is valid; otherwise, returns false.
 */
bool checkZeroConstraint(FILE *file);

/**
 * @brief Checks if the first value of the board is 0, 1, 2, or 3.
 *
 * This function skips the file header (dimensions) and reads the very first
 * board value (top-left corner). It verifies that this value is strictly
 * within the set {0, 1, 2, 3}.
 *
 * @param file A pointer to the open file to be checked.
 * @return Returns true if the first board value is 0, 1, 2, or 3; otherwise, returns false.
 */
bool checkFirstBoardValue(FILE *file);

#endif // PROJECT_LOADVALIDATOR_H