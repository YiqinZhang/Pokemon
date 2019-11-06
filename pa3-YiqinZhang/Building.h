#include "Point2D.h"

class Building: public GameObject
{
private:
    unsigned int pokemon_count;
    Building();
    Building(char in_code, int in_Id, Point2D in_loc);
public:
	void AddOnePokemon();
	void RemoveOnePokemon();
	void ShowStatus();
	void ShouldBeVisible()
};
