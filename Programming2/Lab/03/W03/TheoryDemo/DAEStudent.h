#pragma once
#include "Person.h"
class DAEStudent final : public Person		// Final makes this the last class (no one can inheritance from this class)
{
	public:
		enum class Major{GD, SD, GGP, IGP, ANIM, VFX};
		DAEStudent(const std::string& firstName, const std::string& lastName, Major major);
		~DAEStudent();

		void Identify() const;
private:
	Major m_Major;

	std::string GetName() const;
};

