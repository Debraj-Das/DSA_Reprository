// C++ Program to test presence of file
#include <iostream>
#include <sys/stat.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	// Path to the directory
	const char* file = "input.txt"; // also you can give absoluted path

	// Structure which would store the metadata
	struct stat sb;

	// Calls the function with path as argument
	// If the file/directory exists at the path returns 0
	// If block executes if path exists
	if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR))
		cout << "The path is valid!";
	else
		cout << "The Path is invalid!";

	return 0;
}
