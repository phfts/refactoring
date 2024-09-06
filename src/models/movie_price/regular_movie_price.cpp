#include "./movie_price.cpp"

class RegularMoviePrice : public MoviePrice
{
    double calculate(int daysRented)
    {
        double thisAmount = 2;
        if (daysRented > 2)
            thisAmount += (daysRented - 2) * 1.5;
        return thisAmount;
    }
};