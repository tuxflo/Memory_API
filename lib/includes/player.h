#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player
{
public:
    Player();
    void set_name(std::string name);
    std::string get_name();
    int get_score();
    void add_points(int points);

private:
    std::string _name;
    int _score;
};

#endif // PLAYER_H
