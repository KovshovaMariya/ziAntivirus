#include "DatabaseEditorLogic.h"
#include "PipeNamesBuffsizesPaths.h"

void DatabaseEditorLogic::MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

DataTable^ DatabaseEditorLogic::fillDataTable(SQLiteConnection^ database) {
	DataTable^ table;
	try
	{
		SQLiteCommand^ cmdSelect = database->CreateCommand();
		//�������� ��������, ��� SQL ������ ��������� ��� ������� �������
		cmdSelect->CommandText = "SELECT * FROM	ENTRIES;";
		SQLiteDataReader^ reader = cmdSelect->ExecuteReader();

		//����������
		DataColumn^ column; //������� �������
		DataRow^ row; //������ �������

		//������� ������� ������
		table = gcnew DataTable();

		//������ �������� ��������
		vector<String^>^ nameColumns = gcnew vector<String^>();

		//�������� ������ � ��������
		for (int i = 0; i < reader->FieldCount; i++) {
			nameColumns->push_back(reader->GetName(i));
			column = gcnew DataColumn(nameColumns->at(i), String::typeid);
			table->Columns->Add(column);
		}

		std::string strPrefix(sizeof(uint64_t), 0);
		uint64_t intPrefix;

		//��������� �� ������ ������
		while (reader->Read()) {
			//��������� ������� �������
			row = table->NewRow();
			//� ������ ������ ��������� �� ���� ��������
			for (int i = 0; i < reader->FieldCount; i++) {
				//��������� �������� ������� � row
				if (i == 3)
				{
					intPrefix = Convert::ToInt64(reader->GetValue(i)->ToString());
					memcpy(strPrefix.data(), &intPrefix, sizeof(uint64_t));
					row[nameColumns->at(i)] = msclr::interop::marshal_as<String^>(strPrefix);
					continue;
				}				
				row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
				reader->GetValue(i)->ToString();
			}
			table->Rows->Add(row);
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
	}
	return table;
}

void DatabaseEditorLogic::addRecord(SQLiteConnection^ database, String^ malwareName, String^ inputSignature, String^ offsetBegin, String^ offsetEnd) {
	SHA256 sha256;
	std::string signature = msclr::interop::marshal_as<std::string>(inputSignature);
	std::string signaturePrefix = msclr::interop::marshal_as<std::string>(inputSignature->Substring(0, 8));
	uint64_t intSignature;
	memcpy(&intSignature, signaturePrefix.c_str(), sizeof(uint64_t));
	//std::string ABOBA(sizeof(uint64_t), 0); memcpy(ABOBA.data(), &intSignature, sizeof(uint64_t));
	SQLiteCommand^ cmdInsertValue = database->CreateCommand();
	cmdInsertValue->CommandText = "INSERT INTO ENTRIES (MW_NAME, SIGN_LENGTH, SIGN_PREFIX, SHA256, OFFSET_BEGIN, OFFSET_END)" +
		" VALUES('" + malwareName + "', " + inputSignature->Trim()->Length + ", " + intSignature + ", '" +
		gcnew String(sha256.getSHA(signature).c_str()) + "', " + offsetBegin + ", " + offsetEnd + ");";
	cmdInsertValue->ExecuteNonQuery();
}

void DatabaseEditorLogic::deleteRecord(SQLiteConnection^ database, String^ malwareName) {
	SQLiteCommand^ cmdInsertValue = database->CreateCommand();
	cmdInsertValue->CommandText = "DELETE FROM ENTRIES WHERE MW_NAME = '" + malwareName + "';";
	cmdInsertValue->ExecuteNonQuery();
}

void DatabaseEditorLogic::createDatabase(SQLiteConnection^ database, String^ fileName) {
	database->ConnectionString = "Data Source=\"" + fileName + "\"";
	database->Open();
	SQLiteCommand^ cmdInsertValue = database->CreateCommand();
	cmdInsertValue->CommandText = "CREATE TABLE \"ENTRIES\" (\"ID\" TEXT NOT NULL DEFAULT 'kovshova',\
			\"MW_NAME\"	TEXT NOT NULL,\
			\"SIGN_LENGTH\"	INTEGER NOT NULL,\
			\"SIGN_PREFIX\"	INTEGER NOT NULL,\
			\"SHA256\"	TEXT,\
			\"OFFSET_BEGIN\"	INTEGER NOT NULL,\
			\"OFFSET_END\"	INTEGER NOT NULL\
			);";
	cmdInsertValue->ExecuteNonQuery();
}

void DatabaseEditorLogic::openDatabase(SQLiteConnection^ database, String^ fileName)
{
	try
	{
		database->ConnectionString = "Data Source=\"" + fileName + "\"";
		database->Open();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
	}
}

void DatabaseEditorLogic::openDatabase(SQLiteConnection^ database)
{
	try
	{
		database->ConnectionString = "Data Source=\"" + DATABASE_PATH + "\"";
		database->Open();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
	}
}
