#include "../../src/models/movie.cpp"
#include "../../src/statement.cpp"

TEST(Statement, NoRent)
{
    std::string name = "userName"; 
    std::vector<Rental> rentals;
    Statement st = Statement(name, rentals);
    std::string result = "Rental Record for userName\nAmount owed is 0.000000\nYou earned 0 frequent renter points";
    EXPECT_EQ(result, st.build());
}

TEST(Statement, OneRegularMovie)
{
    std::string name = "userName";
    Movie movie = Movie(Movie::REGULAR, "Pistoleiro sem dedo"); 
    std::vector<Rental> rentals = {Rental(movie, 10)};
    Statement st = Statement(name, rentals);
    std::string result = "Rental Record for userName\n\tPistoleiro sem dedo\t14.000000\nAmount owed is 14.000000\nYou earned 1 frequent renter points";    
    EXPECT_EQ(result, st.build());
}

TEST(Statement, TwoMovies)
{
    std::string name = "userName";
    Movie movie1 = Movie(Movie::REGULAR, "Pistoleiro sem dedo"); 
    Movie movie2 = Movie(Movie::CHILDRENS, "Volta dos que nao foram"); 
    std::vector<Rental> rentals = {Rental(movie1, 10), Rental(movie2, 1)};
    Statement st = Statement(name, rentals);
    std::string result = "Rental Record for userName\n\tPistoleiro sem dedo\t14.000000\n\tVolta dos que nao foram\t1.500000\nAmount owed is 15.500000\nYou earned 2 frequent renter points";   
    EXPECT_EQ(result, st.build());
}