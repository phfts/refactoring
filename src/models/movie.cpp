#pragma once

#include <string>
#include <map>

#include "./movie_price/childrens_movie_price.cpp"
#include "./movie_price/new_release_movie_price.cpp"
#include "./movie_price/regular_movie_price.cpp"

class Movie {
private:
    int code;
    std::string title;
    std::map<int, MoviePrice*> pricingStrategies = {
        {REGULAR, new RegularMoviePrice()},
        {CHILDRENS, new ChildrensMoviePrice()},
        {NEW_RELEASE, new NewReleaseMoviePrice()}
    };

public:
    const static int REGULAR = 1;
    const static int NEW_RELEASE = 2;
    const static int CHILDRENS = 3;

    Movie(int code, std::string title) : code(code), title(title) {}

    int getPriceCode()
    {
        return code;
    }

    bool isNewRelease()
    {
        return getPriceCode() == NEW_RELEASE;
    }

    std::string getTitle()
    {
        return title;
    }

    double amount(int daysRented)
    {
        auto moviePriceObj = pricingStrategies[getPriceCode()];
        return moviePriceObj->calculate(daysRented);
    }
};

