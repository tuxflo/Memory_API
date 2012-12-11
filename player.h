#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player
{
public:
    Player();
    void set_name_id(std::string name, int id);
    std::string get_name();
    int get_score();
    void add_points(int points);

private:
    std::string _name;
    int _player_id;
    int _score;
};

#endif // PLAYER_H
