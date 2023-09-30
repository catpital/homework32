#include "ClassThatUsesDB.h"

ClassThatUsesDB::ClassThatUsesDB(std::unique_ptr<IDBConnection> db_connection) : _db_connection(std::move(db_connection)) {}

void ClassThatUsesDB::openConnection()
{
	_db_connection->open();
}

void ClassThatUsesDB::useConnection(const std::string& query)
{
	auto req = _db_connection->execQuery(query);
}

void ClassThatUsesDB::closeConnection()
{
	_db_connection->close();
}
