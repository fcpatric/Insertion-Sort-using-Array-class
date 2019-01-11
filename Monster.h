/// Lab 6, Insertion Sort using Array class
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Monster
{
  private:
    string name;
    int ID;

  public:
    Monster();
    Monster(const string mName, const int mID);
    Monster& operator=( const Monster& m );
    bool operator==( const Monster& m );
    bool operator>( const Monster& m );
    bool operator<( const Monster& m );

  friend ostream& operator<<(ostream &out, const Monster& m);
};

#include "Monster.cpp"

#endif // MONSTER_H
