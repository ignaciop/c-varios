#include <iostream>

enum ItemsTypes {
	ITEM_HEALTH_POTIONS,
	ITEM_TORCHES,
	ITEM_ARROWS,
	MAX_ITEMS
};


int countTotalItems(int *items) {
	int totalItems = 0;
	
	for (int index = 0; index < MAX_ITEMS; ++index) {
		totalItems =+ items[index];
	}
	
	return totalItems;
}


int main() {
	int items[MAX_ITEMS] = {2, 5, 10};
	
	std::cout << "The player has " << countTotalItems(items) << " items in total.\n"; 

	return 0;
}