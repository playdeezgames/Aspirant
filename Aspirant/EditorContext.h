#pragma once
namespace aspirant
{
	class EditorContext
	{
	private:
		size_t scenarioIndex;
	public:
		EditorContext();
		void SetScenarioIndex(size_t);
		size_t GetScenarioIndex() const;
	};
}
