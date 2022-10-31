#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int getRandom() {
            int x = rand();
            x = x % 10;
            return x;
        };

int offspring = 0;
int foodCount = 5;
int days = 0;
int buddy = 0;
void restart() {
     cout <<"\n";
        offspring = 0;
        foodCount = 5;
        days = 0;
        buddy = 0;
}
class Hunger {
    public:
        int h;
        void getHunger();
        void setHunger();
};

class Creature: public Hunger {
    float deathChance;
    float reproductionChance;
    public:
        int getHunger() {
            return h;
        }
        void setHunger(int hunger) {
            h = hunger;
        }
        void life();
};

class World: public Creature {
    float CreateChance;
    public:
        string name;
        void createCreature() {
                cout << "Creature Created\n--------------\nName Creature: ";
                cin >> name;
                cout << "-\n";

                int num = 0;
                while (::getRandom() != -1) {
                    num++;
                    cout << "Day " << num << ": ";
                    int x = life(::getRandom());
                    cout << "-\n";
                    if (x == 0) {
                        break;
                    }
                }
                cout << name << " has died\n";
                cout << "--------------\n";
                cout << "Days Survived: " << days << "\nAmount of Offspring: " << ::offspring << "\nAmount of Buddies: " << buddy << "\n";
        }

        int life(int x) {
            days++;
            if (x == 9) {
                cout << name << " has reproduced\n";
                ::offspring++;
                return 1;
            } else if (x == 8) {
                if (offspring > 0) {
                cout << "Offspring has died \n";
                ::offspring--;
                } else {
                    cout << "Depressed\n";
                }
                return 1;
            } else if (x == 7) {
                cout << "Gained Food: ";
                foodCount++;
                cout << foodCount << " total \n";
                return 1;
            } else if (x == 6) {
                cout << "Lost Food: ";
                if (foodCount > 0) {
                foodCount--;
                cout << foodCount << " left \n";
                }
                return 1;
            } else if (x == 5) {
                setHunger(::getRandom());
                int y = getHunger();
                if (0 <= foodCount - y) {
                    foodCount = foodCount - y;
                    cout << "Ate " << y << " ammount of food, there is " << foodCount << " food left\n";
                    return 1;
                } else {
                    cout << "Not enough food: needed " << y << "\n";
                    return 0;
                }
            } else if (x == 4) {
                cout << "Made a buddy\n";
                buddy++;
            } else if (x == 3) {
                if (buddy > 0) {
                    cout << "Buddy has died\n";
                    buddy--;
                    return 1;
                } else {
                    cout << "Went Hiking\n";
                    return 1;
                }
            } else if (x == 2) {
                cout << "Saw a cool rock\n";
                return 1;
            } else if (x == 1) {
                cout << "Found no extra food\n";
            } else if (x == 0) {
                cout << "Went Stargazing\n";
            }
    }
};



int main() {
    srand((unsigned) time(NULL));
    World w;
    int x = 1;
    while (x == 1) {
        w.createCreature();
            cout << "--------------\n";
        cout << "Would you like to play again? Yes or No\n";
        string y;
        cin >> y;
        if (y == "Yes" || y == "yes" || y == "YES") {
            ::restart();
            continue;
        } else if (y == "No" || y == "no" || y == "NO") {
            break;
        }
    }


    cout <<"\nFinished";
    return 0;
}