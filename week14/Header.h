#pragma once
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal(const char* name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	Animal()
	{
		this->name = new char[1];
		strcpy_s(this->name, 1, " ");
	}
	Animal(const Animal& other)
	{
		this->copy(other);
	}
	Animal& operator=(const Animal& other)
	{
		if (this != &other)
		{
			delete[] this->name;
			this->copy(other);
		}
		return *this;
	}
	~Animal()
	{
		delete[] this->name;
	}
	const char* getName() const
	{
		return this->name;
	}

	virtual void asksForFood() = 0
	{

	}

private:
	char* name;
	void copy(const Animal& other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
	}

};

class Parrot : public Animal
{
public:
	Parrot(const char* name) : Animal(name)
	{
	}
	void asksForFood()
	{
		cout << "parrot " << this->getName() << "whistles for food" << endl;
	}
};

class Monkey : public Animal
{
public:
	Monkey(const char* name) : Animal(name)
	{
	}
	void asksForFood()
	{
		cout << "monkey " << this->getName() << "cries for food" << endl;
	}
};

class Zoo
{
public:
	Zoo()
	{
		this->currentAnimal = 0;
	}
	Zoo(const Zoo& other)
	{
		this->copy(other);
	}
	Zoo& operator=(const Zoo& other)
	{
		if (this != &other)
		{
			delete[] this->listOfAnimals;
			this->copy(other);
		}
		return *this;
	}
	~Zoo()
	{
		//delete[] this->listOfAnimals;
	}
	void add(Animal* animal)
	{
		if (currentAnimal < 100) {
			this->listOfAnimals[currentAnimal] = animal;
			currentAnimal++;
		}
	}
	void morningSounds()
	{
		for (size_t i = 0; i < currentAnimal; i++)
		{
			this->listOfAnimals[i]->asksForFood();
		}
	}

private:
	Animal* listOfAnimals[100];
	int currentAnimal;
	void copy(const Zoo& other)
	{
		this->currentAnimal = other.currentAnimal;

		for (int i = 0; i < this->currentAnimal; i++)
		{
			this->listOfAnimals[i] = other.listOfAnimals[i];
		}
	}
};

