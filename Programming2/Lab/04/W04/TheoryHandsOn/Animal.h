#pragma once
class Animal
{
public:
	enum class AnimalType{animal, cat, dog};
	Animal(AnimalType animalType);
	virtual ~Animal();  // Virtual Destructor allows calling the destructor of the derived classes
	virtual void MakeSound()const =0; // Can instantiate the class anymore
	AnimalType GetAnimalType()const;

private:
	const AnimalType m_AnimalType;
};

 
