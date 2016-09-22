#pragma once

template<typename T>
class Singleton
{
private:

	Singleton(Singleton const&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	Singleton& operator=(Singleton&&) = delete;

protected:
	Singleton();
	~Singleton();
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};