#include <string>
#include <vector>

class Movie {
public:
    const static int REGULAR = 1;
    const static int NEW_RELEASE = 2;
    const static int CHILDRENS = 3;

    int getPriceCode()
    {
        return 1;
    }

    std::string getTitle()
    {
        return "";
    }
};

class Rental {
private:
    Movie movie;
public:
    Movie getMovie() 
    {
        return movie;
    }

    int getDaysRented()
    {
        return 0;
    }
};

class MyRentals {
private:
    std::string _name;
    std::vector<Rental> _rentals;
    std::string getName()
    {
        return _name;
    }
public:
    std::string statement()
    {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        std::string result = "Rental Record for " + getName() + "\n";
        for (Rental each : _rentals)
        {
            double thisAmount = 0;
            // determine amounts for each line
            switch (each.getMovie().getPriceCode())
            {
            case Movie::REGULAR:
                thisAmount += 2;
                if (each.getDaysRented() > 2)
                    thisAmount += (each.getDaysRented() - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += each.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (each.getDaysRented() > 3)
                    thisAmount += (each.getDaysRented() - 3) * 1.5;
                break;
            }
            // add frequent renter points
            frequentRenterPoints++;
            // add bonus for a two day new release rental
            if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
                each.getDaysRented() > 1)
                frequentRenterPoints++;
            // show figures for this rental
            result += "\t" + each.getMovie().getTitle() + "\t" +
                      std::to_string(thisAmount) + "\n";
            totalAmount += thisAmount;
        }
        // add footer lines
        result += "Amount owed is " + std::to_string(totalAmount) +
                  "\n";
        result += "You earned " + std::to_string(frequentRenterPoints) +
                  " frequent renter points";
        return result;
    }
};