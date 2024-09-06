#include "./movie_price.cpp"

class NewReleaseMoviePrice : public MoviePrice {
    double calculate(int daysRented)
    {
        return daysRented * 3;
    }
};