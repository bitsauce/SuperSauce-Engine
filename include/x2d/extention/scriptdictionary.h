#ifndef X2D_SCRIPT_DICTIONARY_H
#define X2D_SCRIPT_DICTIONARY_H

// The dictionary class relies on the script string object, thus the script
// string type must be registered with the engine before registering the
// dictionary type

#ifndef ANGELSCRIPT_H 
// Avoid having to inform include path if header is already include before
#include <angelscript.h>
#endif

#include <string>

#ifdef _MSC_VER
// Turn off annoying warnings about truncated symbol names
#pragma warning (disable:4786)
#endif

#include <map>

// Sometimes it may be desired to use the same method names as used by C++ STL.
// This may for example reduce time when converting code from script to C++ or
// back.
//
//  0 = off
//  1 = on

#ifndef AS_USE_STLNAMES
#define AS_USE_STLNAMES 0
#endif
class XScriptArray;
class XScriptDictionary;

class CScriptDictValue
{
public:
	// This class must not be declared as local variable in C++, because it needs 
	// to receive the script engine pointer in all operations. The engine pointer
	// is not kept as member in order to keep the size down
	CScriptDictValue();
	CScriptDictValue(asIScriptEngine *engine, void *value, int typeId);

	// Destructor must not be called without first calling FreeValue, otherwise a memory leak will occur
	~CScriptDictValue();

	// Replace the stored value
	void Set(asIScriptEngine *engine, void *value, int typeId);
	void Set(asIScriptEngine *engine, const asINT64 &value);
	void Set(asIScriptEngine *engine, const double &value);

	// Gets the stored value. Returns false if the value isn't compatible with the informed typeId
	bool Get(asIScriptEngine *engine, void *value, int typeId) const;
	bool Get(asIScriptEngine *engine, asINT64 &value) const;
	bool Get(asIScriptEngine *engine, double &value) const;

	// Returns the type id of the stored value
	int  GetTypeId() const;

	// Free the stored value
	void FreeValue(asIScriptEngine *engine);

protected:
	friend class XScriptDictionary;

	union
	{
		asINT64 m_valueInt;
		double  m_valueFlt;
		void   *m_valueObj;
	};
	int m_typeId;
};

class XScriptDictionary
{
public:
	// Factory functions
	static XScriptDictionary *Create(asIScriptEngine *engine);

	// Called from the script to instantiate a dictionary from an initialization list
	static XScriptDictionary *Create(asBYTE *buffer);

	// Reference counting
	void AddRef() const;
	void Release() const;

	// Reassign the dictionary
	XScriptDictionary &operator =(const XScriptDictionary &other);

	// Sets a key/value pair
	void Set(const std::string &key, void *value, int typeId);
	void Set(const std::string &key, const asINT64 &value);
	void Set(const std::string &key, const double &value);

	// Gets the stored value. Returns false if the value isn't compatible with the informed typeId
	bool Get(const std::string &key, void *value, int typeId) const;
	bool Get(const std::string &key, asINT64 &value) const;
	bool Get(const std::string &key, double &value) const;

	// Index accessors. If the dictionary is not const it inserts the value if it doesn't already exist
	// If the dictionary is const then a script exception is set if it doesn't exist and a null pointer is returned
	CScriptDictValue *operator[](const std::string &key);
	const CScriptDictValue *operator[](const std::string &key) const;

	// Returns the type id of the stored value, or negative if it doesn't exist
	int GetTypeId(const std::string &key) const;

	// Returns true if the key is set
	bool Exists(const std::string &key) const;

	// Returns true if there are no key/value pairs in the dictionary
	bool IsEmpty() const;

	// Returns the number of key/value pairs in the dictionary
	asUINT GetSize() const;

	// Deletes the key
	void Delete(const std::string &key);

	// Deletes all keys
	void DeleteAll();

	// Get an array of all keys
	XScriptArray *GetKeys() const;

public:
	// STL style iterator
	class CIterator
	{
	public:
		void operator++();    // Pre-increment
		void operator++(int); // Post-increment

		// This is needed to support C++11 range-for
		CIterator &operator*();

		bool operator==(const CIterator &other) const;
		bool operator!=(const CIterator &other) const;

		// Accessors
		const std::string &GetKey() const;
		int                GetTypeId() const;
		bool               GetValue(asINT64 &value) const;
		bool               GetValue(double &value) const;
		bool               GetValue(void *value, int typeId) const;

	protected:
		friend class XScriptDictionary;

		CIterator();
		CIterator(const XScriptDictionary &dict,
		          std::map<std::string, CScriptDictValue>::const_iterator it);

		CIterator &operator=(const CIterator &) {return *this;} // Not used

		std::map<std::string, CScriptDictValue>::const_iterator m_it;
		const XScriptDictionary &m_dict;
	};

	CIterator begin() const;
	CIterator end() const;

	// Garbage collections behaviours
	int GetRefCount();
	void SetGCFlag();
	bool GetGCFlag();
	void EnumReferences(asIScriptEngine *engine);
	void ReleaseAllReferences(asIScriptEngine *engine);

protected:
	// Since the dictionary uses the asAllocMem and asFreeMem functions to allocate memory
	// the constructors are made protected so that the application cannot allocate it 
	// manually in a different way
	XScriptDictionary(asIScriptEngine *engine);
	XScriptDictionary(asBYTE *buffer);

	// We don't want anyone to call the destructor directly, it should be called through the Release method
	virtual ~XScriptDictionary();
	
	// Our properties
	asIScriptEngine *engine;
	mutable int refCount;
	mutable bool gcFlag;

	// TODO: memory: The allocator should use the asAllocMem and asFreeMem
	// TODO: optimize: Use C++11 std::unordered_map instead
	std::map<std::string, CScriptDictValue> dict;
};

// This function will determine the configuration of the engine
// and use one of the two functions below to register the dictionary object
void RegisterScriptDictionary(asIScriptEngine *engine);

// Call this function to register the math functions
// using native calling conventions
void RegisterScriptDictionary_Native(asIScriptEngine *engine);

// Use this one instead if native calling conventions
// are not supported on the target platform
void RegisterScriptDictionary_Generic(asIScriptEngine *engine);

#endif // X2D_SCRIPT_DICTIONARY_H