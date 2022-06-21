#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

#include "asm_file.h"

class AsmFileWriter
{
	private:
		AsmFile* asmFile;
	public:
		AsmFileWriter(AsmFile* asmFile);
		~AsmFileWriter();

		void saveFile(std::string asmFilePath);
};