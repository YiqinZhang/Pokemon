class PokemonCenter: public Building
{
enum PokemonCenterStates{
    STAMINA_POINTS_AVAILABLE = 0;
    NO_STAMINA_POINTS_AVAILABLE = 1;
};
private:
    unsigned int stamina_capacity;
    unsigned int num_stamina_points_remaining;
    double dollar_cost_per_stamina_points;
    
    PokemonCenter() ;
    PokemonCenter(int in_Id, Point2D in_loc) ;
public:
    bool HasStaminaPoints();
    unsigned int GetNumStaminaPointsRemaining();
    double GetDollarCost(unsigned in stamina_points);
    unsigned int DistributeStamina(unsigned int points_needed = <??>);
    bool Update();
    void ShowStatus();
};
