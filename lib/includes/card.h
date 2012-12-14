#ifndef CARD_H
#define CARD_H

template<class T>
class Card
{
public:
    Card()
    {
        _turned = false;
        //Start value 100, for each "not right" turning subtracting 10 points
        _points = 100;
    }

    void set_turned(bool b)
    {
        _turned = b;
    }

    bool get_turned()
    {
        return _turned;
    }

    void set_picture(T pic, int cover)
    {
        _picture = pic;
        _cover = cover;
    }

    int get_picture()
    {
        return _picture;
    }

    int get_cover()
    {
        return _cover;
    }

    void set_id(int id)
    {
        _id = id;
    }

    int get_id()
    {
        return _id;
    }

    void set_points(int p)
    {
        if(_points > 0)
            _points -= p;
    }

    int get_points()
    {
        return _points;
    }

private:
    int _cover;
    T _picture;
    int _id;
    bool _turned;
    int _points;
};

#endif // CARD_H
