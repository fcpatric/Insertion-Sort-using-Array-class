/// Lab 6, Insertion Sort using Array class
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// Monster.cpp

Monster::Monster()
{
  name = "";
  ID = 0;
}

Monster::Monster( const string mName, const int mID )
{
  name = mName;
  ID = mID;
}

Monster& Monster::operator=( const Monster& m )
{
  name = m.name;
  ID = m.ID;
  return *this;
}

bool Monster::operator==( const Monster& m )
{
  return (name == m.name && ID == m.ID);
}

bool Monster::operator>( const Monster& m )
{
  return (name > m.name);
}

bool Monster::operator<( const Monster& m )
{
  return (name < m.name);
}

ostream& operator<<(ostream &out, const Monster& m)
{
  out << m.name << "(" << m.ID << ")";

  return out;
}
