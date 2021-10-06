/* Smoking Gun Interactive Code Evaluation
 * Author: Danillo Neves Souza
 * Created on: October 5th, 2021
 */

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include "Entity.h"
#include "HealthComponent.h"
#include "AttackComponent.h"
#include "MovementComponent.h"

void DetectNumberOfIntersections(Entity**, unsigned int);

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Specify a file to run this program.\n";
		return 1;
	}
	std::cout << "Running program against file: " << argv[1] << "\n";
	std::ifstream file(argv[1], std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file.\n";
		return 2;
	}
	unsigned int numberOfEntities = 0;
	if (!(file >> numberOfEntities))
	{
		std::cerr << "Failed to get number of Entities from file.\n";
		return 3;
	}

	std::cout << "Number of entities is: " << numberOfEntities << "\n";

	// Allocate the collection of entities
	Entity** entityCollection = new Entity* [numberOfEntities];

	// Populate the collection
	for (unsigned int i = 0; i < numberOfEntities; ++i)
	{
		float x = 0;
		float y = 0;
		float width = 0;
		float height = 0;
		if (!(file >> x >> y >> width >> height))
		{
			std::cerr << "Error getting bounds on line " << i + 1 << ".\n";
			return 4;
		}

		// Create Entity with bounding box. Add components later.
		Rectangle2D newBox = Rectangle2D(Vector2D(x,y), width, height);
		entityCollection[i] = new Entity(newBox);

		// Not every Entity has Components.
		std::string componentTypes;
		const auto currentPos = file.tellg();
		file >> componentTypes;
		if (!componentTypes.empty() && !std::isalpha(componentTypes.back()))
		{
			file.seekg(currentPos);
			componentTypes.clear();
		}
		for (const char type : componentTypes)
		{
			switch (type)
			{
				case 'H':
				{
					HealthComponent h = HealthComponent();
					entityCollection[i]->TryAddComponent(h);
					break;
				}
				case 'A':
				{
					AttackComponent a = AttackComponent();
					entityCollection[i]->TryAddComponent(a);
					break; 
				}
				case 'M':
				{
					MovementComponent m = MovementComponent();
					entityCollection[i]->TryAddComponent(m);
					break;
				}
				default:
					std::cerr << "Unknown Component type: " << type << "\n";
					break;
			}
		}
	}
	file.close();

	const auto start = std::chrono::high_resolution_clock::now();
	DetectNumberOfIntersections(entityCollection, numberOfEntities);
	const auto end = std::chrono::high_resolution_clock::now();
	const auto runMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Algorithm executed in " << runMS.count() << "ms.\n";

	// Deallocate the collection of entities
	for (unsigned int i = 0; i < numberOfEntities; i++) delete[] entityCollection[i];
	delete[] entityCollection;

	return 0;
}

/// <summary>
/// Algorithm to detect number of Entity intersections.
/// If two Entities intersect each other, that counts as one unique intersection rather than two.
/// </summary>
void DetectNumberOfIntersections(Entity** entities, unsigned int numberOfEntities)
{
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "\rChecking entities..." << "\n";
	int numberOfIntersections = 0;
	for (unsigned int i = 0; i < numberOfEntities; ++i)
	{
		//std::cout << "\x1B[3J\x1B[H";
		//std::cout << "\rChecking entity #" << i << "\n";
		// Compare entity with all other entities below its index
		for (unsigned int j = i + 1; j < numberOfEntities; ++j)
		{
			if ((*entities[i]).CollidesWith(*entities[j]))
			{
				numberOfIntersections++;
			}
		}
	}

	std::cout << "**********************"<< "\n";
	std::cout << "Number of intersections: " << numberOfIntersections << "!\n";
	std::cout << "**********************" << "\n";
}