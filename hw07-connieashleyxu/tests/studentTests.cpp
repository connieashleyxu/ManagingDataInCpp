#include <string>
#include <sstream>
#include <fstream>
#include <list>

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "ITPDoubleList.hpp"
#include "movie.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string &fileNameA,
							   const std::string &fileNameB);

TEST_CASE("Student list tests", "[student]")
{
	SECTION("Default constructor, size, and destructor")
	{
		std::list<int> mylist;

		REQUIRE(mylist.size() == 0);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
		std::list<int> mylist;

		mylist.push_front(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_front(2);
		REQUIRE(mylist.back() == 1);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
		std::list<int> mylist;

		mylist.push_front(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_front(2);
		REQUIRE(mylist.back() == 1);

		mylist.pop_front();
		REQUIRE(mylist.front() == 1);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_back(2);
		REQUIRE(mylist.back() == 2);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_back(2);
		REQUIRE(mylist.back() == 2);

		mylist.pop_back();
		REQUIRE(mylist.back() == 1);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		REQUIRE(mylist.front() == 1);

		mylist.clear();
		REQUIRE(mylist.size() == 0);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_back(2);
		REQUIRE(mylist.back() == 2);

		mylist.pop_back();
		REQUIRE(mylist.back() == 1);

		std::list<int> copyList(mylist);
		REQUIRE(copyList.front() == mylist.front());
		REQUIRE(copyList.back() == mylist.back());

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_back(2);
		REQUIRE(mylist.back() == 2);

		mylist.pop_back();
		REQUIRE(mylist.back() == 1);

		std::list<int> anotherList;
		anotherList = mylist;
		REQUIRE(anotherList.front() == mylist.front());
		REQUIRE(anotherList.back() == mylist.back());

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
		std::list<int> mylist;

		if (!mylist.empty())
		{
			REQUIRE(mylist.front() == 0);
			REQUIRE(mylist.back() == 0);
			REQUIRE_NOTHROW(mylist.pop_front());
			REQUIRE_NOTHROW(mylist.pop_back());
		}

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
		std::list<int> mylist;

		mylist.push_front(1);
		REQUIRE(mylist.front() == 1);

		REQUIRE(mylist.front() == 1);

		mylist.push_front(2);
		REQUIRE(mylist.back() == 1);

		auto it = mylist.begin();
		REQUIRE(*it == 2);

		std::list<int> copyList(mylist);
		REQUIRE(copyList.front() == mylist.front());
		REQUIRE(copyList.back() == mylist.back());

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		mylist.push_back(2);
		auto it = mylist.begin();
		REQUIRE(*it == 1);

		auto it2 = it;
		REQUIRE(*it2 == *it);

		REQUIRE(it == it2);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		mylist.push_back(2);
		auto it = mylist.begin();
		REQUIRE(*it == 1);

		++it;
		REQUIRE(*it == 2);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		mylist.push_back(2);
		auto it = mylist.begin();
		REQUIRE(*it == 1);

		++it;
		REQUIRE(*it == 2);

		--it;
		REQUIRE(*it == 1);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		mylist.push_back(2);
		mylist.push_back(4);

		auto it = mylist.begin();
		mylist.insert(it, 0);
		REQUIRE(mylist.front() == 0);

		it = mylist.begin();
		++it;
		mylist.insert(it, 3);
		it = mylist.begin();
		++it;
		REQUIRE(*it == 3);

		it = mylist.end();
		--it;
		mylist.insert(it, 4);
		REQUIRE(mylist.back() == 4);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
		std::list<int> mylist;

		mylist.push_back(1);
		mylist.push_back(2);
		mylist.push_back(3);
		mylist.push_back(4);

		auto it = mylist.begin();
		it = mylist.erase(it);
		REQUIRE(mylist.front() == 2);

		it = mylist.begin();
		++it;
		it = mylist.erase(it);
		REQUIRE(*it == 4);

		it = mylist.end();
		--it;
		it = mylist.erase(it);
		REQUIRE(mylist.back() != 4);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]")
{
	SECTION("Bad constructor")
	{
		MoviePlayer player("dne.txt");
		REQUIRE(player.getCurrFrameNum() == 0);
		REQUIRE(player.getNumFrames() == 0);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
		MoviePlayer player("input/scene2.ani");
		REQUIRE(player.getCurrFrameNum() == 0);
		REQUIRE(player.getNumFrames() > 1);
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Checking frames, scene 2")
	{
		MoviePlayer player("input/scene2.ani");
		REQUIRE(player.getCurrFrame() == player.getCurrFrame());
		player.goFwrd();
		REQUIRE(player.getCurrFrame() == player.getCurrFrame());
		player.goBack();
		REQUIRE(player.getCurrFrame() == player.getCurrFrame());

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}
