#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

enum HERO {
    AXE,
    PUDGE,
    INVOKER,
    ANTIMAGE,
    NAGA,
    RUBICK,
    LION,
    DAZZLE
};

enum ROLE {
    FULSUPPORT,
    SEMISUPPORT,
    OFFLINE,
    MIDLINE,
    SAFELINE,
    JUNGLER
};

enum SKILL {
    NORMAL,
    HIGH,
    VERYHIGH
};

string getHero(HERO hero) {
    switch (hero) {
        case HERO::ANTIMAGE:
            return "ANTIMAGE";
        case HERO::AXE:
            return "AXE";
        case HERO::PUDGE:
            return "PUDGE";
        case HERO::INVOKER:
            return "INVOKER";
        case HERO::NAGA:
            return "NAGA";
        case HERO::LION:
            return "LION";
        case HERO::DAZZLE:
            return "DAZZLE";
        case HERO::RUBICK:
            return "RUBICK";
    }
};

string  getRole(ROLE role) {
    switch (role) {
        case ROLE::FULSUPPORT:
            return "FULSUPPORT";
        case ROLE::SEMISUPPORT:
            return "SEMISUPPORT";
        case ROLE::OFFLINE:
            return "OFFLINE";
        case ROLE::MIDLINE:
            return "MIDLINE";
        case ROLE::SAFELINE:
            return "SAFELINE";
        case ROLE::JUNGLER:
            return "JUNGLER";
    }
}

string getSkill(SKILL skill) {
    switch (skill) {
        case SKILL::HIGH:
            return "HIGH";
        case SKILL::NORMAL:
            return "NARMAL";
        case SKILL::VERYHIGH:
            return "VERYHIGH";
    }
}

class Game {
private:
    string nickname;
    HERO hero;
    ROLE role;
    SKILL skill;
    unsigned int kills;
    unsigned  int maxHp;
public:
    Game(const string &nickname, HERO hero, ROLE role,unsigned int kills, unsigned int maxHp, SKILL skill)
    : nickname(nickname),hero(hero), role(role), kills(kills), maxHp(maxHp), skill(skill) {}

    void showMe() {
        cout << "Никнэйм: " << nickname << endl;
        cout << "Герой: " << getHero(hero) << endl;
        cout << "Роль: " << getRole(role) << endl;
        cout << "Убийства: " << kills << endl;
        cout << "Максимальное здоровье: " << maxHp << endl;
        cout << "Скилл: " << getSkill(skill) << endl;
    }
};

class GameBuilder {
private:
    string nickname;
    HERO hero;
    ROLE role;
    SKILL skill;
    unsigned int kills;
    unsigned  int maxHp;
public:
    void setNickname(const string &nickname) {
        GameBuilder::nickname = nickname;
    }

    void setHero(HERO hero) {
        GameBuilder::hero = hero;
    }

    void setRole(ROLE role) {
        GameBuilder::role = role;
    }

    void setSkill(SKILL skill) {
        GameBuilder::skill = skill;
    }

    void setKills(unsigned  int kills) {
        GameBuilder::kills = kills;
    }

    void setMaxHp(unsigned int maxHp) {
        GameBuilder::maxHp = maxHp;
    }

    Game *createGame() {
        return new Game(nickname,hero, role ,kills, maxHp,skill);
    }
};

int main() {
    Game *game;
    GameBuilder gameBuilder;

    gameBuilder.setNickname("nagibator_2000");
    gameBuilder.setHero(HERO::PUDGE);
    gameBuilder.setRole(ROLE::MIDLINE);
    gameBuilder.setKills(999);
    gameBuilder.setMaxHp(9999);
    gameBuilder.setSkill(SKILL::VERYHIGH);

    game = gameBuilder.createGame();
    game->showMe();
}
