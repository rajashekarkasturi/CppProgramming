#include<iostream>
#include<vector>

struct Vertex {
	int x, y, z;

	Vertex(int x, int y, int z) :
		x(x), y(y), z(z)
	{

	}

	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z) 
	{
		std::cout << "Copied" << std::endl;
	}
};

int main() {

	std::vector<Vertex> vertices;
	/*
	//vertices.push_back(Vertex(1, 2, 3));
	//vertices.push_back(Vertex(4, 5, 6));
	//vertices.push_back(Vertex(7, 8, 9));

	//Output:

	*	Copied
		Copied
		Copied
		Copied
		Copied
		Copied

		Here copying is happening 2 times for each push_back
		1. Creating a stack allocated object and from there it is copying to the vector allocated memory.
	*/

	/*
	vertices.reserve(3);
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
	
	Output:
	Copied
	Copied
	Copied

	Using the reserve, we decreased one overhead of copying.
	*/

	//Finally using the emplace_back, we can directly insert at the memory allocated at the vector location

	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(3, 4, 5);
	vertices.emplace_back(7, 8, 9);


	return 0;
}