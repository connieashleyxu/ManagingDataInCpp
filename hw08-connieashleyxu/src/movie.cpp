// FROM hw07 (slightly modified)

#include "movie.h"

// Parameterized Constructor
MoviePlayer::MoviePlayer(std::string filmName)
	: mFilmName(filmName), currFrameNum(0), pos(mFilm.begin())
{
	loadTape();
}

// Destructor
MoviePlayer::~MoviePlayer()
{
	mFilm.clear();
}

// Moves the current "frame" forward by 1 frame
void MoviePlayer::goFwrd()
{
	if (currFrameNum < mFilm.size() - 1)
	{
		++currFrameNum;
		++pos;
	}
}

// Moves the current "frame" backward by 1 frame
void MoviePlayer::goBack()
{
	if (currFrameNum > 0)
	{
		--currFrameNum;
		--pos;
	}
}

// Moves the current "frame" to the movie's beginning again
void MoviePlayer::rewind()
{
	currFrameNum = 0;
	pos = mFilm.begin();
}

// Gets the string that contains the current "frame" as stored
std::string MoviePlayer::getCurrFrame()
{
	if (pos != mFilm.end())
	{
		return *pos;
	}
	return "";
}

// Deletes the current frame, moves forward to the next one
void MoviePlayer::delCurrFrame()
{
	if (mFilm.size() == 1 || currFrameNum == mFilm.size() - 1)
	{
		return;
	}

	pos = mFilm.erase(pos);
}

// Copies current frame and places the copy BEFORE the current frame
void MoviePlayer::copyCurrFrame()
{
	if (pos != mFilm.end())
	{
		auto copyPos = pos;
		++copyPos;
		mFilm.insert(copyPos, *pos);
	}
}

// Gets the "index" that corresponds to the current frame
unsigned MoviePlayer::getCurrFrameNum() const
{
	return currFrameNum;
}

// Gets the total number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
	return mFilm.size();
}

// Gives the number of lines in a frame
unsigned int MoviePlayer::getFrameSize() const
{
	return FRAMESIZE;
}

// Uses mFilmName (set by constructor) to fill
void MoviePlayer::loadTape()
{
	std::ifstream file(mFilmName);
	if (!file)
	{
		std::cerr << "Failed to open the movie file: " << mFilmName << std::endl;
		return;
	}

	mFilm.clear();
	currFrameNum = 0;

	std::string line;
	std::string frameText;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		if (line[0] == '_')
		{
			mFilm.push_back(frameText);
			frameText = "";
		}
		else
		{
			frameText += line + "\n";
		}
	}

	if (!frameText.empty())
	{
		mFilm.push_back(frameText);
	}

	pos = mFilm.begin();
}