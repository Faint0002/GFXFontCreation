#pragma once
#include "Common.hpp"

class fileStream {
public:
	fileStream(fs::path path, bool binaryFlag = false) : m_path(path) {
		m_stream.open(path.string(), binaryFlag ? std::ios::binary : std::ios::out);
	}
	~fileStream() {
		finish();
	}
public:
	void write(std::string line) {
		m_stream << line << std::endl;
	}
	void write(int8_t* array, int arraySize) {
		m_stream.write(reinterpret_cast<char*>(array), arraySize);
	}
	void finish() {
		m_stream.close();
	}
public:
	fs::path m_path{};
	std::ofstream m_stream{};
};