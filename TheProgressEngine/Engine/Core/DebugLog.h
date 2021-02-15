#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <iostream>
#include <string>
#include <fstream>

class DebugLog {
public:
	enum class MessageType : unsigned short {
		TYPE_NONE = 0,
		TYPE_FATAL_ERROR,
		TYPE_ERROR,
		TYPE_WARNING,
		TYPE_TRACE,
		TYPE_INFO
	};

	DebugLog() = delete;
	DebugLog(const DebugLog&) = delete;
	DebugLog(DebugLog&&) = delete;
	DebugLog& operator=(const DebugLog&) = delete;
	DebugLog& operator=(DebugLog&&) = delete;

	static void OnCreate(const std::string& name_ = "ProgressEngineLog");
	static void SeverityLvl(MessageType type_);
	static void Info(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Trace(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Warning(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void Error(const std::string& message_, const std::string& fileName_,
		const int line_);
	static void FatalError(const std::string& message_, const std::string& fileName_,
		const int line_);
private:
	static void Log(const MessageType type_, const std::string& message_,
		const std::string& fileName_, const int line_);
	static MessageType currentSev;
	static std::string outputName;
};
#endif
