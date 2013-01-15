#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
public:
    Card();
    void set_turned(bool b);
    bool get_turned();
    void set_picture_path(std::string pic);
    std::string get_picture_path();
    void set_id(int id);
    int get_id();
    void set_points(int p);
    int get_points();
private:
    std::string _picture_path;
    int _id;
    bool _turned;
    int _points;
};

#endif // CARD_H
