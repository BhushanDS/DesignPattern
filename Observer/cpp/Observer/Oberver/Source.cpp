#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

class Player : public Observer {
private:
    std::string playerName;
    int health;
    Subject& subject;  // Reference to the subject

public:
    Player(const std::string& name, Subject& subj) : playerName(name), health(100), subject(subj) {
        subject.addObserver(this);
    }

    ~Player() {
        subject.removeObserver(this);
    }

    void update() override {
        std::cout << playerName << "'s health has been updated to " << health << std::endl;
    }

    void setHealth(int newHealth) {
        health = newHealth;
        subject.notifyObservers();  // Notify observers when health changes
    }
};

int main() {
    Subject game;

    Player player1("Player 1", game);
    Player player2("Player 2", game);

    player1.setHealth(80);

    return 0;
}
