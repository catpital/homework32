#pragma once

#include "IDBConnection.h"

#include <gmock/gmock.h>

class DBConnectionMock :
	public IDBConnection
{
public:
	MOCK_METHOD(bool, open, (), (override));
	MOCK_METHOD(bool, close, (), (override));
	MOCK_METHOD(std::string, execQuery, (const std::string&), (override));
};
