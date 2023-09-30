#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ClassThatUsesDB.h"
#include "DBConnectionMock.h"

TEST(DBConnectionMockTest, classThatUsesDB_openConnection) {
	std::unique_ptr<DBConnectionMock> db_con_mock = std::make_unique<DBConnectionMock>();
	EXPECT_CALL(*db_con_mock, open()).Times(1);
	ClassThatUsesDB class_object(std::move(db_con_mock));	

	class_object.openConnection();
}

TEST(DBConnectionMockTest, classThatUsesDB_useConnection) {
	std::unique_ptr<DBConnectionMock> db_con_mock = std::make_unique<DBConnectionMock>();
	std::string query = "";
	EXPECT_CALL(*db_con_mock, execQuery(query)).Times(1);
	ClassThatUsesDB class_object(std::move(db_con_mock));	

	class_object.useConnection(query);
}

TEST(DBConnectionMockTest, classThatUsesDB_closeConnection) {
	std::unique_ptr<DBConnectionMock> db_con_mock = std::make_unique<DBConnectionMock>();
	EXPECT_CALL(*db_con_mock, close()).Times(1);
	ClassThatUsesDB class_object(std::move(db_con_mock));	

	class_object.closeConnection();
}

int main(int argc, char** argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
