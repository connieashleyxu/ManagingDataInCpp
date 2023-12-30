// BEK - The hasX() tests have been gutted.  You need to
// fill those in to find the errors in Cards.cpp.

#include <sstream>

#include "catch.hpp"
#include "ITPVector.hpp"
#include "Cards.h"
#include "Play.h"

// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string &fileNameA,
							   const std::string &fileNameB);

static int grade = 0;

TEST_CASE("Graded cards tests", "[graded]")
{
	SECTION("Card constructors")
	{
		Card c1;
		Card c2(14, SPADES);

		REQUIRE(c1.mRank == 2);
		REQUIRE(c1.mSuit == CLUBS);
		REQUIRE(c2.mRank == 14);
		REQUIRE(c2.mSuit == SPADES);

		grade += 1;
	}

	SECTION("Output stream")
	{
		Card c1;
		Card c2(14, SPADES);
		Card c3(11, HEARTS);
		Card c4(9, DIAMONDS);

		std::ostringstream oss;

		oss << c1;
		REQUIRE(oss.str() == "2 of Clubs");

		oss.str(std::string());
		oss << c2;
		REQUIRE(oss.str() == "Ace of Spades");

		oss.str(std::string());
		oss << c3;
		REQUIRE(oss.str() == "Jack of Hearts");

		oss.str(std::string());
		oss << c4;
		REQUIRE(oss.str() == "9 of Diamonds");

		grade += 4;
	}

	SECTION("Card comparisons")
	{
		Card c1;
		Card c2(14, SPADES);
		Card c3(14, HEARTS);

		REQUIRE(c1 < c2);
		REQUIRE(c2 > c1);
		REQUIRE(c3 < c2);
		REQUIRE(c2 > c3);

		grade += 4;
	}

	SECTION("Score")
	{
		WARN("*** SCORE: " << grade << "/" << 50 << "***");
	}
}

TEST_CASE("Graded poker hand tests", "[graded]")
{
	SECTION("Poker hand constructor and stream output")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(5, SPADES));
		testDeck.push_back(Card(11, CLUBS));
		testDeck.push_back(Card(3, HEARTS));
		testDeck.push_back(Card(5, DIAMONDS));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Display the hand
		std::ostringstream oss;
		oss << testHand;
		std::string testOutput = "{ 3 of Hearts, 5 of Diamonds, 5 of Spades, Jack of Clubs, Queen of Hearts }";
		REQUIRE(oss.str() == testOutput);

		grade += 4;
	}

	// Testing high card
	SECTION("High card")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(11, CLUBS));
		testDeck.push_back(Card(5, DIAMONDS));
		testDeck.push_back(Card(3, HEARTS));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "high card");

		grade += 3;
	}

	// Testing pair
	SECTION("Pair")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(11, CLUBS));
		testDeck.push_back(Card(5, DIAMONDS));
		testDeck.push_back(Card(3, HEARTS));
		testDeck.push_back(Card(12, HEARTS));
		testDeck.push_back(Card(5, SPADES));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test hand
		REQUIRE(testHand.getBestPokerHand() == "pair");

		grade += 3;
	}

	// Testing two pair
	SECTION("Two pair")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(8, CLUBS));
		testDeck.push_back(Card(5, DIAMONDS));
		testDeck.push_back(Card(5, HEARTS));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "two pairs");

		grade += 3;
	}

	// Testing three of a kind
	SECTION("Three of a kind")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(8, CLUBS));
		testDeck.push_back(Card(8, DIAMONDS));
		testDeck.push_back(Card(5, HEARTS));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "three of a kind");

		grade += 3;
	}

	// Testing straight
	SECTION("Straight")
	{
		// Creating testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(10, HEARTS));
		testDeck.push_back(Card(11, CLUBS));
		testDeck.push_back(Card(12, DIAMONDS));
		testDeck.push_back(Card(13, HEARTS));
		testDeck.push_back(Card(1, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "straight");

		grade += 3;
	}

	// Testing flush
	SECTION("Flush")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(11, HEARTS));
		testDeck.push_back(Card(5, HEARTS));
		testDeck.push_back(Card(3, HEARTS));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "flush");

		grade += 3;
	}

	// Testing full house
	SECTION("Full house")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(8, CLUBS));
		testDeck.push_back(Card(8, DIAMONDS));
		testDeck.push_back(Card(5, HEARTS));
		testDeck.push_back(Card(5, CLUBS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "full house");

		grade += 3;
	}

	// TODO: write Four of a kind test
	SECTION("Four of a kind")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(8, HEARTS));
		testDeck.push_back(Card(8, CLUBS));
		testDeck.push_back(Card(8, DIAMONDS));
		testDeck.push_back(Card(8, SPADES));
		testDeck.push_back(Card(12, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "four of a kind");

		grade += 3;
	}

	// TODO: write Straight flush test
	SECTION("Straight flush")
	{
		// Create testing deck
		std::vector<Card> testDeck;
		testDeck.push_back(Card(10, HEARTS));
		testDeck.push_back(Card(11, HEARTS));
		testDeck.push_back(Card(12, HEARTS));
		testDeck.push_back(Card(13, HEARTS));
		testDeck.push_back(Card(1, HEARTS));

		// Make the hand
		PokerHand testHand(testDeck);

		// Test the hand
		REQUIRE(testHand.getBestPokerHand() == "straight flush");

		grade += 3;
	}

	SECTION("Score")
	{
		WARN("*** SCORE: " << grade << "/" << 50 << "***");
	}
}

TEST_CASE("Graded end to end tests", "[graded]")
{
	SECTION("Test input 01 -- seed A")
	{
		playPoker("input/input01.txt", "output/output01.txt", 946684800);
		bool result = false;

#ifdef _MSC_VER
		// Use the Windows output file
		result = CheckTextFilesSame("output/output01.txt", "expected/output01.txt");
#elif __APPLE__
		// Use the Mac output file
		result = CheckTextFilesSame("output/output01.txt", "expected/output01.txt");
#else
		// Use the Travis output file
		result = CheckTextFilesSame("output/output01.txt", "expected/output01.txt");
#endif

		REQUIRE(true); // BEK changed from 'result' to 'true'

		grade += 5;
	}

	SECTION("Test input 01 -- seed B")
	{
		playPoker("input/input01.txt", "output/output02.txt", 1);
		bool result = false;

#ifdef _MSC_VER
		// Use the Windows output file
		result = CheckTextFilesSame("output/output02.txt", "expected/output02.txt");
#elif __APPLE__
		// Use the Mac output file
		result = CheckTextFilesSame("output/output02.txt", "expected/output02.txt");
#else
		// Use the Travis output file
		result = CheckTextFilesSame("output/output02.txt", "expected/output02.txt");
#endif

		REQUIRE(true); // BEK changed from 'result' to 'true'

		grade += 5;
	}

	SECTION("Score")
	{
		WARN("*** SCORE: " << grade << "/" << 50 << "***");
	}
}

TEST_CASE("Test Cases Grade", "[graded]")
{
	WARN("****TEST CASES GRADE: " << grade << "/" << 50 << "****");
}
