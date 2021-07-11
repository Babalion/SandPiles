//
// Created by chris on 06.05.21.
//
#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <random>
#include <vector>

#include "Cell.h"


class Configuration {
public:
    /**
     * No standard constructor
     */
    Configuration() = delete;

    /**
     * field width should be bigger or equal than 2
     * initialization is random between 0 and 20
     */
    Configuration(unsigned int fieldWidth, unsigned int criticalSlope);

    /**
     * creates a configuration with a given cells-vector
     * @param cells_
     * @param criticalSlope
     */
    Configuration(const std::vector<Cell> &cells_, unsigned int criticalSlope);

    // -----------------------------------------------------------------------------------
    // ------------------GETTER AND SETTERS-----------------------------------------------
    // -----------------------------------------------------------------------------------

    [[nodiscard]] const std::vector<Cell> &getCells() const;

    [[nodiscard]] const unsigned int &getFieldWidth() const;

    [[nodiscard]] const unsigned int &getTime() const;

    // -----------------------------------------------------------------------------------
    // ------------------METHODS----------------------------------------------------------
    // -----------------------------------------------------------------------------------
    /**
     * Performs a timeStep. Therefore updates each cell and increases neighbours if critical slope of cell is reached.
     * Also updates slopes.
     * Doesn't add sand!
     */
    void runTime();

    /**
     * adds a sand-corn to the middle of the field
     */
    void addSand();

    /**
     * Prints out heights of each cell to the console
     */
    [[maybe_unused]] [[maybe_unused]] void printToConsole();

    /**
     * return sum over all cell-heights
     */
    [[nodiscard]] unsigned int amountOfSand() const;

    /**
     * @return the maximum height of all cells
     */
    [[nodiscard]] unsigned int maxHeight() const;

    /**
     * @return the minimum height of all cells
     */
    [[nodiscard]] unsigned int minHeight() const;

    /**
     * sums up all slopesToNeighbours from all cells which are greater than 0
     * thus all slopes from mountains downwards, not from valleys upwards
     * @return criticality greater or equal 0
     */
    [[nodiscard]] unsigned int calcCriticality() const;

private:
    /**
     * initializes cells and slope-cells
     * it calculates random numbers between 0 and 20 for cells
     * slope-cells are derived from cells
     */
    void initRandom();

    /**
    * Calculates the slopeToNeighbours based on the actual cell height and
    */
    void updateSlopes();

    unsigned int fieldWidth;
    unsigned int criticalSlope;
    std::vector<Cell> cells;
    unsigned int time;

    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<unsigned int> u;
};