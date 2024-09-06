#include <string>
#include <vector>

#include "./models/rental.cpp"
#include "./models/movie.cpp"

class Statement
{
private:
    std::string name;
    std::vector<Rental> rentals;

public:
    Statement(std::string name, std::vector<Rental> rentals) : name(name), rentals(rentals) {}

    std::string getName()
    {
        return name;
    }

    std::string buildReport()
    {
        int frequentRenterPoints = 0;
        double totalAmount = 0;        
        std::string result = buildReportHeader();
        for (Rental each : rentals)
        {
            totalAmount += each.calculateAmount(result);
            frequentRenterPoints += each.calculateFrequentPoints(result);
        }
        return result + buildReportFooter(totalAmount, frequentRenterPoints);
    }

    std::string buildReportHeader()
    {
        return "Rental Record for " + getName() + "\n";
    }

    std::string buildReportFooter(double totalAmount, int frequentRenterPoints)
    {
        return "Amount owed is " + std::to_string(totalAmount) +
                  "\n" +
                "You earned " + std::to_string(frequentRenterPoints) +
                  " frequent renter points";
    }
};