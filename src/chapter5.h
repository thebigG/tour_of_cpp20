#ifndef CHAPTER5_H
#define CHAPTER5_H
#include <memory>

struct Blob {
  float value;
};

class Player {
 public:
  Player(int id);
  Player(const Player& otherPlayer);             // copy constructor
  Player(Player&& otherPlayer);                  // move constructor
  Player& operator=(const Player& otherPlayer);  // copy assignment
  Player& operator=(Player&& otherPlayer);       // move assignment

  std::unique_ptr<Blob> blob;

  float getHealth() const;
  void setHealth(float newHealth);

  int getId() const;
  void setId(int newId);

  bool hasBlob();

 private:
  float health;  // value between 0 and 1(might be a good candidate to
                 // experiment with concepts)
  int id;
};

#endif
