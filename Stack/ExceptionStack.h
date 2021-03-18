#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>


namespace exc {
	class Exception
	{
	private:
		char* message;
	public:
		Exception(const char* arg_message)
		{
			message = new char[strlen(arg_message) + 1];
			strcpy(message, arg_message);
		}
		Exception(const Exception& arg)
		{
			message = new char[strlen(arg.message) + 1];
			strcpy(message, arg.message);
		}
		~Exception()
		{
			delete message;
		}
		const char* what() const { return message; }
	};

	// StackOverFlow and StackEmpty
	class StackOverFlow : public Exception
	{
	public:
		explicit StackOverFlow(const char* arg) : Exception(arg) {}
		//..explicit StackOverFlow(const StackOverFlow& arg) : Exception(arg) {}
	};

	class StackEmpty : public Exception
	{
	public:
		explicit StackEmpty(const char* arg) : Exception(arg) {}
		//..explicit StackEmpty(const StackEmpty& arg) : Exception(arg) {}
	};


}

