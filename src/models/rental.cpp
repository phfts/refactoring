#include "./movie.cpp"

class Rental
{
private:
    Movie movie;
    int daysRented;

public:
    Rental(Movie movie, int daysRented) : movie(movie), daysRented(daysRented) {}

    Movie getMovie()
    {
        return movie;
    }

    int getDaysRented()
    {
        return daysRented;
    }

    int calculateFrequentPoints(std::string &result)
    {
        int frequentRenterPoints = 1;
        if (movie.isNewRelease() && getDaysRented() > 1)
            frequentRenterPoints++;

        return frequentRenterPoints;
    }

    double calculateAmount(std::string &result)
    {
        double thisAmount = movie.amount(daysRented);
        result += "\t" + movie.getTitle() + "\t" +
                  std::to_string(thisAmount) + "\n";
        return thisAmount;
    }

    
};
