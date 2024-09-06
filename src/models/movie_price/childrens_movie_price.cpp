#include "./movie_price.cpp"

class ChildrensMoviePrice : public MoviePrice
{
    double calculate(int daysRented)
    {
        double thisAmount = 1.5;
        if (daysRented > 3)
            thisAmount += (daysRented - 3) * 1.5;
        return thisAmount;
    }
};