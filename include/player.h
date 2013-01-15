#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player();
    Player(const char *name);
    void set_name(const std::string &name);
    std::string get_name();
    void add_points(int points);
    int get_score();
private:
    int _score;
    std::string _name;
};

#endif // PLAYER_H
