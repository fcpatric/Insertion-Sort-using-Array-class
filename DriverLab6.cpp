/// Lab 6, Insertion Sort using Array class
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// DriverLab6.cpp

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Monster.h"
#include "Array.h"

int main()
{
  // programmer's identification
  cout << "Lab 6, Insertion Sort using Array class\n";
  cout << "Programmer: Fernando Ian Patricio\n";
  cout << "Programmer's ID: 1428751\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Monster monster1("Whitesmith Harword", 1648);
  Monster monster2("Eddga", 1115);
  Monster monster3("Lord Knight Seyren", 1646);
  Monster monster4("Lady Tanee", 1688);
  Monster monster5("High Priest Magaletha", 1649);
  Monster monster6("Wounded Morroc", 1917);
  Monster monster7("Phreeoni", 1159);
  Monster monster8("Valkyrie Randgris", 1751);
  Monster monster9("High Wizard Katrinne", 1651);
  Monster monster10("Assassin Cross Eremes", 1647);

  const int sizeOfArrayOfMyStructs = 10;
  Array<Monster> arrayOfMonsters(sizeOfArrayOfMyStructs);

  arrayOfMonsters[0] = monster1;
  arrayOfMonsters[1] = monster2;
  arrayOfMonsters[2] = monster3;
  arrayOfMonsters[3] = monster4;
  arrayOfMonsters[4] = monster5;
  arrayOfMonsters[5] = monster6;
  arrayOfMonsters[6] = monster7;
  arrayOfMonsters[7] = monster8;
  arrayOfMonsters[8] = monster9;
  arrayOfMonsters[9] = monster10;

  cout << "UNSORTED ARRAY OF MONSTERS:\n";
  cout << "MONSTER NAME(MONSTER ID)" << endl;
  cout << "----------------------------\n";
  cout << arrayOfMonsters;
  cout << "----------------------------\n\n";

  arrayOfMonsters.insertionSort();
  cout << "SORTED ARRAY OF MONSTERS:\n";
  cout << "MONSTER NAME(MONSTER ID)" << endl;
  cout << "----------------------------\n";
  cout << arrayOfMonsters;
  cout << "----------------------------\n\n";

  cout << "Press enter to exit.";
  cin.get();
}
