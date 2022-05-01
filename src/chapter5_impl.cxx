#include <utility>

#include "chapter5.h"

Player::Player(int newId) : health{1}, id{newId} {
  blob = std::make_unique<Blob>();
}

Player::Player(const Player& otherPlayer) {
  blob = std::make_unique<Blob>();
  this->health = otherPlayer.health;
  this->id = otherPlayer.id;
  blob->value = otherPlayer.blob->value;
}

Player::Player(Player&& otherPlayer) {
  //"move" operations degrade to copies when it comes
  // built-in types such as int and float.
  // When move is more relevant is in the context of resource owners
  // such as smart pointers. Or in this case the mighty blob.
  this->id = std::move(otherPlayer.id);
  this->health = std::move(otherPlayer.health);
  this->blob = std::move(otherPlayer.blob);
}

Player& Player::operator=(const Player& otherPlayer) {
  this->blob = std::make_unique<Blob>();
  this->health = otherPlayer.health;
  this->id = otherPlayer.id;
  blob->value = otherPlayer.blob->value;
  return *this;
}  // copy assignment
Player& Player::operator=(Player&& otherPlayer) {
  //"move" operations degrade to copies when it comes
  // built-in types such as int and float.
  // When move is more relevant is in the context of resource owners
  // such as smart pointers. Or in this case the mighty blob.
  this->id = std::move(otherPlayer.id);
  this->health = std::move(otherPlayer.health);
  this->blob = std::move(otherPlayer.blob);
  return *this;
}  // move assignment
float Player::getHealth() const { return health; }

void Player::setHealth(float newHealth) { health = newHealth; }

int Player::getId() const { return id; }

void Player::setId(int newId) { id = newId; }

bool Player::hasBlob() { return blob.get() != nullptr ? true : false; }
