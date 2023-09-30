#pragma once

#include <string>

class IDBConnection
{
public:
	virtual ~IDBConnection() = default;
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual std::string execQuery(const std::string& q) = 0;
};
