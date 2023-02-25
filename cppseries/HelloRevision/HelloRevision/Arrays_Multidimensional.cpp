#include<iostream>

int main() {
	int** a2d = new int* [10];

	for (int i = 0; i < 10; i++) {
		a2d[i] = new int[50];
	}

	//Deleting
	/* for(int i = 0 ; i < 10; i++)
	*		delete[] a2d[i];
	* delete[] a2d;
	* 
	*/

	/// <summary>
	/// Creating a 3d array
	/// </summary>
	/// <returns></returns>
	
	int*** a3d = new int** [10];

	for (int i = 0; i < 10; i++)
	{
		a3d[i] = new int*[10];
		for (int j = 0; j < 10; j++)
		{
			int** ptr = a3d[i];
			ptr[j] = new int[10];
		}
	}

	return 0
}