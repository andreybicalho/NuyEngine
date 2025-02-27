#pragma once

#include <string>

namespace nuy { namespace utils { 

	class FileUtils
	{
	public:
		static std::string ReadFile(const char* filePath)
		{
			FILE* file = fopen(filePath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}
	};
} }