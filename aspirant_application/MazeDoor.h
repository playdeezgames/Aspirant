#pragma once
namespace maze
{
	class MazeDoor
	{
	private:
		bool open;
	public:
		MazeDoor() : open(false) {}
		MazeDoor(const MazeDoor& other) : open(other.open) {}
		MazeDoor(MazeDoor&& other) : open(other.open) {}
		MazeDoor& operator=(const MazeDoor& other) { open = other.open; return *this; }
		MazeDoor& operator=(MazeDoor&& other) { open = other.open; return *this; }
		bool IsOpen() const;
		void SetOpen(bool);
	};
}