#include "pch.h"

#include "Cat.h"
#include "Dog.h"
#include <vector>

int main()
{
	std::cout << "\n\n\nVector of base class pointers\n";
	std::vector<Animal*>animals;
	//animals.push_back(new Animal{});
	animals.push_back(new Dog{});
	animals.push_back(new Cat{});
	animals.push_back(new Cat{});
	animals.push_back(new Dog{});
	animals.push_back(new Dog{});
	animals.push_back(new Cat{});
	for (Animal*pAnimal : animals)
	{
		pAnimal->MakeSound();
	}

	for (Animal* pAnimal : animals)
	{
		//((Dog*)pAnimal)->SetSurveillanceMode(true);  // Typecast from Animal to Dog

		Dog* pDog{ dynamic_cast<Dog*>(pAnimal) };  
		if (pDog) // Check if it exits (in case it was a cat)
		{
			pDog->SetSurveillanceMode(true);
		}
	}


	for (Animal* pAnimal : animals)
	{
		if (typeid(*pAnimal) == typeid(Cat))
		{
			// Only if the type of the object is a Cat 
			Cat* pCat{ static_cast<Cat*>(pAnimal) };
			pCat->SetNightVision(true);
		}
		
		
	}



	for (Animal* pAnimal : animals)
	{
		// The same but using enum	
		if (pAnimal->GetAnimalType() == Animal::AnimalType::cat)
		{
			Cat* pCat{ static_cast<Cat*>(pAnimal) };
			pCat->SetNightVision(false);
		}

	}

	for (Animal*pAnimal : animals)
	{
		delete pAnimal;
	}


	std::cin.get();
	return 0;
}

