#pragma once

class MoviePrice {
public:
    virtual double calculate(int daysRented) = 0;
};