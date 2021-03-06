#pragma once


#include <collection.h>
#include <ppltasks.h>
#include "ROMDBEntry.h"
#include "Database.h"
#include "ROMDBEntry.h"




using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace Platform::Collections;
using namespace Concurrency;



namespace GBA10
{
	namespace WFC = Windows::Foundation::Collections;
	namespace PC  = Platform::Collections;

	ref class ROMDatabase sealed
	{
	public:

		ROMDatabase();
	internal:
		task<void> Initialize(void);
		task<void> AddAsync(ROMDBEntry^ entry);
		task<Vector<ROMDBEntry^>^> RetrieveQuerry();
		task<void> UpdateAsync(ROMDBEntry^ entry);
		ROMDBEntry^ GetEntryFromName(Platform::String^ name);
		task<void> RemoveAsync(ROMDBEntry^ entry);
		
		property PC::Vector<ROMDBEntry^>^ AllROMDBEntries
		{
			PC::Vector<ROMDBEntry^>^ get()
			{
				return _allROMDBEntries;
			}
		}

	private:
		//static ROMDatabase^ singleton;

		SQLiteWinRT::Database^ db;
		SQLiteWinRT::Statement^ statement; //temporary pointer to store statement

		PC::Vector<ROMDBEntry^>^ _allROMDBEntries;
		task<void> LoadSnapshotImage();
		Platform::String^ ReplaceSingleQuote(Platform::String^ pstr);
		bool initialized;
		
	};

		

}