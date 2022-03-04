#include <iostream>


class Log {
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo;
public:
	void setLevel(Level level) {
		m_LogLevel = level;
	}

	void error(const char* message) {
		if (m_LogLevel >= LevelError) {
			std::cout << "[ERROR!] " << message << std::endl;
		}
	}

	void warn(const char* message) {
		if (m_LogLevel >= LevelWarning) {
			std::cout << "[WARNING!] " << message << std::endl;
		}
	}

	void info(const char* message) {
		if (m_LogLevel >= LevelInfo) {
			std::cout << "[INFO!] " << message << std::endl;
		}
	}
};
int main() {
	
	Log log;
	log.setLevel(Log::LevelInfo);
	log.warn("Hello!");
	log.error("Hello!");
	log.info("Hello!");
	return 0;
}