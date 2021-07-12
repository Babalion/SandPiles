//
// Created by chris on 06.05.21.
//

#pragma once

class Cell {
public:
    Cell() = default;

    //initializes with given height
    explicit Cell(unsigned int height) : height(height), slopeToNeighbours(0) {};

// -----------------------------------------------------------------------------------
// ------------------GETTER AND SETTERS-----------------------------------------------
// -----------------------------------------------------------------------------------

    [[nodiscard]] unsigned int getHeight() const {
        return height;
    }

    void setHeight(unsigned int height) {
        Cell::height = height;
        slopeToNeighbours = 0;
    }

    [[nodiscard]] int getSlopeToNeighbours() const {
        return slopeToNeighbours;
    }

    void setSlopeToNeighbours(int slopeToNeighbours) {
        Cell::slopeToNeighbours = slopeToNeighbours;
    }

// -----------------------------------------------------------------------------------
// ------------------METHODS----------------------------------------------------------
// -----------------------------------------------------------------------------------

    //increases height by 1
    void incHeight() {
        height++;
    }

    friend bool operator==(const Cell &lhs, const Cell &rhs) {
        return (lhs.height == rhs.height) && (lhs.getSlopeToNeighbours() == rhs.getSlopeToNeighbours());
    }

private:
    unsigned int height;
    int slopeToNeighbours;
};

