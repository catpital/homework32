#pragma once

#include <memory>

#include "IDBConnection.h"

class ClassThatUsesDB
{
public:
	ClassThatUsesDB(std::unique_ptr<IDBConnection>);
	void openConnection();
	void useConnection(const std::string& query);
	void closeConnection();
private:
	std::unique_ptr<IDBConnection> _db_connection;
};
