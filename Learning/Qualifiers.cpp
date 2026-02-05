#include <iostream>
#include <string>

inline int calculateSum(int x, int y) {
  return x + y; // removes overhead from function call since compiler may choose
               // to insert code directly into calling code
}

constexpr int calcXp(int level) {
    return level * level * 100; // eval at compile time
}

void generateUniqueID(){
	int id = 0; //static local variable - value is kept even  after function call
	++id;
	std::cout << "Generated id: " << id << std::endl;

}


int main() {
  // const
  const int maxHealth = 100;
  // maxHealth = 200; // Error: assignment of read-only variable 'maxHealth'

  volatile int enemyStatus; // forces c++ to always check during comparisons and
                            // not optimise; useful for embedd
  constexpr const int experience = calcXp(5);
  std::cout << "Experience: " << experience << std::endl;

  generateUniqueID(); // Output: Generated ID: 1
  generateUniqueID(); // Output: Generated ID: 2
  generateUniqueID(); // Output: Generated ID: 3
  return 0;
}
