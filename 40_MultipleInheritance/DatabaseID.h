#pragma once

class DatabaseID {
public:
	DatabaseID(int id) : theID(id){}
	int id() { return theID; }
private:
	int theID;
};