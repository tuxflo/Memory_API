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
private:
    int _cover;
    int _picture;
    int _id;
    bool _turned;
};

#endif // CARD_H
