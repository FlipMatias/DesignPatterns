#include <iostream>
#include <string>
using namespace std;


class Band
{
public:
    string name;
    string genre;
    string country;
    int year;
};


class BandBuilder
{
private:
    Band _band;

public:
    BandBuilder() {}

    BandBuilder& setName(const string& name)
    {
        _band.name = name;
        return *this;
    }

    BandBuilder& setGenre(const string& genre)
    {
        _band.genre = genre;
        return *this;
    }

    BandBuilder& setCountry(const string& country)
    {
        _band.country = country;
        return *this;
    }

    BandBuilder& setYear(int year)
    {
        _band.year = year;
        return *this;
    }

    Band build()
    {
        return _band;
    }
};


void print(const Band& band)
{
    printf("Name: %s\n", band.name.c_str());
    printf("Genre: %s\n", band.genre.c_str());
    printf("Country: %s\n", band.country.c_str());
    printf("Year: %d\n\n", band.year);
}


int main()
{
    BandBuilder bb;
    Band band = bb.setName("Blink 182")
                .setCountry("USA")
                .setGenre("Punk Rock")
                .setYear(1992)
                .build();

    print(band);

    printf("\n\n");
    return 0;
}
