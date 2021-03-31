#include "MazeDoor.h"
namespace maze
{
	bool MazeDoor::IsOpen() const
	{
		return open;
	}

	void MazeDoor::SetOpen(bool state)
	{
		open = state;
	}
}