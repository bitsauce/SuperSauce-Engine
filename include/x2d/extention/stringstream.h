#ifndef X2D_STRING_STREAM_H
#define X2D_STRING_STREAM_H

#include "../engine.h"

class XStringStream
{
	AS_DECL_REF
public:
	XStringStream() :
		m_stream()
	{
	}
	
	XStringStream(const string &content) :
		m_stream(content)
	{
	}
	
	void write(const bool);
	void write(const char);
	void write(const short);
	void write(const int);
	void write(const long);
	void write(const float);
	void write(const double);
	void write(const string&);
	void write(const Vector2&);
	
	void read(bool&);
	void read(char&);
	void read(short&);
	void read(int&);
	void read(long&);
	void read(float&);
	void read(double&);
	void read(string&);
	void read(Vector2&);

	string str() const;

private:
	static XStringStream *Factory()
	{
		return new XStringStream();
	}

	stringstream m_stream;
};

#endif // X2D_STRING_STREAM_H