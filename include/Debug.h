#pragma once

#define DEBUG_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

namespace DebugTools
{	
	extern void DebugCallBack();

	class UITools
	{
	public:
		static char* ReplicateChar(char chr, int times)		// concatenates the char into an empty string for provided number of times
		{
			char* MultipleChars = new char[times];
			
			for (int x = 0; x < times; x++)
				MultipleChars[x] = chr;

			return MultipleChars;
		}
	};

	class Debugger
	{
	public:
		std::string Title;
		int LogCount; 
	
	public:
		void StartConsole();	// Set up the debug console tools 

		void Log(char*);	// Outputs the provided string as a debug message to the console
		void Log(char**, int);	// Outputs the provided string array as debug messages to the console
		
		template<typename T>
		void Log(T value)	// Outputs the provided value of type T to the console 
		{
			std::cout << "\nDebug " << this->LogCount++ << ": " << value << "\n\n";
		}
		
		template<typename T>
		void Log(char* message, T value)	// Outputs the provided value of type T to the console 
		{
			std::cout << "\nDebug " << this->LogCount++ << ": " << message << ": " << value << "\n\n";
		}
		
		template<typename T>
		void Log(T* value, unsigned int size)	// Outputs the values of elements of the provided array of type T to the console
		{
			for (int x = 0; x < size; x++)
				std::cout << "\nDebug " << this->LogCount++ << ": " << value[x] << '\n';
		}

		template<typename T>
		void Log(std::vector<T> vectorArray)	// Outputs the values of elements of the provided array of type T to the console
		{
			int size = vectorArray.size();

			for (int x = 0; x < size; x++)
				std::cout << "\nDebug " << this->LogCount++ << ": " << vectorArray.at(x) << '\n';
		}

	public:
		Debugger() : Title("New Debug Console"), LogCount(0)
		{	 
		}

		Debugger(char* title) : Title(title), LogCount(0)
		{
		}
	}; 
}
