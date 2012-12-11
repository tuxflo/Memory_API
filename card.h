#ifndef CARD_H
#define CARD_H

class Card
{
public:
    Card();
    void set_turned(bool b);
    bool get_turned();
    void set_picture(int pic, int cover);
    int get_picture();
    int get_cover();
    void set_id(int id);
    int get_id();
    void set_points(int p);
    int get_points();
private:
    int _cover;
    int _picture;
    int _id;
    bool _turned;
    int _points;
};

#endif // CARD_H
