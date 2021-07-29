#include "Object.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<float> initial_position {0, 0};
	std::vector<float> initial_velocity {2.0, 3.0};

	Object object(5, initial_position, initial_velocity);

	do	
	{
		object.Update(0.001);
	} while (object.GetPosition()[1] > 0);

	std::cout << object.GetPosition()[0] << std::endl;

	return 0;
}
