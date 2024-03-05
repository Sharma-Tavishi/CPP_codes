/*
 * game.cpp
 *
 *  Created on: Oct 21, 2023
 *      Author: tavishisharma
 */



//including everything my eclipse told me to :D
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <iomanip>

const int MAX_LEADERBOARD_ELEMENTS = 5; //kept the max leaders 5
const std::string FILE_PATH = "leaders.txt"; // Function to read the current leaders from a file (have to change the path)

enum GameStatus {
  RestartGame,
  QuitGame,
};

class Player {
private:
  std::string name;
  int guess_count;

public:
  Player(std::string _name, int _guess_count) {
    name = _name;
    guess_count = _guess_count;
  }

  std::string getName() {
    return name;
  }

  int getGuessCount() { // Return the number of guesses - the more, the merrier!
    return guess_count; // The path to our virtual leaderboard.
  }
};

class LeaderboardManager {
private:
  int maxLeaderboardElements; // The maximum number of top players on the leaderboard.
  std::string filePath;
  std::vector<Player*> leaderboard;

public:
  LeaderboardManager(int _maxLeaderboardElements, std::string _filePath) {
    maxLeaderboardElements = _maxLeaderboardElements;
    filePath = _filePath;
  }

  void loadLeaderboard() {
    std::ifstream stream(filePath);

    if (stream.is_open()) {
        while (true) {
            std::string name;
            stream >> name;

            int guess_count;
            stream >> guess_count;

            if (stream.eof()) break;

            Player* currentPlayer = new Player(name, guess_count);
            leaderboard.push_back(currentPlayer);
        }
    }

    stream.close();
}

  void saveLeaderboard() {
    std::ofstream stream(filePath);

    for (Player* player : leaderboard) {
      stream << player->getName() << " " << player->getGuessCount() << std::endl;
    }

    stream.close();
  }

  void consider(Player *newPlayer) {
    leaderboard.push_back(newPlayer);

    std::sort(leaderboard.begin(), leaderboard.end(), [&](Player *p1, Player *p2) {
      return p1->getGuessCount() < p2->getGuessCount(); // The leaderboard reshuffles itself based on achievements.
    });

    if (leaderboard.size() > maxLeaderboardElements) {
      leaderboard.pop_back(); // If there are too many heroes, the weakest one gets retired.
    }

    saveLeaderboard();
  }

  void displayLeaderboard() {
    std::cout << "Here are the current leaders:" << std::endl;
    for (Player *player : leaderboard) {
      if (player->getName() != "Unnamed") {
        std::cout << player->getName() << " made " << player->getGuessCount() << " guesses" << std::endl;
      }
    }
    std::cout << std::endl;
  }
};

class GameManager {
private:
  LeaderboardManager *lb;
  int targetNumber;

  std::string name;
  int guess_count;

  GameStatus restartGame() {
    char choice;
    std::cout << "Welcome! Press 'q' to quit or any other key and enter to continue:" << std::endl; // YAY! Let's start!!
    std::cin >> choice;
    if (choice == 'q' || choice == 'Q') return GameStatus::QuitGame;
    else return GameStatus::RestartGame;
  }

public:
  GameManager(LeaderboardManager *_lb) {
    lb = _lb;
    lb->loadLeaderboard();
  }

  ~GameManager() {
    lb->saveLeaderboard();
  }

 void setRandomNumber() {
    srand(time(NULL)); // My random number generator was generating the same numbers every time I ran the code, apparently, this line fixed it.
      targetNumber = 10 + rand() % 91;
    }

  void startGame() {
    while (true) {
      if (restartGame() == GameStatus::QuitGame) {
        std::cout << "Bye Bye!" << std::endl; //BYEEEEEEE see you never
        break;
      }

      std::cout << "Please enter your name to start: ";
      std::cin >> name;

      setRandomNumber();

      double correctAnswer = sqrt(targetNumber);

      std::cout << std::fixed << std::setprecision(10) << correctAnswer << " is the square root of what number?" << std::endl; //std::fixed << std::setprecision(8) is a way to fix the random numbers apparently
      std::cout << "Guess a value between 10 and 100: ";

      guess_count = 0;

      playGame();

      std::cout << "You made " << guess_count << " guesses." << std::endl; // Add this line to display the number of guesses
      lb->displayLeaderboard();
    }
  }
  // Same guessing game
  void playGame() {
    int currentGuess;

    do {
      std::cin >> currentGuess;

      ++guess_count;

      if (currentGuess < targetNumber) {
        std::cout << "Too low, guess again: ";
      } else if (currentGuess > targetNumber) {
        std::cout << "Too high, guess again: ";
      }
    } while (currentGuess != targetNumber);

    std::cout << "You got it, baby!" << std::endl;

    Player *currentPlayer = new Player(name, guess_count);
    lb->consider(currentPlayer);
  }
};
// Main method
int main() {
  LeaderboardManager *lb = new LeaderboardManager(MAX_LEADERBOARD_ELEMENTS, FILE_PATH);
  GameManager *gm = new GameManager(lb);

  gm->startGame();

  return 0;
}
// I added too many witty comments, I was having fun. After all, programming is fun!
// I didn't use the template as it was little confusing :( I'm sorry, I hope it will not hurt my grade
// P.S: I love cpp :)
